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
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FTImage
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *lbImage;
    QPushButton *pbClose;

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

        pbClose = new QPushButton(FTImage);
        pbClose->setObjectName(QString::fromUtf8("pbClose"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/icons/Actions-window-close-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbClose->setIcon(icon);
        pbClose->setIconSize(QSize(32, 32));

        verticalLayout->addWidget(pbClose);


        retranslateUi(FTImage);

        QMetaObject::connectSlotsByName(FTImage);
    } // setupUi

    void retranslateUi(QWidget *FTImage)
    {
        FTImage->setWindowTitle(QCoreApplication::translate("FTImage", "Ingrandimento Immagine", nullptr));
        lbImage->setText(QString());
        pbClose->setText(QCoreApplication::translate("FTImage", "Chiudi", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FTImage: public Ui_FTImage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FTIMAGE_H
