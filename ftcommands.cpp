#include "ftcommands.h"
#include "ui_ftcommands.h"
#include <QSqlDatabase>
#include "ftagsmov.h"
#include "ftoverview.h"

FtCommands::FtCommands(QSqlDatabase pdb,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FtCommands)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::CustomizeWindowHint);
    this->setMouseTracking(true);

    connect (this,SIGNAL(sig_close()),this,SLOT(close()));
}

FtCommands::~FtCommands()
{
    delete ui;
}

void FtCommands::on_pbOverview_clicked()
{
    FTOverview *f=new FTOverview(db);
    emit accepted();
    f->showMaximized();



}


void FtCommands::on_pbMov_clicked()
{
    FTagsMov *f=new FTagsMov(0,QString(),QString(),db);
    emit accepted();
    f->show();

}


void FtCommands::on_FtCommands_accepted()
{
    close();
}


void FtCommands::on_pbClose_clicked()
{
    close();
}

