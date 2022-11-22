#ifndef FTCONTAINER_UNLOAD_H
#define FTCONTAINER_UNLOAD_H

#include <QWidget>
#include <QSqlDatabase>

namespace Ui {
class FtContainer_unload;
}

class FtContainer_unload : public QWidget
{
    Q_OBJECT

public:
    explicit FtContainer_unload(const int pid_tag=-1, QSqlDatabase pdb=QSqlDatabase(), QWidget *parent = nullptr);
    ~FtContainer_unload();

private:
    Ui::FtContainer_unload *ui;
    QSqlDatabase db;
    int id_tag;
    int id_generic_supplier;
private slots:
   void getTags();
   void saveUnload();
   void on_pbClose_clicked();
   void on_pbSave_clicked();
   void findGenericSupplier();
signals:
   void save_done();

};

#endif // FTCONTAINER_UNLOAD_H
