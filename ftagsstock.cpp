#include "ftagsstock.h"
#include "ui_ftagsstock.h"

FTagsStock::FTagsStock(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FTagsStock)
{
    ui->setupUi(this);
}

FTagsStock::~FTagsStock()
{
    delete ui;
}

void FTagsStock::setup()
{

}

void FTagsStock::on_pushButton_clicked()
{

}

