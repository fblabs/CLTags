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

  const QModelIndex ix=item.model()->index(item.row(),7);
  const QModelIndex igm=item.model()->index(item.row(),10);

    bool ok=false;

    if(role==Qt::BackgroundRole && ix.data(0).toInt(&ok)<igm.data(0).toInt())
  {
        if(ok){
        return QColor(Qt::yellow);
        }

  }

    if(role==Qt::BackgroundRole &&  ix.data(0).toInt()<igm.data(0).toInt())
  {
      return QColor(Qt::red);
  }

  if(role==Qt::ForegroundRole && ix.data(0).toInt()<igm.data(0).toInt())
  {
     return QColor(Qt::darkRed);
  }



  return QSqlRelationalTableModel::data(item, role);


}
