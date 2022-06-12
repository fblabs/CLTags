/********************************************************************************
** Form generated from reading UI file 'ftagsunload.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FTAGSUNLOAD_H
#define UI_FTAGSUNLOAD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FTagsUnload
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QDateEdit *dateEdit;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton;
    QPushButton *pbClose;

    void setupUi(QWidget *FTagsUnload)
    {
        if (FTagsUnload->objectName().isEmpty())
            FTagsUnload->setObjectName(QString::fromUtf8("FTagsUnload"));
        FTagsUnload->resize(442, 278);
        widget = new QWidget(FTagsUnload);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(80, 0));
        label_3->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_3->addWidget(label_3);

        dateEdit = new QDateEdit(widget);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));

        horizontalLayout_3->addWidget(dateEdit);

        widget1 = new QWidget(FTagsUnload);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        horizontalLayout_4 = new QHBoxLayout(widget1);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(widget1);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_4->addWidget(pushButton);

        pbClose = new QPushButton(widget1);
        pbClose->setObjectName(QString::fromUtf8("pbClose"));

        horizontalLayout_4->addWidget(pbClose);


        retranslateUi(FTagsUnload);

        QMetaObject::connectSlotsByName(FTagsUnload);
    } // setupUi

    void retranslateUi(QWidget *FTagsUnload)
    {
        FTagsUnload->setWindowTitle(QCoreApplication::translate("FTagsUnload", "Scarico", nullptr));
        label_3->setText(QCoreApplication::translate("FTagsUnload", "Data:", nullptr));
        pushButton->setText(QCoreApplication::translate("FTagsUnload", "Salva", nullptr));
        pbClose->setText(QCoreApplication::translate("FTagsUnload", "Chiudi", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FTagsUnload: public Ui_FTagsUnload {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FTAGSUNLOAD_H
