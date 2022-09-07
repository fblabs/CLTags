#ifndef FTMODMOV_H
#define FTMODMOV_H

#include <QWidget>
#include <QSqlDatabase>

namespace Ui {
class FTModMov;
}

class FTModMov : public QWidget
{
    Q_OBJECT

public:
    explicit FTModMov(int pid=0, QSqlDatabase pdb=QSqlDatabase(), QString ptitle=QString(), QWidget *parent = nullptr);
    ~FTModMov();

private:
    Ui::FTModMov *ui;
    QSqlDatabase db;
    int id;
    int action;

private slots:
    void setup();
    void on_pbCancel_clicked();
    void save();
    void on_pbSave_clicked();

signals:
    void mod_mov_done();
};

#endif // FTMODMOV_H
