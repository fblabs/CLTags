/********************************************************************************
** Form generated from reading UI file 'ftmodmov.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FTMODMOV_H
#define UI_FTMODMOV_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
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

class Ui_FTModMov
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QDateEdit *dateEdit;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *lbBarcode;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *rbCarico;
    QRadioButton *rbScarico;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLineEdit *leAmount;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QComboBox *cbStampatori;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout;
    QLabel *label_5;
    QSpacerItem *verticalSpacer_2;
    QTextEdit *teNote;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pbSave;
    QPushButton *pbCancel;

    void setupUi(QWidget *FTModMov)
    {
        if (FTModMov->objectName().isEmpty())
            FTModMov->setObjectName(QString::fromUtf8("FTModMov"));
        FTModMov->setWindowModality(Qt::ApplicationModal);
        FTModMov->resize(516, 342);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/icons/8704261_premium_toggle_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        FTModMov->setWindowIcon(icon);
        verticalLayout_2 = new QVBoxLayout(FTModMov);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_4 = new QLabel(FTModMov);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_5->addWidget(label_4);

        dateEdit = new QDateEdit(FTModMov);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));

        horizontalLayout_5->addWidget(dateEdit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(FTModMov);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(label);

        lbBarcode = new QLabel(FTModMov);
        lbBarcode->setObjectName(QString::fromUtf8("lbBarcode"));
        lbBarcode->setMinimumSize(QSize(200, 0));
        lbBarcode->setMaximumSize(QSize(120, 16777215));
        lbBarcode->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 127);"));

        horizontalLayout->addWidget(lbBarcode);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 26, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        rbCarico = new QRadioButton(FTModMov);
        rbCarico->setObjectName(QString::fromUtf8("rbCarico"));

        horizontalLayout_2->addWidget(rbCarico);

        rbScarico = new QRadioButton(FTModMov);
        rbScarico->setObjectName(QString::fromUtf8("rbScarico"));

        horizontalLayout_2->addWidget(rbScarico);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_3 = new QLabel(FTModMov);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(80, 0));
        label_3->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_4->addWidget(label_3);

        leAmount = new QLineEdit(FTModMov);
        leAmount->setObjectName(QString::fromUtf8("leAmount"));

        horizontalLayout_4->addWidget(leAmount);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(FTModMov);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(80, 0));
        label_2->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_3->addWidget(label_2);

        cbStampatori = new QComboBox(FTModMov);
        cbStampatori->setObjectName(QString::fromUtf8("cbStampatori"));

        horizontalLayout_3->addWidget(cbStampatori);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_5 = new QLabel(FTModMov);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout->addWidget(label_5);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        horizontalLayout_6->addLayout(verticalLayout);

        teNote = new QTextEdit(FTModMov);
        teNote->setObjectName(QString::fromUtf8("teNote"));
        teNote->setMaximumSize(QSize(16777215, 60));

        horizontalLayout_6->addWidget(teNote);


        verticalLayout_2->addLayout(horizontalLayout_6);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        pbSave = new QPushButton(FTModMov);
        pbSave->setObjectName(QString::fromUtf8("pbSave"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/icons/save-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbSave->setIcon(icon1);
        pbSave->setIconSize(QSize(32, 32));

        horizontalLayout_7->addWidget(pbSave);

        pbCancel = new QPushButton(FTModMov);
        pbCancel->setObjectName(QString::fromUtf8("pbCancel"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resources/icons/Actions-window-close-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbCancel->setIcon(icon2);
        pbCancel->setIconSize(QSize(32, 32));

        horizontalLayout_7->addWidget(pbCancel);


        verticalLayout_2->addLayout(horizontalLayout_7);


        retranslateUi(FTModMov);

        QMetaObject::connectSlotsByName(FTModMov);
    } // setupUi

    void retranslateUi(QWidget *FTModMov)
    {
        FTModMov->setWindowTitle(QCoreApplication::translate("FTModMov", "Modifica azione", nullptr));
        label_4->setText(QCoreApplication::translate("FTModMov", "Data:", nullptr));
        label->setText(QCoreApplication::translate("FTModMov", "Barcode:", nullptr));
        lbBarcode->setText(QString());
        rbCarico->setText(QCoreApplication::translate("FTModMov", "Carico", nullptr));
        rbScarico->setText(QCoreApplication::translate("FTModMov", "Scarico", nullptr));
        label_3->setText(QCoreApplication::translate("FTModMov", "Quantit\303\240:", nullptr));
        label_2->setText(QCoreApplication::translate("FTModMov", "Stampatore:", nullptr));
        label_5->setText(QCoreApplication::translate("FTModMov", "Note:", nullptr));
        pbSave->setText(QCoreApplication::translate("FTModMov", "Salva", nullptr));
        pbCancel->setText(QCoreApplication::translate("FTModMov", "Chiudi", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FTModMov: public Ui_FTModMov {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FTMODMOV_H
