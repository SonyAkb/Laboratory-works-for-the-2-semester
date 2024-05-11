/********************************************************************************
** Form generated from reading UI file 'messgae_window.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSGAE_WINDOW_H
#define UI_MESSGAE_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Messgae_window
{
public:
    QLabel *label_mes;
    QPushButton *pushButton_ok;

    void setupUi(QDialog *Messgae_window)
    {
        if (Messgae_window->objectName().isEmpty())
            Messgae_window->setObjectName(QString::fromUtf8("Messgae_window"));
        Messgae_window->resize(523, 239);
        label_mes = new QLabel(Messgae_window);
        label_mes->setObjectName(QString::fromUtf8("label_mes"));
        label_mes->setGeometry(QRect(10, 80, 501, 41));
        QFont font;
        font.setPointSize(20);
        label_mes->setFont(font);
        pushButton_ok = new QPushButton(Messgae_window);
        pushButton_ok->setObjectName(QString::fromUtf8("pushButton_ok"));
        pushButton_ok->setGeometry(QRect(210, 170, 101, 41));
        pushButton_ok->setFont(font);

        retranslateUi(Messgae_window);

        QMetaObject::connectSlotsByName(Messgae_window);
    } // setupUi

    void retranslateUi(QDialog *Messgae_window)
    {
        Messgae_window->setWindowTitle(QApplication::translate("Messgae_window", "Dialog", nullptr));
        label_mes->setText(QApplication::translate("Messgae_window", "\320\236\321\210\320\270\320\261\320\272\320\260", nullptr));
        pushButton_ok->setText(QApplication::translate("Messgae_window", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Messgae_window: public Ui_Messgae_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSGAE_WINDOW_H
