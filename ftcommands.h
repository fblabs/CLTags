#ifndef FTCOMMANDS_H
#define FTCOMMANDS_H

#include <QDialog>
#include <QSqlDatabase>

namespace Ui {
class FtCommands;
}

class FtCommands : public QDialog
{
    Q_OBJECT

public:
    explicit FtCommands(int p_id_tag=-1, QSqlDatabase pdb=QSqlDatabase(), QWidget *parent = nullptr);
    ~FtCommands();

private slots:
    void on_pbOverview_clicked();

    void on_pbMov_clicked();

    void on_FtCommands_accepted();

    void on_pbClose_clicked();

private: signals:

    void sig_close();


private:
    Ui::FtCommands *ui;
    int id_tag;
    QSqlDatabase db;
};

#endif // FTCOMMANDS_H
