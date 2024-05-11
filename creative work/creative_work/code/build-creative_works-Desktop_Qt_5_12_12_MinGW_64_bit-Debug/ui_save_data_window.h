/********************************************************************************
** Form generated from reading UI file 'save_data_window.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVE_DATA_WINDOW_H
#define UI_SAVE_DATA_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_save_data_window
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_phone;
    QLineEdit *lineEdit_phone;
    QLabel *label_name;
    QLineEdit *lineEdit_name;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLabel *label_S_in_1f_1;
    QLabel *label_found_1;
    QLabel *label_S_out_1f_1;
    QLabel *label_S_in_1f_2;
    QLabel *label_amount_floor_1;
    QLabel *label_S_out_1f_2;
    QLabel *label_electrics_1;
    QLabel *label_S_in_all_1;
    QLabel *label_sheathing_1;
    QLabel *label_amount_floor_2;
    QLabel *label_S_in_all_2;
    QLabel *label_plumbing_1;
    QLabel *label_hot_floor_1;
    QLabel *label_found_2;
    QLabel *label_sheathing_2;
    QLabel *label_plumbing_2;
    QLabel *label_electrics_2;
    QLabel *label_hot_floor_2;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_result_1;
    QLabel *label_result_2;
    QPushButton *pushButton_save;
    QPushButton *pushButton_cansel;
    QLabel *label_title;

    void setupUi(QDialog *save_data_window)
    {
        if (save_data_window->objectName().isEmpty())
            save_data_window->setObjectName(QString::fromUtf8("save_data_window"));
        save_data_window->resize(783, 662);
        gridLayoutWidget = new QWidget(save_data_window);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 60, 741, 91));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_phone = new QLabel(gridLayoutWidget);
        label_phone->setObjectName(QString::fromUtf8("label_phone"));
        QFont font;
        font.setPointSize(17);
        label_phone->setFont(font);

        gridLayout->addWidget(label_phone, 1, 0, 1, 1);

        lineEdit_phone = new QLineEdit(gridLayoutWidget);
        lineEdit_phone->setObjectName(QString::fromUtf8("lineEdit_phone"));
        lineEdit_phone->setFont(font);

        gridLayout->addWidget(lineEdit_phone, 1, 1, 1, 1);

        label_name = new QLabel(gridLayoutWidget);
        label_name->setObjectName(QString::fromUtf8("label_name"));
        label_name->setFont(font);

        gridLayout->addWidget(label_name, 0, 0, 1, 1);

        lineEdit_name = new QLineEdit(gridLayoutWidget);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        lineEdit_name->setFont(font);

        gridLayout->addWidget(lineEdit_name, 0, 1, 1, 1);

        gridLayoutWidget_2 = new QWidget(save_data_window);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(20, 180, 741, 381));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_S_in_1f_1 = new QLabel(gridLayoutWidget_2);
        label_S_in_1f_1->setObjectName(QString::fromUtf8("label_S_in_1f_1"));
        label_S_in_1f_1->setFont(font);

        gridLayout_2->addWidget(label_S_in_1f_1, 2, 0, 1, 1);

        label_found_1 = new QLabel(gridLayoutWidget_2);
        label_found_1->setObjectName(QString::fromUtf8("label_found_1"));
        label_found_1->setFont(font);

        gridLayout_2->addWidget(label_found_1, 4, 0, 1, 1);

        label_S_out_1f_1 = new QLabel(gridLayoutWidget_2);
        label_S_out_1f_1->setObjectName(QString::fromUtf8("label_S_out_1f_1"));
        label_S_out_1f_1->setFont(font);

        gridLayout_2->addWidget(label_S_out_1f_1, 1, 0, 1, 1);

        label_S_in_1f_2 = new QLabel(gridLayoutWidget_2);
        label_S_in_1f_2->setObjectName(QString::fromUtf8("label_S_in_1f_2"));
        label_S_in_1f_2->setFont(font);

        gridLayout_2->addWidget(label_S_in_1f_2, 2, 1, 1, 1);

        label_amount_floor_1 = new QLabel(gridLayoutWidget_2);
        label_amount_floor_1->setObjectName(QString::fromUtf8("label_amount_floor_1"));
        label_amount_floor_1->setFont(font);

        gridLayout_2->addWidget(label_amount_floor_1, 0, 0, 1, 1);

        label_S_out_1f_2 = new QLabel(gridLayoutWidget_2);
        label_S_out_1f_2->setObjectName(QString::fromUtf8("label_S_out_1f_2"));
        label_S_out_1f_2->setFont(font);

        gridLayout_2->addWidget(label_S_out_1f_2, 1, 1, 1, 1);

        label_electrics_1 = new QLabel(gridLayoutWidget_2);
        label_electrics_1->setObjectName(QString::fromUtf8("label_electrics_1"));
        label_electrics_1->setFont(font);

        gridLayout_2->addWidget(label_electrics_1, 7, 0, 1, 1);

        label_S_in_all_1 = new QLabel(gridLayoutWidget_2);
        label_S_in_all_1->setObjectName(QString::fromUtf8("label_S_in_all_1"));
        label_S_in_all_1->setFont(font);

        gridLayout_2->addWidget(label_S_in_all_1, 3, 0, 1, 1);

        label_sheathing_1 = new QLabel(gridLayoutWidget_2);
        label_sheathing_1->setObjectName(QString::fromUtf8("label_sheathing_1"));
        label_sheathing_1->setFont(font);

        gridLayout_2->addWidget(label_sheathing_1, 5, 0, 1, 1);

        label_amount_floor_2 = new QLabel(gridLayoutWidget_2);
        label_amount_floor_2->setObjectName(QString::fromUtf8("label_amount_floor_2"));
        label_amount_floor_2->setFont(font);

        gridLayout_2->addWidget(label_amount_floor_2, 0, 1, 1, 1);

        label_S_in_all_2 = new QLabel(gridLayoutWidget_2);
        label_S_in_all_2->setObjectName(QString::fromUtf8("label_S_in_all_2"));
        label_S_in_all_2->setFont(font);

        gridLayout_2->addWidget(label_S_in_all_2, 3, 1, 1, 1);

        label_plumbing_1 = new QLabel(gridLayoutWidget_2);
        label_plumbing_1->setObjectName(QString::fromUtf8("label_plumbing_1"));
        label_plumbing_1->setFont(font);

        gridLayout_2->addWidget(label_plumbing_1, 6, 0, 1, 1);

        label_hot_floor_1 = new QLabel(gridLayoutWidget_2);
        label_hot_floor_1->setObjectName(QString::fromUtf8("label_hot_floor_1"));
        label_hot_floor_1->setFont(font);

        gridLayout_2->addWidget(label_hot_floor_1, 8, 0, 1, 1);

        label_found_2 = new QLabel(gridLayoutWidget_2);
        label_found_2->setObjectName(QString::fromUtf8("label_found_2"));
        label_found_2->setFont(font);

        gridLayout_2->addWidget(label_found_2, 4, 1, 1, 1);

        label_sheathing_2 = new QLabel(gridLayoutWidget_2);
        label_sheathing_2->setObjectName(QString::fromUtf8("label_sheathing_2"));
        label_sheathing_2->setFont(font);

        gridLayout_2->addWidget(label_sheathing_2, 5, 1, 1, 1);

        label_plumbing_2 = new QLabel(gridLayoutWidget_2);
        label_plumbing_2->setObjectName(QString::fromUtf8("label_plumbing_2"));
        label_plumbing_2->setFont(font);

        gridLayout_2->addWidget(label_plumbing_2, 6, 1, 1, 1);

        label_electrics_2 = new QLabel(gridLayoutWidget_2);
        label_electrics_2->setObjectName(QString::fromUtf8("label_electrics_2"));
        label_electrics_2->setFont(font);

        gridLayout_2->addWidget(label_electrics_2, 7, 1, 1, 1);

        label_hot_floor_2 = new QLabel(gridLayoutWidget_2);
        label_hot_floor_2->setObjectName(QString::fromUtf8("label_hot_floor_2"));
        label_hot_floor_2->setFont(font);

        gridLayout_2->addWidget(label_hot_floor_2, 8, 1, 1, 1);

        horizontalLayoutWidget = new QWidget(save_data_window);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 600, 478, 41));
        QFont font1;
        font1.setPointSize(18);
        horizontalLayoutWidget->setFont(font1);
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_result_1 = new QLabel(horizontalLayoutWidget);
        label_result_1->setObjectName(QString::fromUtf8("label_result_1"));
        label_result_1->setFont(font1);

        horizontalLayout->addWidget(label_result_1);

        label_result_2 = new QLabel(horizontalLayoutWidget);
        label_result_2->setObjectName(QString::fromUtf8("label_result_2"));
        label_result_2->setFont(font1);

        horizontalLayout->addWidget(label_result_2);

        pushButton_save = new QPushButton(save_data_window);
        pushButton_save->setObjectName(QString::fromUtf8("pushButton_save"));
        pushButton_save->setGeometry(QRect(510, 590, 121, 51));
        pushButton_save->setFont(font);
        pushButton_cansel = new QPushButton(save_data_window);
        pushButton_cansel->setObjectName(QString::fromUtf8("pushButton_cansel"));
        pushButton_cansel->setGeometry(QRect(640, 590, 121, 51));
        pushButton_cansel->setFont(font);
        label_title = new QLabel(save_data_window);
        label_title->setObjectName(QString::fromUtf8("label_title"));
        label_title->setGeometry(QRect(560, 10, 201, 39));
        label_title->setFont(font);

        retranslateUi(save_data_window);

        QMetaObject::connectSlotsByName(save_data_window);
    } // setupUi

    void retranslateUi(QDialog *save_data_window)
    {
        save_data_window->setWindowTitle(QApplication::translate("save_data_window", "Dialog", nullptr));
        label_phone->setText(QApplication::translate("save_data_window", "\320\235\320\276\320\274\320\265\321\200 \321\202\320\265\320\273\320\265\321\204\320\276\320\275\320\260:", nullptr));
        label_name->setText(QApplication::translate("save_data_window", "\320\230\320\274\321\217 \320\277\320\276\320\272\321\203\320\277\320\260\321\202\320\265\320\273\321\217:", nullptr));
        label_S_in_1f_1->setText(QApplication::translate("save_data_window", "\320\237\320\273\320\276\321\211\320\260\320\264\321\214 \320\262\320\275\321\203\321\202\321\200\320\265\320\275\320\275\321\217\321\217 (1 \321\215\321\202\320\260\320\266)", nullptr));
        label_found_1->setText(QApplication::translate("save_data_window", "\320\244\321\203\320\275\320\264\320\260\320\274\320\265\320\275\321\202", nullptr));
        label_S_out_1f_1->setText(QApplication::translate("save_data_window", "\320\237\320\273\320\276\321\211\320\260\320\264\321\214 \320\262\320\275\320\265\321\210\320\275\321\217\321\217 (1 \321\215\321\202\320\260\320\266)", nullptr));
        label_S_in_1f_2->setText(QString());
        label_amount_floor_1->setText(QApplication::translate("save_data_window", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\215\321\202\320\260\320\266\320\265\320\271", nullptr));
        label_S_out_1f_2->setText(QString());
        label_electrics_1->setText(QApplication::translate("save_data_window", "\320\255\320\273\320\265\320\272\321\202\321\200\320\270\320\272\320\260", nullptr));
        label_S_in_all_1->setText(QApplication::translate("save_data_window", "\320\237\320\273\320\276\321\211\320\260\320\264\321\214 \320\262\320\275\321\203\321\202\321\200\320\265\320\275\320\275\321\217\321\217 (\320\262\321\201\321\217)", nullptr));
        label_sheathing_1->setText(QApplication::translate("save_data_window", "\320\236\320\261\321\210\320\270\320\262\320\272\320\260 (\320\262\320\275\321\203\321\202\321\200\320\270)", nullptr));
        label_amount_floor_2->setText(QApplication::translate("save_data_window", "---------------------------------------------------", nullptr));
        label_S_in_all_2->setText(QString());
        label_plumbing_1->setText(QApplication::translate("save_data_window", "\320\241\320\260\320\275\321\202\320\265\321\205\320\275\320\270\320\272\320\260", nullptr));
        label_hot_floor_1->setText(QApplication::translate("save_data_window", "\320\242\320\265\320\277\320\273\321\213\320\271 \320\277\320\276\320\273", nullptr));
        label_found_2->setText(QString());
        label_sheathing_2->setText(QString());
        label_plumbing_2->setText(QString());
        label_electrics_2->setText(QString());
        label_hot_floor_2->setText(QString());
        label_result_1->setText(QApplication::translate("save_data_window", "\320\230\321\202\320\276\320\263\320\276\320\262\320\260\321\217 \321\206\320\265\320\275\320\260", nullptr));
        label_result_2->setText(QApplication::translate("save_data_window", "----------------------------------", nullptr));
        pushButton_save->setText(QApplication::translate("save_data_window", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        pushButton_cansel->setText(QApplication::translate("save_data_window", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
        label_title->setText(QApplication::translate("save_data_window", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\264\320\260\320\275\320\275\321\213\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class save_data_window: public Ui_save_data_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVE_DATA_WINDOW_H
