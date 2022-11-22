#include "ftsettings.h"
#include "ui_ftsettings.h"
#include <QSettings>

FTSettings::FTSettings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FTSettings)
{
    ui->setupUi(this);
    QSettings settings("ctags.ini",QSettings::IniFormat);

    ui->leServer->setText(settings.value("server").toString());
    ui->lePassword->setText(settings.value("pwd").toString());
    ui->leGenericCustomerID->setText(settings.value("generic_customer_id").toString());
    ui->leGenericSupplier->setText(settings.value("generic_supplier_id").toString());
    ui->leGenericProductID->setText(settings.value("generic_product_id").toString());


}

FTSettings::~FTSettings()
{
    delete ui;
}

void FTSettings::on_pbSave_clicked()
{
     QSettings settings("ctags.ini",QSettings::IniFormat);
     settings.setValue("server",ui->leServer->text());
     settings.setValue("pwd",ui->lePassword->text());
     settings.setValue("generic_customer_id",ui->leGenericCustomerID->text());
     settings.setValue("generic_supplier_id",ui->leGenericSupplier->text());
     settings.setValue("generic_product_id",ui->leGenericProductID->text());

     emit setup_done();

     close();

}


void FTSettings::on_pbClose_clicked()
{
    close();
}

