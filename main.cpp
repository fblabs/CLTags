#include "mainwindow.h"

#include <QApplication>
#include <QSqlDatabase>
#include <QDebug>
#include <QSettings>
#include "ftsettings.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);



        MainWindow w;
        w.show();






    return a.exec();

}
