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
    void chooseImage();


    void on_rbCarico_toggled(bool checked);

    void on_pbImg_clicked();
    void showImage(const QString path);

protected:
    bool eventFilter(QObject *obj, QEvent *evt);

signals:
    void mod_mov_done();
    void imageClicked(const QString path);
};

#endif // FTMODMOV_H
