#include "ftoverview.h"
#include "ui_ftoverview.h"

#include "ftagsmov.h"
#include "ftoperate.h"
#include "ftmodmov.h"
#include <QSqlRelation>
#include <QSqlRelationalDelegate>
#include <QCompleter>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QDate>
#include <QSettings>
#include "htagsrelationaltablemodel.h"

#include <QSqlError>
#include <QMessageBox>

#include <QDebug>
#include "ftprint.h"


#include <QStandardItem>


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


    tagsmod=buildModel();

    tagsmod->setHeaderData(1,Qt::Horizontal,"BARCODE");
    tagsmod->setHeaderData(2,Qt::Horizontal,"CLIENTE");
    tagsmod->setHeaderData(3,Qt::Horizontal,"PRODOTTO");
    tagsmod->setHeaderData(4,Qt::Horizontal,"TIPO");
    tagsmod->setHeaderData(5,Qt::Horizontal,"SPECIFICA");
    tagsmod->setHeaderData(6,Qt::Horizontal,"IMMAGINE");
    tagsmod->setHeaderData(7,Qt::Horizontal,"GIACENZA");
    tagsmod->setHeaderData(8,Qt::Horizontal,"NOTE");

    ui->tvTags->setModel(tagsmod);

    ui->tvTags->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
    ui->tvTags->horizontalHeader()->setCascadingSectionResizes(true);
    ui->tvTags->horizontalHeader()->setSectionResizeMode(1,QHeaderView::ResizeToContents);
    ui->tvTags->horizontalHeader()->setSectionResizeMode(2,QHeaderView::Interactive);
    ui->tvTags->horizontalHeader()->setSectionResizeMode(3,QHeaderView::Interactive);
    ui->tvTags->horizontalHeader()->setSectionResizeMode(4,QHeaderView::ResizeToContents);
    ui->tvTags->horizontalHeader()->setSectionResizeMode(5,QHeaderView::ResizeToContents);
    ui->tvTags->horizontalHeader()->setSectionResizeMode(6,QHeaderView::Interactive);
    ui->tvTags->horizontalHeader()->setSectionResizeMode(8,QHeaderView::Interactive);
    ui->tvTags->setColumnHidden(0,true);
    ui->tvTags->setColumnHidden(6,true);
    ui->tvTags->setColumnHidden(9,true);
    ui->tvTags->horizontalHeader()->setStretchLastSection(true);
    ui->cbCliente->completer()->setCompletionMode(QCompleter::PopupCompletion);


    connect(ui->tvTags->selectionModel(),SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),this,SLOT(findTagsMov()));
    clientimod=new QSqlTableModel(nullptr,db);
    clientimod->setTable("anagrafica");
    clientimod->setFilter("cliente>0");
    clientimod->setSort(1,Qt::AscendingOrder);
    clientimod->select();

    ui->cbCliente->setModel(clientimod);
    ui->cbCliente->setModelColumn(1);
    ui->cbCliente->completer()->setCompletionColumn(1);
    ui->cbCliente->completer()->setCompletionMode(QCompleter::PopupCompletion);


    QModelIndex ix=tagsmod->index(0,0);
    ui->tvTags->setCurrentIndex(ix);

    ui->tvTags->selectionModel()->setCurrentIndex(ix,QItemSelectionModel::Select);
    connect(ui->cbCliente->lineEdit(),SIGNAL(returnPressed()),this,SLOT(buildFilter()));

    //  on_pbNoFilters_clicked();




}

void FTOverview::findTagsMov()
{
    current_tag_id=ui->tvTags->model()->index(ui->tvTags->currentIndex().row(),0).data(0).toInt();

    tagsmovmod=new QSqlQueryModel();
    QSqlQuery q(db);
    QString sql=QString();

    sql="SELECT tags_mov.ID,tags_mov.ID_tags,tags_mov.data as DATA, tags.barcode as BARCODE,prodotti.ID as IDProdotto,prodotti.descrizione as PRODOTTO,clienti.ID as IDCliente,clienti.ragione_sociale as CLIENTE,\
            stampatori.ID as IDStampatore,stampatori.ragione_sociale as STAMPATORE,azione as IDAZIONE,azioni.descrizione as AZIONE,tags_mov.amount as QUANT,tags_mov.note\
            FROM tags,tags_mov,anagrafica as stampatori,anagrafica as clienti,azioni,prodotti\
            WHERE tags_mov.ID_tags=tags.ID and stampatori.ID=tags_mov.IDStampatore AND azioni.ID=tags_mov.azione and prodotti.ID=tags.IDProdotto and clienti.ID=tags.IDCliente and tags.ID =:id order by tags_mov.data DESC";
            q.prepare(sql);
    q.bindValue(":id", current_tag_id);
    q.bindValue(":idprodotto", tagsmod->index(ui->tvTags->currentIndex().row(),3).data(0).toString());
    if (!q.exec())
    {
        qDebug()<<q.lastError().text()<<q.lastQuery();
    }
    tagsmovmod->setQuery(q);
    ui->tvTags_mov->setModel(tagsmovmod);
    ui->tvTags_mov->setColumnHidden(0,true);
    ui->tvTags_mov->setColumnHidden(1,true);
    ui->tvTags_mov->setColumnHidden(3,true);
    ui->tvTags_mov->setColumnHidden(4,true);
    ui->tvTags_mov->setColumnHidden(5,true);
    ui->tvTags_mov->setColumnHidden(6,true);
    ui->tvTags_mov->setColumnHidden(8,true);
    ui->tvTags_mov->setColumnHidden(10,true);



    ui->tvTags_mov->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);

    ui->tvTags_mov->horizontalHeader()->setSectionResizeMode(0,QHeaderView::ResizeToContents);
    ui->tvTags_mov->horizontalHeader()->setSectionResizeMode(1,QHeaderView::ResizeToContents);
    ui->tvTags_mov->horizontalHeader()->setSectionResizeMode(2,QHeaderView::ResizeToContents);
    ui->tvTags_mov->horizontalHeader()->setSectionResizeMode(3,QHeaderView::ResizeToContents);
    ui->tvTags_mov->horizontalHeader()->setSectionResizeMode(4,QHeaderView::Interactive);
    ui->tvTags_mov->horizontalHeader()->setSectionResizeMode(5,QHeaderView::ResizeToContents);
    ui->tvTags_mov->horizontalHeader()->setSectionResizeMode(6,QHeaderView::Interactive);
    ui->tvTags_mov->horizontalHeader()->setSectionResizeMode(7,QHeaderView::Interactive);
    ui->tvTags_mov->horizontalHeader()->setSectionResizeMode(8,QHeaderView::Interactive);
    ui->tvTags_mov->horizontalHeader()->setSectionResizeMode(9,QHeaderView::Interactive);
    ui->tvTags_mov->horizontalHeader()->setSectionResizeMode(10,QHeaderView::Interactive);
    ui->tvTags_mov->horizontalHeader()->setStretchLastSection(true);
    ui->tvTags_mov->horizontalHeader()->setCascadingSectionResizes(true);



    ui->tvTags_mov->horizontalHeader()->setStretchLastSection(true);

    ui->cbProdotto->completer()->setCompletionColumn(1);
    ui->cbProdotto->completer()->setCompletionMode(QCompleter::PopupCompletion);

    qDebug()<<"FINDTAGSMOV"<<q.lastError().text()<<q.lastQuery();

}

void FTOverview::refresh()
{

    QModelIndex current=ui->tvTags->currentIndex();
    QModelIndex row=ui->tvTags->model()->index(current.row(),0);
    QModelIndex mov=ui->tvTags_mov->currentIndex();
    ui->tvTags->reset();
    ui->tvTags->clearSelection();
    ui->tvTags->selectionModel()->select(row,QItemSelectionModel::ClearAndSelect);

    tagsmod->select();

    ui->tvTags->setCurrentIndex(row);
    ui->tvTags->selectionModel()->select(current,QItemSelectionModel::Select);
    ui->tvTags_mov->setCurrentIndex(mov);


}

void FTOverview::mod_mov(const QModelIndex index)
{

    QModelIndex ix=ui->tvTags->currentIndex();
    int id=ui->tvTags_mov->model()->index(index.row(),0).data(0).toInt();
    QString title=QString();


    title=ui->tvTags_mov->model()->index(index.row(),6).data(0).toString() + " - " + ui->tvTags_mov->model()->index(index.row(),4).data(0).toString();

    FTModMov *f=new FTModMov(id,db,title);
    //  connect(f,SIGNAL(mod_mov_done()),this,SLOT(refresh()));
    connect(f,SIGNAL(mod_mov_done()),this,SLOT(findTagsMov()));
    f->show();
    ui->tvTags->setCurrentIndex(ix);
}

void FTOverview::mod_tag(const QModelIndex index)
{
    // FTagsMov *f=new FTagsMov(1,tagsmod->index(index.row(),0).data(0).toInt(),tagsmod->index(index.row(),3).data(0).toInt(),db);
    QString prodDesc=ui->tvTags->model()->index(ui->tvTags->currentIndex().row(),3).data(0).toString();

    int idtag=ui->tvTags->model()->index(ui->tvTags->currentIndex().row(),0).data(0).toInt();
    qDebug()<<"IDTAG"<<idtag;

    FTagsMov *f=new FTagsMov(1,idtag,prodDesc,db);
    connect(f,SIGNAL(tag_saved()),this,SLOT(refresh()));
    f->show();
}

bool FTOverview::deleteOperation()
{
    int row=ui->tvTags_mov->currentIndex().row();
    int idop=ui->tvTags_mov->model()->index(row,0).data(0).toInt();
    bool result=0;

    QSqlQuery q(db);
    QString sql="DELETE FROM tags_mov WHERE ID=:id";
    q.prepare(sql);
    q.bindValue(":id",idop);

    result= q.exec();

    qDebug()<<"DELETE"<<q.lastError().text();


    return result;
}

HTagsRelationalTableModel* FTOverview::buildModel()
{
    HTagsRelationalTableModel* local_model=new HTagsRelationalTableModel(nullptr);

    local_model->setTable("tags");
    local_model->setRelation(2,QSqlRelation("anagrafica","ID","ragione_sociale"));  //CLIENTE -relTblAl_2 (anagrafica)
    local_model->setRelation(3,QSqlRelation("prodotti","ID","descrizione")); //prodotto - relTblAl_3 (prodotti)
    local_model->setRelation(4,QSqlRelation("tags_tipi","ID","descrizione")); // tipo - (tags_tipi)
    local_model->select();


    local_model->setHeaderData(1,Qt::Horizontal,"BARCODE");
    local_model->setHeaderData(2,Qt::Horizontal,"CLIENTE");
    local_model->setHeaderData(3,Qt::Horizontal,"PRODOTTO");
    local_model->setHeaderData(4,Qt::Horizontal,"TIPO");
    local_model->setHeaderData(5,Qt::Horizontal,"SPECIFICA");
    local_model->setHeaderData(6,Qt::Horizontal,"IMMAGINE");
    local_model->setHeaderData(7,Qt::Horizontal,"GIACENZA");
    local_model->setHeaderData(8,Qt::Horizontal,"NOTE");


    return  local_model;
}



void FTOverview::on_pbClose_clicked()
{
    close();
}


void FTOverview::on_pbOperate_clicked()
{
    qDebug()<<"current_tag_id"<<current_tag_id;
    FTOperate *f=new FTOperate(1,current_tag_id,db);
    connect(f,SIGNAL(operation_saved()),this,SLOT(refresh()));

    f->show();
}


void FTOverview::on_pbDefinizioni_clicked()
{
    FTagsMov *f=new FTagsMov(0,-1,QString(),db);
    connect(f,SIGNAL(tag_saved()),this,SLOT(refresh()));
    f->show();
}


void FTOverview::on_tvTags_doubleClicked(const QModelIndex &index)
{
    mod_tag(ui->tvTags->currentIndex());
}

void FTOverview::on_pbModTag_clicked()
{
    mod_tag(ui->tvTags->currentIndex());
}


void FTOverview::on_tvTags_mov_doubleClicked(const QModelIndex &index)
{
    /*  int id=ui->tvTags_mov->model()->index(index.row(),0).data(0).toInt();
    QString title=QString();
    title=ui->tvTags_mov->model()->index(index.row(),2).data(0).toString() + " - " + ui->tvTags_mov->model()->index(index.row(),3).data(0).toString();

    FTModMov *f=new FTModMov(id,db,title);
    connect(f,SIGNAL(mod_mov_done()),this,SLOT(refresh()));
    f->show();*/


    mod_mov(index);

}


void FTOverview::on_pbPrint_clicked()
{
    QAbstractItemModel *modToPrint =static_cast<QAbstractItemModel*> (tagsmod);
    QStringList coltitles;
    coltitles<<"BARCODE"<<"CLIENTE"<<"PRODOTTO"<<"TIPO"<<"SPECIFICA"<<"IMMAGINE"<<"GIACENZA"<<"NOTE";
    QList<int> hiddencols;
    hiddencols<<5;

    QString title=QString();

    if (ui->rbLabels->isChecked())
    {
        title=QDate::currentDate().toString().toUpper() + " - ETICHETTE";
    }
    else if (ui->rbSigilli->isChecked())
    {
        title=QDate::currentDate().toString().toUpper() + " - SIGILLI";
    }
    else if (ui->rbBarcode->isChecked())
    {
        title=QDate::currentDate().toString().toUpper() + " - ETICHETTE E SIGILLI";
    }

    FTPrint *f=new FTPrint(modToPrint,title,coltitles,hiddencols);
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
    tagsmod=buildModel();
    ui->tvTags->setModel(buildModel());
    tagsmod->setFilter("");
    ui->leBarcode->setText("");

}



void FTOverview::on_cbCliente_currentIndexChanged(int index)
{

    if(ui->rbCust->isChecked())
    {
        int cx=ui->cbCliente->model()->index(index,0).data(0).toInt();
        getProdotti(cx);

        tagsmod->setFilter(buildFilter());
    }


}


QString FTOverview::buildFilter()
{
    //CLIENTE -relTblAl_2 (anagrafica)
    //prodotto - relTblAl_3 (prodotti)
    // tipo - (tags_tipi)
    QModelIndex curix=ui->tvTags->currentIndex();

    current_tag_id=ui->tvTags->model()->index(curix.row(),0).data(0).toInt();
    QString filter="";

    QString ftipo,flabels,fsigilli,fprodotto,fcliente,fstato,fbarcode=QString();

    QString AND=" AND ";

    int cust,prod =-1;




    //TIPO

    if(ui->rbLabels->isChecked())
    {
        ftipo="relTblAl_4.ID=1";
    }

    if (ui->rbSigilli->isChecked())
    {
        ftipo="relTblAl_4.ID=2";
    }

    //CLIENTE




    if(ui->rbCust->isChecked())
    {

        cust=ui->cbCliente->model()->index(ui->cbCliente->currentIndex(),0).data(0).toInt();
        fcliente="relTblAl_2.ID="+QString::number(cust);



    }

    //PRODOTTO


    if(ui->rbAnyProd->isChecked())
    {

        int prod=ui->cbProdotto->model()->index(ui->cbProdotto->currentIndex(),0).data(0).toInt();
        fprodotto="relTblAl_3.ID="+QString::number(prod);

    }

    //BARCODE

    if(ui->rbBarcode->isChecked())
    {
        fbarcode="barcode like '"+ui->leBarcode->text()+"%'";
    }

    //STATO

    if(ui->cbAttivi->isChecked()){

        fstato="stato>0";
    }
    else
    {
        fstato ="stato<1";
    }

    if(ftipo.length()>0){ftipo+=AND;}
    if(fcliente.length()>0){fcliente+=AND;}
    if(fprodotto.length()>0){fprodotto=fprodotto+AND;}
    if(fbarcode.length()>0){fbarcode +=AND;}


    filter=filter+ftipo+fcliente+fprodotto+fbarcode+fstato;


    qDebug()<<"BUILDFILTER"<<filter;

    qDebug()<<tagsmod->query().lastQuery()<<tagsmod->lastError().text();


    return filter;


}


void FTOverview::on_pbFilter_clicked()
{
    tagsmod->setFilter(buildFilter());
}


void FTOverview::on_leBarcode_returnPressed()
{
    ui->rbBarcode->setChecked(true);
    tagsmod->setFilter(buildFilter());
}


void FTOverview::on_cbAttivi_toggled(bool checked)
{
    tagsmod->setFilter(buildFilter());
}


void FTOverview::on_pb_Scarico_clicked()
{

    FTOperate *f=new FTOperate(2,current_tag_id,db);
    connect(f,SIGNAL(operation_saved()),this,SLOT(refresh()));

    f->show();
}




void FTOverview::on_rbLabels_toggled(bool checked)
{
    if (checked){tagsmod->setFilter(buildFilter());}
}


void FTOverview::on_rbCust_toggled(bool checked)
{
    if (checked) {tagsmod->setFilter(buildFilter());}
}


void FTOverview::on_rbAnyProd_toggled(bool checked)
{
    if (checked){tagsmod->setFilter(buildFilter());}
}


void FTOverview::on_rbNoCust_toggled(bool checked)
{
    if (checked){tagsmod->setFilter(buildFilter());}
}


void FTOverview::on_rbSigilli_toggled(bool checked)
{
    if (checked){tagsmod->setFilter(buildFilter());}
}



void FTOverview::on_rbNoProd_toggled(bool checked)
{
    if (checked){tagsmod->setFilter(buildFilter());}
}


void FTOverview::on_cbProdotto_currentIndexChanged(int index)
{
    if(ui->rbAnyProd->isChecked()){
        tagsmod->setFilter(buildFilter());
    }
}


void FTOverview::on_pbDEleteOperation_clicked()
{
    bool b;

    if(QMessageBox::question(this,QApplication::applicationName(),"Confermare eliminazione operazione?",QMessageBox::Ok|QMessageBox::Cancel)==QMessageBox::Ok)
    {
        db.transaction();
        b=deleteOperation();
        if(b){
            db.commit();
            refresh();
            QMessageBox::information(this,QApplication::applicationName(),"Operazione eliminata",QMessageBox::Ok);

            refresh();

        }else{

            db.rollback();
            QMessageBox::information(this,QApplication::applicationName(),"Errore eliminando l'operazione",QMessageBox::Ok);
        }


    }else{

        QMessageBox::information(this,QApplication::applicationName(),"Eliminazione operazione cancellata",QMessageBox::Ok);
    }





}


void FTOverview::on_pbModifyOperation_clicked()
{
    mod_mov(ui->tvTags_mov->currentIndex());
}

