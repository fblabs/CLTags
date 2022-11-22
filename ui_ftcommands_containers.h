/********************************************************************************
** Form generated from reading UI file 'ftcommands_containers.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FTCOMMANDS_CONTAINERS_H
#define UI_FTCOMMANDS_CONTAINERS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FtCommands_Containers
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pbContainersOverview;
    QPushButton *pbLoad;
    QPushButton *pbUnload;
    QPushButton *pbClose;

    void setupUi(QWidget *FtCommands_Containers)
    {
        if (FtCommands_Containers->objectName().isEmpty())
            FtCommands_Containers->setObjectName(QString::fromUtf8("FtCommands_Containers"));
        FtCommands_Containers->setWindowModality(Qt::ApplicationModal);
        FtCommands_Containers->resize(454, 66);
        verticalLayout = new QVBoxLayout(FtCommands_Containers);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pbContainersOverview = new QPushButton(FtCommands_Containers);
        pbContainersOverview->setObjectName(QString::fromUtf8("pbContainersOverview"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/icons/8644322_graphic_chart_graph_bam_icon (1).png"), QSize(), QIcon::Normal, QIcon::Off);
        pbContainersOverview->setIcon(icon);
        pbContainersOverview->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(pbContainersOverview);

        pbLoad = new QPushButton(FtCommands_Containers);
        pbLoad->setObjectName(QString::fromUtf8("pbLoad"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/icons/Plus.PNG"), QSize(), QIcon::Normal, QIcon::Off);
        pbLoad->setIcon(icon1);
        pbLoad->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(pbLoad);

        pbUnload = new QPushButton(FtCommands_Containers);
        pbUnload->setObjectName(QString::fromUtf8("pbUnload"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resources/icons/Minus.PNG"), QSize(), QIcon::Normal, QIcon::Off);
        pbUnload->setIcon(icon2);
        pbUnload->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(pbUnload);

        pbClose = new QPushButton(FtCommands_Containers);
        pbClose->setObjectName(QString::fromUtf8("pbClose"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/resources/icons/Actions-window-close-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbClose->setIcon(icon3);
        pbClose->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(pbClose);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(FtCommands_Containers);

        QMetaObject::connectSlotsByName(FtCommands_Containers);
    } // setupUi

    void retranslateUi(QWidget *FtCommands_Containers)
    {
        FtCommands_Containers->setWindowTitle(QCoreApplication::translate("FtCommands_Containers", "Form", nullptr));
        pbContainersOverview->setText(QCoreApplication::translate("FtCommands_Containers", "Panoramica", nullptr));
        pbLoad->setText(QCoreApplication::translate("FtCommands_Containers", "Carico", nullptr));
        pbUnload->setText(QCoreApplication::translate("FtCommands_Containers", "Scatico", nullptr));
        pbClose->setText(QCoreApplication::translate("FtCommands_Containers", "Chiudi", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FtCommands_Containers: public Ui_FtCommands_Containers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FTCOMMANDS_CONTAINERS_H
