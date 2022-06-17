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

private:
    Ui::FTImage *ui;
signals:
    void transfer_Barcode(const QString pBarcode);
};

#endif // FTIMAGE_H
