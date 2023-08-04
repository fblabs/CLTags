/********************************************************************************
** Form generated from reading UI file 'ftupdate_tag.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FTUPDATE_TAG_H
#define UI_FTUPDATE_TAG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FtUpdate_Tag
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *leProdotto;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QTextEdit *teNote;
    QFormLayout *formLayout;
    QLabel *label_3;
    QLineEdit *le_giacenza_minima;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pbSave;
    QPushButton *pbClose;

    void setupUi(QWidget *FtUpdate_Tag)
    {
        if (FtUpdate_Tag->objectName().isEmpty())
            FtUpdate_Tag->setObjectName(QString::fromUtf8("FtUpdate_Tag"));
        FtUpdate_Tag->setWindowModality(Qt::ApplicationModal);
        FtUpdate_Tag->resize(503, 342);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/icons/Box.PNG"), QSize(), QIcon::Normal, QIcon::Off);
        FtUpdate_Tag->setWindowIcon(icon);
        verticalLayout_2 = new QVBoxLayout(FtUpdate_Tag);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(FtUpdate_Tag);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        leProdotto = new QLineEdit(FtUpdate_Tag);
        leProdotto->setObjectName(QString::fromUtf8("leProdotto"));
        leProdotto->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 127);"));
        leProdotto->setReadOnly(true);

        horizontalLayout->addWidget(leProdotto);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(FtUpdate_Tag);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        teNote = new QTextEdit(FtUpdate_Tag);
        teNote->setObjectName(QString::fromUtf8("teNote"));

        verticalLayout->addWidget(teNote);


        verticalLayout_2->addLayout(verticalLayout);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_3 = new QLabel(FtUpdate_Tag);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        le_giacenza_minima = new QLineEdit(FtUpdate_Tag);
        le_giacenza_minima->setObjectName(QString::fromUtf8("le_giacenza_minima"));
        le_giacenza_minima->setMinimumSize(QSize(80, 0));
        le_giacenza_minima->setMaximumSize(QSize(80, 16777215));

        formLayout->setWidget(0, QFormLayout::FieldRole, le_giacenza_minima);


        verticalLayout_2->addLayout(formLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pbSave = new QPushButton(FtUpdate_Tag);
        pbSave->setObjectName(QString::fromUtf8("pbSave"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/icons/save-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbSave->setIcon(icon1);
        pbSave->setIconSize(QSize(32, 32));

        horizontalLayout_2->addWidget(pbSave);

        pbClose = new QPushButton(FtUpdate_Tag);
        pbClose->setObjectName(QString::fromUtf8("pbClose"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resources/icons/Actions-window-close-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbClose->setIcon(icon2);
        pbClose->setIconSize(QSize(32, 32));

        horizontalLayout_2->addWidget(pbClose);


        verticalLayout_2->addLayout(horizontalLayout_2);


        retranslateUi(FtUpdate_Tag);

        QMetaObject::connectSlotsByName(FtUpdate_Tag);
    } // setupUi

    void retranslateUi(QWidget *FtUpdate_Tag)
    {
        FtUpdate_Tag->setWindowTitle(QCoreApplication::translate("FtUpdate_Tag", "Modifica ", nullptr));
        label->setText(QCoreApplication::translate("FtUpdate_Tag", "Prodotto:", nullptr));
        label_2->setText(QCoreApplication::translate("FtUpdate_Tag", "Note", nullptr));
        label_3->setText(QCoreApplication::translate("FtUpdate_Tag", "Giacenza minima:", nullptr));
        pbSave->setText(QCoreApplication::translate("FtUpdate_Tag", "Salva", nullptr));
        pbClose->setText(QCoreApplication::translate("FtUpdate_Tag", "Chiudi", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FtUpdate_Tag: public Ui_FtUpdate_Tag {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FTUPDATE_TAG_H
