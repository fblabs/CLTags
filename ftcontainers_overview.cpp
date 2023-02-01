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
#include <QMessageBox>
#include "ftupdate_tag.h"

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
    mod=new QSqlQueryModel();
    QString sql="SELECT tags_containers.ID, prodotti.ID,prodotti.descrizione as 'DESCRIZIONE', tags_containers.giacenza as 'GIACENZA',tags_containers.note as 'NOTE' from tags_containers,prodotti where prodotti.ID=tags_containers.ID_Prodotto and prodotti.tipo IN(3,4,5) order by prodotti.descrizione";
    q.prepare(sql);
    q.exec();
    mod->setQuery(q);
    ui->tvOverview->setModel(mod);
    ui->tvOverview->setColumnHidden(0,true);
    ui->tvOverview->setColumnHidden(1,true);
    ui->tvOverview->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

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
    if(QMessageBox::question(this,QApplication::applicationName(),"Chiudere la finestra?",QMessageBox::Ok|QMessageBox::Cancel)==QMessageBox::Ok)
    {
        close();
    }
}


void FtContainers_Overview::on_pbModify_clicked()
{
    modify_tag();
}


void FtContainers_Overview::on_pbLoad_clicked()
{
    int row=ui->tvOverview->currentIndex().row();
    int id=ui->tvOverview->model()->index(row,0).data(0).toInt();
    QString supplier=ui->tvDetails->model()->index(row,4).data(0).toString();
    QModelIndex ix=ui->tvOverview->currentIndex();
    FtContainerLoad *f=new FtContainerLoad(id,db);
    connect(f,SIGNAL(sg_save_load()),this,SLOT(refresh()));

    f->show();

}


void FtContainers_Overview::on_pbUnload_clicked()
{
    int row=ui->tvOverview->currentIndex().row();
    int id=ui->tvOverview->model()->index(row,0).data(0).toInt();
    QModelIndex ix=ui->tvOverview->currentIndex();

    FtContainer_unload *f=new FtContainer_unload(id,db);
    connect(f,SIGNAL(save_done()),this,SLOT(refresh()));
    f->show();
    ui->tvOverview->setCurrentIndex(ix);

}

void FtContainers_Overview::modify_tag()
{
    QModelIndex prev=ui->tvDetails->selectionModel()->currentIndex();
    int row=ui->tvDetails->selectionModel()->currentIndex().row();
    QModelIndex ix=ui->tvDetails->model()->index(row,0);

    int idop=ix.data(0).toInt();
    QString supplier=ui->tvDetails->model()->index(row,4).data(0).toString();


    FtContainersOperation_mod *f=new FtContainersOperation_mod(idop,supplier,db);

    connect(f,SIGNAL(save_done()),this,SLOT(refresh()));

    f->show();

    refresh();

    getContainerOperations();

}


bool FtContainers_Overview::deleteOperation()
{
    int row=ui->tvDetails->selectionModel()->currentIndex().row();
    QModelIndex ix=ui->tvDetails->model()->index(row,0);

    int idop=ix.data(0).toInt();
    QSqlQuery q(db);
    QString sql="DELETE FROM tags_containers_mov WHERE ID=:id";

    q.prepare(sql);
    q.bindValue(":id", idop);

    bool res=q.exec();

    return res;
}


void FtContainers_Overview::on_pbDelete_clicked()
{
    if  (QMessageBox::question(this,QApplication::applicationName(),"Eliminare l'operazione?",QMessageBox::Ok|QMessageBox::Cancel)==QMessageBox::Ok)
    {




        db.transaction();
        if(deleteOperation())
        {
            db.commit();
            QMessageBox::information(this,QApplication::applicationName(),"Operazione eliminata",QMessageBox::Ok);
        }else{
            db.rollback();
            QMessageBox::information(this,QApplication::applicationName(),"Errore eliminando l-operazione",QMessageBox::Ok);
        }

        refresh();

        connect(ui->tvOverview,SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),this,SLOT(getContainerOperations()));




    }

}

void FtContainers_Overview::refresh()
{
    qDebug()<<"REFRESH";

    QModelIndex current=ui->tvOverview->currentIndex();
    QModelIndex row=ui->tvOverview->model()->index(current.row(),0);
    QModelIndex mov=ui->tvDetails->currentIndex();
    ui->tvOverview->reset();
    ui->tvOverview->clearSelection();
    ui->tvOverview->selectionModel()->select(row,QItemSelectionModel::ClearAndSelect);

    QSqlQuery q(db);
  //  QString sql="SELECT tags_containers.ID, prodotti.ID,prodotti.descrizione, tags_containers.giacenza from tags_containers,prodotti where prodotti.ID=tags_containers.ID_Prodotto and prodotti.tipo IN(3,4,5) order by prodotti.descrizione";

    QString sql="SELECT tags_containers.ID, prodotti.ID,prodotti.descrizione as 'DESCRIZIONE', tags_containers.giacenza as 'GIACENZA',tags_containers.note as 'NOTE' from tags_containers,prodotti where prodotti.ID=tags_containers.ID_Prodotto and prodotti.tipo IN(3,4,5) order by prodotti.descrizione";
    q.prepare(sql);
    q.exec();
    mod->setQuery(q);


    ui->tvOverview->setCurrentIndex(current);
    ui->tvOverview->selectionModel()->select(current,QItemSelectionModel::Select);
    ui->tvDetails->setCurrentIndex(mov);



}


void FtContainers_Overview::on_tvDetails_doubleClicked(const QModelIndex &index)
{
    QModelIndex ix=ui->tvOverview->currentIndex();
    modify_tag();

    ui->tvOverview->setCurrentIndex(ix);

    refresh();
}


void FtContainers_Overview::on_tvOverview_doubleClicked(const QModelIndex &index)
{
    int row=ui->tvOverview->currentIndex().row();
    int id=ui->tvOverview->model()->index(row,0).data(0).toInt();

    FtUpdate_Tag *f= new FtUpdate_Tag(id,db);
    connect(f,SIGNAL(container_updated()),this,SLOT(refresh()));
    f->show();
}

