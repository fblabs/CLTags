/********************************************************************************
** Form generated from reading UI file 'ftagsoverview.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FTAGSOVERVIEW_H
#define UI_FTAGSOVERVIEW_H

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

class Ui_FTagsOverview
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QTableView *tags_view;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QTableView *tags_mov_view;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pbDefinizione;
    QPushButton *pbLoad;
    QPushButton *pbUnload;
    QPushButton *pbClose;

    void setupUi(QWidget *FTagsOverview)
    {
        if (FTagsOverview->objectName().isEmpty())
            FTagsOverview->setObjectName(QString::fromUtf8("FTagsOverview"));
        FTagsOverview->setWindowModality(Qt::ApplicationModal);
        FTagsOverview->resize(1102, 603);
        verticalLayout_3 = new QVBoxLayout(FTagsOverview);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(FTagsOverview);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);


        verticalLayout->addLayout(horizontalLayout);

        tags_view = new QTableView(FTagsOverview);
        tags_view->setObjectName(QString::fromUtf8("tags_view"));
        tags_view->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tags_view->setAlternatingRowColors(true);
        tags_view->setSelectionMode(QAbstractItemView::SingleSelection);
        tags_view->setSelectionBehavior(QAbstractItemView::SelectRows);
        tags_view->horizontalHeader()->setStretchLastSection(true);
        tags_view->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(tags_view);


        horizontalLayout_4->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(FTagsOverview);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);


        verticalLayout_2->addLayout(horizontalLayout_3);

        tags_mov_view = new QTableView(FTagsOverview);
        tags_mov_view->setObjectName(QString::fromUtf8("tags_mov_view"));
        tags_mov_view->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tags_mov_view->setProperty("showDropIndicator", QVariant(false));
        tags_mov_view->setDragDropOverwriteMode(false);
        tags_mov_view->setAlternatingRowColors(true);
        tags_mov_view->setSelectionMode(QAbstractItemView::SingleSelection);
        tags_mov_view->setSelectionBehavior(QAbstractItemView::SelectRows);
        tags_mov_view->setSortingEnabled(true);
        tags_mov_view->horizontalHeader()->setStretchLastSection(true);
        tags_mov_view->verticalHeader()->setVisible(false);

        verticalLayout_2->addWidget(tags_mov_view);


        horizontalLayout_4->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pbDefinizione = new QPushButton(FTagsOverview);
        pbDefinizione->setObjectName(QString::fromUtf8("pbDefinizione"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/icons/7627459_app_tools_logo_apple_reminders_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbDefinizione->setIcon(icon);
        pbDefinizione->setIconSize(QSize(32, 32));

        horizontalLayout_2->addWidget(pbDefinizione);

        pbLoad = new QPushButton(FTagsOverview);
        pbLoad->setObjectName(QString::fromUtf8("pbLoad"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/icons/Arrow-Down.PNG"), QSize(), QIcon::Normal, QIcon::Off);
        pbLoad->setIcon(icon1);
        pbLoad->setIconSize(QSize(32, 32));

        horizontalLayout_2->addWidget(pbLoad);

        pbUnload = new QPushButton(FTagsOverview);
        pbUnload->setObjectName(QString::fromUtf8("pbUnload"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resources/icons/Arrow-Up.PNG"), QSize(), QIcon::Normal, QIcon::Off);
        pbUnload->setIcon(icon2);
        pbUnload->setIconSize(QSize(32, 32));

        horizontalLayout_2->addWidget(pbUnload);

        pbClose = new QPushButton(FTagsOverview);
        pbClose->setObjectName(QString::fromUtf8("pbClose"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/resources/icons/Actions-window-close-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbClose->setIcon(icon3);
        pbClose->setIconSize(QSize(32, 32));

        horizontalLayout_2->addWidget(pbClose);


        verticalLayout_3->addLayout(horizontalLayout_2);


        retranslateUi(FTagsOverview);

        QMetaObject::connectSlotsByName(FTagsOverview);
    } // setupUi

    void retranslateUi(QWidget *FTagsOverview)
    {
        FTagsOverview->setWindowTitle(QCoreApplication::translate("FTagsOverview", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("FTagsOverview", "Definizioni", nullptr));
        label_3->setText(QCoreApplication::translate("FTagsOverview", "Movimenti", nullptr));
        pbDefinizione->setText(QCoreApplication::translate("FTagsOverview", "Definizione", nullptr));
        pbLoad->setText(QCoreApplication::translate("FTagsOverview", "Carico", nullptr));
        pbUnload->setText(QCoreApplication::translate("FTagsOverview", "Scarico", nullptr));
        pbClose->setText(QCoreApplication::translate("FTagsOverview", "Chiudi", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FTagsOverview: public Ui_FTagsOverview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FTAGSOVERVIEW_H
