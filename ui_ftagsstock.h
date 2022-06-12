/********************************************************************************
** Form generated from reading UI file 'ftagsstock.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FTAGSSTOCK_H
#define UI_FTAGSSTOCK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FTagsStock
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QComboBox *cbBarcode;
    QHBoxLayout *horizontalLayout;
    QListView *lvBarcode;
    QTableView *tvOperation;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton;
    QPushButton *pbClose;

    void setupUi(QWidget *FTagsStock)
    {
        if (FTagsStock->objectName().isEmpty())
            FTagsStock->setObjectName(QString::fromUtf8("FTagsStock"));
        FTagsStock->resize(1278, 658);
        verticalLayout = new QVBoxLayout(FTagsStock);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(FTagsStock);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(80, 0));
        label->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_2->addWidget(label);

        cbBarcode = new QComboBox(FTagsStock);
        cbBarcode->setObjectName(QString::fromUtf8("cbBarcode"));
        cbBarcode->setMinimumSize(QSize(200, 0));

        horizontalLayout_2->addWidget(cbBarcode);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lvBarcode = new QListView(FTagsStock);
        lvBarcode->setObjectName(QString::fromUtf8("lvBarcode"));
        lvBarcode->setMaximumSize(QSize(200, 16777215));

        horizontalLayout->addWidget(lvBarcode);

        tvOperation = new QTableView(FTagsStock);
        tvOperation->setObjectName(QString::fromUtf8("tvOperation"));

        horizontalLayout->addWidget(tvOperation);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButton = new QPushButton(FTagsStock);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_3->addWidget(pushButton);

        pbClose = new QPushButton(FTagsStock);
        pbClose->setObjectName(QString::fromUtf8("pbClose"));

        horizontalLayout_3->addWidget(pbClose);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(FTagsStock);

        QMetaObject::connectSlotsByName(FTagsStock);
    } // setupUi

    void retranslateUi(QWidget *FTagsStock)
    {
        FTagsStock->setWindowTitle(QCoreApplication::translate("FTagsStock", "Form", nullptr));
        label->setText(QCoreApplication::translate("FTagsStock", "Barcode:", nullptr));
        pushButton->setText(QCoreApplication::translate("FTagsStock", "Movimenti", nullptr));
        pbClose->setText(QCoreApplication::translate("FTagsStock", "Chiudi", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FTagsStock: public Ui_FTagsStock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FTAGSSTOCK_H
