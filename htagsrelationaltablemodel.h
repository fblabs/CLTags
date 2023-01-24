#ifndef HTAGSRELATIONALTABLEMODEL_H
#define HTAGSRELATIONALTABLEMODEL_H

#include <QSqlRelationalTableModel>
#include <QObject>

class HTagsRelationalTableModel : public QSqlRelationalTableModel
{
    Q_OBJECT
public:
    explicit HTagsRelationalTableModel(QObject *parent = nullptr);
    QVariant data(const QModelIndex &index, int role) const;
    QModelIndex ix;
    int giacenza;
};

#endif // HTAGSRELATIONALTABLEMODEL_H
