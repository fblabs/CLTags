/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pbOverview;
    QPushButton *pbMov;
    QPushButton *pbExit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1265, 660);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/icons/fblabs.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8("background-image: url(:/resources/icons/grey.png);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(300, 300));
        label->setMaximumSize(QSize(300, 300));
        label->setPixmap(QPixmap(QString::fromUtf8(":/resources/icons/fblabs.png")));
        label->setScaledContents(true);

        horizontalLayout_2->addWidget(label);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font;
        font.setFamily(QString::fromUtf8("Palatino Linotype"));
        font.setPointSize(72);
        font.setBold(true);
        font.setItalic(false);
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_2->setScaledContents(true);

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(50, 50));
        pushButton->setMaximumSize(QSize(50, 50));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/icons/8712748_setting_iso_premium_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);
        pushButton->setIconSize(QSize(64, 64));
        pushButton->setFlat(true);

        horizontalLayout->addWidget(pushButton);

        pbOverview = new QPushButton(centralwidget);
        pbOverview->setObjectName(QString::fromUtf8("pbOverview"));
        pbOverview->setMinimumSize(QSize(50, 50));
        pbOverview->setMaximumSize(QSize(50, 50));
        pbOverview->setAutoFillBackground(false);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resources/icons/8644322_graphic_chart_graph_bam_icon (1).png"), QSize(), QIcon::Normal, QIcon::Off);
        pbOverview->setIcon(icon2);
        pbOverview->setIconSize(QSize(64, 64));
        pbOverview->setFlat(true);

        horizontalLayout->addWidget(pbOverview);

        pbMov = new QPushButton(centralwidget);
        pbMov->setObjectName(QString::fromUtf8("pbMov"));
        pbMov->setMinimumSize(QSize(0, 50));
        pbMov->setMaximumSize(QSize(50, 50));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/resources/icons/7627459_app_tools_logo_apple_reminders_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbMov->setIcon(icon3);
        pbMov->setIconSize(QSize(48, 48));
        pbMov->setFlat(true);

        horizontalLayout->addWidget(pbMov);

        pbExit = new QPushButton(centralwidget);
        pbExit->setObjectName(QString::fromUtf8("pbExit"));
        pbExit->setMinimumSize(QSize(100, 65));
        pbExit->setMaximumSize(QSize(100, 65));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/resources/icons/8712836_fire_iso_premium_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbExit->setIcon(icon4);
        pbExit->setIconSize(QSize(65, 65));
        pbExit->setFlat(true);

        horizontalLayout->addWidget(pbExit);


        verticalLayout->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "CLTags", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>CLTags <span style=\" font-size:20pt;\">1.0.</span><span style=\" font-size:12pt;\">003</span></p></body></html>", nullptr));
        pushButton->setText(QString());
        pbOverview->setText(QString());
        pbMov->setText(QString());
        pbExit->setText(QCoreApplication::translate("MainWindow", "ESci", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
