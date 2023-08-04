
#ifndef HCONTAINERSTABLEMODEL_H
#define HCONTAINERSTABLEMODEL_H

#include <QSqlQueryModel>

#include <QObject>


class HContainersTableModel : public QSqlQueryModel
{
    Q_OBJECT
public:
    explicit HContainersTableModel(QObject *parent = nullptr);
    QVariant data(const QModelIndex &index, int role) const;
    QModelIndex ix;
    int giacenza;
};

#endif // HCONTAINERSTABLEMODEL_H
