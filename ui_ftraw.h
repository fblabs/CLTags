/********************************************************************************
** Form generated from reading UI file 'ftraw.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FTRAW_H
#define UI_FTRAW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FtRaw
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QDateEdit *deDal;
    QDateEdit *deAl;
    QRadioButton *rbLabels;
    QRadioButton *rbVases;
    QSpacerItem *horizontalSpacer;
    QTableView *tvRaw;
    QHBoxLayout *horizontalLayout;
    QPushButton *pbPrint;
    QPushButton *pbClose;

    void setupUi(QWidget *FtRaw)
    {
        if (FtRaw->objectName().isEmpty())
            FtRaw->setObjectName(QString::fromUtf8("FtRaw"));
        FtRaw->setWindowModality(Qt::ApplicationModal);
        FtRaw->resize(1122, 431);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/icons/8712509_chart_graph_diagram_report_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        FtRaw->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(FtRaw);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        deDal = new QDateEdit(FtRaw);
        deDal->setObjectName(QString::fromUtf8("deDal"));
        deDal->setCalendarPopup(true);

        horizontalLayout_2->addWidget(deDal);

        deAl = new QDateEdit(FtRaw);
        deAl->setObjectName(QString::fromUtf8("deAl"));
        deAl->setCalendarPopup(true);

        horizontalLayout_2->addWidget(deAl);

        rbLabels = new QRadioButton(FtRaw);
        rbLabels->setObjectName(QString::fromUtf8("rbLabels"));
        rbLabels->setChecked(true);

        horizontalLayout_2->addWidget(rbLabels);

        rbVases = new QRadioButton(FtRaw);
        rbVases->setObjectName(QString::fromUtf8("rbVases"));

        horizontalLayout_2->addWidget(rbVases);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);

        tvRaw = new QTableView(FtRaw);
        tvRaw->setObjectName(QString::fromUtf8("tvRaw"));
        tvRaw->setStyleSheet(QString::fromUtf8("selection-color: rgb(255, 255, 255);\n"
"selection-background-color: rgb(0, 85, 255);"));
        tvRaw->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tvRaw->setAlternatingRowColors(true);
        tvRaw->setSelectionMode(QAbstractItemView::SingleSelection);
        tvRaw->setSelectionBehavior(QAbstractItemView::SelectRows);
        tvRaw->setSortingEnabled(false);
        tvRaw->horizontalHeader()->setCascadingSectionResizes(true);
        tvRaw->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(tvRaw);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pbPrint = new QPushButton(FtRaw);
        pbPrint->setObjectName(QString::fromUtf8("pbPrint"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/icons/print-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbPrint->setIcon(icon1);
        pbPrint->setIconSize(QSize(48, 48));

        horizontalLayout->addWidget(pbPrint);

        pbClose = new QPushButton(FtRaw);
        pbClose->setObjectName(QString::fromUtf8("pbClose"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resources/icons/Actions-window-close-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbClose->setIcon(icon2);
        pbClose->setIconSize(QSize(48, 48));

        horizontalLayout->addWidget(pbClose);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(FtRaw);

        QMetaObject::connectSlotsByName(FtRaw);
    } // setupUi

    void retranslateUi(QWidget *FtRaw)
    {
        FtRaw->setWindowTitle(QCoreApplication::translate("FtRaw", "Panoramica movimenti", nullptr));
        rbLabels->setText(QCoreApplication::translate("FtRaw", "Etichette e sigilli", nullptr));
        rbVases->setText(QCoreApplication::translate("FtRaw", "vasi e tappi", nullptr));
        pbPrint->setText(QCoreApplication::translate("FtRaw", "Stampa", nullptr));
        pbClose->setText(QCoreApplication::translate("FtRaw", "Chiudi", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FtRaw: public Ui_FtRaw {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FTRAW_H
