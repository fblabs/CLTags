#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ftagsmov.h"
#include "ftoverview.h"
#include <QSqlDatabase>
#include <QSettings>
#include <QDebug>
#include <QSqlError>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setup();



}

MainWindow::~MainWindow()
{
    db.close();
    delete ui;
}





void MainWindow::on_pbExit_clicked()
{
    db.close();
    close();
}


void MainWindow::on_pbMov_clicked()
{
    FTagsMov *f=new FTagsMov(0,QString(),QString(),db);
    f->show();
}


void MainWindow::on_pbOverview_clicked()
{
    FTOverview *f=new FTOverview(db);
    f->showMaximized();

}


void MainWindow::on_pushButton_clicked()
{
    FTSettings *sets=new FTSettings();
    connect(sets,SIGNAL(setup_done()),this,SLOT(setup()));
    sets->show();
}

void MainWindow::readSettings()
{
    QSettings settings("ctags.ini",QSettings::IniFormat);

    if(settings.contains("server"))
    {
        server=settings.value("server").toString();

        generic_customer_id=settings.value("generic_customer_id").toInt();
        pwd=settings.value("pwd").toString();



    }
}

void MainWindow::setup()
{
    qDebug()<<"setup"<<server;

    readSettings();

    db.close();
    db=QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("fbgmdb260");
    db.setHostName(server);
    db.setPort(3306);
    db.setPassword(pwd);
    db.setUserName("hamlet");


    if(db.open())
    {
        qDebug()<<"DATABEIS APERTO"<<server;
    }
    else
    {
       qDebug()<<"DATABEIS NON APERTO";
       readSettings();

    }

    if(db.open()){qDebug()<<"DATABEIS APERTO";}else{;}
}



