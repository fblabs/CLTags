/********************************************************************************
** Form generated from reading UI file 'ftagsmov.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FTAGSMOV_H
#define UI_FTAGSMOV_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FTagsMov
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_2;
    QComboBox *cbTipo;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QComboBox *cbClienti;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QCheckBox *cbGenericProduct;
    QComboBox *cbProdotto;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QLineEdit *leBarcode;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *leSpecifica;
    QGridLayout *gridLayout;
    QFormLayout *formLayout;
    QLabel *label_6;
    QTextEdit *teNote;
    QLabel *label_7;
    QCheckBox *cbState;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QRadioButton *rbAll;
    QRadioButton *rb1;
    QRadioButton *rb2;
    QPushButton *pbChooseImage;
    QPushButton *pbReset;
    QLabel *lbImage1;
    QLabel *lbImage2;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *pbSave;
    QPushButton *pbMov;
    QPushButton *pbNew;
    QPushButton *pbClose;

    void setupUi(QWidget *FTagsMov)
    {
        if (FTagsMov->objectName().isEmpty())
            FTagsMov->setObjectName(QString::fromUtf8("FTagsMov"));
        FTagsMov->setWindowModality(Qt::ApplicationModal);
        FTagsMov->resize(1021, 936);
        FTagsMov->setMinimumSize(QSize(0, 0));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/icons/7627459_app_tools_logo_apple_reminders_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        FTagsMov->setWindowIcon(icon);
        verticalLayout_2 = new QVBoxLayout(FTagsMov);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_2 = new QLabel(FTagsMov);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(80, 0));
        label_2->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_7->addWidget(label_2);

        cbTipo = new QComboBox(FTagsMov);
        cbTipo->setObjectName(QString::fromUtf8("cbTipo"));
        cbTipo->setEditable(false);

        horizontalLayout_7->addWidget(cbTipo);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_4 = new QLabel(FTagsMov);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(80, 0));
        label_4->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_6->addWidget(label_4);

        cbClienti = new QComboBox(FTagsMov);
        cbClienti->setObjectName(QString::fromUtf8("cbClienti"));
        cbClienti->setEditable(true);

        horizontalLayout_6->addWidget(cbClienti);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(FTagsMov);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(80, 0));
        label_5->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_5->addWidget(label_5);

        cbGenericProduct = new QCheckBox(FTagsMov);
        cbGenericProduct->setObjectName(QString::fromUtf8("cbGenericProduct"));
        cbGenericProduct->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_5->addWidget(cbGenericProduct);

        cbProdotto = new QComboBox(FTagsMov);
        cbProdotto->setObjectName(QString::fromUtf8("cbProdotto"));
        cbProdotto->setEditable(true);

        horizontalLayout_5->addWidget(cbProdotto);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label = new QLabel(FTagsMov);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(80, 0));
        label->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_4->addWidget(label);

        leBarcode = new QLineEdit(FTagsMov);
        leBarcode->setObjectName(QString::fromUtf8("leBarcode"));
        leBarcode->setMaxLength(13);

        horizontalLayout_4->addWidget(leBarcode);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(FTagsMov);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(80, 0));
        label_3->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_3->addWidget(label_3);

        leSpecifica = new QLineEdit(FTagsMov);
        leSpecifica->setObjectName(QString::fromUtf8("leSpecifica"));
        leSpecifica->setMaxLength(10);

        horizontalLayout_3->addWidget(leSpecifica);


        verticalLayout_2->addLayout(horizontalLayout_3);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

        verticalLayout_2->addLayout(gridLayout);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_6 = new QLabel(FTagsMov);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setMinimumSize(QSize(80, 20));
        label_6->setMaximumSize(QSize(16777215, 20));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_6);

        teNote = new QTextEdit(FTagsMov);
        teNote->setObjectName(QString::fromUtf8("teNote"));
        sizePolicy.setHeightForWidth(teNote->sizePolicy().hasHeightForWidth());
        teNote->setSizePolicy(sizePolicy);
        teNote->setMinimumSize(QSize(0, 0));
        teNote->setMaximumSize(QSize(16777215, 16777215));
        teNote->setBaseSize(QSize(0, 100));
        teNote->setAutoFillBackground(false);

        formLayout->setWidget(0, QFormLayout::FieldRole, teNote);

        label_7 = new QLabel(FTagsMov);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_7);

        cbState = new QCheckBox(FTagsMov);
        cbState->setObjectName(QString::fromUtf8("cbState"));

        formLayout->setWidget(1, QFormLayout::FieldRole, cbState);


        verticalLayout_2->addLayout(formLayout);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        rbAll = new QRadioButton(FTagsMov);
        rbAll->setObjectName(QString::fromUtf8("rbAll"));
        sizePolicy.setHeightForWidth(rbAll->sizePolicy().hasHeightForWidth());
        rbAll->setSizePolicy(sizePolicy);
        rbAll->setMinimumSize(QSize(100, 0));
        rbAll->setMaximumSize(QSize(130, 16777215));
        rbAll->setChecked(true);

        verticalLayout->addWidget(rbAll);

        rb1 = new QRadioButton(FTagsMov);
        rb1->setObjectName(QString::fromUtf8("rb1"));
        sizePolicy.setHeightForWidth(rb1->sizePolicy().hasHeightForWidth());
        rb1->setSizePolicy(sizePolicy);
        rb1->setMinimumSize(QSize(100, 0));
        rb1->setMaximumSize(QSize(130, 16777215));
        rb1->setChecked(false);

        verticalLayout->addWidget(rb1);

        rb2 = new QRadioButton(FTagsMov);
        rb2->setObjectName(QString::fromUtf8("rb2"));
        sizePolicy.setHeightForWidth(rb2->sizePolicy().hasHeightForWidth());
        rb2->setSizePolicy(sizePolicy);
        rb2->setMinimumSize(QSize(100, 0));
        rb2->setMaximumSize(QSize(130, 16777215));
        rb2->setChecked(false);

        verticalLayout->addWidget(rb2);

        pbChooseImage = new QPushButton(FTagsMov);
        pbChooseImage->setObjectName(QString::fromUtf8("pbChooseImage"));
        sizePolicy.setHeightForWidth(pbChooseImage->sizePolicy().hasHeightForWidth());
        pbChooseImage->setSizePolicy(sizePolicy);
        pbChooseImage->setMaximumSize(QSize(130, 16777215));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/icons/7898565_refresh_globe_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbChooseImage->setIcon(icon1);
        pbChooseImage->setIconSize(QSize(32, 32));

        verticalLayout->addWidget(pbChooseImage);

        pbReset = new QPushButton(FTagsMov);
        pbReset->setObjectName(QString::fromUtf8("pbReset"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resources/icons/7898564_play_bookmarks_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbReset->setIcon(icon2);
        pbReset->setIconSize(QSize(32, 32));

        verticalLayout->addWidget(pbReset);


        horizontalLayout_2->addLayout(verticalLayout);

        lbImage1 = new QLabel(FTagsMov);
        lbImage1->setObjectName(QString::fromUtf8("lbImage1"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lbImage1->sizePolicy().hasHeightForWidth());
        lbImage1->setSizePolicy(sizePolicy1);
        lbImage1->setMinimumSize(QSize(300, 300));
        lbImage1->setFrameShape(QFrame::Box);
        lbImage1->setScaledContents(true);

        horizontalLayout_2->addWidget(lbImage1);

        lbImage2 = new QLabel(FTagsMov);
        lbImage2->setObjectName(QString::fromUtf8("lbImage2"));
        sizePolicy1.setHeightForWidth(lbImage2->sizePolicy().hasHeightForWidth());
        lbImage2->setSizePolicy(sizePolicy1);
        lbImage2->setMinimumSize(QSize(300, 300));
        lbImage2->setFrameShape(QFrame::Box);
        lbImage2->setScaledContents(true);

        horizontalLayout_2->addWidget(lbImage2);


        horizontalLayout_8->addLayout(horizontalLayout_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pbSave = new QPushButton(FTagsMov);
        pbSave->setObjectName(QString::fromUtf8("pbSave"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/resources/icons/8712817_tick_iso_premium_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbSave->setIcon(icon3);
        pbSave->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(pbSave);

        pbMov = new QPushButton(FTagsMov);
        pbMov->setObjectName(QString::fromUtf8("pbMov"));
        pbMov->setEnabled(true);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/resources/icons/8712785_tool_iso_premium_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbMov->setIcon(icon4);
        pbMov->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(pbMov);

        pbNew = new QPushButton(FTagsMov);
        pbNew->setObjectName(QString::fromUtf8("pbNew"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/resources/icons/8721738_add_plus_+_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbNew->setIcon(icon5);
        pbNew->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(pbNew);

        pbClose = new QPushButton(FTagsMov);
        pbClose->setObjectName(QString::fromUtf8("pbClose"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/resources/icons/Actions-window-close-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbClose->setIcon(icon6);
        pbClose->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(pbClose);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(FTagsMov);

        QMetaObject::connectSlotsByName(FTagsMov);
    } // setupUi

    void retranslateUi(QWidget *FTagsMov)
    {
        FTagsMov->setWindowTitle(QCoreApplication::translate("FTagsMov", "Definizioni", nullptr));
        label_2->setText(QCoreApplication::translate("FTagsMov", "Tipo:", nullptr));
        label_4->setText(QCoreApplication::translate("FTagsMov", "Cliente:", nullptr));
        label_5->setText(QCoreApplication::translate("FTagsMov", "Prodotto:", nullptr));
        cbGenericProduct->setText(QCoreApplication::translate("FTagsMov", "Generico (NA)", nullptr));
        label->setText(QCoreApplication::translate("FTagsMov", "Barcode:", nullptr));
        label_3->setText(QCoreApplication::translate("FTagsMov", "Specifica:", nullptr));
        label_6->setText(QCoreApplication::translate("FTagsMov", "Note:", nullptr));
        label_7->setText(QCoreApplication::translate("FTagsMov", "Stato:", nullptr));
        cbState->setText(QString());
        rbAll->setText(QCoreApplication::translate("FTagsMov", "Mostra tutto", nullptr));
        rb1->setText(QCoreApplication::translate("FTagsMov", "Immagine 1", nullptr));
        rb2->setText(QCoreApplication::translate("FTagsMov", "Immagine 2", nullptr));
        pbChooseImage->setText(QCoreApplication::translate("FTagsMov", "Scegli immagine...", nullptr));
        pbReset->setText(QCoreApplication::translate("FTagsMov", "Reset immagine", nullptr));
        lbImage1->setText(QString());
        lbImage2->setText(QString());
        pbSave->setText(QCoreApplication::translate("FTagsMov", "Salva", nullptr));
        pbMov->setText(QCoreApplication::translate("FTagsMov", "Operazioni", nullptr));
        pbNew->setText(QCoreApplication::translate("FTagsMov", "Nuovo", nullptr));
        pbClose->setText(QCoreApplication::translate("FTagsMov", "Chiudi", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FTagsMov: public Ui_FTagsMov {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FTAGSMOV_H
