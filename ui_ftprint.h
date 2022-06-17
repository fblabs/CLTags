/********************************************************************************
** Form generated from reading UI file 'ftprint.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FTPRINT_H
#define UI_FTPRINT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FTPrint
{
public:
    QVBoxLayout *verticalLayout;
    QTextEdit *teDoc;
    QHBoxLayout *horizontalLayout;
    QPushButton *pbPrint;
    QPushButton *pbClose;

    void setupUi(QWidget *FTPrint)
    {
        if (FTPrint->objectName().isEmpty())
            FTPrint->setObjectName(QString::fromUtf8("FTPrint"));
        FTPrint->resize(1176, 518);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/icons/print-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        FTPrint->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(FTPrint);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        teDoc = new QTextEdit(FTPrint);
        teDoc->setObjectName(QString::fromUtf8("teDoc"));

        verticalLayout->addWidget(teDoc);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pbPrint = new QPushButton(FTPrint);
        pbPrint->setObjectName(QString::fromUtf8("pbPrint"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/icons/Printer-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbPrint->setIcon(icon1);
        pbPrint->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(pbPrint);

        pbClose = new QPushButton(FTPrint);
        pbClose->setObjectName(QString::fromUtf8("pbClose"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resources/icons/Actions-window-close-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbClose->setIcon(icon2);
        pbClose->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(pbClose);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(FTPrint);

        QMetaObject::connectSlotsByName(FTPrint);
    } // setupUi

    void retranslateUi(QWidget *FTPrint)
    {
        FTPrint->setWindowTitle(QCoreApplication::translate("FTPrint", "Stampa", nullptr));
        pbPrint->setText(QCoreApplication::translate("FTPrint", "Stampa", nullptr));
        pbClose->setText(QCoreApplication::translate("FTPrint", "Chiudi", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FTPrint: public Ui_FTPrint {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FTPRINT_H
