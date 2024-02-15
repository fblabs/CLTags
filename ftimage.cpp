#include "ftimage.h"
#include "ui_ftimage.h"
#include <QImage>
#include <QPixmap>
#include <QGuiApplication>
#include <QScreen>
#include <QPrinter>
#include <QPainter>
#include <QPrintDialog>
#include <QDesktopWidget>
#include <QScreen>
#include <QDebug>

//#include <QDebug>

FTImage::FTImage(const QString filename,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FTImage)
{
    ui->setupUi(this);


    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->availableGeometry();
    //resize(screenGeometry.width()/2,screenGeometry.height()/2);


    QImage img(filename);

    double h=0.2;
    double v=0.2;
    int x,y=0;
    x=(screenGeometry.width()-this->width())/2;
    y=(screenGeometry.height()-this->height())/2;
    this->move(x,y);


    ui->lbImage->setPixmap(QPixmap::fromImage(img).scaled(screenGeometry.width()*0.6,screenGeometry.height()*0.7));


    ui->lbImage->installEventFilter(this);
    connect(this,&imageclicked,&closeWindow);


    x=(screenGeometry.width()-this->width())/2;
    y=(screenGeometry.height()-this->height())/2;
    qDebug()<<screenGeometry.width()<<this->width();
    hide();
    this->move(x,y);
    show();
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

void FTImage::closeWindow()
{
    close();
}

bool FTImage::eventFilter(QObject *obj, QEvent *evt)
{
    if(obj==ui->lbImage && evt->type()==QEvent::MouseButtonDblClick)
    {


        emit closeWindow();


    }


    return QObject::eventFilter(obj,evt);
}

