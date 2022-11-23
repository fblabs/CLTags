#ifndef FTCOMMANDS_CONTAINERS_H
#define FTCOMMANDS_CONTAINERS_H

#include <QWidget>
#include <QSqlDatabase>

namespace Ui {
class FtCommands_Containers;
}

class FtCommands_Containers : public QWidget
{
    Q_OBJECT

public:
    explicit FtCommands_Containers(int pid_tag=-1,QSqlDatabase pdb=QSqlDatabase(),QWidget *parent = nullptr);
    ~FtCommands_Containers();

private slots:
    void on_pbLoad_clicked();

    void on_pbUnload_clicked();

    void on_pbContainersOverview_clicked();

    void on_pbClose_clicked();

private:
    Ui::FtCommands_Containers *ui;
    QSqlDatabase db;
    int pidtag;
};

#endif // FTCOMMANDS_CONTAINERS_H
