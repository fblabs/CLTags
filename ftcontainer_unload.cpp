#include "ftcontainer_unload.h"
#include "ui_ftcontainer_unload.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QDate>
#include <QDebug>
#include <QSqlError>

FtContainer_unload::FtContainer_unload(const int pid_tag, QSqlDatabase pdb, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FtContainer_unload)
{
    ui->setupUi(this);
    db=pdb;
    id_tag=pid_tag;
    ui->deData->setDate(QDate::currentDate());
    findGenericSupplier();
    qDebug()<<id_generic_supplier;



   if(id_tag>-1){

       getTags();
   }else{
    //  ui->label->setVisible(false);
    //  ui->cbTags->setVisible(false);
       getTags();
   }

   connect(this,SIGNAL(save_done),this,SLOT(refresh));
}

FtContainer_unload::~FtContainer_unload()
{
    delete ui;
}

void FtContainer_unload::getTags()
{
    QSqlQueryModel *qtags_mod=new QSqlQueryModel();
    QSqlQuery q(db);
    QString sql="SELECT tags_containers.ID,prodotti.ID, prodotti.descrizione from tags_containers,prodotti where prodotti.ID=tags_containers.ID_Prodotto ORDER BY prodotti.descrizione ASC";
    q.prepare(sql);
    q.exec();

    qtags_mod->setQuery(q);



    ui->cbTags->setModel(qtags_mod);
    ui->cbTags->setModelColumn(2);

}

void FtContainer_unload::saveUnload()
{
    QSqlQuery q(db);
    QString sql="INSERT INTO `fbgmdb260`.`tags_containers_mov`(ID_tags_container,ID_supplier,data,azione,amount,note)VALUES(:ID_tags_container,:id_supplier,:data,:azione,:amount,:note)";
    int amount=ui->leAmount->text().toInt();
    q.prepare(sql);
    if(id_tag<0)
    {
       id_tag=ui->cbTags->model()->index(0,ui->cbTags->currentIndex()).data(0).toInt();
    }

    q.bindValue(":ID_tags_container",id_tag);
    q.bindValue(":id_supplier",id_generic_supplier);
    q.bindValue(":data",ui->deData->date());
    q.bindValue(":azione",2);
    q.bindValue(":amount",amount);
    q.bindValue(":note",ui->teNote->toPlainText());

    db.transaction();
    bool b=q.exec();

    if (!b)
    {
        qDebug()<<"ERRORE:"<<q.lastError().text();
        db.rollback();
    }
    db.commit();
    emit save_done();
    close();
}


void FtContainer_unload::on_pbClose_clicked()
{
    close();
}


void FtContainer_unload::on_pbSave_clicked()
{
    saveUnload();
    close();

}

void FtContainer_unload::findGenericSupplier()
{

    QSqlQuery q(db);
    QString sql="SELECT ID from anagrafica where ragione_sociale='NESSUN FORNITORE'";
    q.prepare(sql);
    q.exec();
    q.first();


    qDebug()<<q.lastError().text();

    id_generic_supplier=q.value(0).toInt();

}





