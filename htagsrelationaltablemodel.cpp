#include "htagsrelationaltablemodel.h"
#include <QColor>

#include <QSqlRecord>
#include <QDebug>

HTagsRelationalTableModel::HTagsRelationalTableModel(QObject *parent)
    : QSqlRelationalTableModel{parent}
{

}

QVariant HTagsRelationalTableModel::data(const QModelIndex &item, int role) const
{

  const QModelIndex ix=item.model()->index(item.row(),6);

 /* if(role==Qt::BackgroundRole && ix.data(0).toInt()==0)
  {
       return QColor(Qt::yellow);

  }*/

  if(role==Qt::ForegroundRole && ix.data(0).toInt()<0)
  {
     return QColor(Qt::red);
  }

  return QSqlQueryModel::data(item, role);


}
