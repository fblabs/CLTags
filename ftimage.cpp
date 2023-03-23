#include "ftimage.h"
#include "ui_ftimage.h"
#include <QImage>
#include <QPixmap>
#include <QGuiApplication>
#include <QScreen>
#include <QPrinter>
#include <QPainter>
#include <QPrintDialog>

//#include <QDebug>

FTImage::FTImage(const QString filename,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FTImage)
{
    ui->setupUi(this);
    QSize rect=QGuiApplication::primaryScreen()->size();
    ui->lbImage->setMaximumHeight(rect.height()-100);
    ui->lbImage->setMaximumWidth(rect.width()-100);

    QImage img(filename);

    ui->lbImage->setPixmap(QPixmap::fromImage(img));
   // qDebug()<<filename;

}

FTImage::~FTImage()
{
    delete ui;
}

void FTImage::on_pbClose_clicked()
{
    emit transfer_Barcode(ui->leBarcode->text());
    close();
}


void FTImage::on_pbCloseWindoiw_clicked()
{
    close();
}


void FTImage::on_pbPrint_clicked()
{
    printImage();
}

void FTImage::printImage()
{
    QPrinter printer(QPrinter::HighResolution);
    printer.setFullPage(true);
    printer.setPageSize(QPrinter::A4);
    QImage img=ui->lbImage->pixmap()->toImage();

    QImage image_norm=img.scaledToWidth(printer.pageRect().width()-100,Qt::SmoothTransformation);

    QPrintDialog *dlg=new QPrintDialog(&printer,0);


    if(dlg->exec()==QDialog::Accepted)
    {
        QPainter painter(&printer);


        painter.drawImage(QPoint(10,100), image_norm);
        painter.end();


    }
}

