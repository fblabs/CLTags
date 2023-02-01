#include "ftupdate_tag.h"
#include "ui_ftupdate_tag.h"
#include <QSqlDatabase>
#include <QSqlQuery>

FtUpdate_Tag::FtUpdate_Tag(const int p_id_tag=-1,QSqlDatabase pdb, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FtUpdate_Tag)
{
    ui->setupUi(this);
    id_tag=p_id_tag;
    db=pdb;
    populate();
}

FtUpdate_Tag::~FtUpdate_Tag()
{
    delete ui;
}

void FtUpdate_Tag::populate()
{
    QSqlQuery q(db);
    QString sql="SELECT prodotti.descrizione, tags_containers.note from tags_containers,prodotti WHERE prodotti.ID=tags_containers.ID_Prodotto and tags_containers.ID=:id";
    q.prepare(sql);
    q.bindValue(":id",id_tag);

    q.exec();
    q.next();

    ui->leProdotto->setText(q.value(0).toString());
    ui->teNote->setText(q.value(1).toString());
}

void FtUpdate_Tag::save()
{
    QSqlQuery q(db);
    QString note=ui->teNote->toPlainText();
    QString sql="UPDATE tags_containers set note=:note WHERE  tags_containers.ID=:id";
    q.prepare(sql);
    q.bindValue(":note",note);
    q.bindValue(":id",id_tag);
    q.exec();
}

void FtUpdate_Tag::on_pbSave_clicked()
{
    save();
    populate();
    emit container_updated();
}


void FtUpdate_Tag::on_pbClose_clicked()
{
    close();
}

