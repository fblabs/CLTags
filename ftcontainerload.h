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
    explicit FtContainerLoad(const int pidtag=-1, QSqlDatabase pdb=QSqlDatabase(), QWidget *parent = nullptr);
    ~FtContainerLoad();

private slots:
    void on_pbClose_clicked();
    void getSuppliers();
    void getTags();
    bool save_tag();
    void on_pbSave_clicked();
private:
    Ui::FtContainerLoad *ui;
    QSqlDatabase db;
    int id_tag;
    int inserted_tag_id;
    QString supplier;

signals:
    void sg_save_load();

};

#endif // FTCONTAINERLOAD_H
