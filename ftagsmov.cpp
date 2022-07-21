#include "ftagsmov.h"
#include "ui_ftagsmov.h"
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QFileDialog>
#include <QPixmap>
#include "ftoperate.h"
#include <QMessageBox>
#include <QCompleter>
#include <QSettings>
#include <QMessageBox>
#include <QMouseEvent>
#include "ftimage.h"


#include <QDebug>
#include <QSqlError>

//#define CLIENTE_GENERICO 783

struct {

    QImage img;
    QString path;

}img1, img2;

FTagsMov::FTagsMov(int pazione, QString pbarcode, QString pdescprodotto, QSqlDatabase pdb, QWidget *parent):
    QWidget(parent),
    ui(new Ui::FTagsMov)
{

    QSettings settings("ctags.ini",QSettings::IniFormat);

    GENERIC_CUSTOMER=settings.value("generic_customer_id").toInt();
    GENERIC_PRODUCT=settings.value("generic_product_id").toInt();

    ui->setupUi(this);
    ui->lbImage1->installEventFilter(this);
    ui->lbImage2->installEventFilter(this);

    db=pdb;
    azione=pazione;
    barcode=pbarcode;
    descprod=pdescprodotto;
    separator="F: ";
    modbarcodes=new QSqlTableModel(nullptr,db);
    modbarcodes->setTable("tags");
    modbarcodes->setSort(0,Qt::AscendingOrder);
    modbarcodes->select();
    QCompleter *compbar=new QCompleter(modbarcodes);
    compbar->setCaseSensitivity(Qt::CaseInsensitive);
    compbar->setCompletionColumn(0);
    compbar->setCompletionMode(QCompleter::PopupCompletion);

    ui->leBarcode->setCompleter(compbar);
    ui->pbMov->setVisible(false);


    setup();

}

FTagsMov::~FTagsMov()
{
    delete ui;
}

void FTagsMov::on_pbClose_clicked()
{
    close();
}



void FTagsMov::setup()
{


    connect(this,SIGNAL(imageClicked(QString)),this,SLOT(showImage(QString)));

    modtipi=new QSqlTableModel(nullptr,db);
    modtipi->setTable("tags_tipi");
    modtipi->setSort(1,Qt::AscendingOrder);
    modtipi->select();

    ui->cbTipo->setModel(modtipi);
    ui->cbTipo->setModelColumn(1);
    ui->cbTipo->setCurrentIndex(0);


    modclienti=new QSqlTableModel(nullptr,db);
    modclienti->setTable("anagrafica");
    modclienti->setFilter("cliente>0");
    modclienti->setSort(1,Qt::AscendingOrder);
    modclienti->select();

    ui->cbClienti->setModel(modclienti);
    ui->cbClienti->setModelColumn(1);
    ui->cbClienti->setCurrentIndex(0);

    sl_immagini<<QString()+separator<<QString();

    if(azione==1)
    {
        ui->pbNew->setVisible(false);
        QSqlQuery q(db);
        QString sql ="select tags_tipi.descrizione as tipo, clienti.ragione_sociale as clienti, prodotti.descrizione as prodotto, tags.barcode, tags.specifica,tags.immagine,tags.note\
                from tags,tags_tipi,anagrafica as clienti,prodotti\
                where tags.barcode  =:barcode and clienti.cliente>0 and tags_tipi.ID=tags.IDtipo and clienti.ID=tags.IDCliente and prodotti.ID=tags.IDProdotto";
                q.prepare(sql);
        q.bindValue(":barcode",barcode);
        q.exec();
        QSqlQueryModel *datamod=new QSqlQueryModel(this);
        datamod->setQuery(q);

        int ixt=ui->cbTipo->findText(datamod->index(0,0).data(0).toString());
        ui->cbTipo->setCurrentIndex(ixt);
        int ixc=ui->cbClienti->findText(datamod->index(0,1).data(0).toString());
        ui->cbClienti->setCurrentIndex(ixc);

        getProdotti(modclienti->index(ixc,0).data(0).toInt());

        ui->leBarcode->setText(datamod->index(0,3).data(0).toString());
        ui->leSpecifica->setText(datamod->index(0,4).data(0).toString());
        ui->teNote->setText(datamod->index(0,6).data(0).toString());


        s_images = datamod->index(0,5).data(0).toString();

        sl_immagini=s_images.split(separator);




        QPixmap p1,p2;


        QString fn1,fn2=QString();

        fn1=sl_immagini[0];
        fn2=sl_immagini[1];


        QImage image1(fn1);
        QImage image2(fn2);

        ui->lbImage1->setMinimumWidth(300);
        ui->lbImage1->setMinimumHeight(300);
        ui->lbImage1->setMaximumWidth(300);
        ui->lbImage1->setMaximumHeight(300);
        ui->lbImage2->setMinimumWidth(300);
        ui->lbImage2->setMinimumHeight(300);
        ui->lbImage2->setMaximumWidth(300);
        ui->lbImage2->setMaximumHeight(300);



        img1.path=fn1;
        img1.img=image1;

        img2.path=fn2;
        img2.img=image2;


        p1=QPixmap::fromImage(img1.img);
        ui->lbImage1->setPixmap(p1);

        p2=QPixmap::fromImage(img2.img);
        ui->lbImage2->setPixmap(p2);

        connect(this,SIGNAL(refresh_img()),this,SLOT (refresh()));



    }

    on_rbAll_toggled(true);


    ui->pbChooseImage->setEnabled(false);


}

void FTagsMov::getProdotti(int pidcliente)
{
    QString sql;
    QSqlQuery q(db);

    QSettings settings("ctags.ini",QSettings::IniFormat);

    GENERIC_CUSTOMER=settings.value("generic_customer_id").toInt();

    if (pidcliente==GENERIC_CUSTOMER)
    {
        sql="select prodotti.ID,prodotti.descrizione from prodotti where tipo=2 order by descrizione ASC";
        q.prepare(sql);
        q.exec();

    }
    else
    {
        sql="select prodotti.ID,prodotti.descrizione,associazioni.visualizza from prodotti, ricette, associazioni where ricette.ID=associazioni.ID_ricetta and prodotti.ID=ricette.ID_prodotto and associazioni.visualizza>0 and associazioni.ID_cliente=:idcliente order by prodotti.descrizione asc";


        q.prepare(sql);
        q.bindValue(":idcliente",pidcliente);
        q.exec();

    }



    modprodotti=new QSqlQueryModel();
    modprodotti->setQuery(q);

    ui->cbProdotto->setModel(modprodotti);
    ui->cbProdotto->setModelColumn(1);

    int ixp=ui->cbProdotto->findText(descprod);
    ui->cbProdotto->setCurrentIndex(ixp);

}

void FTagsMov::save()
{
    QSqlQuery q(db);
    QString sql=QString();


    if(azione==0)
    {
        sql="INSERT INTO `fbgmdb260`.`tags`(`barcode`,`IDProdotto`,`IDCliente`,`IDTipo`,`specifica`,`immagine`,`note`) VALUES (:barcode,:IDProdotto,:IDCliente,:IDTipo,:specifica,:immagine,:note)";
    }else{


        sql="UPDATE `fbgmdb260`.`tags` SET`barcode`=:barcode,`IDProdotto`=:IDProdotto,`IDCliente`=:IDCliente,`IDTipo`=:IDTipo,`specifica`=:specifica,`immagine`=:immagine,`note`=:note WHERE barcode=:obarcode";

    }

    q.prepare(sql);
    QString nbarcode=ui->leBarcode->text();
    int idprodotto=0;
    if(ui->cbGenericProduct->isChecked()){

        idprodotto=GENERIC_PRODUCT;

    }else{
        idprodotto=modprodotti->index(ui->cbProdotto->currentIndex(),0).data(0).toInt();
    }
    int idcliente=modclienti->index(ui->cbClienti->currentIndex(),0).data(0).toInt();
    int idtipo=modtipi->index(ui->cbTipo->currentIndex(),0).data(0).toInt();
    QString spec=ui->leSpecifica->text();
    QStringList loc_immagini;
    loc_immagini<<img1.path<<img2.path;
    sl_immagini=loc_immagini;
    QString lista_immagini= sl_immagini.join(separator);
    QString note=ui->teNote->toPlainText();



    q.bindValue(":barcode",nbarcode);
    q.bindValue(":IDProdotto",idprodotto);
    q.bindValue(":IDCliente",idcliente);
    q.bindValue(":IDTipo",idtipo);
    q.bindValue(":specifica",spec);
    q.bindValue(":immagine",lista_immagini);
    q.bindValue(":note",note);
    if(azione==1){
        q.bindValue(":obarcode",barcode);

    }

    if(QMessageBox::question(nullptr,QApplication::applicationName(),"Salvare?",QMessageBox::Ok|QMessageBox::Cancel)==QMessageBox::Ok)
    {

        db.transaction();

        if(q.exec())
        {
            db.commit();
            emit tag_saved();
            ui->pbNew->setVisible(true);
            return ;

        }
        else
        {
            db.rollback();
            qDebug()<<q.lastError().text();
            QMessageBox::information(nullptr,QApplication::applicationName(),"Errore salvando i dati",QMessageBox::Ok);

        }
    }
    else
    {
        return;
    }
}

void FTagsMov::chooseImage()
{


    QString filename= QFileDialog::getOpenFileName(nullptr,"Scegli immagine","","tutti(*.*);;JPEG(*.jpg,*.jpeg);;PNG(*.png);;TIFF(*.tif)");

    // QString s_images=QString();

    if(ui->rb1->isChecked()){

        QImage image(filename);
        img1.path=filename;
        img1.img=image;
        sl_immagini[0]=img1.path;

        QPixmap pixmap=QPixmap::fromImage(image);
        ui->lbImage1->setPixmap(pixmap);

    }
    else if(ui->rb2->isChecked())
    {

        QImage image(filename);
        img2.path=filename;
        img2.img=image;
        sl_immagini[1]=img2.path;

        //    qDebug()<<"chooseImage"<<sl_immagini.size();

        QPixmap pixmap1=QPixmap::fromImage(image);
        ui->lbImage2->setPixmap(pixmap1);

    }




}

void FTagsMov::img_reset()
{
    //qDebug()<<"img_reset";

    if (ui->rbAll->isChecked())
    {
        img1.img=QImage();
        img1.path=QString();
        img2.img=QImage();
        img2.path=QString();
    }

    if(ui->rb1->isChecked())
    {
        img1.img=QImage();
        img1.path=QString();
    }

    if(ui->rb2->isChecked())
    {
        img2.img=QImage();
        img2.path=QString();
    }


    refresh();
}

void FTagsMov::refresh()
{
   // qDebug()<<"refresh()";

    if(ui->rb1->isChecked()){

        //   QImage image(img1.img);
        sl_immagini[0]=img1.path;

        QPixmap pixmap1=QPixmap::fromImage(img1.img);
        ui->lbImage1->setPixmap(pixmap1);

    }
    else if(ui->rb2->isChecked())
    {

        sl_immagini[1]=img2.path;

        QPixmap pixmap2=QPixmap::fromImage(img2.img);
        ui->lbImage2->setPixmap(pixmap2);

    }
    else if(ui->rbAll->isChecked()){


        QImage image1(img1.path);
        sl_immagini[0]=img1.path;
        QPixmap pixmap1=QPixmap::fromImage(image1);
        ui->lbImage1->setPixmap(pixmap1);

        QImage image2(img2.path);
        sl_immagini[1]=img2.path;
        QPixmap pixmap2=QPixmap::fromImage(image2);
        ui->lbImage2->setPixmap(pixmap2);

    }


}




void FTagsMov::on_cbClienti_currentIndexChanged(int index)
{
    int row=index;
    int col=0;
    int idc=0;


    idc=modclienti->index(row,col).data(0).toInt();
    getProdotti(idc);
}


void FTagsMov::on_pbSave_clicked()
{
    save();

    QMessageBox::information(nullptr,QApplication::applicationName(),"I dati sono stati salvati",QMessageBox::Ok);


    ui->pbMov->setEnabled(true);

    if(azione==0)
    {
        ui->pbNew->setVisible(true);

    }
}


void FTagsMov::on_pbChooseImage_clicked()
{
    // ui->rb1->setChecked(true);


    chooseImage();


}


void FTagsMov::on_rb1_toggled(bool checked)
{
    ui->lbImage1->setVisible(checked);
    ui->lbImage2->setVisible(!checked);

    ui->lbImage1->setMinimumWidth(400);
    ui->lbImage1->setMinimumHeight(400);
    ui->lbImage1->setMaximumWidth(this->size().width());
    ui->lbImage1->setMaximumHeight(800);

    ui->lbImage2->setMinimumWidth(400);
    ui->lbImage2->setMinimumHeight(400);
    ui->lbImage2->setMaximumWidth(this->size().width());
    ui->lbImage2->setMaximumHeight(800);

    ui->pbChooseImage->setEnabled(checked);


}




void FTagsMov::on_rb2_toggled(bool checked)
{
    ui->lbImage1->setVisible(!checked);
    ui->lbImage2->setVisible(checked);



    ui->lbImage1->setMinimumWidth(400);
    ui->lbImage1->setMinimumHeight(400);
    ui->lbImage1->setMaximumWidth(this->size().width());
    ui->lbImage1->setMaximumHeight(800);

    ui->lbImage2->setMinimumWidth(400);
    ui->lbImage2->setMinimumHeight(400);
    ui->lbImage2->setMaximumWidth(this->size().width());
    ui->lbImage2->setMaximumHeight(800);
    ui->pbChooseImage->setEnabled(checked);
}


void FTagsMov::on_rbAll_toggled(bool checked)
{
    ui->lbImage2->setVisible(checked);
    ui->lbImage1->setVisible(checked);



    ui->lbImage1->setMinimumWidth(400);
    ui->lbImage1->setMinimumHeight(400);
    ui->lbImage1->setMaximumWidth(this->size().width());
    ui->lbImage1->setMaximumHeight(800);

    ui->lbImage2->setMinimumWidth(400);
    ui->lbImage2->setMinimumHeight(400);
    ui->lbImage2->setMaximumWidth(this->size().width());
    ui->lbImage2->setMaximumHeight(800);
    ui->pbChooseImage->setEnabled(!checked);

}


void FTagsMov::on_pbMov_clicked()
{
    FTOperate *f=new FTOperate(db,ui->leBarcode->text());

    f->show();
}



void FTagsMov::on_cbGenericProduct_toggled(bool checked)
{
    ui->cbProdotto->setEnabled(!checked);
}


void FTagsMov::on_pbReset_clicked()
{

    if (QMessageBox::question(nullptr,QApplication::applicationName(),"resettare le immagini?", QMessageBox::Ok|QMessageBox::Cancel)==QMessageBox::Ok)
    {
        img_reset();
    }
}

void FTagsMov::showImage(const QString path)
{

    FTImage *f=new FTImage(path);
    connect(f,SIGNAL(transfer_Barcode(QString)),this,SLOT(setBarcode(QString)));
    f->show();

}

void FTagsMov::resetUI()
{
    ui->teNote->setPlainText(QString());
    ui->leSpecifica->setText(QString());
    ui->leBarcode->setText(QString());
    img_reset();
}

void FTagsMov::setBarcode(const QString pbarcode)
{
    ui->leBarcode->setText(pbarcode);
}

bool FTagsMov::eventFilter(QObject *obj, QEvent *evt)
{


    if(obj==ui->lbImage1 && evt->type()==QEvent::MouseButtonDblClick)
    {

           //qDebug()<<"event label1";
           emit imageClicked(img1.path);


     }
     if  (obj==ui->lbImage2 && evt->type()== QEvent::MouseButtonDblClick)
    {
        //qDebug()<<"event label2";
        emit imageClicked(img2.path);
    }

    return QObject::eventFilter(obj,evt);

}




void FTagsMov::on_pbNew_clicked()
{
    resetUI();
    azione=0;
}

