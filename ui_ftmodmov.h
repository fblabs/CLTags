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

class Ui_FTModMov
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *lbTitle;
    QLabel *label_4;
    QDateEdit *dateEdit;
    QFormLayout *formLayout_2;
    QLabel *label;
    QLabel *lbBarcode;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *rbCarico;
    QRadioButton *rbScarico;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QComboBox *cbStampatori;
    QFormLayout *formLayout;
    QLabel *label_6;
    QLabel *lbImg;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *leAmount;
    QLabel *lbImgPath;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout;
    QLabel *label_5;
    QTextEdit *teNote;
    QSpacerItem *verticalSpacer_3;
    QGridLayout *gridLayout_2;
    QPushButton *pbImg;
    QPushButton *pbSave;
    QPushButton *pbCancel;

    void setupUi(QWidget *FTModMov)
    {
        if (FTModMov->objectName().isEmpty())
            FTModMov->setObjectName(QString::fromUtf8("FTModMov"));
        FTModMov->setWindowModality(Qt::ApplicationModal);
        FTModMov->resize(516, 478);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/icons/8704261_premium_toggle_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        FTModMov->setWindowIcon(icon);
        verticalLayout_2 = new QVBoxLayout(FTModMov);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lbTitle = new QLabel(FTModMov);
        lbTitle->setObjectName(QString::fromUtf8("lbTitle"));
        lbTitle->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 127);"));

        verticalLayout_2->addWidget(lbTitle);

        label_4 = new QLabel(FTModMov);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_2->addWidget(label_4);

        dateEdit = new QDateEdit(FTModMov);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setCalendarPopup(true);

        verticalLayout_2->addWidget(dateEdit);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label = new QLabel(FTModMov);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(100, 16777215));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label);

        lbBarcode = new QLabel(FTModMov);
        lbBarcode->setObjectName(QString::fromUtf8("lbBarcode"));
        lbBarcode->setMinimumSize(QSize(200, 0));
        lbBarcode->setMaximumSize(QSize(120, 16777215));
        lbBarcode->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 127);"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, lbBarcode);


        verticalLayout_2->addLayout(formLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        rbCarico = new QRadioButton(FTModMov);
        rbCarico->setObjectName(QString::fromUtf8("rbCarico"));

        horizontalLayout_2->addWidget(rbCarico);

        rbScarico = new QRadioButton(FTModMov);
        rbScarico->setObjectName(QString::fromUtf8("rbScarico"));

        horizontalLayout_2->addWidget(rbScarico);


        horizontalLayout->addLayout(horizontalLayout_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout);

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

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_6 = new QLabel(FTModMov);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_6);

        lbImg = new QLabel(FTModMov);
        lbImg->setObjectName(QString::fromUtf8("lbImg"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lbImg);


        verticalLayout_2->addLayout(formLayout);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(FTModMov);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(80, 0));
        label_3->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 2, 1, 1);

        leAmount = new QLineEdit(FTModMov);
        leAmount->setObjectName(QString::fromUtf8("leAmount"));
        leAmount->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(leAmount, 0, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        lbImgPath = new QLabel(FTModMov);
        lbImgPath->setObjectName(QString::fromUtf8("lbImgPath"));

        verticalLayout_2->addWidget(lbImgPath);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_5 = new QLabel(FTModMov);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout->addWidget(label_5);


        horizontalLayout_6->addLayout(verticalLayout);

        teNote = new QTextEdit(FTModMov);
        teNote->setObjectName(QString::fromUtf8("teNote"));
        teNote->setMaximumSize(QSize(16777215, 60));

        horizontalLayout_6->addWidget(teNote);


        verticalLayout_2->addLayout(horizontalLayout_6);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pbImg = new QPushButton(FTModMov);
        pbImg->setObjectName(QString::fromUtf8("pbImg"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/icons/Text-align--justify64.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbImg->setIcon(icon1);
        pbImg->setIconSize(QSize(32, 32));

        gridLayout_2->addWidget(pbImg, 0, 0, 1, 1);

        pbSave = new QPushButton(FTModMov);
        pbSave->setObjectName(QString::fromUtf8("pbSave"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resources/icons/save-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbSave->setIcon(icon2);
        pbSave->setIconSize(QSize(32, 32));

        gridLayout_2->addWidget(pbSave, 0, 1, 1, 1);

        pbCancel = new QPushButton(FTModMov);
        pbCancel->setObjectName(QString::fromUtf8("pbCancel"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/resources/icons/Actions-window-close-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbCancel->setIcon(icon3);
        pbCancel->setIconSize(QSize(32, 32));

        gridLayout_2->addWidget(pbCancel, 0, 2, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);


        retranslateUi(FTModMov);

        QMetaObject::connectSlotsByName(FTModMov);
    } // setupUi

    void retranslateUi(QWidget *FTModMov)
    {
        FTModMov->setWindowTitle(QCoreApplication::translate("FTModMov", "Modifica operazione", nullptr));
        lbTitle->setText(QCoreApplication::translate("FTModMov", "TextLabel", nullptr));
        label_4->setText(QCoreApplication::translate("FTModMov", "Data:", nullptr));
        label->setText(QCoreApplication::translate("FTModMov", "Barcode:", nullptr));
        lbBarcode->setText(QString());
        rbCarico->setText(QCoreApplication::translate("FTModMov", "Carico", nullptr));
        rbScarico->setText(QCoreApplication::translate("FTModMov", "Scarico", nullptr));
        label_2->setText(QCoreApplication::translate("FTModMov", "Stampatore:", nullptr));
        label_6->setText(QCoreApplication::translate("FTModMov", "Bolla:", nullptr));
        lbImg->setText(QString());
        label_3->setText(QCoreApplication::translate("FTModMov", "Quantit\303\240:", nullptr));
        lbImgPath->setText(QCoreApplication::translate("FTModMov", "TextLabel", nullptr));
        label_5->setText(QCoreApplication::translate("FTModMov", "Note:", nullptr));
        pbImg->setText(QCoreApplication::translate("FTModMov", "Scegli immagine bolla...", nullptr));
        pbSave->setText(QCoreApplication::translate("FTModMov", "Salva", nullptr));
        pbCancel->setText(QCoreApplication::translate("FTModMov", "Chiudi", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FTModMov: public Ui_FTModMov {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FTMODMOV_H
