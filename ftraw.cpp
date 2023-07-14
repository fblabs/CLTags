#include "ftraw.h"
#include "ui_ftraw.h"
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QDesktopServices>
#include <QTextDocument>
#include <QFileDialog>
#include <QPrinter>

#include "ftmodmov.h"
#include "ftcontainersoperation_mod.h"


FtRaw::FtRaw(QSqlDatabase p_db, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FtRaw)
{
    ui->setupUi(this);
    db=p_db;
    ui->deDal->setDate(QDate::currentDate().addYears(-1));
    ui->deAl->setDate(QDate::currentDate());
    connect(ui->deDal, SIGNAL(dateChanged(const QDate)),this,SLOT(get_Operations()));
    connect(ui->deAl, SIGNAL(dateChanged(const QDate)),this,SLOT(get_Operations()));
    get_Operations();
}

FtRaw::~FtRaw()
{
    delete ui;
}

void FtRaw::get_Operations()
{
    QSqlQueryModel *mod_details=new QSqlQueryModel();
     QSqlQuery q(db);
    QString sql=QString();


        if(ui->rbLabels->isChecked()){

        sql="SELECT tags_mov.ID,tags_mov.ID_tags,tags_mov.data as DATA, tags.barcode as BARCODE,prodotti.ID as IDProdotto,prodotti.descrizione as PRODOTTO,clienti.ID as IDCliente,clienti.ragione_sociale as CLIENTE,\
              stampatori.ID as IDStampatore,stampatori.ragione_sociale as STAMPATORE,azione as IDAZIONE,azioni.descrizione as AZIONE,tags_mov.amount as QUANT,tags_mov.note\
              FROM tags,tags_mov,anagrafica as stampatori,anagrafica as clienti,azioni,prodotti\
              WHERE tags_mov.ID_tags=tags.ID and stampatori.ID=tags_mov.IDStampatore AND azioni.ID=tags_mov.azione and prodotti.ID=tags.IDProdotto and clienti.ID=tags.IDCliente and tags_mov.data between :df and :dt order by tags_mov.data DESC";
        q.prepare(sql);
        q.bindValue(":df", ui->deDal->date());
        q.bindValue(":dt", ui->deAl->date());
        q.exec();
        mod_details->setQuery(q);

        ui->tvRaw->setModel(mod_details);

        for (int x=0;x<mod_details->columnCount();++x)
        {
            ui->tvRaw->setColumnHidden(x,false);
        }

        ui->tvRaw->setColumnHidden(0,true);
        ui->tvRaw->setColumnHidden(1,true);
        ui->tvRaw->setColumnHidden(4,true);
        ui->tvRaw->setColumnHidden(6,true);
        ui->tvRaw->setColumnHidden(8,true);
        ui->tvRaw->setColumnHidden(10,true);
        ui->tvRaw->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);

        ui->tvRaw->horizontalHeader()->setSectionResizeMode(0,QHeaderView::ResizeToContents);
        ui->tvRaw->horizontalHeader()->setSectionResizeMode(1,QHeaderView::ResizeToContents);
        ui->tvRaw->horizontalHeader()->setSectionResizeMode(2,QHeaderView::ResizeToContents);
        ui->tvRaw->horizontalHeader()->setSectionResizeMode(3,QHeaderView::ResizeToContents);
        ui->tvRaw->horizontalHeader()->setSectionResizeMode(4,QHeaderView::Interactive);
        ui->tvRaw->horizontalHeader()->setSectionResizeMode(5,QHeaderView::ResizeToContents);
        ui->tvRaw->horizontalHeader()->setSectionResizeMode(6,QHeaderView::Interactive);
        ui->tvRaw->horizontalHeader()->setSectionResizeMode(7,QHeaderView::Interactive);
        ui->tvRaw->horizontalHeader()->setSectionResizeMode(8,QHeaderView::Interactive);
        ui->tvRaw->horizontalHeader()->setSectionResizeMode(9,QHeaderView::Interactive);
        ui->tvRaw->horizontalHeader()->setSectionResizeMode(10,QHeaderView::Interactive);
        ui->tvRaw->horizontalHeader()->setStretchLastSection(true);
        ui->tvRaw->horizontalHeader()->setCascadingSectionResizes(true);






        }else{




        sql="select tags_containers_mov.ID,tags_containers_mov.ID_tags_container,tags_containers_mov.data as'DATA', prodotti.descrizione as 'PRODOTTO', anagrafica.ragione_sociale as 'FORNITORE',azioni.descrizione as 'AZIONE',tags_containers_mov.amount as 'QUANTITA',tags_containers_mov.bolla as 'BOLLA',tags_containers_mov.note as 'NOTE'\
            from tags_containers_mov,tags_containers, prodotti, anagrafica,azioni\
                                               where tags_containers.ID = tags_containers_mov.ID_tags_container\
                                                     and anagrafica.ID=tags_containers_mov.ID_supplier  \
                                                     and azioni.ID=tags_containers_mov.azione \
                                                     and prodotti.ID =tags_containers.ID_Prodotto \
                                                 and tags_containers_mov.data BETWEEN :df AND :dt order by tags_containers_mov.data desc";

        q.prepare(sql);
        q.bindValue(":df",ui->deDal->date());
        q.bindValue(":dt",ui->deAl->date());
        q.exec();
        mod_details->setQuery(q);
        ui->tvRaw->setModel(mod_details);

        for (int x=0;x<mod_details->columnCount();++x)
        {
            ui->tvRaw->setColumnHidden(x,false);
        }
        ui->tvRaw->setColumnHidden(0,true);
        ui->tvRaw->setColumnHidden(1,true);
       /* ui->tvRaw->setColumnHidden(4,true);
        ui->tvRaw->setColumnHidden(6,true);
        ui->tvRaw->setColumnHidden(8,true);
        ui->tvRaw->setColumnHidden(10,true);*/
       // ui->tvRaw->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);






        }



    ui->tvRaw->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);



}

void FtRaw::on_pbClose_clicked()
{
    close();
}

void FtRaw::modify_operation()
{
    QModelIndex index=ui->tvRaw->currentIndex();
    int id=ui->tvRaw->model()->index(index.row(),0).data(0).toInt();
    QString title=QString();

    if(ui->rbLabels->isChecked())
    {


    title=ui->tvRaw->model()->index(index.row(),7).data(0).toString() + " - " + ui->tvRaw->model()->index(index.row(),5).data(0).toString();


    FTModMov *f=new FTModMov(id,db,title);
    connect(f,SIGNAL(mod_mov_done()),this,SLOT(refresh));
    f->show();
    ui->tvRaw->setCurrentIndex(index);
    }
    else
    {

        int row=ui->tvRaw->selectionModel()->currentIndex().row();
        QModelIndex ix=ui->tvRaw->model()->index(row,0);

        int idop=ix.data(0).toInt();
        QString supplier=ui->tvRaw->model()->index(row,4).data(0).toString();


        FtContainersOperation_mod *f=new FtContainersOperation_mod(idop,supplier,db);

        connect(f,SIGNAL(save_done()),this,SLOT(refresh()));

        f->show();
    }
}

void FtRaw::print()
{
    QString strStream;



    QTextStream out(&strStream);

    const int rowCount = ui->tvRaw->model()->rowCount();
    const int columnCount = ui->tvRaw->model()->columnCount();



    QString title=QString();

        if (ui->rbLabels->isChecked()){
        title="Etichette/sigilli  "+QDate::currentDate().toString("dd.MM.yyyy");
        }else{

        title="Vasi/Tappi  "+QDate::currentDate().toString("dd.MM.yyyy");

        }


    out <<  "<html>\n<head>\n<meta Content=\"Text/html; charset=Windows-1251\">\n"<< "</head>\n<body bgcolor=#ffffff link=#5000A0>\n<table border=1 cellspacing=0 cellpadding=2>\n";

    out << "<thead><tr bgcolor='lightyellow'><th colspan='5'>"+ title +"</th></tr>";
    // headers
    out << "<tr bgcolor=#f0f0f0>";
    for (int column = 0; column < columnCount; column++)
        if (!ui->tvRaw->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tvRaw->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tvRaw->isColumnHidden(column)) {
                QString data = ui->tvRaw->model()->data(ui->tvRaw->model()->index(row, column)).toString().simplified();
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

void FtRaw::refresh()
{
    get_Operations();
}


void FtRaw::on_tvRaw_doubleClicked(const QModelIndex &index)
{
   // QModelIndex ix=ui->tvRaw->currentIndex();

    modify_operation();

    ui->tvRaw->setCurrentIndex(index);
}


void FtRaw::on_rbLabels_toggled(bool checked)
{
    if(checked){get_Operations();}
}


void FtRaw::on_rbVases_toggled(bool checked)
{
    if (checked){get_Operations();}
}


void FtRaw::on_pbPrint_clicked()
{
    print();
}

