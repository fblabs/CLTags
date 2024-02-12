/********************************************************************************
** Form generated from reading UI file 'ftaddcontainer.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FTADDCONTAINER_H
#define UI_FTADDCONTAINER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FtAddContainer
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableView *tvContainers;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QPushButton *pbClose;

    void setupUi(QWidget *FtAddContainer)
    {
        if (FtAddContainer->objectName().isEmpty())
            FtAddContainer->setObjectName(QString::fromUtf8("FtAddContainer"));
        FtAddContainer->setWindowModality(Qt::ApplicationModal);
        FtAddContainer->resize(431, 280);
        verticalLayout_2 = new QVBoxLayout(FtAddContainer);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(FtAddContainer);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        tvContainers = new QTableView(FtAddContainer);
        tvContainers->setObjectName(QString::fromUtf8("tvContainers"));
        tvContainers->setMaximumSize(QSize(16777215, 16777215));
        tvContainers->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tvContainers->setSelectionBehavior(QAbstractItemView::SelectRows);
        tvContainers->horizontalHeader()->setStretchLastSection(true);

        verticalLayout->addWidget(tvContainers);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton = new QPushButton(FtAddContainer);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/icons/8704069_premium_plus_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(32, 32));

        horizontalLayout_2->addWidget(pushButton);

        pbClose = new QPushButton(FtAddContainer);
        pbClose->setObjectName(QString::fromUtf8("pbClose"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/icons/8712836_fire_iso_premium_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbClose->setIcon(icon1);
        pbClose->setIconSize(QSize(32, 32));

        horizontalLayout_2->addWidget(pbClose);


        verticalLayout_2->addLayout(horizontalLayout_2);


        retranslateUi(FtAddContainer);

        QMetaObject::connectSlotsByName(FtAddContainer);
    } // setupUi

    void retranslateUi(QWidget *FtAddContainer)
    {
        FtAddContainer->setWindowTitle(QCoreApplication::translate("FtAddContainer", "Form", nullptr));
        label->setText(QCoreApplication::translate("FtAddContainer", "Contenitori da aggiungere:", nullptr));
        pushButton->setText(QCoreApplication::translate("FtAddContainer", "Aggiungi selezionati", nullptr));
        pbClose->setText(QCoreApplication::translate("FtAddContainer", "Chiudi", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FtAddContainer: public Ui_FtAddContainer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FTADDCONTAINER_H
