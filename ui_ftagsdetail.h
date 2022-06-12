/********************************************************************************
** Form generated from reading UI file 'ftagsdetail.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FTAGSDETAIL_H
#define UI_FTAGSDETAIL_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FtagsDetail
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *cbClienti;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *cbProdotti;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QComboBox *cbTipo;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLineEdit *leBarcode;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *leSpecifica;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QTextEdit *teNote;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pbSave;
    QPushButton *pbClose;

    void setupUi(QWidget *FtagsDetail)
    {
        if (FtagsDetail->objectName().isEmpty())
            FtagsDetail->setObjectName(QString::fromUtf8("FtagsDetail"));
        FtagsDetail->setWindowModality(Qt::ApplicationModal);
        FtagsDetail->resize(511, 395);
        verticalLayout_2 = new QVBoxLayout(FtagsDetail);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(FtagsDetail);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(80, 0));
        label->setMaximumSize(QSize(80, 16777215));

        horizontalLayout->addWidget(label);

        cbClienti = new QComboBox(FtagsDetail);
        cbClienti->setObjectName(QString::fromUtf8("cbClienti"));
        cbClienti->setMinimumSize(QSize(365, 0));
        cbClienti->setEditable(true);
        cbClienti->setInsertPolicy(QComboBox::NoInsert);

        horizontalLayout->addWidget(cbClienti);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(FtagsDetail);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(80, 0));
        label_2->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_2->addWidget(label_2);

        cbProdotti = new QComboBox(FtagsDetail);
        cbProdotti->setObjectName(QString::fromUtf8("cbProdotti"));
        cbProdotti->setEditable(true);
        cbProdotti->setInsertPolicy(QComboBox::NoInsert);

        horizontalLayout_2->addWidget(cbProdotti);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(FtagsDetail);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(80, 0));
        label_3->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_3->addWidget(label_3);

        cbTipo = new QComboBox(FtagsDetail);
        cbTipo->setObjectName(QString::fromUtf8("cbTipo"));
        cbTipo->setEditable(true);
        cbTipo->setInsertPolicy(QComboBox::NoInsert);

        horizontalLayout_3->addWidget(cbTipo);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(FtagsDetail);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(80, 0));
        label_5->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_4->addWidget(label_5);

        leBarcode = new QLineEdit(FtagsDetail);
        leBarcode->setObjectName(QString::fromUtf8("leBarcode"));
        leBarcode->setMaxLength(13);

        horizontalLayout_4->addWidget(leBarcode);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_6 = new QLabel(FtagsDetail);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(80, 0));
        label_6->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_6->addWidget(label_6);

        leSpecifica = new QLineEdit(FtagsDetail);
        leSpecifica->setObjectName(QString::fromUtf8("leSpecifica"));
        leSpecifica->setMaxLength(13);

        horizontalLayout_6->addWidget(leSpecifica);


        verticalLayout_2->addLayout(horizontalLayout_6);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_4 = new QLabel(FtagsDetail);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMaximumSize(QSize(16777215, 10));

        verticalLayout->addWidget(label_4);

        teNote = new QTextEdit(FtagsDetail);
        teNote->setObjectName(QString::fromUtf8("teNote"));
        teNote->setMinimumSize(QSize(0, 100));
        teNote->setMaximumSize(QSize(16777215, 100));

        verticalLayout->addWidget(teNote);


        verticalLayout_2->addLayout(verticalLayout);

        verticalSpacer = new QSpacerItem(20, 42, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        pbSave = new QPushButton(FtagsDetail);
        pbSave->setObjectName(QString::fromUtf8("pbSave"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/icons/save-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbSave->setIcon(icon);
        pbSave->setIconSize(QSize(32, 32));

        horizontalLayout_5->addWidget(pbSave);

        pbClose = new QPushButton(FtagsDetail);
        pbClose->setObjectName(QString::fromUtf8("pbClose"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/icons/8712836_fire_iso_premium_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbClose->setIcon(icon1);
        pbClose->setIconSize(QSize(32, 32));

        horizontalLayout_5->addWidget(pbClose);


        verticalLayout_2->addLayout(horizontalLayout_5);


        retranslateUi(FtagsDetail);

        QMetaObject::connectSlotsByName(FtagsDetail);
    } // setupUi

    void retranslateUi(QWidget *FtagsDetail)
    {
        FtagsDetail->setWindowTitle(QCoreApplication::translate("FtagsDetail", "Dettagli ", nullptr));
        label->setText(QCoreApplication::translate("FtagsDetail", "Cliente:", nullptr));
        label_2->setText(QCoreApplication::translate("FtagsDetail", "Prodotto:", nullptr));
        label_3->setText(QCoreApplication::translate("FtagsDetail", "Tipo:", nullptr));
        label_5->setText(QCoreApplication::translate("FtagsDetail", "Barcode:", nullptr));
        label_6->setText(QCoreApplication::translate("FtagsDetail", "Specifica:", nullptr));
        label_4->setText(QCoreApplication::translate("FtagsDetail", "Note:", nullptr));
        pbSave->setText(QCoreApplication::translate("FtagsDetail", "Salva", nullptr));
        pbClose->setText(QCoreApplication::translate("FtagsDetail", "Chiudi", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FtagsDetail: public Ui_FtagsDetail {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FTAGSDETAIL_H
