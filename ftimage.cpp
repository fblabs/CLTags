#include "ftimage.h"
#include "ui_ftimage.h"
#include <QImage>
#include <QPixmap>
#include <QGuiApplication>
#include <QScreen>
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
    close();
}

