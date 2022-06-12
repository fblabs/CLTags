/********************************************************************************
** Form generated from reading UI file 'tassociations.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASSOCIATIONS_H
#define UI_TASSOCIATIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TAssociations
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QWidget *TAssociations)
    {
        if (TAssociations->objectName().isEmpty())
            TAssociations->setObjectName(QString::fromUtf8("TAssociations"));
        TAssociations->resize(587, 453);
        label = new QLabel(TAssociations);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 49, 16));
        label_2 = new QLabel(TAssociations);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 60, 49, 16));
        label_3 = new QLabel(TAssociations);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 110, 49, 16));

        retranslateUi(TAssociations);

        QMetaObject::connectSlotsByName(TAssociations);
    } // setupUi

    void retranslateUi(QWidget *TAssociations)
    {
        TAssociations->setWindowTitle(QCoreApplication::translate("TAssociations", "Form", nullptr));
        label->setText(QCoreApplication::translate("TAssociations", "Cliente:", nullptr));
        label_2->setText(QCoreApplication::translate("TAssociations", "Prodotto:", nullptr));
        label_3->setText(QCoreApplication::translate("TAssociations", "Tipo:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TAssociations: public Ui_TAssociations {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASSOCIATIONS_H
