
#include "hcontainerstablemodel.h"

#include <QColor>

#include <QSqlRecord>
#include <QDebug>

HContainersTableModel::HContainersTableModel(QObject *parent)
    : QSqlQueryModel{parent}
{

}

QVariant HContainersTableModel::data(const QModelIndex &item, int role) const
{

    const QModelIndex ix=item.model()->index(item.row(),3);
    const QModelIndex igm=item.model()->index(item.row(),5);

  //  bool ok=false;

    if(role==Qt::BackgroundRole && ix.data(0).toInt()<igm.data(0).toInt())
    {
     //  if(ok){
            return QColor(Qt::yellow);
     //   }

    }

    if(role==Qt::BackgroundRole &&  ix.data(0).toInt()<igm.data(0).toInt())
    {
        return QColor(Qt::red);
    }

    if(role==Qt::ForegroundRole && ix.data(0).toInt()<igm.data(0).toInt())
    {
        return QColor(Qt::darkRed);
    }



    return QSqlQueryModel::data(item, role);


}


