/********************************************************************************
** Form generated from reading UI file 'ftagsdef.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FTAGSDEF_H
#define UI_FTAGSDEF_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FTagsDef
{
public:

    void setupUi(QWidget *FTagsDef)
    {
        if (FTagsDef->objectName().isEmpty())
            FTagsDef->setObjectName(QString::fromUtf8("FTagsDef"));
        FTagsDef->resize(543, 581);

        retranslateUi(FTagsDef);

        QMetaObject::connectSlotsByName(FTagsDef);
    } // setupUi

    void retranslateUi(QWidget *FTagsDef)
    {
        FTagsDef->setWindowTitle(QCoreApplication::translate("FTagsDef", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FTagsDef: public Ui_FTagsDef {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FTAGSDEF_H
