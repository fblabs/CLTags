#include "ftcontainersoperation_mod.h"
#include "ui_ftcontainersoperation_mod.h"

#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlError>
#include <QDebug>


FtContainersOperation_mod::FtContainersOperation_mod(const int pidop,const QString p_supplier,QSqlDatabase pdb, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FtContainersOperation_mod)
{
    ui->setupUi(this);
     qDebug()<<"INIT";
    db=pdb;
    idop=pidop;
    supplier=p_supplier;

    getSuppliers();
    getDetails();





}

FtContainersOperation_mod::~FtContainersOperation_mod()
{
    delete ui;
}

void FtContainersOperation_mod::on_pbSave_clicked()
{
    updateOp();
}

void FtContainersOperation_mod::getDetails()
{

    QSqlTableModel *tmod=new QSqlTableModel(nullptr,db);
    tmod->setTable("tags_containers_mov");
    tmod->setFilter("ID="+QString::number(idop));
    tmod->select();

    qDebug()<<tmod->lastError().text()<<tmod->rowCount()<<tmod->filter();


    //---ORA RIEMPIO I CAMPI

    // QString bolla=q.value(2).toString();
    QString bolla=tmod->index(0,3).data(0).toString();
    ui->leBolla->setText(bolla);

    // QDate date=q.value(3).toDate();
    QDate date=tmod->index(0,4).data(0).toDate();
    ui->deData->setDate(date);

    // int azione=q.value(4).toInt();
    int azione=tmod->index(0,5).data(0).toInt();

    if (azione==1)
    {
        ui->rbCarico->setChecked(true);
    }
    if (azione==2)
    {
        ui->rbScarico->setChecked(true);
    }


    //  int amount=q.value(5).toInt();
    int amount=tmod->index(0,6).data(0).toInt();
    ui->leAmount->setText(QString::number(amount));

    // QString note=q.value(6).toString();
    QString note=tmod->index(0,7).data(0).toString();
    ui->teNote->setPlainText(note);

    int cix=ui->cbSupplier->findText(supplier);
    ui->cbSupplier->setCurrentIndex(cix);


}

void FtContainersOperation_mod::updateOp()
{
    QString bolla=ui->leBolla->text();
    QDate data=ui->deData->date();
    int azione=0;
    int idsup=ui->cbSupplier->model()->index(ui->cbSupplier->currentIndex(),0).data(0).toInt();
    if(ui->rbCarico->isChecked()){azione=1;}
    if(ui->rbScarico->isChecked()){azione=2;}
    int amount=ui->leAmount->text().toInt();
    QString note=ui->teNote->toPlainText();

    QSqlQuery q(db);
    QString sql="UPDATE fbgmdb260.tags_containers_mov SET ID_supplier = :ID_supplier,bolla = :bolla,data = :data ,`azione` = :azione, amount = :amount,note = :note WHERE ID = :idop";
    q.prepare(sql);

    q.bindValue(":ID_supplier",idsup);
    q.bindValue(":bolla",bolla);
    q.bindValue(":data", data);
    q.bindValue(":azione",azione);
    q.bindValue(":amount",amount);
    q.bindValue(":note",note);
    q.bindValue(":idop",idop);

    db.transaction();
    bool b=q.exec();

    if(!b)
    {
        qDebug()<<"SAVE"<<q.lastError().text();
        db.rollback();
    }

    db.commit();
    emit save_done();
    close();
}

void FtContainersOperation_mod::getSuppliers()
{
    QSqlTableModel *suppliers_mod=new QSqlTableModel(nullptr,db);

    suppliers_mod->setTable("anagrafica");
    suppliers_mod->setFilter("fornitore > 0");
    suppliers_mod->setSort(1,Qt::AscendingOrder);
    suppliers_mod->select();

    ui->cbSupplier->setModel(suppliers_mod);
    ui->cbSupplier->setModelColumn(1);


}


void FtContainersOperation_mod::on_pbClose_clicked()
{
    close();
}

