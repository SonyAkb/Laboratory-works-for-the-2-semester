/********************************************************************************
** Form generated from reading UI file 'main_window_1.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_1_H
#define UI_MAIN_WINDOW_1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Main_Window_1
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *floor_house;
    QLabel *label_floor;
    QRadioButton *floor_1_rb;
    QRadioButton *floor_1_attic_rb;
    QRadioButton *floor_2_rb;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *the_area_of_the_house;
    QLabel *label_area_house;
    QRadioButton *external_area_rb;
    QRadioButton *internal_area;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *foundation;
    QLabel *label_foundation;
    QRadioButton *screw_foundation_rb;
    QRadioButton *piled_foundation_rb;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *plumbing;
    QLabel *label_plumbing;
    QRadioButton *no_plumbing_rb;
    QRadioButton *yes_plumbing_rb;
    QWidget *verticalLayoutWidget_6;
    QVBoxLayout *electrics;
    QLabel *label_electrics;
    QRadioButton *no_electrics_rb;
    QRadioButton *yes_electrics_rb;
    QWidget *verticalLayoutWidget_7;
    QVBoxLayout *underfloor_heating;
    QLabel *label_underfloor_heating;
    QRadioButton *no_underfloor_heating_rb;
    QRadioButton *yes_underfloor_heating_rb;
    QWidget *verticalLayoutWidget_8;
    QVBoxLayout *sheathings;
    QLabel *label_sheathings;
    QRadioButton *not_sh_rb;
    QRadioButton *gkl_rb;
    QRadioButton *board_walls;
    QRadioButton *board_walls_ceiling;
    QPushButton *calculate_but;
    QPushButton *save_data_but;
    QPushButton *change_prices_but;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *the_final_prices;
    QWidget *gridLayoutWidget_2;
    QGridLayout *enter_the_area_house;
    QPushButton *pushButton_clear;
    QLineEdit *lineEdit_enter_area;
    QLabel *label_2;
    QLabel *label_enter_area;
    QPushButton *pushButton_exit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Main_Window_1)
    {
        if (Main_Window_1->objectName().isEmpty())
            Main_Window_1->setObjectName(QString::fromUtf8("Main_Window_1"));
        Main_Window_1->resize(892, 669);
        Main_Window_1->setCursor(QCursor(Qt::ArrowCursor));
        centralwidget = new QWidget(Main_Window_1);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(40, 30, 241, 154));
        QFont font;
        font.setPointSize(18);
        verticalLayoutWidget->setFont(font);
        floor_house = new QVBoxLayout(verticalLayoutWidget);
        floor_house->setObjectName(QString::fromUtf8("floor_house"));
        floor_house->setContentsMargins(0, 0, 0, 0);
        label_floor = new QLabel(verticalLayoutWidget);
        label_floor->setObjectName(QString::fromUtf8("label_floor"));
        label_floor->setFont(font);

        floor_house->addWidget(label_floor);

        floor_1_rb = new QRadioButton(verticalLayoutWidget);
        floor_1_rb->setObjectName(QString::fromUtf8("floor_1_rb"));
        floor_1_rb->setFont(font);
        floor_1_rb->setAutoRepeat(false);

        floor_house->addWidget(floor_1_rb);

        floor_1_attic_rb = new QRadioButton(verticalLayoutWidget);
        floor_1_attic_rb->setObjectName(QString::fromUtf8("floor_1_attic_rb"));
        floor_1_attic_rb->setFont(font);

        floor_house->addWidget(floor_1_attic_rb);

        floor_2_rb = new QRadioButton(verticalLayoutWidget);
        floor_2_rb->setObjectName(QString::fromUtf8("floor_2_rb"));
        floor_2_rb->setFont(font);

        floor_house->addWidget(floor_2_rb);

        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(320, 30, 171, 121));
        the_area_of_the_house = new QVBoxLayout(verticalLayoutWidget_2);
        the_area_of_the_house->setObjectName(QString::fromUtf8("the_area_of_the_house"));
        the_area_of_the_house->setContentsMargins(0, 0, 0, 0);
        label_area_house = new QLabel(verticalLayoutWidget_2);
        label_area_house->setObjectName(QString::fromUtf8("label_area_house"));
        label_area_house->setFont(font);

        the_area_of_the_house->addWidget(label_area_house);

        external_area_rb = new QRadioButton(verticalLayoutWidget_2);
        external_area_rb->setObjectName(QString::fromUtf8("external_area_rb"));
        external_area_rb->setFont(font);

        the_area_of_the_house->addWidget(external_area_rb);

        internal_area = new QRadioButton(verticalLayoutWidget_2);
        internal_area->setObjectName(QString::fromUtf8("internal_area"));
        internal_area->setFont(font);

        the_area_of_the_house->addWidget(internal_area);

        verticalLayoutWidget_4 = new QWidget(centralwidget);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(480, 170, 163, 121));
        foundation = new QVBoxLayout(verticalLayoutWidget_4);
        foundation->setObjectName(QString::fromUtf8("foundation"));
        foundation->setContentsMargins(0, 0, 0, 0);
        label_foundation = new QLabel(verticalLayoutWidget_4);
        label_foundation->setObjectName(QString::fromUtf8("label_foundation"));
        label_foundation->setFont(font);

        foundation->addWidget(label_foundation);

        screw_foundation_rb = new QRadioButton(verticalLayoutWidget_4);
        screw_foundation_rb->setObjectName(QString::fromUtf8("screw_foundation_rb"));
        screw_foundation_rb->setFont(font);

        foundation->addWidget(screw_foundation_rb);

        piled_foundation_rb = new QRadioButton(verticalLayoutWidget_4);
        piled_foundation_rb->setObjectName(QString::fromUtf8("piled_foundation_rb"));
        piled_foundation_rb->setFont(font);

        foundation->addWidget(piled_foundation_rb);

        verticalLayoutWidget_5 = new QWidget(centralwidget);
        verticalLayoutWidget_5->setObjectName(QString::fromUtf8("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(690, 320, 163, 121));
        plumbing = new QVBoxLayout(verticalLayoutWidget_5);
        plumbing->setObjectName(QString::fromUtf8("plumbing"));
        plumbing->setContentsMargins(0, 0, 0, 0);
        label_plumbing = new QLabel(verticalLayoutWidget_5);
        label_plumbing->setObjectName(QString::fromUtf8("label_plumbing"));
        label_plumbing->setFont(font);

        plumbing->addWidget(label_plumbing);

        no_plumbing_rb = new QRadioButton(verticalLayoutWidget_5);
        no_plumbing_rb->setObjectName(QString::fromUtf8("no_plumbing_rb"));
        no_plumbing_rb->setFont(font);

        plumbing->addWidget(no_plumbing_rb);

        yes_plumbing_rb = new QRadioButton(verticalLayoutWidget_5);
        yes_plumbing_rb->setObjectName(QString::fromUtf8("yes_plumbing_rb"));
        yes_plumbing_rb->setFont(font);

        plumbing->addWidget(yes_plumbing_rb);

        verticalLayoutWidget_6 = new QWidget(centralwidget);
        verticalLayoutWidget_6->setObjectName(QString::fromUtf8("verticalLayoutWidget_6"));
        verticalLayoutWidget_6->setGeometry(QRect(690, 170, 163, 121));
        electrics = new QVBoxLayout(verticalLayoutWidget_6);
        electrics->setObjectName(QString::fromUtf8("electrics"));
        electrics->setContentsMargins(0, 0, 0, 0);
        label_electrics = new QLabel(verticalLayoutWidget_6);
        label_electrics->setObjectName(QString::fromUtf8("label_electrics"));
        label_electrics->setFont(font);

        electrics->addWidget(label_electrics);

        no_electrics_rb = new QRadioButton(verticalLayoutWidget_6);
        no_electrics_rb->setObjectName(QString::fromUtf8("no_electrics_rb"));
        no_electrics_rb->setFont(font);

        electrics->addWidget(no_electrics_rb);

        yes_electrics_rb = new QRadioButton(verticalLayoutWidget_6);
        yes_electrics_rb->setObjectName(QString::fromUtf8("yes_electrics_rb"));
        yes_electrics_rb->setFont(font);

        electrics->addWidget(yes_electrics_rb);

        verticalLayoutWidget_7 = new QWidget(centralwidget);
        verticalLayoutWidget_7->setObjectName(QString::fromUtf8("verticalLayoutWidget_7"));
        verticalLayoutWidget_7->setGeometry(QRect(480, 320, 167, 121));
        underfloor_heating = new QVBoxLayout(verticalLayoutWidget_7);
        underfloor_heating->setObjectName(QString::fromUtf8("underfloor_heating"));
        underfloor_heating->setContentsMargins(0, 0, 0, 0);
        label_underfloor_heating = new QLabel(verticalLayoutWidget_7);
        label_underfloor_heating->setObjectName(QString::fromUtf8("label_underfloor_heating"));
        label_underfloor_heating->setFont(font);

        underfloor_heating->addWidget(label_underfloor_heating);

        no_underfloor_heating_rb = new QRadioButton(verticalLayoutWidget_7);
        no_underfloor_heating_rb->setObjectName(QString::fromUtf8("no_underfloor_heating_rb"));
        no_underfloor_heating_rb->setFont(font);

        underfloor_heating->addWidget(no_underfloor_heating_rb);

        yes_underfloor_heating_rb = new QRadioButton(verticalLayoutWidget_7);
        yes_underfloor_heating_rb->setObjectName(QString::fromUtf8("yes_underfloor_heating_rb"));
        yes_underfloor_heating_rb->setFont(font);

        underfloor_heating->addWidget(yes_underfloor_heating_rb);

        verticalLayoutWidget_8 = new QWidget(centralwidget);
        verticalLayoutWidget_8->setObjectName(QString::fromUtf8("verticalLayoutWidget_8"));
        verticalLayoutWidget_8->setGeometry(QRect(40, 240, 331, 201));
        verticalLayoutWidget_8->setFont(font);
        sheathings = new QVBoxLayout(verticalLayoutWidget_8);
        sheathings->setObjectName(QString::fromUtf8("sheathings"));
        sheathings->setContentsMargins(0, 0, 0, 0);
        label_sheathings = new QLabel(verticalLayoutWidget_8);
        label_sheathings->setObjectName(QString::fromUtf8("label_sheathings"));
        label_sheathings->setFont(font);

        sheathings->addWidget(label_sheathings);

        not_sh_rb = new QRadioButton(verticalLayoutWidget_8);
        not_sh_rb->setObjectName(QString::fromUtf8("not_sh_rb"));
        not_sh_rb->setFont(font);
        not_sh_rb->setAutoRepeat(false);

        sheathings->addWidget(not_sh_rb);

        gkl_rb = new QRadioButton(verticalLayoutWidget_8);
        gkl_rb->setObjectName(QString::fromUtf8("gkl_rb"));
        gkl_rb->setFont(font);

        sheathings->addWidget(gkl_rb);

        board_walls = new QRadioButton(verticalLayoutWidget_8);
        board_walls->setObjectName(QString::fromUtf8("board_walls"));
        board_walls->setFont(font);

        sheathings->addWidget(board_walls);

        board_walls_ceiling = new QRadioButton(verticalLayoutWidget_8);
        board_walls_ceiling->setObjectName(QString::fromUtf8("board_walls_ceiling"));
        board_walls_ceiling->setFont(font);

        sheathings->addWidget(board_walls_ceiling);

        calculate_but = new QPushButton(centralwidget);
        calculate_but->setObjectName(QString::fromUtf8("calculate_but"));
        calculate_but->setGeometry(QRect(340, 530, 211, 61));
        QFont font1;
        font1.setPointSize(18);
        font1.setBold(false);
        font1.setWeight(50);
        font1.setKerning(true);
        calculate_but->setFont(font1);
        calculate_but->setCursor(QCursor(Qt::PointingHandCursor));
        save_data_but = new QPushButton(centralwidget);
        save_data_but->setObjectName(QString::fromUtf8("save_data_but"));
        save_data_but->setGeometry(QRect(40, 530, 251, 51));
        QFont font2;
        font2.setPointSize(17);
        save_data_but->setFont(font2);
        change_prices_but = new QPushButton(centralwidget);
        change_prices_but->setObjectName(QString::fromUtf8("change_prices_but"));
        change_prices_but->setGeometry(QRect(600, 530, 251, 51));
        change_prices_but->setFont(font);
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(340, 460, 261, 51));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 0, 3, 1, 1);

        the_final_prices = new QLabel(gridLayoutWidget);
        the_final_prices->setObjectName(QString::fromUtf8("the_final_prices"));
        QFont font3;
        font3.setPointSize(20);
        font3.setBold(false);
        font3.setWeight(50);
        the_final_prices->setFont(font3);

        gridLayout->addWidget(the_final_prices, 0, 2, 1, 1);

        gridLayoutWidget_2 = new QWidget(centralwidget);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(550, 30, 301, 116));
        enter_the_area_house = new QGridLayout(gridLayoutWidget_2);
        enter_the_area_house->setObjectName(QString::fromUtf8("enter_the_area_house"));
        enter_the_area_house->setContentsMargins(0, 0, 0, 0);
        pushButton_clear = new QPushButton(gridLayoutWidget_2);
        pushButton_clear->setObjectName(QString::fromUtf8("pushButton_clear"));
        QFont font4;
        font4.setPointSize(15);
        pushButton_clear->setFont(font4);

        enter_the_area_house->addWidget(pushButton_clear, 2, 0, 1, 1);

        lineEdit_enter_area = new QLineEdit(gridLayoutWidget_2);
        lineEdit_enter_area->setObjectName(QString::fromUtf8("lineEdit_enter_area"));
        QFont font5;
        font5.setPointSize(20);
        lineEdit_enter_area->setFont(font5);

        enter_the_area_house->addWidget(lineEdit_enter_area, 1, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font2);

        enter_the_area_house->addWidget(label_2, 1, 1, 1, 1);

        label_enter_area = new QLabel(gridLayoutWidget_2);
        label_enter_area->setObjectName(QString::fromUtf8("label_enter_area"));
        label_enter_area->setFont(font);

        enter_the_area_house->addWidget(label_enter_area, 0, 0, 1, 2);

        pushButton_exit = new QPushButton(centralwidget);
        pushButton_exit->setObjectName(QString::fromUtf8("pushButton_exit"));
        pushButton_exit->setGeometry(QRect(760, 590, 91, 31));
        pushButton_exit->setFont(font4);
        Main_Window_1->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Main_Window_1);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 892, 20));
        Main_Window_1->setMenuBar(menubar);
        statusbar = new QStatusBar(Main_Window_1);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Main_Window_1->setStatusBar(statusbar);

        retranslateUi(Main_Window_1);

        QMetaObject::connectSlotsByName(Main_Window_1);
    } // setupUi

    void retranslateUi(QMainWindow *Main_Window_1)
    {
        Main_Window_1->setWindowTitle(QApplication::translate("Main_Window_1", "Main_Window_1", nullptr));
        label_floor->setText(QApplication::translate("Main_Window_1", "\320\255\321\202\320\260\320\266\320\275\320\276\321\201\321\202\321\214 \320\264\320\276\320\274\320\260", nullptr));
        floor_1_rb->setText(QApplication::translate("Main_Window_1", "1 \321\215\321\202\320\260\320\266", nullptr));
        floor_1_attic_rb->setText(QApplication::translate("Main_Window_1", "1 \321\215\321\202\320\260\320\266 + \320\274\320\260\320\275\321\201\320\260\321\200\320\264\320\260", nullptr));
        floor_2_rb->setText(QApplication::translate("Main_Window_1", "2 \321\215\321\202\320\260\320\266\320\260", nullptr));
        label_area_house->setText(QApplication::translate("Main_Window_1", "\320\237\320\273\320\276\321\211\320\260\320\264\321\214 \320\264\320\276\320\274\320\260", nullptr));
        external_area_rb->setText(QApplication::translate("Main_Window_1", "\320\222\320\275\320\265\321\210\320\275\321\217\321\217", nullptr));
        internal_area->setText(QApplication::translate("Main_Window_1", "\320\222\320\275\321\203\321\202\321\200\320\265\320\275\320\275\321\217\321\217", nullptr));
        label_foundation->setText(QApplication::translate("Main_Window_1", "\320\244\321\203\320\275\320\264\320\260\320\274\320\265\320\275\321\202", nullptr));
        screw_foundation_rb->setText(QApplication::translate("Main_Window_1", "\320\222\320\270\320\275\321\202\320\276\320\262\320\276\320\271", nullptr));
        piled_foundation_rb->setText(QApplication::translate("Main_Window_1", "\320\241\320\262\320\260\320\271\320\275\321\213\320\271", nullptr));
        label_plumbing->setText(QApplication::translate("Main_Window_1", "\320\241\320\260\320\275\321\202\320\265\321\205\320\275\320\270\320\272\320\260", nullptr));
        no_plumbing_rb->setText(QApplication::translate("Main_Window_1", "\320\275\320\265 \320\275\321\203\320\266\320\275\320\260", nullptr));
        yes_plumbing_rb->setText(QApplication::translate("Main_Window_1", "\320\275\321\203\320\266\320\275\320\260", nullptr));
        label_electrics->setText(QApplication::translate("Main_Window_1", "\320\255\320\273\320\265\320\272\321\202\321\200\320\270\320\272\320\260", nullptr));
        no_electrics_rb->setText(QApplication::translate("Main_Window_1", "\320\275\320\265 \320\275\321\203\320\266\320\275\320\260", nullptr));
        yes_electrics_rb->setText(QApplication::translate("Main_Window_1", "\320\275\321\203\320\266\320\275\320\260", nullptr));
        label_underfloor_heating->setText(QApplication::translate("Main_Window_1", "\320\242\320\265\320\277\320\273\321\213\320\271 \320\277\320\276\320\273", nullptr));
        no_underfloor_heating_rb->setText(QApplication::translate("Main_Window_1", "\320\275\320\265 \320\275\321\203\320\266\320\265\320\275", nullptr));
        yes_underfloor_heating_rb->setText(QApplication::translate("Main_Window_1", "\320\275\321\203\320\266\320\265\320\275", nullptr));
        label_sheathings->setText(QApplication::translate("Main_Window_1", "\320\236\320\261\321\210\320\270\320\262\320\272\320\260", nullptr));
        not_sh_rb->setText(QApplication::translate("Main_Window_1", "\320\275\320\265 \320\275\321\203\320\266\320\275\320\260", nullptr));
        gkl_rb->setText(QApplication::translate("Main_Window_1", "\320\223\320\232\320\233", nullptr));
        board_walls->setText(QApplication::translate("Main_Window_1", "\320\262\320\260\320\263\320\276\320\275\320\272\320\260: \321\201\321\202\320\265\320\275\321\213", nullptr));
        board_walls_ceiling->setText(QApplication::translate("Main_Window_1", "\320\262\320\260\320\263\320\276\320\275\320\272\320\260: \321\201\321\202\320\265\320\275\321\213 + \320\277\320\276\321\202\320\276\320\273\320\276\320\272", nullptr));
        calculate_but->setText(QApplication::translate("Main_Window_1", "\320\240\320\260\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
        save_data_but->setText(QApplication::translate("Main_Window_1", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\264\320\260\320\275\320\275\321\213\320\265", nullptr));
        change_prices_but->setText(QApplication::translate("Main_Window_1", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \321\206\320\265\320\275\321\213", nullptr));
        label->setText(QApplication::translate("Main_Window_1", "\342\202\275", nullptr));
        the_final_prices->setText(QApplication::translate("Main_Window_1", "0                                    ", nullptr));
        pushButton_clear->setText(QApplication::translate("Main_Window_1", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        label_2->setText(QApplication::translate("Main_Window_1", "\320\272\320\262. \320\274", nullptr));
        label_enter_area->setText(QApplication::translate("Main_Window_1", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\277\320\273\320\276\321\211\320\260\320\264\321\214 1 \321\215\321\202\320\260\320\266\320\260", nullptr));
        pushButton_exit->setText(QApplication::translate("Main_Window_1", "\320\222\321\213\321\205\320\276\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Main_Window_1: public Ui_Main_Window_1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_1_H
