#include "ftoperate.h"
#include "ui_ftoperate.h"
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QCompleter>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>
#include <QShortcut>
#include "ftimage.h"
#include <QMessageBox>

FTOperate::FTOperate(const int p_action,const int p_id_tag, QSqlDatabase pdb,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FTOperate)
{
    ui->setupUi(this);
    QShortcut *sh=new QShortcut(QKeySequence(Qt::ALT + Qt::Key_B),this);
    connect(sh,&QShortcut::activated,this,&chooseImage);

    ui->label_8->setVisible(false);
    ui->lbImgPath->setVisible(false);

    db=pdb;
    id_tag=p_id_tag;
    action=p_action;
    setup();

}

void FTOperate::setup()
{


    ui->deDate->setDate(QDate::currentDate());
    ui->lbImg->installEventFilter(this);



    modbarcodes=new QSqlQueryModel();
    QString sql="SELECT barcode from tags order by barcode";
    QSqlQuery q(db);
    q.exec();
    modbarcodes->setQuery(sql);

    sql="SELECT barcode from tags where ID=:id_tag";
    q.prepare(sql);
    q.bindValue(":id_tag",id_tag);
    q.exec();
    qDebug()<<"TAGID"<<id_tag;
    q.next();
    ui->leBarcode->setText(q.value(0).toString());

    QCompleter *barcmp=new QCompleter(modbarcodes);
    barcmp->setCaseSensitivity(Qt::CaseInsensitive);
    barcmp->setCompletionColumn(0);
    barcmp->setCompletionMode(QCompleter::PopupCompletion);
    ui->leBarcode->setCompleter(barcmp);

    modstampatori=new QSqlTableModel(this,db);
    modstampatori->setTable("anagrafica");
    modstampatori->setFilter("stampatore>0");
    modstampatori->select();
    ui->cbStampatore->setModel(modstampatori);
    ui->cbStampatore->setModelColumn(1);

    modtipi=new QSqlTableModel(this,db);
    modtipi->setTable("tags_tipi");
    modtipi->select();
    ui->cbTipo->setModel(modtipi);
    ui->cbTipo->setModelColumn(1);


    if(action==1){
        ui->rbCarico->setChecked(true);
        ui->cbStampatore->setVisible(true);
        ui->label_4->setVisible(true);
    }
    if(action==2){

        ui->rbScarico->setChecked(true);
        ui->cbStampatore->setVisible(false);
        ui->label_4->setVisible(false);

    }


    connect(this,&imageClicked,&showImage);


    emit ui->leBarcode->returnPressed();





}

void FTOperate::saveOp()
{
    QSqlQuery q(db);
    QString sql="INSERT INTO `fbgmdb260`.`tags_mov`(`ID_tags`,`data`,`barcode`,`IDStampatore`,`azione`,`amount`,`note`,`bolla`) VALUES(:idtags,:data,:barcode,:IDStampatore,:azione,:amount,:note,:bolla)";
    q.prepare(sql);
    q.bindValue(":idtags",id_tag);

    qDebug()<<"saveOp Id_tag:"<<id_tag;

    q.bindValue(":idtags",id_tag);
    q.bindValue(":data",ui->deDate->date());
    q.bindValue(":barcode",ui->leBarcode->text());
    q.bindValue(":IDStampatore",ui->cbStampatore->model()->index(ui->cbStampatore->currentIndex(),0).data().toInt());
    int azione;
    ui->rbCarico->isChecked() ? azione=1:azione=2;

    q.bindValue(":azione",azione);
    q.bindValue(":amount",ui->leAmount->text().toInt());
    q.bindValue(":note",ui->teNote->toPlainText());
    q.bindValue(":bolla",ui->lbImgPath->text().simplified());


    db.transaction();

    if(q.exec())
    {

        db.commit();

        qDebug()<<"SAVEOP:"<<q.lastQuery();
        QMessageBox::information(nullptr,QApplication::applicationName(),"Dati salvati",QMessageBox::Ok);
        emit operation_saved();


    }
    else
    {


        QMessageBox::information(nullptr,QApplication::applicationName(),"ERORE:"+q.lastError().text(),QMessageBox::Ok);
        db.rollback();

    }

    qDebug()<<"LASTERROR"<<q.lastError().text();
}


FTOperate::~FTOperate()
{
    delete ui;
}

void FTOperate::populate()
{
    QString sql=QString();
    QString title=QString();
    QSqlQuery q(db);

    sql="SELECT tags.barcode,tags.IDCLIente,tags.IDProdotto,prodotti.descrizione,clienti.ragione_sociale AS CLIENTE,IDTipo,tags_tipi.descrizione, specifica\
        FROM tags, anagrafica as clienti, prodotti,tags_tipi\
                                     WHERE clienti.ID=tags.IDCliente AND prodotti.ID=tags.IDProdotto AND tags_tipi.ID=tags.IDTipo AND tags.ID=:id_tag";
                                                                                                                                       q.prepare(sql);
    q.bindValue(":id_tag",id_tag);
    qDebug()<<q.lastError().text();
    if (q.exec())
    {
        q.next();
        int ixt=ui->cbTipo->findText(q.value(5).toString());
        ui->cbTipo->setCurrentIndex(ixt);
        title=q.value(3).toString()+ " - " + q.value(4).toString();

        ui->lbTitle->setText(title);

    }
}

void FTOperate::chooseImage()
{
    connect(this,SIGNAL(imageClicked(QString)),this,SLOT(showImage(QString)));


    QString filename= QFileDialog::getOpenFileName(nullptr,"Scegli immagine","","tutti(*.*);;JPEG(*.jpg,*.jpeg);;PNG(*.png);;TIFF(*.tif)");


    if(QMessageBox::question(this,QApplication::applicationName(),"Confermare?",QMessageBox::Ok|QMessageBox::Cancel)==QMessageBox::Ok)
    {


    QImage image(filename);
    image=image.scaled(209,297);


    QPixmap pixmap=QPixmap::fromImage(image);


    ui->lbImg->setPixmap(pixmap);
    ui->lbImgPath->setText(filename);

    }


}



void FTOperate::on_pbSave_clicked()
{
    saveOp();
    close();
}


void FTOperate::on_pbClose_clicked()
{
    close();
}





void FTOperate::on_rbCarico_toggled(bool checked)
{
    // ui->cbStampatore->setVisible(checked);
    int six=ui->cbStampatore->findText("NESSUNO STAMPATORE");
    ui->cbStampatore->setCurrentIndex(six);

    if(checked)
    {
        /* int six=ui->cbStampatore->findText("NESSUNO STAMPATORE");
       ui->cbStampatore->setCurrentIndex(six);*/
        ui->cbStampatore->setVisible(true);
        ui->label_4->setVisible(true);
        ui->label_8->setVisible(true);
        ui->lbImg->setVisible(true);
    }

    if(!checked){

        ui->rbScarico->setChecked(true);
        ui->cbStampatore->setVisible(false);
        ui->label_4->setVisible(false);
        ui->label_8->setVisible(true);
        ui->lbImg->setVisible(false);
    }
}


void FTOperate::on_pbBolla_clicked()
{
    chooseImage();

}

void FTOperate::showImage(const QString path)
{
    FTImage *f=new FTImage(path);
    // connect(f,SIGNAL(transfer_Barcode(QString)),this,SLOT(setBarcode(QString)));
    f->show();
}

bool FTOperate::eventFilter(QObject *obj, QEvent *evt)
{


    if(obj==ui->lbImg && evt->type()==QEvent::MouseButtonDblClick)
    {

        qDebug()<<"event label1";
        emit imageClicked(ui->lbImgPath->text());

    }


    return QObject::eventFilter(obj,evt);

}

