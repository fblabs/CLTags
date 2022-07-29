#include "ftoperate.h"
#include "ui_ftoperate.h"
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QCompleter>
#include <QDebug>

FTOperate::FTOperate(QSqlDatabase pdb, QString pbarcode, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FTOperate)
{
    ui->setupUi(this);
    db=pdb;
    barcode=pbarcode;
    setup();

}

void FTOperate::setup()
{

    ui->deDate->setDate(QDate::currentDate());
    ui->leBarcode->setText(barcode);

    modbarcodes=new QSqlQueryModel();
    QString sql="SELECT barcode from tags order by barcode";
    QSqlQuery q(db);
    q.exec();
    modbarcodes->setQuery(sql);

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

    emit ui->leBarcode->returnPressed();





}

void FTOperate::saveOp()
{
    QSqlQuery q(db);
    QString sql="INSERT INTO `fbgmdb260`.`tags_mov`(`data`,`barcode`,`IDStampatore`,`azione`,`amount`,`note`) VALUES(:data,:barcode,:IDStampatore,:azione,:amount,:note)";
    q.prepare(sql);
    q.bindValue(":data",ui->deDate->date());
    q.bindValue(":barcode",ui->leBarcode->text());
    q.bindValue(":IDStampatore",ui->cbStampatore->model()->index(ui->cbStampatore->currentIndex(),0).data().toInt());
    int azione=0;
    ui->rbCarico->isChecked() ? azione=1:azione=2;
    q.bindValue(":azione",azione);
    q.bindValue(":amount",ui->leAmount->text().toInt());
    q.bindValue(":note",ui->teNote->toPlainText());

   // qDebug()<<azione;

    db.transaction();

    if(q.exec())
    {
     //   qDebug()<<"OK";
        db.commit();
        emit operation_saved();


    }
    else
    {

     //   qDebug()<<"ERORRE"<<q.lastError().text();

        db.rollback();

    }
}


FTOperate::~FTOperate()
{
    delete ui;
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


void FTOperate::on_leBarcode_returnPressed()
{
  // qDebug()<<"SLOT";
   QString sql=QString();
   QString title=QString();
   QSqlQuery q(db);

    sql="SELECT tags.IDCLIente,tags.IDProdotto,prodotti.descrizione,clienti.ragione_sociale AS CLIENTE,IDTipo,tags_tipi.descrizione, specifica\
            FROM tags, anagrafica as clienti, prodotti,tags_tipi\
            WHERE clienti.ID=tags.IDCliente AND prodotti.ID=tags.IDProdotto AND tags_tipi.ID=tags.IDTipo AND tags.barcode=:barcode";
    q.prepare(sql);
    q.bindValue(":barcode",barcode);
    qDebug()<<q.lastError().text();
    if (q.exec())
    {
        q.next();
        int ixt=ui->cbTipo->findText(q.value(5).toString());
        ui->cbTipo->setCurrentIndex(ixt);
        title=q.value(2).toString()+ " - " + q.value(3).toString();

        ui->lbTitle->setText(title);

    }

}


void FTOperate::on_rbCarico_toggled(bool checked)
{
  //  ui->cbStampatore->setVisible(checked);
    int six=ui->cbStampatore->findText("NESSUNO STAMPATORE");
    ui->cbStampatore->setCurrentIndex(six);

}




