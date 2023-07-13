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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
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
    QCheckBox *cbAttivi;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_5;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QDateEdit *deDal;
    QLabel *label;
    QDateEdit *deAl;
    QPushButton *pbReset;
    QSplitter *splitter;
    QTableView *tvTags;
    QTableView *tvTags_mov;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pbDefinizioni;
    QPushButton *pbModTag;
    QPushButton *pbPrint;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pbOperate;
    QPushButton *pb_Scarico;
    QPushButton *pbModifyOperation;
    QPushButton *pbDEleteOperation;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pbClose;
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
        leBarcode->setClearButtonEnabled(true);

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

        cbAttivi = new QCheckBox(FTOverview);
        cbAttivi->setObjectName(QString::fromUtf8("cbAttivi"));
        cbAttivi->setChecked(true);

        horizontalLayout_3->addWidget(cbAttivi);

        horizontalSpacer_3 = new QSpacerItem(1243, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(FTOverview);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        deDal = new QDateEdit(FTOverview);
        deDal->setObjectName(QString::fromUtf8("deDal"));
        deDal->setMinimumSize(QSize(200, 0));
        deDal->setCalendarPopup(true);

        gridLayout->addWidget(deDal, 0, 1, 1, 1);

        label = new QLabel(FTOverview);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        deAl = new QDateEdit(FTOverview);
        deAl->setObjectName(QString::fromUtf8("deAl"));
        deAl->setMinimumSize(QSize(200, 0));
        deAl->setMaximumSize(QSize(16777215, 16777215));
        deAl->setCalendarPopup(true);

        gridLayout->addWidget(deAl, 0, 3, 1, 1);

        pbReset = new QPushButton(FTOverview);
        pbReset->setObjectName(QString::fromUtf8("pbReset"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/resources/icons/Counterclockwise-arrow64.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbReset->setIcon(icon3);

        gridLayout->addWidget(pbReset, 0, 4, 1, 1);


        horizontalLayout_2->addLayout(gridLayout);


        verticalLayout_3->addLayout(horizontalLayout_2);

        splitter = new QSplitter(FTOverview);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        tvTags = new QTableView(splitter);
        tvTags->setObjectName(QString::fromUtf8("tvTags"));
        tvTags->setMinimumSize(QSize(0, 0));
        tvTags->setStyleSheet(QString::fromUtf8("selection-color: rgb(255, 255, 255);\n"
"selection-background-color: rgb(0, 85, 127);"));
        tvTags->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tvTags->setAlternatingRowColors(true);
        tvTags->setSelectionMode(QAbstractItemView::SingleSelection);
        tvTags->setSelectionBehavior(QAbstractItemView::SelectRows);
        tvTags->setSortingEnabled(true);
        splitter->addWidget(tvTags);
        tvTags->horizontalHeader()->setCascadingSectionResizes(true);
        tvTags->horizontalHeader()->setStretchLastSection(true);
        tvTags->verticalHeader()->setVisible(false);
        tvTags->verticalHeader()->setCascadingSectionResizes(true);
        tvTags->verticalHeader()->setHighlightSections(false);
        tvTags_mov = new QTableView(splitter);
        tvTags_mov->setObjectName(QString::fromUtf8("tvTags_mov"));
        tvTags_mov->setMinimumSize(QSize(0, 0));
        tvTags_mov->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tvTags_mov->setAlternatingRowColors(true);
        tvTags_mov->setSelectionMode(QAbstractItemView::SingleSelection);
        tvTags_mov->setSelectionBehavior(QAbstractItemView::SelectRows);
        tvTags_mov->setSortingEnabled(true);
        splitter->addWidget(tvTags_mov);
        tvTags_mov->horizontalHeader()->setCascadingSectionResizes(true);
        tvTags_mov->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        tvTags_mov->horizontalHeader()->setStretchLastSection(true);
        tvTags_mov->verticalHeader()->setVisible(false);
        tvTags_mov->verticalHeader()->setCascadingSectionResizes(true);

        verticalLayout_3->addWidget(splitter);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pbDefinizioni = new QPushButton(FTOverview);
        pbDefinizioni->setObjectName(QString::fromUtf8("pbDefinizioni"));
        pbDefinizioni->setMinimumSize(QSize(120, 0));
        pbDefinizioni->setMaximumSize(QSize(120, 16777215));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/resources/icons/7627459_app_tools_logo_apple_reminders_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbDefinizioni->setIcon(icon4);
        pbDefinizioni->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(pbDefinizioni);

        pbModTag = new QPushButton(FTOverview);
        pbModTag->setObjectName(QString::fromUtf8("pbModTag"));
        pbModTag->setMinimumSize(QSize(150, 0));
        pbModTag->setMaximumSize(QSize(150, 16777215));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/resources/icons/8704072_premium_flash_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbModTag->setIcon(icon5);
        pbModTag->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(pbModTag);

        pbPrint = new QPushButton(FTOverview);
        pbPrint->setObjectName(QString::fromUtf8("pbPrint"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/resources/icons/Printer-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbPrint->setIcon(icon6);
        pbPrint->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(pbPrint);


        horizontalLayout_5->addLayout(horizontalLayout);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        pbOperate = new QPushButton(FTOverview);
        pbOperate->setObjectName(QString::fromUtf8("pbOperate"));
        pbOperate->setMinimumSize(QSize(130, 0));
        pbOperate->setMaximumSize(QSize(130, 16777215));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/resources/icons/8721738_add_plus_+_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbOperate->setIcon(icon7);
        pbOperate->setIconSize(QSize(32, 32));

        horizontalLayout_4->addWidget(pbOperate);

        pb_Scarico = new QPushButton(FTOverview);
        pb_Scarico->setObjectName(QString::fromUtf8("pb_Scarico"));
        pb_Scarico->setMinimumSize(QSize(130, 0));
        pb_Scarico->setMaximumSize(QSize(130, 16777215));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/resources/icons/Minus.PNG"), QSize(), QIcon::Normal, QIcon::Off);
        pb_Scarico->setIcon(icon8);
        pb_Scarico->setIconSize(QSize(32, 32));

        horizontalLayout_4->addWidget(pb_Scarico);

        pbModifyOperation = new QPushButton(FTOverview);
        pbModifyOperation->setObjectName(QString::fromUtf8("pbModifyOperation"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/resources/icons/Actions-configure-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbModifyOperation->setIcon(icon9);
        pbModifyOperation->setIconSize(QSize(32, 32));

        horizontalLayout_4->addWidget(pbModifyOperation);

        pbDEleteOperation = new QPushButton(FTOverview);
        pbDEleteOperation->setObjectName(QString::fromUtf8("pbDEleteOperation"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/resources/icons/Flag-red64.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbDEleteOperation->setIcon(icon10);
        pbDEleteOperation->setIconSize(QSize(32, 32));

        horizontalLayout_4->addWidget(pbDEleteOperation);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        pbClose = new QPushButton(FTOverview);
        pbClose->setObjectName(QString::fromUtf8("pbClose"));
        pbClose->setMinimumSize(QSize(120, 0));
        pbClose->setMaximumSize(QSize(120, 16777215));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/resources/icons/Actions-window-close-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbClose->setIcon(icon11);
        pbClose->setIconSize(QSize(32, 32));

        horizontalLayout_4->addWidget(pbClose);


        horizontalLayout_5->addLayout(horizontalLayout_4);


        verticalLayout_3->addLayout(horizontalLayout_5);


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
        cbAttivi->setText(QCoreApplication::translate("FTOverview", "Attivi", nullptr));
        label_2->setText(QCoreApplication::translate("FTOverview", "e il:", nullptr));
        label->setText(QCoreApplication::translate("FTOverview", "Tra il:", nullptr));
        pbReset->setText(QCoreApplication::translate("FTOverview", "Reset", nullptr));
        pbDefinizioni->setText(QCoreApplication::translate("FTOverview", "Definizioni", nullptr));
        pbModTag->setText(QCoreApplication::translate("FTOverview", "Modifica Selezionato", nullptr));
        pbPrint->setText(QCoreApplication::translate("FTOverview", "Stampa", nullptr));
        pbOperate->setText(QCoreApplication::translate("FTOverview", "Carico", nullptr));
        pb_Scarico->setText(QCoreApplication::translate("FTOverview", "Scarico", nullptr));
        pbModifyOperation->setText(QCoreApplication::translate("FTOverview", "Modifica operazione selezionata", nullptr));
        pbDEleteOperation->setText(QCoreApplication::translate("FTOverview", "Elimina operazione selezionata", nullptr));
        pbClose->setText(QCoreApplication::translate("FTOverview", "Chiudi", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FTOverview: public Ui_FTOverview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FTOVERVIEW_H
