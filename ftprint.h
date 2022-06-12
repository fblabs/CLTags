#ifndef FTPRINT_H
#define FTPRINT_H

#include <QWidget>
#include <QAbstractItemModel>

namespace Ui {
class FTPrint;
}

class FTPrint : public QWidget
{
    Q_OBJECT

public:
    explicit FTPrint(QAbstractItemModel *pmod=nullptr, QString ptitle=QString(), QStringList pcolnames=QStringList(), QList<int> phiddencols=QList<int>(), QWidget *parent = nullptr);
    ~FTPrint();

private:
    Ui::FTPrint *ui;
    QAbstractItemModel *mod;
private slots:
    void modelToHtml(QString ptitle=QString(),QStringList pcolNames=QStringList(),QList<int>hiddenCols=QList<int>());

    void print();

    void on_pbPrint_clicked();
    void on_pbClose_clicked();
};

#endif // FTPRINT_H
