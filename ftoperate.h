#ifndef FTOPERATE_H
#define FTOPERATE_H

#include <QWidget>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlTableModel>

namespace Ui {
class FTOperate;
}

class FTOperate : public QWidget
{
    Q_OBJECT

public:
    explicit FTOperate(QSqlDatabase pdb=QSqlDatabase(),QString pbarcode=QString(),QWidget *parent = nullptr);
    ~FTOperate();

private:
    Ui::FTOperate *ui;
    QSqlDatabase db;
    QString barcode;
    QSqlQueryModel *modbarcodes;
    QSqlTableModel *modstampatori;
    QSqlTableModel *modtipi;
private slots:
    void setup();
    void saveOp();
    void on_pbSave_clicked();
    void on_pbClose_clicked();

    void on_leBarcode_returnPressed();

    void on_rbCarico_toggled(bool checked);

signals:
    void operation_saved();
};

#endif // FTOPERATE_H
