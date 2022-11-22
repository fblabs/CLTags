#ifndef FTCONTAINERS_OVERVIEW_H
#define FTCONTAINERS_OVERVIEW_H

#include <QWidget>
#include <QSqlDatabase>

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
private slots:
   void getContainers();
   void getContainerOperations();
   void on_pbClose_clicked();
   void on_pbModify_clicked();
   void on_pbLoad_clicked();
   void on_pbUnload_clicked();
   void modify_tag();
   void update_data();
};

#endif // FTCONTAINERS_OVERVIEW_H
