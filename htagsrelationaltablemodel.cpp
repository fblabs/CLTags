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

    bool ok=false;

  if(role==Qt::BackgroundRole && ix.data(0).toInt(&ok)==0)
  {
        if(ok){
        return QColor(Qt::yellow);
        }

  }

  if(role==Qt::BackgroundRole &&  ix.data(0).toInt()<0)
  {
      return QColor(Qt::red);
  }

 /* if(role==Qt::ForegroundRole && ix.data(0).toInt()==0)
  {
      return QColor(Qt::magenta);
  }*/

  if(role==Qt::ForegroundRole && ix.data(0).toInt()==0)
  {
     return QColor(Qt::red);
  }



  return QSqlRelationalTableModel::data(item, role);


}
