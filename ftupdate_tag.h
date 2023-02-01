#ifndef FTUPDATE_TAG_H
#define FTUPDATE_TAG_H

#include <QWidget>
#include <QSqlDatabase>

namespace Ui {
class FtUpdate_Tag;
}

class FtUpdate_Tag : public QWidget
{
    Q_OBJECT

public:
    explicit FtUpdate_Tag(const int p_id_tag,QSqlDatabase p_db=QSqlDatabase(), QWidget *parent = nullptr);
    ~FtUpdate_Tag();

private:
    Ui::FtUpdate_Tag *ui;
    QSqlDatabase db;
    int id_tag;
private slots:
    void populate();
    void save();
    void on_pbSave_clicked();

    void on_pbClose_clicked();

signals:
    void container_updated();
};

#endif // FTUPDATE_TAG_H
