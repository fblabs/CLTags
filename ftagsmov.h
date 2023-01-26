#ifndef FTAGSMOV_H
#define FTAGSMOV_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlTableModel>


namespace Ui {
class FTagsMov;
}

class FTagsMov : public QWidget
{
    Q_OBJECT

public:
    explicit FTagsMov(const int pazione=0, const QString pbarcode=QString(), const QString pidprodotto=QString(), QSqlDatabase pdb=QSqlDatabase(), QWidget *parent = nullptr);
    ~FTagsMov();

private slots:
    void on_pbClose_clicked();

    void on_cbClienti_currentIndexChanged(int index);

    void on_pbSave_clicked();

    void setup();
    void getProdotti(int pidcliente=0);
    void save();
    void chooseImage();
    void img_reset();

    void refresh();

    void on_pbChooseImage_clicked();

    void on_rb1_toggled(bool checked);

    void on_rb2_toggled(bool checked);

    void on_rbAll_toggled(bool checked);

    void on_pbMov_clicked();

    void on_cbGenericProduct_toggled(bool checked);

    void on_pbReset_clicked();

    void showImage(const QString path);

    void resetUI();

    void setBarcode(const QString pbarcode);


    void on_pbNew_clicked();

private:
    Ui::FTagsMov *ui;
    QSqlDatabase db;
    QSqlQueryModel *modprodotti;
    QSqlTableModel *modclienti;
    QSqlTableModel *modtipi;
    QSqlTableModel *modstampatori;
    QSqlTableModel *modbarcodes;
    QSqlTableModel *modazioni;
    int azione;
    QString barcode,descprod;
    QStringList sl_immagini;
    QString separator;
    QString s_images;
    int GENERIC_CUSTOMER;
    int GENERIC_PRODUCT;
protected:
     bool eventFilter(QObject *obj, QEvent *evt);



signals:
  void  tag_saved();
  void refresh_img();
  void imageClicked(const QString path);



};

#endif // FTAGSMOV_H
