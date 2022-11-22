/********************************************************************************
** Form generated from reading UI file 'ftnewcontainer.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FTNEWCONTAINER_H
#define UI_FTNEWCONTAINER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FtNewContainer
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *cbProducts;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QVBoxLayout *verticalLayout;
    QTextEdit *teNote;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pbSave;
    QPushButton *pbClose;

    void setupUi(QWidget *FtNewContainer)
    {
        if (FtNewContainer->objectName().isEmpty())
            FtNewContainer->setObjectName(QString::fromUtf8("FtNewContainer"));
        FtNewContainer->setWindowModality(Qt::ApplicationModal);
        FtNewContainer->resize(390, 376);
        verticalLayout_2 = new QVBoxLayout(FtNewContainer);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(FtNewContainer);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(80, 0));
        label->setMaximumSize(QSize(80, 16777215));

        horizontalLayout->addWidget(label);

        cbProducts = new QComboBox(FtNewContainer);
        cbProducts->setObjectName(QString::fromUtf8("cbProducts"));
        cbProducts->setEditable(true);

        horizontalLayout->addWidget(cbProducts);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));

        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_5 = new QLabel(FtNewContainer);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setTextFormat(Qt::PlainText);
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        horizontalLayout_2->addWidget(label_5);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        teNote = new QTextEdit(FtNewContainer);
        teNote->setObjectName(QString::fromUtf8("teNote"));
        teNote->setMinimumSize(QSize(0, 150));
        teNote->setMaximumSize(QSize(16777215, 150));

        verticalLayout->addWidget(teNote);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        pbSave = new QPushButton(FtNewContainer);
        pbSave->setObjectName(QString::fromUtf8("pbSave"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/icons/save-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbSave->setIcon(icon);
        pbSave->setIconSize(QSize(32, 32));

        horizontalLayout_7->addWidget(pbSave);

        pbClose = new QPushButton(FtNewContainer);
        pbClose->setObjectName(QString::fromUtf8("pbClose"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/icons/Actions-window-close-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbClose->setIcon(icon1);
        pbClose->setIconSize(QSize(32, 32));

        horizontalLayout_7->addWidget(pbClose);


        verticalLayout_2->addLayout(horizontalLayout_7);


        retranslateUi(FtNewContainer);

        QMetaObject::connectSlotsByName(FtNewContainer);
    } // setupUi

    void retranslateUi(QWidget *FtNewContainer)
    {
        FtNewContainer->setWindowTitle(QCoreApplication::translate("FtNewContainer", "Definizione Contenitore", nullptr));
        label->setText(QCoreApplication::translate("FtNewContainer", "Prodotto:", nullptr));
        label_5->setText(QCoreApplication::translate("FtNewContainer", "Note:", nullptr));
        pbSave->setText(QCoreApplication::translate("FtNewContainer", "Salva", nullptr));
        pbClose->setText(QCoreApplication::translate("FtNewContainer", "Chiudi", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FtNewContainer: public Ui_FtNewContainer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FTNEWCONTAINER_H
