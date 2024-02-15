#include "ftmodmov.h"
#include "ui_ftmodmov.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>
#include <QShortcut>
#include <QFileDialog>
#include <QScreen>
#include "ftimage.h"

FTModMov::FTModMov(int pid,QSqlDatabase pdb,QString ptitle,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FTModMov)
{
    ui->setupUi(this);
    ui->label_6->setVisible(false);
    ui->lbImg->installEventFilter(this);

    ui->lbImgPath->setVisible(false);
    QShortcut *sh=new QShortcut(QKeySequence(Qt::ALT + Qt::Key_B),this);
    connect(sh,&QShortcut::activated,this,&chooseImage);
    id=pid;
    db=pdb;
    ui->lbTitle->setText(ptitle);
    setup();
}

FTModMov::~FTModMov()
{
    delete ui;
}

void FTModMov::setup()
{
    QSqlQuery q(db);
    QString sql="SELECT tags_mov.data, tags_mov.barcode,anagrafica.ragione_sociale,azioni.ID,tags_mov.amount,tags_mov.note ,tags_mov.bolla from tags_mov,anagrafica,azioni where anagrafica.ID=tags_mov.IDStampatore and azioni.ID=tags_mov.azione and tags_mov.id=:pid";
    q.prepare(sql);
    q.bindValue(":pid",id);
    q.exec();

    QString bolla=QString();

    QSqlQueryModel *mod=new QSqlQueryModel();
    mod->setQuery(q);

    ui->dateEdit->setDate(mod->index(0,0).data(0).toDate());
    ui->lbBarcode->setText(mod->index(0,1).data(0).toString());
    ui->leAmount->setText(mod->index(0,4).data(0).toString());
    ui->teNote->setPlainText(mod->index(0,5).data(0).toString());
    bolla= mod->index(0,6).data(0).toString();

    ui->lbImgPath->setText(bolla);
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();




    QImage image(bolla);
    //image=image.scaled(209,297);


    QPixmap pixmap=QPixmap::fromImage(image).scaled(209,207,Qt::IgnoreAspectRatio);
   // pixmap.scaled(209,207,Qt::IgnoreAspectRatio);



    ui->lbImg->setPixmap(pixmap);
    ui->lbImgPath->setText(bolla);



    if (mod->index(0,3).data(0).toInt()==1)
     {
        ui->rbCarico->setChecked(true);

     } else {
       ui->rbScarico->setChecked(true);
     }



    QSqlTableModel *stampatorimod = new QSqlTableModel(nullptr,db);
    stampatorimod->setTable("anagrafica");
    stampatorimod->setFilter("stampatore>0");
    stampatorimod->setSort(1,Qt::AscendingOrder);
    stampatorimod->select();
    ui->cbStampatori->setModel(stampatorimod);
    ui->cbStampatori->setModelColumn(1);
    int s=ui->cbStampatori->findText(mod->index(0,2).data(0).toString());
    qDebug()<<"S:"<<s;
    ui->cbStampatori->setCurrentIndex(s);
     connect(this,SIGNAL(imageClicked(QString)),this,SLOT(showImage(QString)));







}

void FTModMov::on_pbCancel_clicked()
{
    close();
}

void FTModMov::save()
{
    QSqlQuery q(db);
    QString sql="UPDATE fbgmdb260.tags_mov SET data = :data,IDStampatore = :IDStampatore,azione = :azione,amount = :amount,note = :note, bolla=:bolla  WHERE ID = :id";
    qDebug()<<"SAVE";

    q.prepare(sql);

    q.bindValue(":data",ui->dateEdit->date());
    q.bindValue(":IDStampatore",ui->cbStampatori->model()->index(ui->cbStampatori->currentIndex(),0).data(0).toInt());
     int azione=0;
    int amount=ui->leAmount->text().toInt();
    if(ui->rbCarico->isChecked())
    {
        azione=1;
    }
    else if (ui->rbScarico->isChecked())
    {
        azione=2;
    }
    q.bindValue(":azione",azione);
    q.bindValue(":amount",amount);
    q.bindValue(":note",ui->teNote->toPlainText());
    q.bindValue(":id",id);
    q.bindValue(":bolla",ui->lbImgPath->text().simplified());

    db.transaction();
   if(q.exec())
   {
       qDebug()<<"OK";
     db.commit();
     QMessageBox::information(nullptr,QApplication::applicationName(),"Dati salvati",QMessageBox::Ok);
     emit mod_mov_done();

   }else{

       qDebug()<<"ERORRE!"<<q.lastError().text()<<ui->cbStampatori->model()->index(ui->cbStampatori->currentIndex(),0).data(0).toInt()<<"azione="<<azione<<"amount"<<amount;

       db.rollback();
       QMessageBox::information(nullptr,QApplication::applicationName(),"Errore:"+q.lastError().text(),QMessageBox::Ok);

   }

}


void FTModMov::on_pbSave_clicked()
{
    if (QMessageBox::question(nullptr,QApplication::applicationName(),"Salvare?",QMessageBox::Ok)==QMessageBox::Ok)
    {
        save();
    }
    close();

}

void FTModMov::chooseImage()
{
    QString filename= QFileDialog::getOpenFileName(nullptr,"Scegli immagine","","tutti(*.*);;JPEG(*.jpg,*.jpeg);;PNG(*.png);;TIFF(*.tif)");
    QImage image(filename);
    image=image.scaled(200,400,Qt::KeepAspectRatio);

    ui->lbImg->setPixmap(QPixmap::fromImage(image).scaledToWidth(297));



   // QPixmap pixmap=QPixmap::fromImage(image);


  //  ui->lbImg->setPixmap(pixmap);
    ui->lbImgPath->setText(filename);

}


void FTModMov::on_rbCarico_toggled(bool checked)
{
    ui->lbImg->setVisible(checked);
    //ui->lbImgPath-
}


void FTModMov::on_pbImg_clicked()
{
    chooseImage();
}

void FTModMov::showImage(const QString path)
{
    FTImage *f=new FTImage(path);
    // connect(f,SIGNAL(transfer_Barcode(QString)),this,SLOT(setBarcode(QString)));
    f->show();
}
bool FTModMov::eventFilter(QObject *obj, QEvent *evt)
{


    if(obj==ui->lbImg && evt->type()==QEvent::MouseButtonDblClick)
    {

        qDebug()<<"event label1";
        emit imageClicked(ui->lbImgPath->text().simplified());


    }


    return QObject::eventFilter(obj,evt);

}

