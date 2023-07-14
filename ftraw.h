#ifndef FTRAW_H
#define FTRAW_H

#include <QWidget>
#include <QSqlDatabase>

namespace Ui {
class FtRaw;
}

class FtRaw : public QWidget
{
    Q_OBJECT

public:
    explicit FtRaw(QSqlDatabase p_db=QSqlDatabase(),QWidget *parent = nullptr);
    ~FtRaw();

private slots:
    void get_Operations();
    void on_pbClose_clicked();
    void modify_operation();
    void print();
    void refresh();

    void on_tvRaw_doubleClicked(const QModelIndex &index);

    void on_rbLabels_toggled(bool checked);

    void on_rbVases_toggled(bool checked);

    void on_pbPrint_clicked();

private:
    Ui::FtRaw *ui;
    QSqlDatabase db;
};

#endif // FTRAW_H
