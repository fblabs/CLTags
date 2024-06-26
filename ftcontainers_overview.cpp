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
#include <QDesktopServices>
#include <QTextStream>
#include <QTextDocument>
#include <QPrinter>
#include <QFileDialog>
#include <QDate>
#include "hcontainerstablemodel.h"
#include "ftaddcontainer.h"

//#include <QDebug>
//#include <QSqlError>

FtContainers_Overview::FtContainers_Overview(QSqlDatabase pdb,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FtContainers_Overview)
{
    ui->setupUi(this);
    db=pdb;
    ui->deDal->setDate(QDate::currentDate().addYears(-1));
    ui->deAl->setDate(QDate::currentDate());
    getContainers();

    connect(ui->deDal,SIGNAL(dateChanged(QDate)),this,SLOT(getContainerOperations()));
    connect(ui->deAl,SIGNAL(dateChanged(QDate)),this,SLOT(getContainerOperations()));


}

FtContainers_Overview::~FtContainers_Overview()
{
    delete ui;
}

void FtContainers_Overview::getContainers()
{
    QSqlQuery q(db);
    mod=new HContainersTableModel();
    QString sql="SELECT tags_containers.ID, prodotti.ID,prodotti.descrizione as 'DESCRIZIONE', tags_containers.giacenza as 'GIACENZA',tags_containers.note as 'NOTE',tags_containers.giacenza_minima as 'GIACENZA MINIMA',tags_containers.visibile from tags_containers,prodotti where prodotti.ID=tags_containers.ID_Prodotto and prodotti.tipo IN(3,4,5) and tags_containers.visibile=:visibile order by prodotti.descrizione";
    q.prepare(sql);
    int visibile=0;
    ui->cbAttivi->isChecked()?visibile=1:visibile=0;
    q.bindValue(":visibile",visibile);

    q.exec();
    mod->setQuery(q);
    qDebug()<<q.lastError().text();
    ui->tvOverview->setModel(mod);
    ui->tvOverview->setColumnHidden(0,true);
    ui->tvOverview->setColumnHidden(1,true);
    ui->tvOverview->setColumnHidden(6,true);
    ui->tvOverview->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    connect(ui->tvOverview->selectionModel(),SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),this,SLOT(getContainerOperations()));

}

void FtContainers_Overview::getContainerOperations()
{
    int id_container=ui->tvOverview->model()->index(ui->tvOverview->currentIndex().row(),0).data(0).toInt();


    QSqlQuery q(db);
    QSqlQueryModel *mod_details=new QSqlQueryModel();
    QString sql="select tags_containers_mov.ID,tags_containers_mov.ID_tags_container,tags_containers_mov.data as'DATA', prodotti.descrizione as 'PRODOTTO', anagrafica.ragione_sociale as 'FORNITORE',azioni.ID,azioni.descrizione as 'AZIONE',tags_containers_mov.amount as 'QUANTITA',tags_containers_mov.bolla as 'BOLLA',tags_containers_mov.note as 'NOTE' \
        from tags_containers_mov,tags_containers, prodotti, anagrafica,azioni\
                                                   where tags_containers.ID = tags_containers_mov.ID_tags_container\
                                                         and anagrafica.ID=tags_containers_mov.ID_supplier  \
                                                         and azioni.ID=tags_containers_mov.azione \
                                                         and prodotti.ID =tags_containers.ID_Prodotto \
                                                         and tags_containers_mov.ID_tags_container=:id_container and tags_containers_mov.data BETWEEN :df AND :dt order by tags_containers_mov.data desc";
                                                                                                                    q.prepare(sql);
    q.bindValue(":id_container", id_container);
    q.bindValue(":df",ui->deDal->date());
    q.bindValue(":dt",ui->deAl->date().addDays(1));

    q.exec();
    qDebug()<<q.lastError().text();

    mod_details->setQuery(q);
    ui->tvDetails->setModel(mod_details);
    ui->tvDetails->setColumnHidden(0,true);
    ui->tvDetails->setColumnHidden(1,true);
    ui->tvDetails->setColumnHidden(5,true);
    ui->tvDetails->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    int tot_scarico=0;
    int tot_carico=0;
    for(int r=0;r<mod_details->rowCount();++r)
    {
        int q=mod_details->index(r,5).data().toInt();

        if(q==1)
        {
            tot_carico+=mod_details->index(r,7).data().toInt();
        }
        else if (q==2)
        {
            tot_scarico+=mod_details->index(r,7).data().toInt();
        }

    }

    ui->lbTot_load->setText(QString::number(tot_carico));
    ui->lbTot_unload->setText(QString::number(tot_scarico));

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
    //QString supplier=ui->tvDetails->model()->index(row,4).data(0).toString();
    // QModelIndex ix=ui->tvOverview->currentIndex();
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
    // QModelIndex prev=ui->tvDetails->selectionModel()->currentIndex();
    int row=ui->tvDetails->selectionModel()->currentIndex().row();
    QModelIndex ix=ui->tvDetails->model()->index(row,0);

    int idop=ix.data(0).toInt();
    QString supplier=ui->tvDetails->model()->index(row,4).data(0).toString();


    FtContainersOperation_mod *f=new FtContainersOperation_mod(idop,supplier,db);

    connect(f,SIGNAL(save_done()),this,SLOT(refresh()));

    f->show();



    getContainerOperations();


}

void FtContainers_Overview::print(bool p_pdf)
{
    QString strStream;
    bool pdf=p_pdf;


    QTextStream out(&strStream);

    const int rowCount = ui->tvOverview->model()->rowCount();
    const int columnCount = ui->tvOverview->model()->columnCount();



    QString title="VASI-TAPPI-CONTENITORI  "+QDate::currentDate().toString("dd.MM.yyyy");


    out <<  "<html>\n<head>\n<meta Content=\"Text/html; charset=Windows-1251\">\n"<< "</head>\n<body bgcolor=#ffffff link=#5000A0>\n<table width=100% border=1 cellspacing=0 cellpadding=2>\n";

    out << "<thead><tr bgcolor='lightyellow'><th colspan='3'>"+ title +"</th></tr>";
    // headers
    out << "<tr bgcolor=#f0f0f0>";
    for (int column = 0; column < columnCount; column++)
        if (!ui->tvOverview->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tvOverview->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tvOverview->isColumnHidden(column)) {
                QString data = ui->tvOverview->model()->data(ui->tvOverview->model()->index(row, column)).toString().simplified();
                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
            }
        }
        out << "</tr>\n";
    }
    out <<  "</table>\n"
           "</body>\n"
           "</html>\n";

    QTextDocument *document = new QTextDocument();

    document->setHtml(strStream);

    QString filename;

    // qDebug()<<"filename="<<filename;
    filename= QFileDialog::getSaveFileName(this,"Scegli il nome del file",QString(),"Pdf (*.pdf)");

    if (filename.isEmpty() && filename.isNull()){
        //  qDebug()<<"annullato";
        return;
    }

    QPrinter printer;
    printer.setOrientation(QPrinter::Portrait);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(filename);

    document->print(&printer);

    delete document;

    QDesktopServices::openUrl(filename);



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


    QModelIndex current=ui->tvOverview->currentIndex();
    QModelIndex row=ui->tvOverview->model()->index(current.row(),0);
    QModelIndex mov=ui->tvDetails->currentIndex();
    ui->tvOverview->reset();
    ui->tvOverview->clearSelection();
    ui->tvOverview->selectionModel()->select(row,QItemSelectionModel::ClearAndSelect);

    QSqlQuery q(db);
    //  QString sql="SELECT tags_containers.ID, prodotti.ID,prodotti.descrizione, tags_containers.giacenza from tags_containers,prodotti where prodotti.ID=tags_containers.ID_Prodotto and prodotti.tipo IN(3,4,5) order by prodotti.descrizione";

    //QString sql="SELECT tags_containers.ID, prodotti.ID,prodotti.descrizione as 'DESCRIZIONE', tags_containers.giacenza as 'GIACENZA',tags_containers.note as 'NOTE' from tags_containers,prodotti where prodotti.ID=tags_containers.ID_Prodotto and prodotti.tipo IN(3,4,5) order by prodotti.descrizione";
    // QString sql="SELECT tags_containers.ID, prodotti.ID,prodotti.descrizione as 'DESCRIZIONE', tags_containers.giacenza as 'GIACENZA',tags_containers.note as 'NOTE',tags_containers.giacenza_minima as 'GIACENZA MINIMA' from tags_containers,prodotti where prodotti.ID=tags_containers.ID_Prodotto and prodotti.tipo IN(3,4,5) order by prodotti.descrizione";
    QString sql="SELECT tags_containers.ID, prodotti.ID,prodotti.descrizione as 'DESCRIZIONE', tags_containers.giacenza as 'GIACENZA',tags_containers.note as 'NOTE',tags_containers.giacenza_minima as 'GIACENZA MINIMA',tags_containers.visibile from tags_containers,prodotti where prodotti.ID=tags_containers.ID_Prodotto and prodotti.tipo IN(3,4,5) and tags_containers.visibile=:visibile order by prodotti.descrizione";
    int visibile=0;
    ui->cbAttivi->isChecked()?visibile=1:visibile=0;

    q.prepare(sql);
    q.bindValue(":visibile",visibile);
    q.exec();
    qDebug()<<"refresh"<<q.lastError().text();

    mod->setQuery(q);


    ui->tvOverview->setCurrentIndex(current);
    ui->tvOverview->selectionModel()->select(current,QItemSelectionModel::Select);
    ui->tvDetails->setCurrentIndex(mov);
    getContainerOperations();
    ui->tvOverview->setColumnHidden(6,true);



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







void FtContainers_Overview::on_leSearch_returnPressed()
{

    disconnect(ui->tvOverview->selectionModel(),SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),this,SLOT(getContainerOperations()));

    QModelIndex ix=ui->tvOverview->currentIndex();



    QString search="%"+ui->leSearch->text()+"%";
    // QString sql="SELECT tags_containers.ID, prodotti.ID,prodotti.descrizione as 'DESCRIZIONE', tags_containers.giacenza as 'GIACENZA',tags_containers.note as 'NOTE' from tags_containers,prodotti where prodotti.ID=tags_containers.ID_Prodotto and prodotti.tipo IN(3,4,5) and prodotti.descrizione LIKE :search order by prodotti.descrizione";
    QString sql="SELECT tags_containers.ID, prodotti.ID,prodotti.descrizione as 'DESCRIZIONE', tags_containers.giacenza as 'GIACENZA',tags_containers.note as 'NOTE',tags_containers.giacenza_minima as 'GIACENZA MINIMA',tags_containers.visibile from tags_containers,prodotti where prodotti.ID=tags_containers.ID_Prodotto and prodotti.tipo IN(3,4,5) and tags_containers.visibile=:visibile order by prodotti.descrizione";
    int visibile=0;
    ui->cbAttivi->isChecked()?visibile=1:visibile=0;
    QSqlQuery q(db);
    q.prepare(sql);
    q.bindValue(":search",search);
    q.bindValue(":visiblie",visibile);
    q.exec();
    mod=new  HContainersTableModel();
    mod->setQuery(q);
    qDebug()<<"SEARCH"<<q.lastError().text();

    ui->tvOverview->setModel(mod);

    connect(ui->tvOverview->selectionModel(),SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),this,SLOT(getContainerOperations()));


    ui->tvOverview->setCurrentIndex(ix);

    getContainerOperations();


}


void FtContainers_Overview::on_pbPrint_clicked()
{
    print();
}


void FtContainers_Overview::on_pbReset_clicked()
{
    ui->deDal->setDate(QDate::currentDate().addYears(-1));
    ui->deAl->setDate(QDate::currentDate());
}




void FtContainers_Overview::on_pbAddContainer_clicked()
{
    FtAddContainer *f=new FtAddContainer(db);
    f->show();
}


void FtContainers_Overview::on_cbAttivi_toggled(bool checked)
{
    getContainers();
}

