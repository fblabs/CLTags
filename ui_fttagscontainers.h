/********************************************************************************
** Form generated from reading UI file 'fttagscontainers.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FTTAGSCONTAINERS_H
#define UI_FTTAGSCONTAINERS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FtTagsContainers
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QTableView *tvContainers;
    QTableView *tableView_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pbNewContainer;
    QPushButton *pbClose;

    void setupUi(QWidget *FtTagsContainers)
    {
        if (FtTagsContainers->objectName().isEmpty())
            FtTagsContainers->setObjectName(QString::fromUtf8("FtTagsContainers"));
        FtTagsContainers->setWindowModality(Qt::ApplicationModal);
        FtTagsContainers->resize(1291, 708);
        verticalLayout = new QVBoxLayout(FtTagsContainers);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        tvContainers = new QTableView(FtTagsContainers);
        tvContainers->setObjectName(QString::fromUtf8("tvContainers"));
        tvContainers->setMinimumSize(QSize(300, 0));
        tvContainers->setMaximumSize(QSize(300, 16777215));
        tvContainers->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tvContainers->setAlternatingRowColors(true);
        tvContainers->setSelectionMode(QAbstractItemView::SingleSelection);
        tvContainers->setSelectionBehavior(QAbstractItemView::SelectRows);
        tvContainers->setSortingEnabled(true);
        tvContainers->verticalHeader()->setVisible(false);

        horizontalLayout_2->addWidget(tvContainers);

        tableView_2 = new QTableView(FtTagsContainers);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));

        horizontalLayout_2->addWidget(tableView_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pbNewContainer = new QPushButton(FtTagsContainers);
        pbNewContainer->setObjectName(QString::fromUtf8("pbNewContainer"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/icons/8721738_add_plus_+_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbNewContainer->setIcon(icon);
        pbNewContainer->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(pbNewContainer);

        pbClose = new QPushButton(FtTagsContainers);
        pbClose->setObjectName(QString::fromUtf8("pbClose"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/icons/Actions-window-close-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbClose->setIcon(icon1);
        pbClose->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(pbClose);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(FtTagsContainers);

        QMetaObject::connectSlotsByName(FtTagsContainers);
    } // setupUi

    void retranslateUi(QWidget *FtTagsContainers)
    {
        FtTagsContainers->setWindowTitle(QCoreApplication::translate("FtTagsContainers", "Contenitori", nullptr));
#if QT_CONFIG(tooltip)
        pbNewContainer->setToolTip(QCoreApplication::translate("FtTagsContainers", "Nuovo lotto virtuale", nullptr));
#endif // QT_CONFIG(tooltip)
        pbNewContainer->setText(QCoreApplication::translate("FtTagsContainers", "Nuovo", nullptr));
#if QT_CONFIG(tooltip)
        pbClose->setToolTip(QCoreApplication::translate("FtTagsContainers", "Chiudi", nullptr));
#endif // QT_CONFIG(tooltip)
        pbClose->setText(QCoreApplication::translate("FtTagsContainers", "Chiudi", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FtTagsContainers: public Ui_FtTagsContainers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FTTAGSCONTAINERS_H
