#ifndef FTSETTINGS_H
#define FTSETTINGS_H

#include <QWidget>

namespace Ui {
class FTSettings;
}

class FTSettings : public QWidget
{
    Q_OBJECT

public:
    explicit FTSettings(QWidget *parent = nullptr);
    ~FTSettings();

private slots:
    void on_pbSave_clicked();

    void on_pbClose_clicked();

private:
    Ui::FTSettings *ui;

signals:
    void setup_done();
};

#endif // FTSETTINGS_H
