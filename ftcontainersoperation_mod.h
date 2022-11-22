#ifndef FTCONTAINERSOPERATION_MOD_H
#define FTCONTAINERSOPERATION_MOD_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>


namespace Ui {
class FtContainersOperation_mod;
}

class FtContainersOperation_mod : public QWidget
{
    Q_OBJECT

public:
    explicit FtContainersOperation_mod(const int pidop=-1, const QString p_supplier=QString(), QSqlDatabase pdb=QSqlDatabase(), QWidget *parent = nullptr);
    ~FtContainersOperation_mod();

private slots:
    void on_pbSave_clicked();
    void getDetails();
    void updateOp();
    void getSuppliers();
    void on_pbClose_clicked();

private:
    Ui::FtContainersOperation_mod *ui;
    QSqlDatabase db;
    int idop;
    QString supplier;
signals:
    void save_done();
};

#endif // FTCONTAINERSOPERATION_MOD_H
