/********************************************************************************
** Form generated from reading UI file 'ftoverview.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FTOVERVIEW_H
#define UI_FTOVERVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FTOverview
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *rbLabels;
    QRadioButton *rbSigilli;
    QRadioButton *rbBarcode;
    QLineEdit *leBarcode;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *rbCust;
    QRadioButton *rbNoCust;
    QComboBox *cbCliente;
    QVBoxLayout *verticalLayout;
    QRadioButton *rbAnyProd;
    QRadioButton *rbNoProd;
    QComboBox *cbProdotto;
    QFrame *line_2;
    QPushButton *pbFilter;
    QPushButton *pbNoFilters;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QTableView *tvTags;
    QTableView *tvTags_mov;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pbDefinizioni;
    QPushButton *pbModTag;
    QPushButton *pbPrint;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pbOperate;
    QPushButton *pushButton;
    QPushButton *pbClose;
    QSpacerItem *horizontalSpacer_2;
    QButtonGroup *buttonGroup;
    QButtonGroup *buttonGroup_2;

    void setupUi(QWidget *FTOverview)
    {
        if (FTOverview->objectName().isEmpty())
            FTOverview->setObjectName(QString::fromUtf8("FTOverview"));
        FTOverview->resize(1349, 519);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/icons/8644322_graphic_chart_graph_bam_icon (1).png"), QSize(), QIcon::Normal, QIcon::Off);
        FTOverview->setWindowIcon(icon);
        verticalLayout_3 = new QVBoxLayout(FTOverview);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        rbLabels = new QRadioButton(FTOverview);
        rbLabels->setObjectName(QString::fromUtf8("rbLabels"));
        rbLabels->setChecked(true);

        horizontalLayout_3->addWidget(rbLabels);

        rbSigilli = new QRadioButton(FTOverview);
        rbSigilli->setObjectName(QString::fromUtf8("rbSigilli"));

        horizontalLayout_3->addWidget(rbSigilli);

        rbBarcode = new QRadioButton(FTOverview);
        rbBarcode->setObjectName(QString::fromUtf8("rbBarcode"));

        horizontalLayout_3->addWidget(rbBarcode);

        leBarcode = new QLineEdit(FTOverview);
        leBarcode->setObjectName(QString::fromUtf8("leBarcode"));

        horizontalLayout_3->addWidget(leBarcode);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        rbCust = new QRadioButton(FTOverview);
        buttonGroup = new QButtonGroup(FTOverview);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(rbCust);
        rbCust->setObjectName(QString::fromUtf8("rbCust"));

        verticalLayout_2->addWidget(rbCust);

        rbNoCust = new QRadioButton(FTOverview);
        buttonGroup->addButton(rbNoCust);
        rbNoCust->setObjectName(QString::fromUtf8("rbNoCust"));
        rbNoCust->setChecked(true);

        verticalLayout_2->addWidget(rbNoCust);


        horizontalLayout_3->addLayout(verticalLayout_2);

        cbCliente = new QComboBox(FTOverview);
        cbCliente->setObjectName(QString::fromUtf8("cbCliente"));
        cbCliente->setMinimumSize(QSize(300, 0));
        cbCliente->setEditable(true);

        horizontalLayout_3->addWidget(cbCliente);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        rbAnyProd = new QRadioButton(FTOverview);
        buttonGroup_2 = new QButtonGroup(FTOverview);
        buttonGroup_2->setObjectName(QString::fromUtf8("buttonGroup_2"));
        buttonGroup_2->addButton(rbAnyProd);
        rbAnyProd->setObjectName(QString::fromUtf8("rbAnyProd"));

        verticalLayout->addWidget(rbAnyProd);

        rbNoProd = new QRadioButton(FTOverview);
        buttonGroup_2->addButton(rbNoProd);
        rbNoProd->setObjectName(QString::fromUtf8("rbNoProd"));
        rbNoProd->setChecked(true);

        verticalLayout->addWidget(rbNoProd);


        horizontalLayout_3->addLayout(verticalLayout);

        cbProdotto = new QComboBox(FTOverview);
        cbProdotto->setObjectName(QString::fromUtf8("cbProdotto"));
        cbProdotto->setMinimumSize(QSize(300, 0));
        cbProdotto->setEditable(true);

        horizontalLayout_3->addWidget(cbProdotto);

        line_2 = new QFrame(FTOverview);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line_2);

        pbFilter = new QPushButton(FTOverview);
        pbFilter->setObjectName(QString::fromUtf8("pbFilter"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/icons/Search.PNG"), QSize(), QIcon::Normal, QIcon::Off);
        pbFilter->setIcon(icon1);
        pbFilter->setIconSize(QSize(32, 32));

        horizontalLayout_3->addWidget(pbFilter);

        pbNoFilters = new QPushButton(FTOverview);
        pbNoFilters->setObjectName(QString::fromUtf8("pbNoFilters"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resources/icons/8704261_premium_toggle_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbNoFilters->setIcon(icon2);
        pbNoFilters->setIconSize(QSize(32, 32));

        horizontalLayout_3->addWidget(pbNoFilters);

        horizontalSpacer_3 = new QSpacerItem(1243, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        tvTags = new QTableView(FTOverview);
        tvTags->setObjectName(QString::fromUtf8("tvTags"));
        tvTags->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tvTags->setAlternatingRowColors(true);
        tvTags->setSelectionMode(QAbstractItemView::SingleSelection);
        tvTags->setSelectionBehavior(QAbstractItemView::SelectRows);
        tvTags->setSortingEnabled(true);
        tvTags->horizontalHeader()->setCascadingSectionResizes(true);
        tvTags->horizontalHeader()->setStretchLastSection(true);
        tvTags->verticalHeader()->setVisible(false);
        tvTags->verticalHeader()->setCascadingSectionResizes(true);
        tvTags->verticalHeader()->setHighlightSections(false);

        horizontalLayout_2->addWidget(tvTags);

        tvTags_mov = new QTableView(FTOverview);
        tvTags_mov->setObjectName(QString::fromUtf8("tvTags_mov"));
        tvTags_mov->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tvTags_mov->setAlternatingRowColors(true);
        tvTags_mov->setSelectionMode(QAbstractItemView::SingleSelection);
        tvTags_mov->setSelectionBehavior(QAbstractItemView::SelectRows);
        tvTags_mov->setSortingEnabled(true);
        tvTags_mov->horizontalHeader()->setCascadingSectionResizes(true);
        tvTags_mov->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        tvTags_mov->horizontalHeader()->setStretchLastSection(true);
        tvTags_mov->verticalHeader()->setVisible(false);
        tvTags_mov->verticalHeader()->setCascadingSectionResizes(true);

        horizontalLayout_2->addWidget(tvTags_mov);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pbDefinizioni = new QPushButton(FTOverview);
        pbDefinizioni->setObjectName(QString::fromUtf8("pbDefinizioni"));
        pbDefinizioni->setMinimumSize(QSize(120, 0));
        pbDefinizioni->setMaximumSize(QSize(120, 16777215));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/resources/icons/7627459_app_tools_logo_apple_reminders_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbDefinizioni->setIcon(icon3);
        pbDefinizioni->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(pbDefinizioni);

        pbModTag = new QPushButton(FTOverview);
        pbModTag->setObjectName(QString::fromUtf8("pbModTag"));
        pbModTag->setMinimumSize(QSize(150, 0));
        pbModTag->setMaximumSize(QSize(150, 16777215));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/resources/icons/8704072_premium_flash_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbModTag->setIcon(icon4);
        pbModTag->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(pbModTag);

        pbPrint = new QPushButton(FTOverview);
        pbPrint->setObjectName(QString::fromUtf8("pbPrint"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/resources/icons/Printer-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbPrint->setIcon(icon5);
        pbPrint->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(pbPrint);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        pbOperate = new QPushButton(FTOverview);
        pbOperate->setObjectName(QString::fromUtf8("pbOperate"));
        pbOperate->setMinimumSize(QSize(130, 0));
        pbOperate->setMaximumSize(QSize(130, 16777215));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/resources/icons/8707831_tool_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbOperate->setIcon(icon6);
        pbOperate->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(pbOperate);

        pushButton = new QPushButton(FTOverview);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/resources/icons/Actions-configure-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon7);
        pushButton->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(pushButton);

        pbClose = new QPushButton(FTOverview);
        pbClose->setObjectName(QString::fromUtf8("pbClose"));
        pbClose->setMinimumSize(QSize(120, 0));
        pbClose->setMaximumSize(QSize(120, 16777215));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/resources/icons/Actions-window-close-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbClose->setIcon(icon8);
        pbClose->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(pbClose);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout);


        retranslateUi(FTOverview);

        QMetaObject::connectSlotsByName(FTOverview);
    } // setupUi

    void retranslateUi(QWidget *FTOverview)
    {
        FTOverview->setWindowTitle(QCoreApplication::translate("FTOverview", "Panoramica", nullptr));
        rbLabels->setText(QCoreApplication::translate("FTOverview", "Etichette", nullptr));
        rbSigilli->setText(QCoreApplication::translate("FTOverview", "Sigilli", nullptr));
        rbBarcode->setText(QCoreApplication::translate("FTOverview", "Barcode", nullptr));
        rbCust->setText(QCoreApplication::translate("FTOverview", "Cliente", nullptr));
        rbNoCust->setText(QCoreApplication::translate("FTOverview", "No Cliente", nullptr));
        rbAnyProd->setText(QCoreApplication::translate("FTOverview", "Prodotto", nullptr));
        rbNoProd->setText(QCoreApplication::translate("FTOverview", "No Prodotto", nullptr));
        pbFilter->setText(QCoreApplication::translate("FTOverview", "Filtra", nullptr));
        pbNoFilters->setText(QCoreApplication::translate("FTOverview", "Annulla filtri", nullptr));
        pbDefinizioni->setText(QCoreApplication::translate("FTOverview", "Definizioni", nullptr));
        pbModTag->setText(QCoreApplication::translate("FTOverview", "Modifica Selezionato", nullptr));
        pbPrint->setText(QCoreApplication::translate("FTOverview", "Stampa", nullptr));
        pbOperate->setText(QCoreApplication::translate("FTOverview", "Operazione", nullptr));
        pushButton->setText(QCoreApplication::translate("FTOverview", "Modifica operazione selezionata", nullptr));
        pbClose->setText(QCoreApplication::translate("FTOverview", "Chiudi", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FTOverview: public Ui_FTOverview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FTOVERVIEW_H
