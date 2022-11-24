#include "ftcontainerload.h"
#include "ui_ftcontainerload.h"
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlError>

FtContainerLoad::FtContainerLoad(const int pidtag,QSqlDatabase pdb, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FtContainerLoad)
{
    ui->setupUi(this);

    db=pdb;
    id_tag=pidtag;
    ui->deDate->setDate(QDate::currentDate());
    getTags();
    getSuppliers();
    inserted_tag_id=-1;
}

FtContainerLoad::~FtContainerLoad()
{
    delete ui;
}

void FtContainerLoad::on_pbClose_clicked()
{
    close();
}



void FtContainerLoad::getSuppliers()
{
    QSqlTableModel *suppliers_mod=new QSqlTableModel(nullptr,db);

    suppliers_mod->setTable("anagrafica");
    suppliers_mod->setFilter("fornitore > 0");
    suppliers_mod->setSort(1,Qt::AscendingOrder);
    suppliers_mod->select();

    ui->cbSupplier->setModel(suppliers_mod);
    ui->cbSupplier->setModelColumn(1);




}

void FtContainerLoad::getTags()
{
    QSqlQueryModel *qtags_mod=new QSqlQueryModel();
    QSqlQuery q(db);
    QString sql;

    if (id_tag==-1){
        sql="SELECT tags_containers.ID,prodotti.ID, prodotti.descrizione from tags_containers,prodotti where prodotti.ID=tags_containers.ID_Prodotto ORDER BY prodotti.descrizione ASC";
        q.prepare(sql);
    }
    if(id_tag>-1)
    {
        sql="SELECT tags_containers.ID,prodotti.ID, prodotti.descrizione from tags_containers,prodotti where prodotti.ID=tags_containers.ID_Prodotto and tags_containers.ID=:id ORDER BY prodotti.descrizione ASC";
        q.prepare(sql);
        q.bindValue(":id",id_tag);
    }


    q.exec();

    qtags_mod->setQuery(q);

    qDebug()<<q.lastError().text();



    ui->cbTags->setModel(qtags_mod);
    ui->cbTags->setModelColumn(2);




}



bool FtContainerLoad::save_tag()
{
    QSqlQuery q(db);
    QString sql=QString();
    bool b=false;

    //inizializzo un nuov tag_container se non esiste

    //  b=init_tag();


    int id_tag=ui->cbTags->model()->index(ui->cbTags->currentIndex(),0).data(0).toInt();
    int id_supplier=ui->cbSupplier->model()->index(ui->cbSupplier->currentIndex(),0).data(0).toInt();
    int amount=ui->leAmount->text().toInt();
    QString s_note=ui->teNote->toPlainText();
    QString s_bolla=ui->leBolla->text();

    sql="INSERT INTO tags_containers_mov(ID_tags_container,ID_supplier,bolla,azione,amount,note)VALUES(:ID_tags_containers,:ID_supplier,:bolla,:azione,:amount,:note)";

    q.prepare(sql);
    q.bindValue(":ID_tags_containers",id_tag);
    q.bindValue(":ID_supplier",id_supplier);
    q.bindValue(":bolla",s_bolla);
    q.bindValue(":azione",1);
    q.bindValue(":amount",amount);
    q.bindValue(":note",s_note);

    db.transaction();

    b= q.exec();

    if(!b)
    {
        db.rollback();
        qDebug()<<"ERRORE IN SAVE:"<<inserted_tag_id<<q.lastQuery()<<q.lastError().text()<<id_tag;
    }

    db.commit();
    emit save_done();

    return b;

}



void FtContainerLoad::on_pbSave_clicked()
{
    db.transaction();
    bool b=save_tag();


    if (b){

        db.commit();
        emit save_done();

    }else{

        db.rollback();
    }
    close();

}




