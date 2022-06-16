#include "ftoverview.h"
#include "ui_ftoverview.h"

#include "ftagsmov.h"
#include "ftoperate.h"
#include "ftmodmov.h"
#include <QSqlRelation>
#include <QCompleter>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSettings>

#include <QSqlError>

//#include <QDebug>
#include "ftprint.h"


FTOverview::FTOverview(QSqlDatabase pdb, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FTOverview)
{
    ui->setupUi(this);
    db=pdb;
    setup();
}

FTOverview::~FTOverview()
{
    delete ui;
}

void FTOverview::setup()
{
    tagsmod=new QSqlRelationalTableModel(nullptr);
    tagsmod->setTable("tags");
    tagsmod->setRelation(1,QSqlRelation("anagrafica","ID","ragione_sociale"));
    tagsmod->setRelation(2,QSqlRelation("prodotti","ID","descrizione"));
    tagsmod->setRelation(3,QSqlRelation("tags_tipi","ID","descrizione"));
    tagsmod->select();
  //  qDebug()<<tagsmod->query().lastQuery();

    tagsmod->setHeaderData(0,Qt::Horizontal,"BARCODE");
    tagsmod->setHeaderData(1,Qt::Horizontal,"CLIENTE");
    tagsmod->setHeaderData(2,Qt::Horizontal,"PRODOTTO");
    tagsmod->setHeaderData(3,Qt::Horizontal,"TIPO");
    tagsmod->setHeaderData(4,Qt::Horizontal,"SPECIFICA");
    tagsmod->setHeaderData(5,Qt::Horizontal,"IMMAGINE");
    tagsmod->setHeaderData(6,Qt::Horizontal,"GIACENZA");
    tagsmod->setHeaderData(7,Qt::Horizontal,"NOTE");

    ui->tvTags->setModel(tagsmod);

    ui->tvTags->horizontalHeader()->sectionResizeMode(QHeaderView::ResizeToContents);
    ui->tvTags->horizontalHeader()->setSectionResizeMode(0,QHeaderView::ResizeToContents);
    ui->tvTags->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
    ui->tvTags->horizontalHeader()->setSectionResizeMode(2,QHeaderView::Stretch);
    ui->tvTags->horizontalHeader()->setSectionResizeMode(3,QHeaderView::ResizeToContents);
    ui->tvTags->horizontalHeader()->setSectionResizeMode(4,QHeaderView::ResizeToContents);
    ui->tvTags->horizontalHeader()->setSectionResizeMode(6,QHeaderView::ResizeToContents);
    ui->tvTags->setColumnHidden(5,true);

    connect(ui->tvTags->selectionModel(),SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),this,SLOT(findTagsMov()));
    clientimod=new QSqlTableModel(nullptr,db);
    clientimod->setTable("anagrafica");
    clientimod->setFilter("cliente>0");
    clientimod->setSort(1,Qt::AscendingOrder);
    clientimod->select();

    clcomp=new QCompleter(clientimod);
    clcomp->setCompletionColumn(1);
    clcomp->setCaseSensitivity(Qt::CaseInsensitive);
    clcomp->setCompletionMode(QCompleter::PopupCompletion);

    ui->cbCliente->setModel(clientimod);
    ui->cbCliente->setModelColumn(1);


    QModelIndex ix=tagsmod->index(0,0);
    ui->tvTags->setCurrentIndex(ix);

    ui->tvTags->selectionModel()->setCurrentIndex(ix,QItemSelectionModel::Select);

     on_pbNoFilters_clicked();






}

void FTOverview::findTagsMov()
{
    tagsmovmod=new QSqlQueryModel();
    QSqlQuery q(db);
    QString sql=QString();

    sql="SELECT tags_mov.ID,tags_mov.data as DATA, tags.barcode as BARCODE,prodotti.ID as IDProdotto,prodotti.descrizione as PRODOTTO,clienti.ID as IDCliente,clienti.ragione_sociale as CLIENTE\
            ,stampatori.ID as IDStampatore,stampatori.ragione_sociale as STAMPATORE,azione as IDAZIONE,azioni.descrizione as AZIONE,tags_mov.amount as QUANT,tags_mov.note\
            FROM tags,tags_mov,anagrafica as stampatori,anagrafica as clienti,azioni,prodotti\
            WHERE tags_mov.barcode=tags.barcode and stampatori.ID=tags_mov.IDStampatore AND azioni.ID=tags_mov.azione and prodotti.ID=tags.IDProdotto and clienti.ID=tags.IDCliente and tags.barcode =:barcode";
            q.prepare(sql);
    q.bindValue(":barcode", tagsmod->index(ui->tvTags->currentIndex().row(),0).data(0).toString());
    q.bindValue(":idprodotto", tagsmod->index(ui->tvTags->currentIndex().row(),3).data(0).toString());
    if (!q.exec())
    {
      //  qDebug()<<q.lastError().text()<<q.lastQuery();
    }
    tagsmovmod->setQuery(q);
    ui->tvTags_mov->setModel(tagsmovmod);
    ui->tvTags_mov->setColumnHidden(0,true);
    ui->tvTags_mov->setColumnHidden(3,true);
    ui->tvTags_mov->setColumnHidden(5,true);
    ui->tvTags_mov->setColumnHidden(7,true);
    ui->tvTags_mov->setColumnHidden(9,true);

    ui->tvTags_mov->horizontalHeader()->setSectionResizeMode(4,QHeaderView::Stretch);
    ui->tvTags_mov->horizontalHeader()->setSectionResizeMode(6,QHeaderView::Stretch);
    ui->tvTags_mov->horizontalHeader()->setSectionResizeMode(8,QHeaderView::Stretch);

   // qDebug()<<q.lastQuery();

}

void FTOverview::refresh()
{
   // qDebug()<<"REFRESH";
    QModelIndex current=ui->tvTags->currentIndex();
    tagsmod->select();
    ui->tvTags->setCurrentIndex(current);


    // tagsmovmod->query().exec();
}



void FTOverview::on_pbClose_clicked()
{
    close();
}


void FTOverview::on_pbOperate_clicked()
{

    FTOperate *f=new FTOperate(db,ui->tvTags->model()->index(ui->tvTags->currentIndex().row(),0).data(0).toString());
    connect(f,SIGNAL(operation_saved()),this,SLOT(refresh()));

    f->show();
}


void FTOverview::on_pbDefinizioni_clicked()
{
    FTagsMov *f=new FTagsMov(0,QString(),QString(),db);
    connect(f,SIGNAL(tag_saved()),this,SLOT(refresh()));
    f->show();
}


void FTOverview::on_tvTags_doubleClicked(const QModelIndex &index)
{
    FTagsMov *f=new FTagsMov(1,tagsmod->index(index.row(),0).data(0).toString(),tagsmod->index(index.row(),2).data(0).toString(),db);

  //  qDebug()<<tagsmod->index(index.row(),5).data(0).toString()<<tagsmod->index(index.row(),2).data(0).toString();
    connect(f,SIGNAL(tag_saved()),this,SLOT(refresh()));
    f->show();

}


void FTOverview::on_pbModTag_clicked()
{
    int row=ui->tvTags->currentIndex().row();
    FTagsMov *f=new FTagsMov(1,tagsmod->index(row,0).data(0).toString(),tagsmod->index(row,2).data(0).toString(),db);


    connect(f,SIGNAL(tag_saved()),this,SLOT(refresh()));
    f->show();
}




void FTOverview::on_tvTags_mov_doubleClicked(const QModelIndex &index)
{
    int id=ui->tvTags_mov->model()->index(index.row(),0).data(0).toInt();

    FTModMov *f=new FTModMov(id,db);
    connect(f,SIGNAL(mod_mov_done()),this,SLOT(refresh()));
    f->show();

}


void FTOverview::on_pbPrint_clicked()
{
    QAbstractItemModel *modToPrint =static_cast<QAbstractItemModel*> (tagsmod);
    QStringList coltitles;
    coltitles<<"BARCODE"<<"CLIENTE"<<"PRODOTTO"<<"TIPO"<<"SPECIFICA"<<"IMMAGINE"<<"GIACENZA"<<"NOTE";
    QList<int> hiddencols;
    hiddencols<<5;
    FTPrint *f=new FTPrint(modToPrint,"ETICHETTE",coltitles,hiddencols);
    f->show();
}


void FTOverview::on_pushButton_clicked()
{
    int id=ui->tvTags_mov->model()->index(ui->tvTags_mov->currentIndex().row(),0).data(0).toInt();

    FTModMov *f=new FTModMov(id,db);
    connect(f,SIGNAL(mod_mov_done()),this,SLOT(refresh()));
    f->show();
}

void FTOverview::getProdotti(int client_id)
{
    QString sql;
    QSqlQuery q(db);

    QSettings settings("ctags.ini",QSettings::IniFormat);

    GENERIC_CUSTOMER=settings.value("generic_customer_id").toInt();
    GENERIC_PRODUCT=settings.value("generic_product_id").toInt();

    if (client_id==GENERIC_CUSTOMER)
    {
        sql="select prodotti.ID,prodotti.descrizione from prodotti where tipo=2 order by descrizione ASC";
        q.prepare(sql);
        q.exec();

    }
    else
    {
        sql="select prodotti.ID,prodotti.descrizione,associazioni.visualizza from prodotti, ricette, associazioni where ricette.ID=associazioni.ID_ricetta and prodotti.ID=ricette.ID_prodotto and associazioni.visualizza>0 and associazioni.ID_cliente=:idcliente order by prodotti.descrizione asc";


        q.prepare(sql);
        q.bindValue(":idcliente",client_id);
        q.exec();

    }



    prodottimod=new QSqlQueryModel();
    prodottimod->setQuery(q);

    ui->cbProdotto->setModel(prodottimod);
    ui->cbProdotto->setModelColumn(1);

    prcomp=new QCompleter(prodottimod);
    prcomp->setCompletionColumn(1);
    prcomp->setCaseSensitivity(Qt::CaseInsensitive);
    prcomp->setCompletionMode(QCompleter::PopupCompletion);

    //  int ixp=ui->cbProdotto->findText(descprod);
    //  ui->cbProdotto->setCurrentIndex(ixp);
}

void FTOverview::on_pbNoFilters_clicked()
{
 tagsmod->setFilter(QString());
 ui->leBarcode->setText(QString());
}



void FTOverview::on_cbCliente_currentIndexChanged(int index)
{
    int cx=ui->cbCliente->model()->index(index,0).data(0).toInt();
    getProdotti(cx);


}


void FTOverview::buildFilter()
{
    QString filter=QString();


    QString stipo;
    ui->rbLabels->isChecked() ?  stipo= "and relTblAl_3.ID=1": stipo="and relTblAl_3.ID=2";




    if(ui->rbLabels->isChecked())
    {
       ui->cbProdotto->setEnabled(true);
        filter="relTblAl_3.ID=1";

    }else{
        ui->cbProdotto->setEnabled(false);
        filter ="relTblAl_3.ID=2";
    }

    if(ui->rbCust->isChecked())
    {

          ui->rbLabels->isChecked()? filter="relTblAl_1.ragione_sociale='"+ui->cbCliente->currentText()+"' and relTblAl_3.ID=1": filter="relTblAl_1.ragione_sociale='"+ui->cbCliente->currentText()+"' and relTblAl_3.ID=2";

    }






    if(ui->rbAnyProd->isChecked())
    {


        if(ui->rbCust->isChecked())
        {


           ui->rbLabels->isChecked() ?  stipo= "and relTblAl_3.ID=1": stipo="and relTblAl_3.ID=2";
           filter="relTblAl_1.ragione_sociale='"+ui->cbCliente->currentText()+"' and relTblAl_2.descrizione='"+ ui->cbProdotto->currentText() +"' "+stipo;

          }




        }


    if(ui->rbBarcode->isChecked())
    {
        filter="barcode like '"+ui->leBarcode->text()+"%'";
    }






  //  qDebug()<<"BUILD FILTER: "<<filter<<filter<<tagsmod->filter()<<tagsmod->lastError().text();
    tagsmod->setFilter(filter);

    if(tagsmod->rowCount()<1)
    {
        ui->tvTags_mov->setModel(nullptr);
    }


}


void FTOverview::on_pbFilter_clicked()
{
   buildFilter();
}







