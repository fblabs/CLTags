#ifndef FTOPERATE_H
#define FTOPERATE_H

#include <QWidget>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlTableModel>

namespace Ui {
class FTOperate;
}

class FTOperate : public QWidget
{
    Q_OBJECT

public:
    explicit FTOperate(const int p_action=-1, const int p_id_tag=-1, QSqlDatabase pdb=QSqlDatabase(), QWidget *parent = nullptr);
    ~FTOperate();

private:
    Ui::FTOperate *ui;
    QSqlDatabase db;
    int id_tag;
    QSqlQueryModel *modbarcodes;
    QSqlTableModel *modstampatori;
    QSqlTableModel *modtipi;
    int action;
    void populate();

private slots:
    void setup();
    void saveOp();
    void on_pbSave_clicked();
    void on_pbClose_clicked();
    void on_rbCarico_toggled(bool checked);
    void chooseImage();
    void on_pbBolla_clicked();
    void showImage(const QString path);
protected:
    bool eventFilter(QObject *obj, QEvent *evt);

signals:
    void operation_saved();
    void imageClicked(const QString path);


};

#endif // FTOPERATE_H
