#ifndef FTIMAGE_H
#define FTIMAGE_H

#include <QWidget>

namespace Ui {
class FTImage;
}

class FTImage : public QWidget
{
    Q_OBJECT

public:
    explicit FTImage(const QString filename=QString(), QWidget *parent = nullptr);
    ~FTImage();

private slots:
    void on_pbClose_clicked();

    void on_pbCloseWindoiw_clicked();

    void on_pbPrint_clicked();

    void printImage();
    void closeWindow();


private:
    Ui::FTImage *ui;
protected:
    bool eventFilter(QObject *obj, QEvent *evt);
signals:
    void transfer_Barcode(const QString pBarcode);
    void imageclicked();
};

#endif // FTIMAGE_H
