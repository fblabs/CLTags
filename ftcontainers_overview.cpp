#include "ftcontainers_overview.h"
#include "ftcontainerload.h"
#include "ftcontainer_unload.h"
#include "ui_ftcontainers_overview.h"
#include "ftcontainersoperation_mod.h"
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QModelIndex>
#include <QSqlError>
#include <QDebug>

FtContainers_Overview::FtContainers_Overview(QSqlDatabase pdb,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FtContainers_Overview)
{
    ui->setupUi(this);
    db=pdb;
    getContainers();


}

FtContainers_Overview::~FtContainers_Overview()
{
    delete ui;
}

void FtContainers_Overview::getContainers()
{
    QSqlQuery q(db);
    QSqlQueryModel *mod=new QSqlQueryModel();
    QString sql="SELECT tags_containers.ID, prodotti.ID,prodotti.descrizione, tags_containers.giacenza from tags_containers,prodotti where prodotti.ID=tags_containers.ID_Prodotto and prodotti.tipo IN(3,4,5) order by prodotti.descrizione";
    q.prepare(sql);
    q.exec();
    mod->setQuery(q);
    ui->tvOverview->setModel(mod);
    ui->tvOverview->setColumnHidden(0,true);
    ui->tvOverview->setColumnHidden(1,true);
    ui->tvOverview->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    connect(ui->tvOverview->selectionModel(),SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),this,SLOT(getContainerOperations()));

}

void FtContainers_Overview::getContainerOperations()
{
    int id_container=ui->tvOverview->model()->index(ui->tvOverview->currentIndex().row(),0).data(0).toInt();
    qDebug()<<id_container;

    QSqlQuery q(db);
    QSqlQueryModel *mod_details=new QSqlQueryModel();
    QString sql="select tags_containers_mov.ID,tags_containers_mov.ID_tags_container,tags_containers_mov.data as'DATA', prodotti.descrizione as 'PRODOTTO', anagrafica.ragione_sociale as 'FORNITORE',azioni.descrizione as 'AZIONE',tags_containers_mov.amount as 'QUANTITA',tags_containers_mov.bolla as 'BOLLA',tags_containers_mov.note as 'NOTE'\
            from tags_containers_mov,tags_containers, prodotti, anagrafica,azioni\
            where tags_containers.ID = tags_containers_mov.ID_tags_container\
            and anagrafica.ID=tags_containers_mov.ID_supplier  \
            and azioni.ID=tags_containers_mov.azione \
            and prodotti.ID =tags_containers.ID_Prodotto \
            and tags_containers.ID=:id_container";
            q.prepare(sql);
    q.bindValue(":id_container", id_container);
    q.exec();
    mod_details->setQuery(q);
qDebug()<<q.lastError().text();
    ui->tvDetails->setModel(mod_details);
    ui->tvDetails->setColumnHidden(0,true);
    ui->tvDetails->setColumnHidden(1,true);
    ui->tvDetails->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);



}

void FtContainers_Overview::on_pbClose_clicked()
{
    close();
}


void FtContainers_Overview::on_pbModify_clicked()
{
   modify_tag();
}


void FtContainers_Overview::on_pbLoad_clicked()
{

    int row=ui->tvOverview->selectionModel()->currentIndex().row();
    int pidtag=ui->tvOverview->model()->index(row,0).data(0).toInt();
    FtContainerLoad *f= new FtContainerLoad(pidtag,db);
    f->show();

    connect(f,SIGNAL(save_done()),this,SLOT(update_data()));


}


void FtContainers_Overview::on_pbUnload_clicked()
{
    int row=ui->tvOverview->currentIndex().row();
    int id=ui->tvOverview->model()->index(row,0).data(0).toInt();
    QModelIndex ix=ui->tvOverview->currentIndex();

    FtContainer_unload *f=new FtContainer_unload(id,db);
    connect(f,SIGNAL(save_done()),this,SLOT(update_data()));
    f->show();

    ui->tvOverview->selectionModel()->setCurrentIndex(ix,QItemSelectionModel::Select);
}

void FtContainers_Overview::modify_tag()
{
    QModelIndex prev=ui->tvDetails->selectionModel()->currentIndex();
    int row=ui->tvDetails->selectionModel()->currentIndex().row();
    QModelIndex ix=ui->tvDetails->model()->index(row,0);

    int idop=ix.data(0).toInt();
    QString supplier=ui->tvDetails->model()->index(row,4).data(0).toString();
    FtContainersOperation_mod *f=new FtContainersOperation_mod(idop,supplier,db);

    connect(f,SIGNAL(save_done()),this,SLOT(update_data()));

    f->show();

    ui->tvDetails->setCurrentIndex(prev);
    getContainerOperations();
}

void FtContainers_Overview::update_data()
{
    qDebug()<<"update_data";
    QModelIndex ix=ui->tvOverview->currentIndex();
    getContainers();
    ui->tvOverview->selectionModel()->setCurrentIndex(ix,QItemSelectionModel::Select);
    getContainerOperations();
}

