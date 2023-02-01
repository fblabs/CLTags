/********************************************************************************
** Form generated from reading UI file 'ftcontainers_overview.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FTCONTAINERS_OVERVIEW_H
#define UI_FTCONTAINERS_OVERVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FtContainers_Overview
{
public:
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QTableView *tvOverview;
    QVBoxLayout *verticalLayout;
    QTableView *tvDetails;
    QHBoxLayout *horizontalLayout;
    QPushButton *pbModify;
    QPushButton *pbLoad;
    QPushButton *pbUnload;
    QPushButton *pbDelete;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pbClose;

    void setupUi(QWidget *FtContainers_Overview)
    {
        if (FtContainers_Overview->objectName().isEmpty())
            FtContainers_Overview->setObjectName(QString::fromUtf8("FtContainers_Overview"));
        FtContainers_Overview->setWindowModality(Qt::ApplicationModal);
        FtContainers_Overview->resize(1319, 485);
        verticalLayout_3 = new QVBoxLayout(FtContainers_Overview);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label = new QLabel(FtContainers_Overview);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_3->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tvOverview = new QTableView(FtContainers_Overview);
        tvOverview->setObjectName(QString::fromUtf8("tvOverview"));
        tvOverview->setMaximumSize(QSize(16777215, 16777215));
        tvOverview->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tvOverview->setSelectionMode(QAbstractItemView::SingleSelection);
        tvOverview->setSelectionBehavior(QAbstractItemView::SelectRows);
        tvOverview->horizontalHeader()->setStretchLastSection(true);
        tvOverview->verticalHeader()->setVisible(false);
        tvOverview->verticalHeader()->setHighlightSections(false);

        verticalLayout_2->addWidget(tvOverview);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tvDetails = new QTableView(FtContainers_Overview);
        tvDetails->setObjectName(QString::fromUtf8("tvDetails"));
        tvDetails->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tvDetails->setAlternatingRowColors(true);
        tvDetails->setSelectionMode(QAbstractItemView::SingleSelection);
        tvDetails->setSelectionBehavior(QAbstractItemView::SelectRows);
        tvDetails->horizontalHeader()->setStretchLastSection(true);
        tvDetails->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(tvDetails);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pbModify = new QPushButton(FtContainers_Overview);
        pbModify->setObjectName(QString::fromUtf8("pbModify"));
        pbModify->setMinimumSize(QSize(0, 0));
        pbModify->setMaximumSize(QSize(16777215, 16777215));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/icons/Pencil.PNG"), QSize(), QIcon::Normal, QIcon::Off);
        pbModify->setIcon(icon);
        pbModify->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(pbModify);

        pbLoad = new QPushButton(FtContainers_Overview);
        pbLoad->setObjectName(QString::fromUtf8("pbLoad"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/icons/Plus.PNG"), QSize(), QIcon::Normal, QIcon::Off);
        pbLoad->setIcon(icon1);
        pbLoad->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(pbLoad);

        pbUnload = new QPushButton(FtContainers_Overview);
        pbUnload->setObjectName(QString::fromUtf8("pbUnload"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resources/icons/Minus.PNG"), QSize(), QIcon::Normal, QIcon::Off);
        pbUnload->setIcon(icon2);
        pbUnload->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(pbUnload);

        pbDelete = new QPushButton(FtContainers_Overview);
        pbDelete->setObjectName(QString::fromUtf8("pbDelete"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/resources/icons/Flag-red64.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbDelete->setIcon(icon3);
        pbDelete->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(pbDelete);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        pbClose = new QPushButton(FtContainers_Overview);
        pbClose->setObjectName(QString::fromUtf8("pbClose"));
        pbClose->setMinimumSize(QSize(0, 0));
        pbClose->setMaximumSize(QSize(16777215, 16777215));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/resources/icons/Actions-window-close-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbClose->setIcon(icon4);
        pbClose->setIconSize(QSize(32, 32));

        horizontalLayout_5->addWidget(pbClose);


        verticalLayout_3->addLayout(horizontalLayout_5);


        retranslateUi(FtContainers_Overview);

        QMetaObject::connectSlotsByName(FtContainers_Overview);
    } // setupUi

    void retranslateUi(QWidget *FtContainers_Overview)
    {
        FtContainers_Overview->setWindowTitle(QCoreApplication::translate("FtContainers_Overview", "Panoramica Vasi e Tappi", nullptr));
        label->setText(QCoreApplication::translate("FtContainers_Overview", "Vasi- Tappi", nullptr));
#if QT_CONFIG(tooltip)
        pbModify->setToolTip(QCoreApplication::translate("FtContainers_Overview", "<html><head/><body><p>modifica operazione selezionata</p><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pbModify->setText(QCoreApplication::translate("FtContainers_Overview", "Modifica Operazione", nullptr));
        pbLoad->setText(QCoreApplication::translate("FtContainers_Overview", "Carico", nullptr));
        pbUnload->setText(QCoreApplication::translate("FtContainers_Overview", "Scarico", nullptr));
        pbDelete->setText(QCoreApplication::translate("FtContainers_Overview", "Elimina operazione", nullptr));
#if QT_CONFIG(tooltip)
        pbClose->setToolTip(QCoreApplication::translate("FtContainers_Overview", "<html><head/><body><p>Chiudi</p><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pbClose->setText(QCoreApplication::translate("FtContainers_Overview", "Chiudi", nullptr));
#if QT_CONFIG(shortcut)
        pbClose->setShortcut(QCoreApplication::translate("FtContainers_Overview", "Backspace, Backspace, Backspace", nullptr));
#endif // QT_CONFIG(shortcut)
    } // retranslateUi

};

namespace Ui {
    class FtContainers_Overview: public Ui_FtContainers_Overview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FTCONTAINERS_OVERVIEW_H
