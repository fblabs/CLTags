#ifndef FTOVERVIEW_H
#define FTOVERVIEW_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include <QCompleter>

namespace Ui {
class FTOverview;
}

class FTOverview : public QWidget
{
    Q_OBJECT

public:
    explicit FTOverview(QSqlDatabase pdb,QWidget *parent = nullptr);
    ~FTOverview();

private:
    Ui::FTOverview *ui;
    QSqlDatabase db;
    QSqlRelationalTableModel *tagsmod;
    QSqlQueryModel *tagsmovmod;
    QSqlTableModel *clientimod;
    QSqlQueryModel *prodottimod;
    QCompleter *clcomp;
    QCompleter *prcomp;
    int GENERIC_CUSTOMER;
    int GENERIC_PRODUCT;

private slots:
   void setup();
   void findTagsMov();
   void refresh();

   void on_pbClose_clicked();
   void on_pbOperate_clicked();
   void on_pbDefinizioni_clicked();
   void on_tvTags_doubleClicked(const QModelIndex &index);

  // void on_leCliente_returnPressed();

   void on_pbModTag_clicked();
   void on_tvTags_mov_doubleClicked(const QModelIndex &index);
   void on_pbPrint_clicked();
   void on_pushButton_clicked();
   void getProdotti(int client_id=0);


   void on_pbNoFilters_clicked();



   void buildFilter();
   void on_cbCliente_currentIndexChanged(int index);
   void on_pbFilter_clicked();


   void on_leBarcode_returnPressed();
};

#endif // FTOVERVIEW_H
