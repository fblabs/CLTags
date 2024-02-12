#include "ftaddcontainer.h"
#include "ui_ftaddcontainer.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>

FtAddContainer::FtAddContainer(QSqlDatabase pdb, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FtAddContainer)
{
    ui->setupUi(this);
    db=pdb;
    get_products_to_add();
}

FtAddContainer::~FtAddContainer()
{
    delete ui;
}

void FtAddContainer::get_products_to_add(const int type)
{
    QSqlQueryModel *mod=new QSqlQueryModel();
    QSqlQuery q(db);
    QString sql=QString();

    if(type < 1)
    {
        sql="SELECT ID,descrizione FROM prodotti where tipo in (3,4,5) and ID not in (select ID_prodotto from tags_containers) order by descrizione ASC";
    }
   else {
        //TODO
    }

    q.prepare(sql);
    q.exec();
    mod->setQuery(q);

    ui->tvContainers->setModel(mod);
    ui->tvContainers->setColumnHidden(0,true);
}

void FtAddContainer::add_containers()
{
    //TODO
    QModelIndexList selection=ui->tvContainers->selectionModel()->selectedIndexes();
    for (int i=0;i<selection.count();++i)
    {

    }
}

void FtAddContainer::on_pbClose_clicked()
{
    if(QMessageBox::question(this,QApplication::applicationName(),"Chiudere?",QMessageBox::Ok|QMessageBox::Cancel)==QMessageBox::Ok)
    {
        close();
    }
}

