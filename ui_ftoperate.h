/********************************************************************************
** Form generated from reading UI file 'ftoperate.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FTOPERATE_H
#define UI_FTOPERATE_H

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

class Ui_FTOperate
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_6;
    QRadioButton *rbCarico;
    QRadioButton *rbScarico;
    QLabel *lbTitle;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDateEdit *deDate;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *leBarcode;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *cbTipo;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QComboBox *cbStampatore;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_7;
    QLineEdit *leAmount;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout;
    QLabel *label_6;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *teNote;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *pbSave;
    QPushButton *pbClose;

    void setupUi(QWidget *FTOperate)
    {
        if (FTOperate->objectName().isEmpty())
            FTOperate->setObjectName(QString::fromUtf8("FTOperate"));
        FTOperate->setWindowModality(Qt::WindowModal);
        FTOperate->resize(514, 495);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/icons/8712785_tool_iso_premium_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        FTOperate->setWindowIcon(icon);
        verticalLayout_3 = new QVBoxLayout(FTOperate);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        rbCarico = new QRadioButton(FTOperate);
        rbCarico->setObjectName(QString::fromUtf8("rbCarico"));
        rbCarico->setChecked(true);

        horizontalLayout_6->addWidget(rbCarico);

        rbScarico = new QRadioButton(FTOperate);
        rbScarico->setObjectName(QString::fromUtf8("rbScarico"));

        horizontalLayout_6->addWidget(rbScarico);


        verticalLayout_3->addLayout(horizontalLayout_6);

        lbTitle = new QLabel(FTOperate);
        lbTitle->setObjectName(QString::fromUtf8("lbTitle"));
        lbTitle->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 127);"));

        verticalLayout_3->addWidget(lbTitle);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(FTOperate);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(80, 0));
        label->setMaximumSize(QSize(80, 16777215));

        horizontalLayout->addWidget(label);

        deDate = new QDateEdit(FTOperate);
        deDate->setObjectName(QString::fromUtf8("deDate"));
        deDate->setMinimumSize(QSize(100, 0));
        deDate->setMaximumSize(QSize(100, 16777215));
        deDate->setCalendarPopup(true);

        horizontalLayout->addWidget(deDate);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(FTOperate);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(80, 0));
        label_3->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_3->addWidget(label_3);

        leBarcode = new QLineEdit(FTOperate);
        leBarcode->setObjectName(QString::fromUtf8("leBarcode"));
        leBarcode->setMaxLength(13);

        horizontalLayout_3->addWidget(leBarcode);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(FTOperate);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(80, 0));
        label_2->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_2->addWidget(label_2);

        cbTipo = new QComboBox(FTOperate);
        cbTipo->setObjectName(QString::fromUtf8("cbTipo"));

        horizontalLayout_2->addWidget(cbTipo);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(FTOperate);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(80, 0));
        label_4->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_4->addWidget(label_4);

        cbStampatore = new QComboBox(FTOperate);
        cbStampatore->setObjectName(QString::fromUtf8("cbStampatore"));

        horizontalLayout_4->addWidget(cbStampatore);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_7 = new QLabel(FTOperate);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(80, 0));
        label_7->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_8->addWidget(label_7);

        leAmount = new QLineEdit(FTOperate);
        leAmount->setObjectName(QString::fromUtf8("leAmount"));
        leAmount->setInputMethodHints(Qt::ImhEmailCharactersOnly|Qt::ImhFormattedNumbersOnly|Qt::ImhLatinOnly|Qt::ImhLowercaseOnly|Qt::ImhPreferNumbers|Qt::ImhUppercaseOnly|Qt::ImhUrlCharactersOnly);
        leAmount->setMaxLength(10);

        horizontalLayout_8->addWidget(leAmount);


        verticalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_6 = new QLabel(FTOperate);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout->addWidget(label_6);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_7->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        teNote = new QTextEdit(FTOperate);
        teNote->setObjectName(QString::fromUtf8("teNote"));
        teNote->setMinimumSize(QSize(0, 50));
        teNote->setMaximumSize(QSize(16777215, 50));

        verticalLayout_2->addWidget(teNote);


        horizontalLayout_7->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_7);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        pbSave = new QPushButton(FTOperate);
        pbSave->setObjectName(QString::fromUtf8("pbSave"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/icons/Accept64.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbSave->setIcon(icon1);
        pbSave->setIconSize(QSize(32, 32));

        horizontalLayout_9->addWidget(pbSave);

        pbClose = new QPushButton(FTOperate);
        pbClose->setObjectName(QString::fromUtf8("pbClose"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resources/icons/Actions-window-close-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbClose->setIcon(icon2);
        pbClose->setIconSize(QSize(32, 32));

        horizontalLayout_9->addWidget(pbClose);


        verticalLayout_3->addLayout(horizontalLayout_9);


        retranslateUi(FTOperate);

        QMetaObject::connectSlotsByName(FTOperate);
    } // setupUi

    void retranslateUi(QWidget *FTOperate)
    {
        FTOperate->setWindowTitle(QCoreApplication::translate("FTOperate", "Operazioni", nullptr));
        rbCarico->setText(QCoreApplication::translate("FTOperate", "Carico", nullptr));
        rbScarico->setText(QCoreApplication::translate("FTOperate", "Scarico", nullptr));
        lbTitle->setText(QCoreApplication::translate("FTOperate", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("FTOperate", "Data:", nullptr));
        label_3->setText(QCoreApplication::translate("FTOperate", "Barcode:", nullptr));
        label_2->setText(QCoreApplication::translate("FTOperate", "Tipo:", nullptr));
        label_4->setText(QCoreApplication::translate("FTOperate", "Stampatore:", nullptr));
        label_7->setText(QCoreApplication::translate("FTOperate", "Quantit\303\240:", nullptr));
        label_6->setText(QCoreApplication::translate("FTOperate", "Note:", nullptr));
        pbSave->setText(QCoreApplication::translate("FTOperate", "Salva", nullptr));
        pbClose->setText(QCoreApplication::translate("FTOperate", "Chiudi", nullptr));
#if QT_CONFIG(shortcut)
        pbClose->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
    } // retranslateUi

};

namespace Ui {
    class FTOperate: public Ui_FTOperate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FTOPERATE_H
