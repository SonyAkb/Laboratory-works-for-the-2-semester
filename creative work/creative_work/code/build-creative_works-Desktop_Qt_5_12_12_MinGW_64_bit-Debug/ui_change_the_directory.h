/********************************************************************************
** Form generated from reading UI file 'change_the_directory.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGE_THE_DIRECTORY_H
#define UI_CHANGE_THE_DIRECTORY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_change_the_directory
{
public:
    QLabel *label_title;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_1_floor_attic;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_1_floor;
    QLabel *label_2_floor;
    QLineEdit *lineEdit_2_floor;
    QLineEdit *lineEdit_1_floor;
    QLineEdit *lineEdit_1_floor_attic;
    QSpacerItem *horizontalSpacer;
    QLabel *label_house;
    QLabel *label_foundation;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLabel *label_pile;
    QLineEdit *lineEdit_screw;
    QLineEdit *lineEdit_pile;
    QLabel *label_screw;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_sheating;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_4;
    QLabel *label_board_wall;
    QLineEdit *lineEdit_board_well;
    QLabel *label_gkl;
    QSpacerItem *horizontalSpacer_8;
    QLineEdit *lineEdit_board_well_celing;
    QSpacerItem *horizontalSpacer_9;
    QLabel *label_board_wall_ceiling;
    QLineEdit *lineEdit_gkl;
    QLabel *label_elect_plumb;
    QWidget *gridLayoutWidget_4;
    QGridLayout *gridLayout_5;
    QLineEdit *lineEdit_electrics;
    QLineEdit *lineEdit_plumbing;
    QLabel *label_electrics;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_plumbing;
    QLabel *label_floor_hot;
    QLineEdit *lineEdit_floor_hot;
    QWidget *gridLayoutWidget_5;
    QGridLayout *gridLayout_6;
    QLineEdit *lineEdit_delivery;
    QLabel *label_delivery;
    QSpacerItem *horizontalSpacer_5;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_change_cost;
    QPushButton *pushButton_cansel;

    void setupUi(QDialog *change_the_directory)
    {
        if (change_the_directory->objectName().isEmpty())
            change_the_directory->setObjectName(QString::fromUtf8("change_the_directory"));
        change_the_directory->resize(1241, 648);
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        change_the_directory->setFont(font);
        label_title = new QLabel(change_the_directory);
        label_title->setObjectName(QString::fromUtf8("label_title"));
        label_title->setGeometry(QRect(450, 10, 331, 41));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(false);
        font1.setWeight(50);
        label_title->setFont(font1);
        gridLayoutWidget = new QWidget(change_the_directory);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 90, 1201, 51));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_1_floor_attic = new QLabel(gridLayoutWidget);
        label_1_floor_attic->setObjectName(QString::fromUtf8("label_1_floor_attic"));
        QFont font2;
        font2.setPointSize(17);
        font2.setBold(false);
        font2.setWeight(50);
        label_1_floor_attic->setFont(font2);

        gridLayout->addWidget(label_1_floor_attic, 0, 3, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(17, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 5, 1, 1);

        label_1_floor = new QLabel(gridLayoutWidget);
        label_1_floor->setObjectName(QString::fromUtf8("label_1_floor"));
        label_1_floor->setFont(font2);

        gridLayout->addWidget(label_1_floor, 0, 0, 1, 1);

        label_2_floor = new QLabel(gridLayoutWidget);
        label_2_floor->setObjectName(QString::fromUtf8("label_2_floor"));
        label_2_floor->setFont(font2);

        gridLayout->addWidget(label_2_floor, 0, 6, 1, 1);

        lineEdit_2_floor = new QLineEdit(gridLayoutWidget);
        lineEdit_2_floor->setObjectName(QString::fromUtf8("lineEdit_2_floor"));
        lineEdit_2_floor->setFont(font2);

        gridLayout->addWidget(lineEdit_2_floor, 0, 7, 1, 1);

        lineEdit_1_floor = new QLineEdit(gridLayoutWidget);
        lineEdit_1_floor->setObjectName(QString::fromUtf8("lineEdit_1_floor"));
        lineEdit_1_floor->setFont(font2);

        gridLayout->addWidget(lineEdit_1_floor, 0, 1, 1, 1);

        lineEdit_1_floor_attic = new QLineEdit(gridLayoutWidget);
        lineEdit_1_floor_attic->setObjectName(QString::fromUtf8("lineEdit_1_floor_attic"));
        lineEdit_1_floor_attic->setFont(font2);

        gridLayout->addWidget(lineEdit_1_floor_attic, 0, 4, 1, 1);

        horizontalSpacer = new QSpacerItem(17, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        label_house = new QLabel(change_the_directory);
        label_house->setObjectName(QString::fromUtf8("label_house"));
        label_house->setGeometry(QRect(20, 50, 401, 34));
        label_house->setFont(font2);
        label_foundation = new QLabel(change_the_directory);
        label_foundation->setObjectName(QString::fromUtf8("label_foundation"));
        label_foundation->setGeometry(QRect(20, 160, 411, 34));
        label_foundation->setFont(font2);
        gridLayoutWidget_2 = new QWidget(change_the_directory);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(20, 200, 1201, 51));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_pile = new QLabel(gridLayoutWidget_2);
        label_pile->setObjectName(QString::fromUtf8("label_pile"));
        label_pile->setFont(font2);

        gridLayout_2->addWidget(label_pile, 0, 0, 1, 1);

        lineEdit_screw = new QLineEdit(gridLayoutWidget_2);
        lineEdit_screw->setObjectName(QString::fromUtf8("lineEdit_screw"));
        lineEdit_screw->setFont(font2);

        gridLayout_2->addWidget(lineEdit_screw, 0, 4, 1, 1);

        lineEdit_pile = new QLineEdit(gridLayoutWidget_2);
        lineEdit_pile->setObjectName(QString::fromUtf8("lineEdit_pile"));
        lineEdit_pile->setFont(font2);

        gridLayout_2->addWidget(lineEdit_pile, 0, 1, 1, 1);

        label_screw = new QLabel(gridLayoutWidget_2);
        label_screw->setObjectName(QString::fromUtf8("label_screw"));
        label_screw->setFont(font2);

        gridLayout_2->addWidget(label_screw, 0, 3, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(18, 28, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 0, 2, 1, 1);

        label_sheating = new QLabel(change_the_directory);
        label_sheating->setObjectName(QString::fromUtf8("label_sheating"));
        label_sheating->setGeometry(QRect(20, 260, 491, 34));
        label_sheating->setFont(font2);
        gridLayoutWidget_3 = new QWidget(change_the_directory);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(20, 310, 1201, 51));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        label_board_wall = new QLabel(gridLayoutWidget_3);
        label_board_wall->setObjectName(QString::fromUtf8("label_board_wall"));
        label_board_wall->setFont(font2);

        gridLayout_4->addWidget(label_board_wall, 0, 3, 1, 1);

        lineEdit_board_well = new QLineEdit(gridLayoutWidget_3);
        lineEdit_board_well->setObjectName(QString::fromUtf8("lineEdit_board_well"));
        lineEdit_board_well->setFont(font2);

        gridLayout_4->addWidget(lineEdit_board_well, 0, 4, 1, 1);

        label_gkl = new QLabel(gridLayoutWidget_3);
        label_gkl->setObjectName(QString::fromUtf8("label_gkl"));
        label_gkl->setFont(font2);

        gridLayout_4->addWidget(label_gkl, 0, 0, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(30, 38, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_8, 0, 2, 1, 1);

        lineEdit_board_well_celing = new QLineEdit(gridLayoutWidget_3);
        lineEdit_board_well_celing->setObjectName(QString::fromUtf8("lineEdit_board_well_celing"));
        lineEdit_board_well_celing->setFont(font2);

        gridLayout_4->addWidget(lineEdit_board_well_celing, 0, 7, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(18, 28, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_9, 0, 5, 1, 1);

        label_board_wall_ceiling = new QLabel(gridLayoutWidget_3);
        label_board_wall_ceiling->setObjectName(QString::fromUtf8("label_board_wall_ceiling"));
        label_board_wall_ceiling->setFont(font2);

        gridLayout_4->addWidget(label_board_wall_ceiling, 0, 6, 1, 1);

        lineEdit_gkl = new QLineEdit(gridLayoutWidget_3);
        lineEdit_gkl->setObjectName(QString::fromUtf8("lineEdit_gkl"));
        lineEdit_gkl->setFont(font2);

        gridLayout_4->addWidget(lineEdit_gkl, 0, 1, 1, 1);

        label_elect_plumb = new QLabel(change_the_directory);
        label_elect_plumb->setObjectName(QString::fromUtf8("label_elect_plumb"));
        label_elect_plumb->setGeometry(QRect(20, 370, 231, 34));
        label_elect_plumb->setFont(font2);
        gridLayoutWidget_4 = new QWidget(change_the_directory);
        gridLayoutWidget_4->setObjectName(QString::fromUtf8("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(20, 410, 1201, 93));
        gridLayout_5 = new QGridLayout(gridLayoutWidget_4);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        lineEdit_electrics = new QLineEdit(gridLayoutWidget_4);
        lineEdit_electrics->setObjectName(QString::fromUtf8("lineEdit_electrics"));
        lineEdit_electrics->setFont(font2);

        gridLayout_5->addWidget(lineEdit_electrics, 0, 4, 1, 1);

        lineEdit_plumbing = new QLineEdit(gridLayoutWidget_4);
        lineEdit_plumbing->setObjectName(QString::fromUtf8("lineEdit_plumbing"));
        lineEdit_plumbing->setFont(font2);

        gridLayout_5->addWidget(lineEdit_plumbing, 0, 1, 1, 1);

        label_electrics = new QLabel(gridLayoutWidget_4);
        label_electrics->setObjectName(QString::fromUtf8("label_electrics"));
        label_electrics->setFont(font2);

        gridLayout_5->addWidget(label_electrics, 0, 3, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(188, 38, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        label_plumbing = new QLabel(gridLayoutWidget_4);
        label_plumbing->setObjectName(QString::fromUtf8("label_plumbing"));
        label_plumbing->setFont(font2);

        gridLayout_5->addWidget(label_plumbing, 0, 0, 1, 1);

        label_floor_hot = new QLabel(gridLayoutWidget_4);
        label_floor_hot->setObjectName(QString::fromUtf8("label_floor_hot"));
        label_floor_hot->setFont(font2);

        gridLayout_5->addWidget(label_floor_hot, 1, 0, 1, 1);

        lineEdit_floor_hot = new QLineEdit(gridLayoutWidget_4);
        lineEdit_floor_hot->setObjectName(QString::fromUtf8("lineEdit_floor_hot"));
        lineEdit_floor_hot->setFont(font2);

        gridLayout_5->addWidget(lineEdit_floor_hot, 1, 1, 1, 1);

        gridLayoutWidget_5 = new QWidget(change_the_directory);
        gridLayoutWidget_5->setObjectName(QString::fromUtf8("gridLayoutWidget_5"));
        gridLayoutWidget_5->setGeometry(QRect(20, 520, 1201, 51));
        gridLayout_6 = new QGridLayout(gridLayoutWidget_5);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        lineEdit_delivery = new QLineEdit(gridLayoutWidget_5);
        lineEdit_delivery->setObjectName(QString::fromUtf8("lineEdit_delivery"));
        lineEdit_delivery->setFont(font2);

        gridLayout_6->addWidget(lineEdit_delivery, 0, 1, 1, 1);

        label_delivery = new QLabel(gridLayoutWidget_5);
        label_delivery->setObjectName(QString::fromUtf8("label_delivery"));
        label_delivery->setFont(font2);

        gridLayout_6->addWidget(label_delivery, 0, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(378, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_5, 0, 2, 1, 1);

        horizontalLayoutWidget = new QWidget(change_the_directory);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(320, 590, 591, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_change_cost = new QPushButton(horizontalLayoutWidget);
        pushButton_change_cost->setObjectName(QString::fromUtf8("pushButton_change_cost"));
        pushButton_change_cost->setFont(font2);
        pushButton_change_cost->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(pushButton_change_cost);

        pushButton_cansel = new QPushButton(horizontalLayoutWidget);
        pushButton_cansel->setObjectName(QString::fromUtf8("pushButton_cansel"));
        pushButton_cansel->setFont(font2);
        pushButton_cansel->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(pushButton_cansel);


        retranslateUi(change_the_directory);

        QMetaObject::connectSlotsByName(change_the_directory);
    } // setupUi

    void retranslateUi(QDialog *change_the_directory)
    {
        change_the_directory->setWindowTitle(QApplication::translate("change_the_directory", "Dialog", nullptr));
        label_title->setText(QApplication::translate("change_the_directory", "\320\230\320\267\320\274\320\265\320\275\320\265\320\275\320\270\320\265 \321\206\320\265\320\275 \320\262 \320\272\320\260\321\202\320\260\320\273\320\276\320\263\320\265", nullptr));
        label_1_floor_attic->setText(QApplication::translate("change_the_directory", "1 \321\215\321\202\320\260\320\266 + \320\274\320\260\320\275\321\201\320\260\321\200\320\264\320\260", nullptr));
        label_1_floor->setText(QApplication::translate("change_the_directory", "1 \321\215\321\202\320\260\320\266", nullptr));
        label_2_floor->setText(QApplication::translate("change_the_directory", "2 \321\215\321\202\320\260\320\266\320\260", nullptr));
        label_house->setText(QApplication::translate("change_the_directory", "\320\241\321\202\320\276\320\270\320\274\320\276\321\201\321\202\321\214 \320\264\320\276\320\274\320\276\320\272\320\276\320\274\320\277\320\273\320\265\320\272\321\202\320\260 \320\267\320\260 1 \320\272\320\262. \320\274", nullptr));
        label_foundation->setText(QApplication::translate("change_the_directory", "\320\241\321\202\320\276\320\270\320\274\320\276\321\201\321\202\321\214 \321\204\321\203\320\275\320\264\320\260\320\274\320\265\320\275\321\202\320\260 (\320\267\320\260 \320\276\320\264\320\275\321\203 \321\201\320\262\320\260\321\216)", nullptr));
        label_pile->setText(QApplication::translate("change_the_directory", "\320\241\320\262\320\260\320\271\320\275\321\213\320\271 \321\204\321\203\320\275\320\264\320\260\320\274\320\265\320\275\321\202", nullptr));
        label_screw->setText(QApplication::translate("change_the_directory", "\320\222\320\270\320\275\321\202\320\276\320\262\320\276\320\271 \321\204\321\203\320\275\320\264\320\260\320\274\320\265\320\275\321\202", nullptr));
        label_sheating->setText(QApplication::translate("change_the_directory", "\320\241\321\202\320\276\320\270\320\274\320\276\321\201\321\202\321\214 \320\276\320\261\321\210\320\270\320\262\320\272\320\270 \320\264\320\276\320\274\320\260 (\320\262\320\275\321\203\321\202\321\200\320\270)  \320\267\320\260 1 \320\272\320\262. \320\274", nullptr));
        label_board_wall->setText(QApplication::translate("change_the_directory", "\320\222\320\260\320\263\320\276\320\275\320\272\320\260 (\321\201\321\202\320\265\320\275\321\213)", nullptr));
        label_gkl->setText(QApplication::translate("change_the_directory", "\320\223\320\232\320\233", nullptr));
        label_board_wall_ceiling->setText(QApplication::translate("change_the_directory", "\320\222\320\260\320\263\320\276\320\275\320\272\320\260 (\321\201\321\202\320\265\320\275\321\213 + \320\277\320\276\321\202\320\276\320\273\320\276\320\272)", nullptr));
        label_elect_plumb->setText(QApplication::translate("change_the_directory", "\320\241\321\202\320\276\320\270\320\274\320\276\321\201\321\202\321\214  \320\267\320\260 1 \320\272\320\262. \320\274", nullptr));
        label_electrics->setText(QApplication::translate("change_the_directory", "\320\255\320\273\320\265\320\272\321\202\321\200\320\270\320\272\320\260", nullptr));
        label_plumbing->setText(QApplication::translate("change_the_directory", "\320\241\320\260\320\275\321\202\320\265\321\205\320\275\320\270\320\272\320\260", nullptr));
        label_floor_hot->setText(QApplication::translate("change_the_directory", "\320\242\320\265\320\277\320\273\321\213\320\271 \320\277\320\276\320\273", nullptr));
        label_delivery->setText(QApplication::translate("change_the_directory", "\320\241\321\202\320\276\320\270\320\274\320\276\321\201\321\202\321\214 \320\264\320\276\321\201\321\202\320\260\320\262\320\272\320\270 \320\267\320\260 1 \320\274\320\260\321\210\320\270\320\275\321\203", nullptr));
        pushButton_change_cost->setText(QApplication::translate("change_the_directory", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \321\206\320\265\320\275\321\213", nullptr));
        pushButton_cansel->setText(QApplication::translate("change_the_directory", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class change_the_directory: public Ui_change_the_directory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGE_THE_DIRECTORY_H
