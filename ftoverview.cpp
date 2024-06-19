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
//#include "ftprint.h"
#include <QTextDocument>
#include <QFileDialog>
#include <QDesktopServices>
#include <QPrinter>
#include <QStandardItem>
#include <QShortcut>


FTOverview::FTOverview(QSqlDatabase pdb, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FTOverview)
{
    ui->setupUi(this);
    db=pdb;

    ui->cbAttivi->setChecked(true);
    setup();
}

FTOverview::~FTOverview()
{
    delete ui;
}

void FTOverview::setup()
{

    QShortcut *det=new QShortcut(QKeySequence(Qt::Key_Right),this);
    connect(det,SIGNAL(activated()),this,SLOT(show_movements()));
    QShortcut *ms=new QShortcut(QKeySequence(Qt::Key_Left),this);
    connect(ms,SIGNAL(activated()),this,SLOT(hide_movements()));

    ui->pbFilter->setVisible(false);
    ui->pbNoFilters->setVisible(false);

    ui->deDal->setDate(QDate::currentDate().addYears(-1));
    ui->deAl->setDate(QDate::currentDate());

    tagsmod=buildModel();
    ui->tvTags->setModel(tagsmod);
    QPalette p = ui->tvTags->palette();
    p.setBrush(p.Inactive, p.Highlight, p.brush(p.Highlight));
    ui->tvTags->setPalette(p);
    /* QPalette m = ui->tvTags_mov->palette();
    m.setBrush(m.Inactive, m.Highlight, m.brush(m.Highlight));*/
    ui->tvTags_mov->setPalette(p);


    ui->tvTags->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
    ui->tvTags->horizontalHeader()->setCascadingSectionResizes(true);
    ui->tvTags->horizontalHeader()->setSectionResizeMode(1,QHeaderView::ResizeToContents);
    ui->tvTags->horizontalHeader()->setSectionResizeMode(2,QHeaderView::Interactive);
    ui->tvTags->horizontalHeader()->setSectionResizeMode(3,QHeaderView::ResizeToContents);
    ui->tvTags->horizontalHeader()->setSectionResizeMode(4,QHeaderView::ResizeToContents);
    ui->tvTags->horizontalHeader()->setSectionResizeMode(5,QHeaderView::ResizeToContents);
    ui->tvTags->horizontalHeader()->setSectionResizeMode(6,QHeaderView::Interactive);
    ui->tvTags->horizontalHeader()->setSectionResizeMode(8,QHeaderView::Interactive);
    ui->tvTags->setColumnHidden(0,true);
    ui->tvTags->setColumnHidden(6,true);
    ui->tvTags->setColumnHidden(9,true);
    ui->tvTags->setColumnHidden(11,true);
    ui->tvTags->horizontalHeader()->setStretchLastSection(true);
    ui->cbCliente->completer()->setCompletionMode(QCompleter::PopupCompletion);



    clientimod=new QSqlTableModel(nullptr,db);
    clientimod->setTable("anagrafica");
    clientimod->setFilter("cliente>0");
    clientimod->setSort(1,Qt::AscendingOrder);
    clientimod->select();

    ui->cbCliente->setModel(clientimod);
    ui->cbCliente->setModelColumn(1);
    ui->cbCliente->completer()->setCompletionColumn(1);
    ui->cbCliente->completer()->setCompletionMode(QCompleter::PopupCompletion);
    connect(ui->cbCliente,SIGNAL(currentIndexChanged(int)),this,SLOT(buildFilter()));



    QModelIndex ix=tagsmod->index(0,0);

    if(ix.isValid()) ui->tvTags->setCurrentIndex(ix);

    ui->tvTags->selectionModel()->setCurrentIndex(ix,QItemSelectionModel::Select);
    connect(ui->cbCliente->lineEdit(),SIGNAL(returnPressed()),this,SLOT(buildFilter()));
    connect(ui->deDal,SIGNAL(dateChanged(QDate)),this,SLOT(findTagsMov()));
    connect(ui->deAl,SIGNAL(dateChanged(QDate)),this,SLOT(findTagsMov()));

    connect(ui->tvTags->selectionModel(),SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),this,SLOT(findTagsMov()));


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
                                                                       WHERE tags_mov.ID_tags=tags.ID and stampatori.ID=tags_mov.IDStampatore AND azioni.ID=tags_mov.azione and prodotti.ID=tags.IDProdotto and clienti.ID=tags.IDCliente and tags_mov.data between :df and :dt and tags.ID =:id order by tags_mov.data DESC";
                                                                                                                                                                                                                                                                                     q.prepare(sql);
    q.bindValue(":id", current_tag_id);
    q.bindValue(":idprodotto", tagsmod->index(ui->tvTags->currentIndex().row(),3).data(0).toString());
    q.bindValue(":df", ui->deDal->date());
    q.bindValue(":dt", ui->deAl->date());

    if (!q.exec())
    {
        qDebug()<<q.lastError().text()<<q.boundValue(":df").toString()<<q.boundValue(":dt").toString();
    }


    tagsmovmod->setQuery(q);
     ui->tvTags_mov->setModel(tagsmovmod);

    ui->tvTags_mov->setColumnHidden(0,true);
    ui->tvTags_mov->setColumnHidden(1,true);
    ui->tvTags_mov->setColumnHidden(3,true);
    ui->tvTags_mov->setColumnHidden(4,true);
    //  ui->tvTags_mov->setColumnHidden(5,true);
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

    int tot_carico=0;
    int tot_scarico=0;
    for (int r=0;r<tagsmovmod->rowCount();++r)
    {
        int az=tagsmovmod->index(r,10).data().toInt();
        if(az==1)
        {
            tot_carico+=tagsmovmod->index(r,12).data().toInt();
        }
        else if (az==2)
        {
            tot_scarico+= tagsmovmod->index(r,12).data().toInt();
        }

    }

    ui->lb_tot_carico->setText(QString::number(tot_carico));
    ui->lb_tot_scarico->setText(QString::number(tot_scarico));



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


    title=ui->tvTags_mov->model()->index(index.row(),5).data(0).toString() + " - " + ui->tvTags_mov->model()->index(index.row(),7).data(0).toString();

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


    ui->tvTags->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    local_model->setHeaderData(1,Qt::Horizontal,"BARCODE");
    local_model->setHeaderData(2,Qt::Horizontal,"CLIENTE");
    local_model->setHeaderData(3,Qt::Horizontal,"PRODOTTO");
    local_model->setHeaderData(4,Qt::Horizontal,"TIPO");
    local_model->setHeaderData(5,Qt::Horizontal,"SPECIFICA");
    local_model->setHeaderData(6,Qt::Horizontal,"IMMAGINE");
    local_model->setHeaderData(7,Qt::Horizontal,"GIACENZA");
    local_model->setHeaderData(8,Qt::Horizontal,"NOTE");
    local_model->setHeaderData(10,Qt::Horizontal," GIACENZA MINIMA ");
    local_model->setHeaderData(11,Qt::Horizontal,"VISIBILE");
    local_model->setHeaderData(12,Qt::Horizontal,"FUSTELLA");


    return  local_model;
}



void FTOverview::on_pbClose_clicked()
{
    close();
}


void FTOverview::on_pbOperate_clicked()
{

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
    /* QAbstractItemModel *modToPrint =static_cast<QAbstractItemModel*> (tagsmod);
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
    f->show();*/
    print(true);
}


void FTOverview::getProdotti(int client_id)
{
    QString sql;
    QSqlQuery q(db);

    QSettings settings("ctags.ini",QSettings::IniFormat);

    GENERIC_CUSTOMER=settings.value("generic_customer_id").toInt();
    GENERIC_PRODUCT=settings.value("generic_product_id").toInt();

    if (client_id==GENERIC_CUSTOMER || client_id==-1)
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

    QString ftipo,fprodotto,fcliente,fstato,fbarcode=QString();

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

void FTOverview::print(bool p_pdf=true){

    QString strStream;
    bool pdf=p_pdf;


    QTextStream out(&strStream);

    const int rowCount = ui->tvTags->model()->rowCount();
    const int columnCount = ui->tvTags->model()->columnCount();



    QString title="Etichette/sigilli  "+QDate::currentDate().toString("dd.MM.yyyy");


    out <<  "<html>\n<head>\n<meta Content=\"Text/html; charset=Windows-1251\">\n"<< "</head>\n<body bgcolor=#ffffff link=#5000A0>\n<table border=1 cellspacing=0 cellpadding=2>\n";

    out << "<thead><tr bgcolor='lightyellow'><th colspan='5'>"+ title +"</th></tr>";
    // headers
    out << "<tr bgcolor=#f0f0f0>";
    for (int column = 0; column < columnCount; column++)
        if (!ui->tvTags->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tvTags->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tvTags->isColumnHidden(column)) {
                QString data = ui->tvTags->model()->data(ui->tvTags->model()->index(row, column)).toString().simplified();
                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
            }
        }
        out << "</tr>\n";
    }
    out <<  "</table>\n"
           "</body>\n"
           "</html>\n";

    QTextDocument *document = new QTextDocument();
    qDebug()<<strStream;
    document->setHtml(strStream);

    QString filename;

    // qDebug()<<"filename="<<filename;
    filename= QFileDialog::getSaveFileName(this,"Scegli il nome del file",QString(),"Pdf (*.pdf)");

    if (filename.isEmpty() && filename.isNull()){
        //  qDebug()<<"annullato";
        return;
    }

    QPrinter printer;
    printer.setOrientation(QPrinter::Landscape);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(filename);

    document->print(&printer);

    delete document;

    QDesktopServices::openUrl(filename);





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
    int idc=-1;

     if (checked) {
            int ix=ui->cbCliente->findText(ui->cbCliente->currentText());
            ui->cbCliente->setCurrentIndex(ix);
            idc=ui->cbCliente->model()->index(ui->cbCliente->currentIndex(),0).data().toInt();
            getProdotti(idc);
     }
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
    /*if (checked){*/tagsmod->setFilter(buildFilter());
}



void FTOverview::on_rbNoProd_toggled(bool checked)
{
    /* if (checked){t*/tagsmod->setFilter(buildFilter());
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


void FTOverview::on_pbReset_clicked()
{
    ui->deDal->setDate(QDate::currentDate().addYears(-1));
    ui->deAl->setDate(QDate::currentDate());

}

void FTOverview::show_movements()
{
    ui->tvTags_mov->setVisible(true);
}

void FTOverview::hide_movements()
{
    ui->tvTags_mov->setVisible(false);
}







void FTOverview::on_pbShowTags_toggled(bool checked)
{
    ui->tvTags->setVisible(checked);
}


void FTOverview::on_pbShowtagOps_toggled(bool checked)
{
    ui->tvTags_mov->setVisible(checked);
}

