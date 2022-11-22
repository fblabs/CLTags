/********************************************************************************
** Form generated from reading UI file 'ftcommands.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FTCOMMANDS_H
#define UI_FTCOMMANDS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_FtCommands
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pbOverview;
    QPushButton *pbMov;
    QPushButton *pbClose;

    void setupUi(QDialog *FtCommands)
    {
        if (FtCommands->objectName().isEmpty())
            FtCommands->setObjectName(QString::fromUtf8("FtCommands"));
        FtCommands->setWindowModality(Qt::ApplicationModal);
        FtCommands->resize(244, 86);
        verticalLayout = new QVBoxLayout(FtCommands);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pbOverview = new QPushButton(FtCommands);
        pbOverview->setObjectName(QString::fromUtf8("pbOverview"));
        pbOverview->setMinimumSize(QSize(50, 50));
        pbOverview->setMaximumSize(QSize(50, 50));
        pbOverview->setAutoFillBackground(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/icons/8644322_graphic_chart_graph_bam_icon (1).png"), QSize(), QIcon::Normal, QIcon::Off);
        pbOverview->setIcon(icon);
        pbOverview->setIconSize(QSize(64, 64));
        pbOverview->setFlat(true);

        horizontalLayout->addWidget(pbOverview);

        pbMov = new QPushButton(FtCommands);
        pbMov->setObjectName(QString::fromUtf8("pbMov"));
        pbMov->setMinimumSize(QSize(0, 50));
        pbMov->setMaximumSize(QSize(50, 50));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/icons/7627459_app_tools_logo_apple_reminders_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbMov->setIcon(icon1);
        pbMov->setIconSize(QSize(48, 48));
        pbMov->setFlat(true);

        horizontalLayout->addWidget(pbMov);

        pbClose = new QPushButton(FtCommands);
        pbClose->setObjectName(QString::fromUtf8("pbClose"));
        pbClose->setMinimumSize(QSize(65, 65));
        pbClose->setMaximumSize(QSize(65, 65));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resources/icons/Actions-window-close-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbClose->setIcon(icon2);
        pbClose->setIconSize(QSize(48, 48));
        pbClose->setFlat(true);

        horizontalLayout->addWidget(pbClose);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(FtCommands);

        QMetaObject::connectSlotsByName(FtCommands);
    } // setupUi

    void retranslateUi(QDialog *FtCommands)
    {
        FtCommands->setWindowTitle(QCoreApplication::translate("FtCommands", "Dialog", nullptr));
#if QT_CONFIG(tooltip)
        FtCommands->setToolTip(QCoreApplication::translate("FtCommands", "Definizioni", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        pbOverview->setToolTip(QCoreApplication::translate("FtCommands", "Vista panoramica", nullptr));
#endif // QT_CONFIG(tooltip)
        pbOverview->setText(QString());
        pbMov->setText(QString());
#if QT_CONFIG(tooltip)
        pbClose->setToolTip(QCoreApplication::translate("FtCommands", "<html><head/><body><p>Chiudi</p><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
    } // retranslateUi

};

namespace Ui {
    class FtCommands: public Ui_FtCommands {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FTCOMMANDS_H
