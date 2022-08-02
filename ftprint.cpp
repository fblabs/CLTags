#include "ftprint.h"
//#include <QDebug>
#include "ui_ftprint.h"
#include <QAbstractItemModel>
#include <QFileDialog>
#include <QPrinter>
#include <QDesktopServices>
#include <QTextStream>

FTPrint::FTPrint(QAbstractItemModel *pmod,QString ptitle, QStringList pcolnames,QList<int>phiddencols, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FTPrint)
{
    ui->setupUi(this);

    mod=pmod;
    modelToHtml(ptitle,pcolnames,phiddencols);
}

FTPrint::~FTPrint()
{
    delete ui;
}

void FTPrint::modelToHtml(QString ptitle,QStringList pcolNames,QList<int>hiddenCols)
{
    QString strStream;
 /*   QString filename=QFileDialog::getSaveFileName(0,"Scegli nome del file",QString(),"Pdf (*.pdf)");
    if(filename.isEmpty() || filename.isNull())
    {
        return;
    }*/
    QTextStream out(&strStream);
    QString bgcol=QString();
    QString title=QString();

    QApplication::setOverrideCursor(Qt::CursorShape::WaitCursor);


    const int rowCount =mod->rowCount();
    const int columnCount = mod->columnCount() - hiddenCols.size();
    const int cols=columnCount-hiddenCols.size();
    title =ptitle;
    out <<  "<html>\n<head>\n<meta Content=\"Text/html; charset=Windows-1251\">\n"<< "</head>\n<body bgcolor=#ffffff link=#5000A0>\n<table width=100% border=1 cellspacing=0 cellpadding=2>\n";





   out << "<thead><tr bgcolor='#5cabff'><th colspan='"+QString::number(cols)+"'>"+ title +"</th></tr><tr bgcolor='lightgrey'>";


    for (int column = 0 ; column < columnCount; column++)
    {


           if (!hiddenCols.contains(column))
            {

              out << QString("<th>%1</th>").arg(pcolNames.at(column));

           }

    }

     out << "</tr></th></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++) {

        out << "<tr>";
        if(row%2)
        {
            bgcol="lightgreen";
        }
        else
        {
            bgcol="white";
        }
        for (int column = 0; column < columnCount; column++) {
            if (!hiddenCols.contains(column)) {
                QString data =mod->index(row, column).data().toString().simplified();



                    out << QString("<td bgcolor='"+bgcol+"'>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));

            }
        }
        out << "</tr>\n";
    }
    out <<  "</table>\n"
        "</body>\n"
        "</html>\n";


    QTextDocument *document = new QTextDocument();
    document->setHtml(strStream);



    ui->teDoc->setDocument(document);




   ui->teDoc->setHtml(document->toHtml());

   QApplication::setOverrideCursor(Qt::CursorShape::ArrowCursor);
   //delete document;
}

void FTPrint::print()
{
      QString filename=QFileDialog::getSaveFileName(0,"Scegli nome del file",QString(),"Pdf (*.pdf)");
       if(filename.isEmpty() || filename.isNull())
       {
           return;
       }

    QPrinter printer;
    QTextDocument *doc=ui->teDoc->document();
    printer.setPageOrientation(QPageLayout::Landscape);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPageSize(QPrinter::A4);
    printer.setOutputFileName(filename);

    doc->print(&printer);
    QDesktopServices::openUrl(filename);
}




void FTPrint::on_pbPrint_clicked()
{
    print();



}


void FTPrint::on_pbClose_clicked()
{
    close();
}

