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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FtContainers_Overview
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *leSearch;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QDateEdit *deDal;
    QLabel *label_3;
    QDateEdit *deAl;
    QPushButton *pbReset;
    QCheckBox *cbAttivi;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QTableView *tvOverview;
    QTableView *tvDetails;
    QHBoxLayout *horizontalLayout;
    QPushButton *pbAddContainer;
    QPushButton *pbModify;
    QPushButton *pbLoad;
    QPushButton *pbUnload;
    QPushButton *pbDelete;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pbPrint;
    QPushButton *pbClose;

    void setupUi(QWidget *FtContainers_Overview)
    {
        if (FtContainers_Overview->objectName().isEmpty())
            FtContainers_Overview->setObjectName(QString::fromUtf8("FtContainers_Overview"));
        FtContainers_Overview->setWindowModality(Qt::ApplicationModal);
        FtContainers_Overview->resize(1319, 485);
        verticalLayout = new QVBoxLayout(FtContainers_Overview);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(FtContainers_Overview);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        leSearch = new QLineEdit(FtContainers_Overview);
        leSearch->setObjectName(QString::fromUtf8("leSearch"));

        gridLayout->addWidget(leSearch, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        label_2 = new QLabel(FtContainers_Overview);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 3, 1, 1);

        deDal = new QDateEdit(FtContainers_Overview);
        deDal->setObjectName(QString::fromUtf8("deDal"));
        deDal->setMinimumSize(QSize(200, 0));
        deDal->setCalendarPopup(true);

        gridLayout->addWidget(deDal, 0, 4, 1, 1);

        label_3 = new QLabel(FtContainers_Overview);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 5, 1, 1);

        deAl = new QDateEdit(FtContainers_Overview);
        deAl->setObjectName(QString::fromUtf8("deAl"));
        deAl->setMinimumSize(QSize(200, 0));
        deAl->setMaximumSize(QSize(16777215, 16777215));
        deAl->setCalendarPopup(true);

        gridLayout->addWidget(deAl, 0, 6, 1, 1);

        pbReset = new QPushButton(FtContainers_Overview);
        pbReset->setObjectName(QString::fromUtf8("pbReset"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/icons/Counterclockwise-arrow64.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbReset->setIcon(icon);

        gridLayout->addWidget(pbReset, 0, 7, 1, 1);

        cbAttivi = new QCheckBox(FtContainers_Overview);
        cbAttivi->setObjectName(QString::fromUtf8("cbAttivi"));
        cbAttivi->setChecked(true);

        gridLayout->addWidget(cbAttivi, 0, 8, 1, 1);


        verticalLayout->addLayout(gridLayout);

        splitter = new QSplitter(FtContainers_Overview);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        tvOverview = new QTableView(layoutWidget);
        tvOverview->setObjectName(QString::fromUtf8("tvOverview"));
        tvOverview->setMaximumSize(QSize(16777215, 16777215));
        tvOverview->setStyleSheet(QString::fromUtf8("selection-color: rgb(255, 255, 255);\n"
"selection-background-color: rgb(85, 85, 255);"));
        tvOverview->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tvOverview->setSelectionMode(QAbstractItemView::SingleSelection);
        tvOverview->setSelectionBehavior(QAbstractItemView::SelectRows);
        tvOverview->horizontalHeader()->setStretchLastSection(true);
        tvOverview->verticalHeader()->setVisible(false);
        tvOverview->verticalHeader()->setHighlightSections(false);

        verticalLayout_2->addWidget(tvOverview);

        splitter->addWidget(layoutWidget);
        tvDetails = new QTableView(splitter);
        tvDetails->setObjectName(QString::fromUtf8("tvDetails"));
        tvDetails->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tvDetails->setAlternatingRowColors(true);
        tvDetails->setSelectionMode(QAbstractItemView::SingleSelection);
        tvDetails->setSelectionBehavior(QAbstractItemView::SelectRows);
        splitter->addWidget(tvDetails);
        tvDetails->horizontalHeader()->setStretchLastSection(true);
        tvDetails->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(splitter);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pbAddContainer = new QPushButton(FtContainers_Overview);
        pbAddContainer->setObjectName(QString::fromUtf8("pbAddContainer"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/icons/App-ark-2-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbAddContainer->setIcon(icon1);
        pbAddContainer->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(pbAddContainer);

        pbModify = new QPushButton(FtContainers_Overview);
        pbModify->setObjectName(QString::fromUtf8("pbModify"));
        pbModify->setMinimumSize(QSize(0, 0));
        pbModify->setMaximumSize(QSize(16777215, 16777215));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resources/icons/Pencil.PNG"), QSize(), QIcon::Normal, QIcon::Off);
        pbModify->setIcon(icon2);
        pbModify->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(pbModify);

        pbLoad = new QPushButton(FtContainers_Overview);
        pbLoad->setObjectName(QString::fromUtf8("pbLoad"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/resources/icons/Plus.PNG"), QSize(), QIcon::Normal, QIcon::Off);
        pbLoad->setIcon(icon3);
        pbLoad->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(pbLoad);

        pbUnload = new QPushButton(FtContainers_Overview);
        pbUnload->setObjectName(QString::fromUtf8("pbUnload"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/resources/icons/Minus.PNG"), QSize(), QIcon::Normal, QIcon::Off);
        pbUnload->setIcon(icon4);
        pbUnload->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(pbUnload);

        pbDelete = new QPushButton(FtContainers_Overview);
        pbDelete->setObjectName(QString::fromUtf8("pbDelete"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/resources/icons/Flag-red64.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbDelete->setIcon(icon5);
        pbDelete->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(pbDelete);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        pbPrint = new QPushButton(FtContainers_Overview);
        pbPrint->setObjectName(QString::fromUtf8("pbPrint"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/resources/icons/print-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbPrint->setIcon(icon6);
        pbPrint->setIconSize(QSize(32, 32));

        horizontalLayout_5->addWidget(pbPrint);

        pbClose = new QPushButton(FtContainers_Overview);
        pbClose->setObjectName(QString::fromUtf8("pbClose"));
        pbClose->setMinimumSize(QSize(0, 0));
        pbClose->setMaximumSize(QSize(16777215, 16777215));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/resources/icons/Actions-window-close-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbClose->setIcon(icon7);
        pbClose->setIconSize(QSize(32, 32));

        horizontalLayout_5->addWidget(pbClose);


        verticalLayout->addLayout(horizontalLayout_5);


        retranslateUi(FtContainers_Overview);

        QMetaObject::connectSlotsByName(FtContainers_Overview);
    } // setupUi

    void retranslateUi(QWidget *FtContainers_Overview)
    {
        FtContainers_Overview->setWindowTitle(QCoreApplication::translate("FtContainers_Overview", "Panoramica Vasi e Tappi", nullptr));
        label->setText(QCoreApplication::translate("FtContainers_Overview", "Cerca:", nullptr));
        label_2->setText(QCoreApplication::translate("FtContainers_Overview", "Tra il:", nullptr));
        label_3->setText(QCoreApplication::translate("FtContainers_Overview", "e il:", nullptr));
        pbReset->setText(QCoreApplication::translate("FtContainers_Overview", "Reset", nullptr));
        cbAttivi->setText(QCoreApplication::translate("FtContainers_Overview", "Attivi", nullptr));
        pbAddContainer->setText(QCoreApplication::translate("FtContainers_Overview", "Aggiungi", nullptr));
#if QT_CONFIG(tooltip)
        pbModify->setToolTip(QCoreApplication::translate("FtContainers_Overview", "<html><head/><body><p>modifica operazione selezionata</p><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pbModify->setText(QCoreApplication::translate("FtContainers_Overview", "Modifica Operazione", nullptr));
        pbLoad->setText(QCoreApplication::translate("FtContainers_Overview", "Carico", nullptr));
        pbUnload->setText(QCoreApplication::translate("FtContainers_Overview", "Scarico", nullptr));
        pbDelete->setText(QCoreApplication::translate("FtContainers_Overview", "Elimina operazione", nullptr));
        pbPrint->setText(QCoreApplication::translate("FtContainers_Overview", "Stampa", nullptr));
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
