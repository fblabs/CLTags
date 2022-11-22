#ifndef FTCONTAINERLOAD_H
#define FTCONTAINERLOAD_H

#include <QWidget>
#include <QSqlDatabase>

namespace Ui {
class FtContainerLoad;
}

class FtContainerLoad : public QWidget
{
    Q_OBJECT

public:
    explicit FtContainerLoad(QSqlDatabase pdb,QWidget *parent = nullptr);
    ~FtContainerLoad();

private slots:
    void on_pbClose_clicked();
    void getSuppliers();
    void getTags();
   // bool init_tag();
    bool save_tag();


    void on_pbSave_clicked();

//    void on_pbInit_clicked();

private:
    Ui::FtContainerLoad *ui;
    QSqlDatabase db;
    int inserted_tag_id;

signals:

    void save_done();

};

#endif // FTCONTAINERLOAD_H
