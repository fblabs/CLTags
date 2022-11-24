/********************************************************************************
** Form generated from reading UI file 'ftcontainersoperation_mod.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FTCONTAINERSOPERATION_MOD_H
#define UI_FTCONTAINERSOPERATION_MOD_H

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

class Ui_FtContainersOperation_mod
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QDateEdit *deData;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *cbSupplier;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *leBolla;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QRadioButton *rbCarico;
    QRadioButton *rbScarico;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QLineEdit *leAmount;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout;
    QLabel *label_5;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *teNote;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pbSave;
    QPushButton *pbClose;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QWidget *FtContainersOperation_mod)
    {
        if (FtContainersOperation_mod->objectName().isEmpty())
            FtContainersOperation_mod->setObjectName(QString::fromUtf8("FtContainersOperation_mod"));
        FtContainersOperation_mod->setWindowModality(Qt::ApplicationModal);
        FtContainersOperation_mod->resize(553, 440);
        verticalLayout_3 = new QVBoxLayout(FtContainersOperation_mod);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, -1, 0, -1);
        label_3 = new QLabel(FtContainersOperation_mod);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_4->addWidget(label_3);

        deData = new QDateEdit(FtContainersOperation_mod);
        deData->setObjectName(QString::fromUtf8("deData"));

        horizontalLayout_4->addWidget(deData);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(FtContainersOperation_mod);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(80, 0));
        label->setMaximumSize(QSize(80, 16777215));

        horizontalLayout->addWidget(label);

        cbSupplier = new QComboBox(FtContainersOperation_mod);
        cbSupplier->setObjectName(QString::fromUtf8("cbSupplier"));

        horizontalLayout->addWidget(cbSupplier);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(FtContainersOperation_mod);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(80, 0));
        label_2->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_2->addWidget(label_2);

        leBolla = new QLineEdit(FtContainersOperation_mod);
        leBolla->setObjectName(QString::fromUtf8("leBolla"));

        horizontalLayout_2->addWidget(leBolla);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        rbCarico = new QRadioButton(FtContainersOperation_mod);
        rbCarico->setObjectName(QString::fromUtf8("rbCarico"));

        horizontalLayout_5->addWidget(rbCarico);

        rbScarico = new QRadioButton(FtContainersOperation_mod);
        rbScarico->setObjectName(QString::fromUtf8("rbScarico"));

        horizontalLayout_5->addWidget(rbScarico);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_4 = new QLabel(FtContainersOperation_mod);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_6->addWidget(label_4);

        leAmount = new QLineEdit(FtContainersOperation_mod);
        leAmount->setObjectName(QString::fromUtf8("leAmount"));

        horizontalLayout_6->addWidget(leAmount);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_5 = new QLabel(FtContainersOperation_mod);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout->addWidget(label_5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_7->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        teNote = new QTextEdit(FtContainersOperation_mod);
        teNote->setObjectName(QString::fromUtf8("teNote"));
        teNote->setMaximumSize(QSize(16777215, 100));

        verticalLayout_2->addWidget(teNote);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        horizontalLayout_7->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        pbSave = new QPushButton(FtContainersOperation_mod);
        pbSave->setObjectName(QString::fromUtf8("pbSave"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/icons/save-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbSave->setIcon(icon);
        pbSave->setIconSize(QSize(32, 32));

        horizontalLayout_3->addWidget(pbSave);

        pbClose = new QPushButton(FtContainersOperation_mod);
        pbClose->setObjectName(QString::fromUtf8("pbClose"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/icons/Actions-window-close-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbClose->setIcon(icon1);
        pbClose->setIconSize(QSize(32, 32));

        horizontalLayout_3->addWidget(pbClose);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout_3->addLayout(horizontalLayout_3);


        retranslateUi(FtContainersOperation_mod);

        QMetaObject::connectSlotsByName(FtContainersOperation_mod);
    } // setupUi

    void retranslateUi(QWidget *FtContainersOperation_mod)
    {
        FtContainersOperation_mod->setWindowTitle(QCoreApplication::translate("FtContainersOperation_mod", "Modica operazione", nullptr));
        label_3->setText(QCoreApplication::translate("FtContainersOperation_mod", "Data:", nullptr));
        label->setText(QCoreApplication::translate("FtContainersOperation_mod", "Fornitore:", nullptr));
        label_2->setText(QCoreApplication::translate("FtContainersOperation_mod", "Bolla:", nullptr));
        rbCarico->setText(QCoreApplication::translate("FtContainersOperation_mod", "Carico", nullptr));
        rbScarico->setText(QCoreApplication::translate("FtContainersOperation_mod", "Scarico", nullptr));
        label_4->setText(QCoreApplication::translate("FtContainersOperation_mod", "Quantit\303\240:", nullptr));
        label_5->setText(QCoreApplication::translate("FtContainersOperation_mod", "TextLabel", nullptr));
        pbSave->setText(QCoreApplication::translate("FtContainersOperation_mod", "Salva", nullptr));
        pbClose->setText(QCoreApplication::translate("FtContainersOperation_mod", "Chiudi", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FtContainersOperation_mod: public Ui_FtContainersOperation_mod {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FTCONTAINERSOPERATION_MOD_H
