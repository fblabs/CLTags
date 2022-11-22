/********************************************************************************
** Form generated from reading UI file 'ftsettings.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FTSETTINGS_H
#define UI_FTSETTINGS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FTSettings
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *leServer;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLineEdit *lePassword;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *leGenericCustomerID;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QLineEdit *leGenericSupplier;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *leGenericProductID;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pbSave;
    QPushButton *pbClose;

    void setupUi(QWidget *FTSettings)
    {
        if (FTSettings->objectName().isEmpty())
            FTSettings->setObjectName(QString::fromUtf8("FTSettings"));
        FTSettings->setWindowModality(Qt::ApplicationModal);
        FTSettings->resize(400, 234);
        verticalLayout = new QVBoxLayout(FTSettings);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(FTSettings);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(130, 0));

        horizontalLayout->addWidget(label);

        leServer = new QLineEdit(FTSettings);
        leServer->setObjectName(QString::fromUtf8("leServer"));

        horizontalLayout->addWidget(leServer);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_4 = new QLabel(FTSettings);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(130, 0));

        horizontalLayout_5->addWidget(label_4);

        lePassword = new QLineEdit(FTSettings);
        lePassword->setObjectName(QString::fromUtf8("lePassword"));
        lePassword->setMinimumSize(QSize(130, 0));
        lePassword->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_5->addWidget(lePassword);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(FTSettings);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(130, 0));

        horizontalLayout_2->addWidget(label_2);

        leGenericCustomerID = new QLineEdit(FTSettings);
        leGenericCustomerID->setObjectName(QString::fromUtf8("leGenericCustomerID"));

        horizontalLayout_2->addWidget(leGenericCustomerID);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_5 = new QLabel(FTSettings);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(130, 0));

        horizontalLayout_6->addWidget(label_5);

        leGenericSupplier = new QLineEdit(FTSettings);
        leGenericSupplier->setObjectName(QString::fromUtf8("leGenericSupplier"));

        horizontalLayout_6->addWidget(leGenericSupplier);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(FTSettings);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(130, 0));

        horizontalLayout_3->addWidget(label_3);

        leGenericProductID = new QLineEdit(FTSettings);
        leGenericProductID->setObjectName(QString::fromUtf8("leGenericProductID"));

        horizontalLayout_3->addWidget(leGenericProductID);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 35, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        pbSave = new QPushButton(FTSettings);
        pbSave->setObjectName(QString::fromUtf8("pbSave"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/icons/save-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbSave->setIcon(icon);

        horizontalLayout_4->addWidget(pbSave);

        pbClose = new QPushButton(FTSettings);
        pbClose->setObjectName(QString::fromUtf8("pbClose"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/icons/Actions-window-close-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbClose->setIcon(icon1);

        horizontalLayout_4->addWidget(pbClose);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(FTSettings);

        QMetaObject::connectSlotsByName(FTSettings);
    } // setupUi

    void retranslateUi(QWidget *FTSettings)
    {
        FTSettings->setWindowTitle(QCoreApplication::translate("FTSettings", "Impostazioni", nullptr));
        label->setText(QCoreApplication::translate("FTSettings", "Server:", nullptr));
        label_4->setText(QCoreApplication::translate("FTSettings", "Password:", nullptr));
        label_2->setText(QCoreApplication::translate("FTSettings", "Ciente generico:", nullptr));
        label_5->setText(QCoreApplication::translate("FTSettings", "Fornitore Generico:", nullptr));
        label_3->setText(QCoreApplication::translate("FTSettings", "Prodotto Generico:", nullptr));
        pbSave->setText(QCoreApplication::translate("FTSettings", "Salva", nullptr));
        pbClose->setText(QCoreApplication::translate("FTSettings", "Chiudi", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FTSettings: public Ui_FTSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FTSETTINGS_H
