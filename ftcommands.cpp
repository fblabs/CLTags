#include "ftcommands.h"
#include "ui_ftcommands.h"
#include <QSqlDatabase>
#include "ftagsmov.h"
#include "ftoverview.h"
#include <QGraphicsOpacityEffect>

FtCommands::FtCommands(int p_id_tag, QSqlDatabase pdb, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FtCommands)
{
    ui->setupUi(this);
    id_tag=p_id_tag;
    this->setWindowFlags(Qt::CustomizeWindowHint);
    this->setMouseTracking(true);

    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlag(Qt::FramelessWindowHint);

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

    FTagsMov *f=new FTagsMov(0,id_tag,QString(),db);
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

