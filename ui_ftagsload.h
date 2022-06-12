/********************************************************************************
** Form generated from reading UI file 'ftagsload.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FTAGSLOAD_H
#define UI_FTAGSLOAD_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FTagsLoad
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDateEdit *deData;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *cbClienti;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QComboBox *cbProdotti;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_9;
    QComboBox *cbTipo;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QComboBox *cbStampatori;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_10;
    QComboBox *cbAzione;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *leBarcode;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_8;
    QLineEdit *leSpec;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QSpinBox *sbAmount;
    QVBoxLayout *verticalLayout;
    QLabel *label_7;
    QTextEdit *teNote;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pbSave;
    QPushButton *pbDetails;
    QPushButton *pbNew;
    QPushButton *pbClose;

    void setupUi(QWidget *FTagsLoad)
    {
        if (FTagsLoad->objectName().isEmpty())
            FTagsLoad->setObjectName(QString::fromUtf8("FTagsLoad"));
        FTagsLoad->setWindowModality(Qt::WindowModal);
        FTagsLoad->resize(559, 559);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/icons/8721738_add_plus_+_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        FTagsLoad->setWindowIcon(icon);
        verticalLayout_2 = new QVBoxLayout(FTagsLoad);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(FTagsLoad);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        deData = new QDateEdit(FTagsLoad);
        deData->setObjectName(QString::fromUtf8("deData"));

        horizontalLayout->addWidget(deData);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(FTagsLoad);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(80, 0));
        label_2->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_2->addWidget(label_2);

        cbClienti = new QComboBox(FTagsLoad);
        cbClienti->setObjectName(QString::fromUtf8("cbClienti"));
        cbClienti->setEditable(true);
        cbClienti->setInsertPolicy(QComboBox::NoInsert);

        horizontalLayout_2->addWidget(cbClienti);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(FTagsLoad);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(80, 0));
        label_3->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_3->addWidget(label_3);

        cbProdotti = new QComboBox(FTagsLoad);
        cbProdotti->setObjectName(QString::fromUtf8("cbProdotti"));
        cbProdotti->setEditable(true);
        cbProdotti->setInsertPolicy(QComboBox::NoInsert);

        horizontalLayout_3->addWidget(cbProdotti);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_9 = new QLabel(FTagsLoad);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMinimumSize(QSize(80, 0));
        label_9->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_8->addWidget(label_9);

        cbTipo = new QComboBox(FTagsLoad);
        cbTipo->setObjectName(QString::fromUtf8("cbTipo"));
        cbTipo->setEditable(true);
        cbTipo->setInsertPolicy(QComboBox::NoInsert);

        horizontalLayout_8->addWidget(cbTipo);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(FTagsLoad);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(80, 0));
        label_4->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_4->addWidget(label_4);

        cbStampatori = new QComboBox(FTagsLoad);
        cbStampatori->setObjectName(QString::fromUtf8("cbStampatori"));
        cbStampatori->setEditable(true);
        cbStampatori->setInsertPolicy(QComboBox::NoInsert);

        horizontalLayout_4->addWidget(cbStampatori);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_10 = new QLabel(FTagsLoad);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMinimumSize(QSize(80, 0));
        label_10->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_10->addWidget(label_10);

        cbAzione = new QComboBox(FTagsLoad);
        cbAzione->setObjectName(QString::fromUtf8("cbAzione"));
        cbAzione->setEditable(true);
        cbAzione->setInsertPolicy(QComboBox::NoInsert);

        horizontalLayout_10->addWidget(cbAzione);


        verticalLayout_2->addLayout(horizontalLayout_10);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(FTagsLoad);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(80, 0));
        label_5->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_5->addWidget(label_5);

        leBarcode = new QLineEdit(FTagsLoad);
        leBarcode->setObjectName(QString::fromUtf8("leBarcode"));
        leBarcode->setMaxLength(13);

        horizontalLayout_5->addWidget(leBarcode);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_8 = new QLabel(FTagsLoad);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(80, 0));
        label_8->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_9->addWidget(label_8);

        leSpec = new QLineEdit(FTagsLoad);
        leSpec->setObjectName(QString::fromUtf8("leSpec"));
        leSpec->setMaxLength(10);

        horizontalLayout_9->addWidget(leSpec);


        verticalLayout_2->addLayout(horizontalLayout_9);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_6 = new QLabel(FTagsLoad);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(80, 0));
        label_6->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_6->addWidget(label_6);

        sbAmount = new QSpinBox(FTagsLoad);
        sbAmount->setObjectName(QString::fromUtf8("sbAmount"));
        sbAmount->setMaximum(1000000);
        sbAmount->setSingleStep(100);

        horizontalLayout_6->addWidget(sbAmount);


        verticalLayout_2->addLayout(horizontalLayout_6);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_7 = new QLabel(FTagsLoad);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(80, 20));
        label_7->setMaximumSize(QSize(80, 20));

        verticalLayout->addWidget(label_7);

        teNote = new QTextEdit(FTagsLoad);
        teNote->setObjectName(QString::fromUtf8("teNote"));

        verticalLayout->addWidget(teNote);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        pbSave = new QPushButton(FTagsLoad);
        pbSave->setObjectName(QString::fromUtf8("pbSave"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/icons/save-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbSave->setIcon(icon1);
        pbSave->setIconSize(QSize(32, 32));

        horizontalLayout_7->addWidget(pbSave);

        pbDetails = new QPushButton(FTagsLoad);
        pbDetails->setObjectName(QString::fromUtf8("pbDetails"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resources/icons/8704072_premium_flash_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbDetails->setIcon(icon2);
        pbDetails->setIconSize(QSize(32, 32));

        horizontalLayout_7->addWidget(pbDetails);

        pbNew = new QPushButton(FTagsLoad);
        pbNew->setObjectName(QString::fromUtf8("pbNew"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/resources/icons/8704069_premium_plus_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbNew->setIcon(icon3);
        pbNew->setIconSize(QSize(32, 32));

        horizontalLayout_7->addWidget(pbNew);

        pbClose = new QPushButton(FTagsLoad);
        pbClose->setObjectName(QString::fromUtf8("pbClose"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/resources/icons/8712836_fire_iso_premium_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbClose->setIcon(icon4);
        pbClose->setIconSize(QSize(32, 32));

        horizontalLayout_7->addWidget(pbClose);


        verticalLayout_2->addLayout(horizontalLayout_7);


        retranslateUi(FTagsLoad);

        QMetaObject::connectSlotsByName(FTagsLoad);
    } // setupUi

    void retranslateUi(QWidget *FTagsLoad)
    {
        FTagsLoad->setWindowTitle(QCoreApplication::translate("FTagsLoad", "Carico", nullptr));
        label->setText(QCoreApplication::translate("FTagsLoad", "Data:", nullptr));
        label_2->setText(QCoreApplication::translate("FTagsLoad", "Cliente:", nullptr));
        label_3->setText(QCoreApplication::translate("FTagsLoad", "Prodotto:", nullptr));
        label_9->setText(QCoreApplication::translate("FTagsLoad", "Tipo:", nullptr));
        label_4->setText(QCoreApplication::translate("FTagsLoad", "Stampatore:", nullptr));
        label_10->setText(QCoreApplication::translate("FTagsLoad", "Azione", nullptr));
        label_5->setText(QCoreApplication::translate("FTagsLoad", "Barcode:", nullptr));
        label_8->setText(QCoreApplication::translate("FTagsLoad", "Specifica:", nullptr));
        label_6->setText(QCoreApplication::translate("FTagsLoad", "Quantit\303\240:", nullptr));
        label_7->setText(QCoreApplication::translate("FTagsLoad", "Note:", nullptr));
        pbSave->setText(QCoreApplication::translate("FTagsLoad", "Salva", nullptr));
        pbDetails->setText(QCoreApplication::translate("FTagsLoad", "Dettagli", nullptr));
        pbNew->setText(QCoreApplication::translate("FTagsLoad", "Nuovo", nullptr));
        pbClose->setText(QCoreApplication::translate("FTagsLoad", "Chiudi", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FTagsLoad: public Ui_FTagsLoad {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FTAGSLOAD_H
