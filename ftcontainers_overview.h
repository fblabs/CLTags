#ifndef FTCONTAINERS_OVERVIEW_H
#define FTCONTAINERS_OVERVIEW_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include "hcontainerstablemodel.h"

namespace Ui {
class FtContainers_Overview;
}

class FtContainers_Overview : public QWidget
{
    Q_OBJECT

public:
    explicit FtContainers_Overview(QSqlDatabase pdb=QSqlDatabase(), QWidget *parent = nullptr);
    ~FtContainers_Overview();

private:
    Ui::FtContainers_Overview *ui;
    QSqlDatabase db;
    HContainersTableModel* mod;
private slots:
   void getContainers();
   void getContainerOperations();
   void on_pbClose_clicked();
   void on_pbModify_clicked();
   void on_pbLoad_clicked();
   void on_pbUnload_clicked();
   void modify_tag();
   void print(bool p_pdf=true);
    bool deleteOperation();
   void on_pbDelete_clicked();
   void refresh();
   void on_tvDetails_doubleClicked(const QModelIndex &index);
   void on_tvOverview_doubleClicked(const QModelIndex &index);

   void on_leSearch_returnPressed();
   void on_pbPrint_clicked();
   void on_pbReset_clicked();

};

#endif // FTCONTAINERS_OVERVIEW_H
