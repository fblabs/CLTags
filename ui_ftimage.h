/********************************************************************************
** Form generated from reading UI file 'ftimage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FTIMAGE_H
#define UI_FTIMAGE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FTImage
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *lbImage;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *leBarcode;
    QPushButton *pbClose;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *FTImage)
    {
        if (FTImage->objectName().isEmpty())
            FTImage->setObjectName(QString::fromUtf8("FTImage"));
        FTImage->setWindowModality(Qt::ApplicationModal);
        FTImage->resize(1231, 658);
        verticalLayout = new QVBoxLayout(FTImage);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lbImage = new QLabel(FTImage);
        lbImage->setObjectName(QString::fromUtf8("lbImage"));
        lbImage->setFrameShape(QFrame::Box);
        lbImage->setScaledContents(true);

        verticalLayout->addWidget(lbImage);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(FTImage);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(50, 0));
        label_2->setMaximumSize(QSize(50, 16777215));

        horizontalLayout->addWidget(label_2);

        leBarcode = new QLineEdit(FTImage);
        leBarcode->setObjectName(QString::fromUtf8("leBarcode"));
        leBarcode->setMinimumSize(QSize(150, 0));
        leBarcode->setMaximumSize(QSize(150, 16777215));

        horizontalLayout->addWidget(leBarcode);

        pbClose = new QPushButton(FTImage);
        pbClose->setObjectName(QString::fromUtf8("pbClose"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/icons/Downright64.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbClose->setIcon(icon);
        pbClose->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(pbClose);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        horizontalLayout->setStretch(1, 1);

        horizontalLayout_2->addLayout(horizontalLayout);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(FTImage);

        QMetaObject::connectSlotsByName(FTImage);
    } // setupUi

    void retranslateUi(QWidget *FTImage)
    {
        FTImage->setWindowTitle(QCoreApplication::translate("FTImage", "Ingrandimento Immagine", nullptr));
        lbImage->setText(QString());
        label_2->setText(QCoreApplication::translate("FTImage", "Barcode:", nullptr));
        pbClose->setText(QCoreApplication::translate("FTImage", "Trasferisci e chiudi", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FTImage: public Ui_FTImage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FTIMAGE_H
