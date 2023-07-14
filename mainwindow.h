#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
       void on_pbExit_clicked();

    //   void on_pbMov_clicked();

    //   void on_pbOverview_clicked();

       void readSettings();

       void setup();

       void on_pbLabels_clicked();

       void on_pbSettings_clicked();

       void on_pbContainers_clicked();

       void on_pbRaw_clicked();

   private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QString server;
    QString pwd;
    int generic_customer_id;

};
#endif // MAINWINDOW_H
