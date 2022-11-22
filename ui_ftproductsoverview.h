/********************************************************************************
** Form generated from reading UI file 'ftproductsoverview.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FTPRODUCTSOVERVIEW_H
#define UI_FTPRODUCTSOVERVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FtProductsOverview
{
public:
    QPushButton *pbClose;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QRadioButton *rbAll;
    QRadioButton *rbVasi;
    QRadioButton *rbTappi;
    QSpacerItem *horizontalSpacer;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QComboBox *cbWhat;
    QTableView *tvProductLots;
    QTableView *tvDetails;

    void setupUi(QWidget *FtProductsOverview)
    {
        if (FtProductsOverview->objectName().isEmpty())
            FtProductsOverview->setObjectName(QString::fromUtf8("FtProductsOverview"));
        FtProductsOverview->resize(1294, 668);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/icons/Box.PNG"), QSize(), QIcon::Normal, QIcon::Off);
        FtProductsOverview->setWindowIcon(icon);
        pbClose = new QPushButton(FtProductsOverview);
        pbClose->setObjectName(QString::fromUtf8("pbClose"));
        pbClose->setGeometry(QRect(220, 600, 80, 38));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/icons/Actions-window-close-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbClose->setIcon(icon1);
        pbClose->setIconSize(QSize(32, 32));
        widget = new QWidget(FtProductsOverview);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(9, 9, 211, 24));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        rbAll = new QRadioButton(widget);
        rbAll->setObjectName(QString::fromUtf8("rbAll"));
        rbAll->setChecked(true);

        horizontalLayout->addWidget(rbAll);

        rbVasi = new QRadioButton(widget);
        rbVasi->setObjectName(QString::fromUtf8("rbVasi"));

        horizontalLayout->addWidget(rbVasi);

        rbTappi = new QRadioButton(widget);
        rbTappi->setObjectName(QString::fromUtf8("rbTappi"));

        horizontalLayout->addWidget(rbTappi);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        widget1 = new QWidget(FtProductsOverview);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(9, 39, 522, 226));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        cbWhat = new QComboBox(widget1);
        cbWhat->setObjectName(QString::fromUtf8("cbWhat"));
        cbWhat->setEditable(true);
        cbWhat->setInsertPolicy(QComboBox::NoInsert);

        verticalLayout->addWidget(cbWhat);

        tvProductLots = new QTableView(widget1);
        tvProductLots->setObjectName(QString::fromUtf8("tvProductLots"));
        tvProductLots->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tvProductLots->setSelectionMode(QAbstractItemView::SingleSelection);
        tvProductLots->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout->addWidget(tvProductLots);


        horizontalLayout_2->addLayout(verticalLayout);

        tvDetails = new QTableView(widget1);
        tvDetails->setObjectName(QString::fromUtf8("tvDetails"));

        horizontalLayout_2->addWidget(tvDetails);


        retranslateUi(FtProductsOverview);

        QMetaObject::connectSlotsByName(FtProductsOverview);
    } // setupUi

    void retranslateUi(QWidget *FtProductsOverview)
    {
        FtProductsOverview->setWindowTitle(QCoreApplication::translate("FtProductsOverview", "Form", nullptr));
        pbClose->setText(QCoreApplication::translate("FtProductsOverview", "Chiudi", nullptr));
        rbAll->setText(QCoreApplication::translate("FtProductsOverview", "Tutto", nullptr));
        rbVasi->setText(QCoreApplication::translate("FtProductsOverview", "Vasi", nullptr));
        rbTappi->setText(QCoreApplication::translate("FtProductsOverview", "Tappi", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FtProductsOverview: public Ui_FtProductsOverview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FTPRODUCTSOVERVIEW_H
