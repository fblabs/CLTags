#ifndef FTAGSSTOCK_H
#define FTAGSSTOCK_H

#include <QWidget>

namespace Ui {
class FTagsStock;
}

class FTagsStock : public QWidget
{
    Q_OBJECT

public:
    explicit FTagsStock(QWidget *parent = nullptr);
    ~FTagsStock();

private slots:
    void setup();
    void on_pushButton_clicked();

private:
    Ui::FTagsStock *ui;
};

#endif // FTAGSSTOCK_H
