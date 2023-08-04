#include "ftupdate_tag.h"
#include "ui_ftupdate_tag.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QIntValidator>
#include <QDebug>

FtUpdate_Tag::FtUpdate_Tag(const int p_id_tag=-1,QSqlDatabase pdb, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FtUpdate_Tag)
{
    ui->setupUi(this);
    id_tag=p_id_tag;
    db=pdb;
    populate();
    QIntValidator *min_giac_validator=new QIntValidator(0,1000000000);
    ui->le_giacenza_minima->setValidator(min_giac_validator);
    connect(this,SIGNAL(container_updated()),this,SLOT(populate()));
}

FtUpdate_Tag::~FtUpdate_Tag()
{
    delete ui;
}

void FtUpdate_Tag::populate()
{
    QSqlQuery q(db);
    QString sql="SELECT prodotti.descrizione, tags_containers.note,tags_containers.giacenza_minima from tags_containers,prodotti WHERE prodotti.ID=tags_containers.ID_Prodotto and tags_containers.ID=:id";

    q.prepare(sql);
    q.bindValue(":id",id_tag);

    q.exec();
    q.next();

    ui->leProdotto->setText(q.value(0).toString());
    ui->teNote->setText(q.value(1).toString());
    ui->le_giacenza_minima->setText(q.value(2).toString());
    qDebug()<<"populate";
}

bool FtUpdate_Tag::save()
{

    db.transaction();
    QSqlQuery q(db);
    QString note=ui->teNote->toPlainText();
    QString sql="UPDATE tags_containers set note=:note, giacenza_minima=:min_giacenza WHERE  tags_containers.ID=:id";
    q.prepare(sql);
    q.bindValue(":note",note);
    q.bindValue(":id",id_tag);
    q.bindValue(":min_giacenza",ui->le_giacenza_minima->text().toInt());

    return q.exec();
}

void FtUpdate_Tag::on_pbSave_clicked()
{
    bool b=save();

    if(b)
    {
        db.commit();
        emit container_updated();
        close();

    }


}


void FtUpdate_Tag::on_pbClose_clicked()
{
    close();
}

