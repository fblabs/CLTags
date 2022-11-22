#include "ftcommands_containers.h"
#include "ftcontainers_overview.h"
#include "ui_ftcommands_containers.h"
#include <QSqlDatabase>
#include "ftcontainer_unload.h"
#include "ftcontainerload.h"

FtCommands_Containers::FtCommands_Containers(QSqlDatabase pdb,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FtCommands_Containers)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::CustomizeWindowHint);
    this->setMouseTracking(true);
    db=pdb;

}

FtCommands_Containers::~FtCommands_Containers()
{
    delete ui;
}

void FtCommands_Containers::on_pbLoad_clicked()
{
        FtContainerLoad *f= new FtContainerLoad(db,nullptr);
        f->show();
        close();
}


void FtCommands_Containers::on_pbUnload_clicked()
{
   FtContainer_unload *f=new FtContainer_unload(-1,db);
   f->show();
   close();
}


void FtCommands_Containers::on_pbContainersOverview_clicked()
{
   FtContainers_Overview *f=new FtContainers_Overview(db);
   f->show();
   close();
}


void FtCommands_Containers::on_pbClose_clicked()
{
    close();
}

