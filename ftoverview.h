#ifndef FTOVERVIEW_H
#define FTOVERVIEW_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include <QCompleter>
#include "htagsrelationaltablemodel.h"

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
    HTagsRelationalTableModel *tagsmod;
    QSqlQueryModel *tagsmovmod;
    QSqlTableModel *clientimod;
    QSqlQueryModel *prodottimod;
    QCompleter *clcomp;
    QCompleter *prcomp;
    int current_tag_id;
    int GENERIC_CUSTOMER;
    int GENERIC_PRODUCT;

private slots:
    void setup();
    void findTagsMov();
    void refresh();
    void mod_mov(const QModelIndex index);
    void mod_tag(const QModelIndex index);
    bool deleteOperation();
    HTagsRelationalTableModel *buildModel();

    void on_pbClose_clicked();
    void on_pbOperate_clicked();
    void on_pbDefinizioni_clicked();
    void on_tvTags_doubleClicked(const QModelIndex &index);
    // void on_leCliente_returnPressed();
    void on_pbModTag_clicked();
    void on_tvTags_mov_doubleClicked(const QModelIndex &index);
    void on_pbPrint_clicked();
    void getProdotti(int client_id=0);
    void on_pbNoFilters_clicked();
    QString buildFilter();
    void on_cbCliente_currentIndexChanged(int index);
    void on_pbFilter_clicked();
    void on_cbAttivi_toggled(bool checked);
    void on_pb_Scarico_clicked();
    void on_rbLabels_toggled(bool checked);
    void on_rbCust_toggled(bool checked);
    void on_rbAnyProd_toggled(bool checked);
    void on_rbNoCust_toggled(bool checked);
    void on_rbSigilli_toggled(bool checked);
    void on_rbNoProd_toggled(bool checked);
    void on_cbProdotto_currentIndexChanged(int index);
    void on_pbDEleteOperation_clicked();
    void on_pbModifyOperation_clicked();
    void on_leBarcode_returnPressed();

signals:
    void mov_deleted();
};

#endif // FTOVERVIEW_H
