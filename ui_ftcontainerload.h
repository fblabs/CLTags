/********************************************************************************
** Form generated from reading UI file 'ftcontainerload.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FTCONTAINERLOAD_H
#define UI_FTCONTAINERLOAD_H

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
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FtContainerLoad
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QDateEdit *deDate;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QComboBox *cbTags;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QComboBox *cbSupplier;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *leBolla;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *leAmount;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QVBoxLayout *verticalLayout;
    QTextEdit *teNote;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *pbSave;
    QPushButton *pbClose;

    void setupUi(QWidget *FtContainerLoad)
    {
        if (FtContainerLoad->objectName().isEmpty())
            FtContainerLoad->setObjectName(QString::fromUtf8("FtContainerLoad"));
        FtContainerLoad->setWindowModality(Qt::ApplicationModal);
        FtContainerLoad->resize(400, 388);
        verticalLayout_2 = new QVBoxLayout(FtContainerLoad);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(FtContainerLoad);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_2->addWidget(label_2);

        deDate = new QDateEdit(FtContainerLoad);
        deDate->setObjectName(QString::fromUtf8("deDate"));
        deDate->setReadOnly(false);
        deDate->setCalendarPopup(true);

        horizontalLayout_2->addWidget(deDate);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(FtContainerLoad);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(60, 0));
        label_5->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_5->addWidget(label_5);

        cbTags = new QComboBox(FtContainerLoad);
        cbTags->setObjectName(QString::fromUtf8("cbTags"));

        horizontalLayout_5->addWidget(cbTags);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(FtContainerLoad);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(60, 0));
        label_3->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_3->addWidget(label_3);

        cbSupplier = new QComboBox(FtContainerLoad);
        cbSupplier->setObjectName(QString::fromUtf8("cbSupplier"));
        cbSupplier->setEditable(true);
        cbSupplier->setInsertPolicy(QComboBox::NoInsert);

        horizontalLayout_3->addWidget(cbSupplier);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(FtContainerLoad);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(60, 0));
        label_4->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_4->addWidget(label_4);

        leBolla = new QLineEdit(FtContainerLoad);
        leBolla->setObjectName(QString::fromUtf8("leBolla"));

        horizontalLayout_4->addWidget(leBolla);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_6 = new QLabel(FtContainerLoad);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(60, 0));
        label_6->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_6->addWidget(label_6);

        leAmount = new QLineEdit(FtContainerLoad);
        leAmount->setObjectName(QString::fromUtf8("leAmount"));

        horizontalLayout_6->addWidget(leAmount);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_7 = new QLabel(FtContainerLoad);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(60, 0));
        label_7->setMaximumSize(QSize(60, 16777215));
        label_7->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        horizontalLayout_7->addWidget(label_7);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        teNote = new QTextEdit(FtContainerLoad);
        teNote->setObjectName(QString::fromUtf8("teNote"));
        teNote->setMaximumSize(QSize(16777215, 80));

        verticalLayout->addWidget(teNote);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_7->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        pbSave = new QPushButton(FtContainerLoad);
        pbSave->setObjectName(QString::fromUtf8("pbSave"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/icons/save-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbSave->setIcon(icon);
        pbSave->setIconSize(QSize(32, 32));

        horizontalLayout_8->addWidget(pbSave);

        pbClose = new QPushButton(FtContainerLoad);
        pbClose->setObjectName(QString::fromUtf8("pbClose"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/icons/Actions-window-close-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbClose->setIcon(icon1);
        pbClose->setIconSize(QSize(32, 32));

        horizontalLayout_8->addWidget(pbClose);


        verticalLayout_2->addLayout(horizontalLayout_8);


        retranslateUi(FtContainerLoad);

        QMetaObject::connectSlotsByName(FtContainerLoad);
    } // setupUi

    void retranslateUi(QWidget *FtContainerLoad)
    {
        FtContainerLoad->setWindowTitle(QCoreApplication::translate("FtContainerLoad", "Carico", nullptr));
        label_2->setText(QCoreApplication::translate("FtContainerLoad", "Data:", nullptr));
        label_5->setText(QCoreApplication::translate("FtContainerLoad", "Prodotto:", nullptr));
        label_3->setText(QCoreApplication::translate("FtContainerLoad", "Fornitore:", nullptr));
        label_4->setText(QCoreApplication::translate("FtContainerLoad", "Bolla:", nullptr));
        label_6->setText(QCoreApplication::translate("FtContainerLoad", "Quantit\303\240:", nullptr));
        label_7->setText(QCoreApplication::translate("FtContainerLoad", "Note:", nullptr));
        pbSave->setText(QCoreApplication::translate("FtContainerLoad", "Salva", nullptr));
        pbClose->setText(QCoreApplication::translate("FtContainerLoad", "Chiudi", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FtContainerLoad: public Ui_FtContainerLoad {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FTCONTAINERLOAD_H
