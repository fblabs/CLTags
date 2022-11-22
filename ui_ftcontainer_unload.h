/********************************************************************************
** Form generated from reading UI file 'ftcontainer_unload.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FTCONTAINER_UNLOAD_H
#define UI_FTCONTAINER_UNLOAD_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FtContainer_unload
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QDateEdit *deData;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *cbTags;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *leAmount;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_2;
    QPlainTextEdit *teNote;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pbSave;
    QPushButton *pbClose;

    void setupUi(QWidget *FtContainer_unload)
    {
        if (FtContainer_unload->objectName().isEmpty())
            FtContainer_unload->setObjectName(QString::fromUtf8("FtContainer_unload"));
        FtContainer_unload->setWindowModality(Qt::ApplicationModal);
        FtContainer_unload->resize(454, 404);
        verticalLayout_3 = new QVBoxLayout(FtContainer_unload);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_3 = new QLabel(FtContainer_unload);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(80, 0));
        label_3->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_5->addWidget(label_3);

        deData = new QDateEdit(FtContainer_unload);
        deData->setObjectName(QString::fromUtf8("deData"));
        deData->setCalendarPopup(true);

        horizontalLayout_5->addWidget(deData);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(FtContainer_unload);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(80, 0));
        label->setMaximumSize(QSize(80, 16777215));

        horizontalLayout->addWidget(label);

        cbTags = new QComboBox(FtContainer_unload);
        cbTags->setObjectName(QString::fromUtf8("cbTags"));

        horizontalLayout->addWidget(cbTags);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(FtContainer_unload);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(80, 0));
        label_2->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_2->addWidget(label_2);

        leAmount = new QLineEdit(FtContainer_unload);
        leAmount->setObjectName(QString::fromUtf8("leAmount"));

        horizontalLayout_2->addWidget(leAmount);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_4 = new QLabel(FtContainer_unload);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(80, 0));
        label_4->setMaximumSize(QSize(80, 16777215));

        verticalLayout->addWidget(label_4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        teNote = new QPlainTextEdit(FtContainer_unload);
        teNote->setObjectName(QString::fromUtf8("teNote"));
        teNote->setMaximumSize(QSize(16777215, 100));

        verticalLayout_2->addWidget(teNote);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        horizontalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        pbSave = new QPushButton(FtContainer_unload);
        pbSave->setObjectName(QString::fromUtf8("pbSave"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/icons/save-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbSave->setIcon(icon);
        pbSave->setIconSize(QSize(32, 32));

        horizontalLayout_4->addWidget(pbSave);

        pbClose = new QPushButton(FtContainer_unload);
        pbClose->setObjectName(QString::fromUtf8("pbClose"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/icons/Actions-window-close-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbClose->setIcon(icon1);
        pbClose->setIconSize(QSize(32, 32));

        horizontalLayout_4->addWidget(pbClose);


        verticalLayout_3->addLayout(horizontalLayout_4);


        retranslateUi(FtContainer_unload);

        QMetaObject::connectSlotsByName(FtContainer_unload);
    } // setupUi

    void retranslateUi(QWidget *FtContainer_unload)
    {
        FtContainer_unload->setWindowTitle(QCoreApplication::translate("FtContainer_unload", "Scarico", nullptr));
        label_3->setText(QCoreApplication::translate("FtContainer_unload", "Data:", nullptr));
        label->setText(QCoreApplication::translate("FtContainer_unload", "Prodotto:", nullptr));
        label_2->setText(QCoreApplication::translate("FtContainer_unload", "Quantit\303\240:", nullptr));
        label_4->setText(QCoreApplication::translate("FtContainer_unload", "Note:", nullptr));
        pbSave->setText(QCoreApplication::translate("FtContainer_unload", "Salva", nullptr));
        pbClose->setText(QCoreApplication::translate("FtContainer_unload", "Chiudi", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FtContainer_unload: public Ui_FtContainer_unload {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FTCONTAINER_UNLOAD_H
