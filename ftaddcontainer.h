#ifndef FTADDCONTAINER_H
#define FTADDCONTAINER_H

#include <QWidget>
#include <QSqlDatabase>

namespace Ui {
class FtAddContainer;
}

class FtAddContainer : public QWidget
{
    Q_OBJECT

public:
    explicit FtAddContainer(QSqlDatabase pdb=QSqlDatabase(),QWidget *parent = nullptr);
    ~FtAddContainer();

private:
    Ui::FtAddContainer *ui;
    QSqlDatabase db;

private slots:
    void get_products_to_add(const int type=-1);
    void add_containers();
    void on_pbClose_clicked();
signals:
    void sg_done();
};

#endif // FTADDCONTAINER_H
