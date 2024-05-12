#include "main_window_1.h"
#include "ui_main_window_1.h"
#include "other_functoins.h"//доп функции
#include "house.h"//класс дома
#include <string>
#include <vector>

Main_Window_1::Main_Window_1(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Main_Window_1)
{
    ui->setupUi(this);
    ui->floor_1_rb->setChecked(true);
    ui->not_sh_rb->setChecked(true);
    ui->external_area_rb->setChecked(true);
    ui->piled_foundation_rb->setChecked(true);
    ui->no_plumbing_rb->setChecked(true);
    ui->no_electrics_rb->setChecked(true);
    ui->no_underfloor_heating_rb->setChecked(true);
    this->setWindowTitle("Калькулятор расчета стоимости строительства дома по финской технологии");

    window_3 = new change_the_directory;//изменить цены
    connect(this, &Main_Window_1::signal_1, window_3, &change_the_directory::slot_1);
    connect(window_3, &change_the_directory::signal_2, this, &Main_Window_1::slot_2);

    window_4 = new save_data_window;//сохранить данные
    connect(this, &Main_Window_1::signal_3, window_4, &save_data_window::slot_3);
}

Main_Window_1::~Main_Window_1()
{
    delete ui;
}

void Main_Window_1::slot_2(){
    current_prices.change_current_prices();
}

void Main_Window_1::on_calculate_but_clicked(){
    if(can_convert_to_string_double(ui->lineEdit_enter_area->text()) && string_to_double(ui->lineEdit_enter_area->text()) > 0){
        std::vector<std::vector<bool>> bool_vector_all_data{{ui->floor_1_rb->isChecked(), ui->floor_1_attic_rb->isChecked(), ui->floor_2_rb->isChecked()},//этаж
                                                            {ui->external_area_rb->isChecked(), ui->internal_area->isChecked()},//площадь
                                                            {ui->screw_foundation_rb->isChecked(), ui->piled_foundation_rb->isChecked()},//фундамент
                                                            {ui->not_sh_rb->isChecked(), ui->gkl_rb->isChecked(), ui->board_walls->isChecked(), ui->board_walls_ceiling->isChecked()},//обшивка
                                                            {ui->no_electrics_rb->isChecked(), ui->yes_electrics_rb->isChecked()},//электрика
                                                            {ui->no_plumbing_rb->isChecked(), ui->yes_plumbing_rb->isChecked()},//сантехника
                                                            {ui->no_underfloor_heating_rb->isChecked(), ui->yes_underfloor_heating_rb->isChecked()}};//теплый пол

        std::vector<int> list_index =  all_list_index(bool_vector_all_data);
        house_2.assemble_the_house(list_index, string_to_double(ui->lineEdit_enter_area->text()));//запрос на дом
        double final_cost = house_2.the_final_price_of_the_house(current_prices);//итоговая цена
        ui->the_final_prices->setText(double_to_string(final_cost));
    }
    else{//введен не текст вместо S
        QMessageBox message_Box_1;
        message_Box_1.setText("Ошибка");
        message_Box_1.setInformativeText("Некорректная площадь");
        message_Box_1.setWindowTitle("Ошибка");
        message_Box_1.setIcon(QMessageBox::Critical);
        QFont font("Helvetica", 16);
        message_Box_1.setFont(font);
        message_Box_1.setInformativeText("Некорректная площадь");
        message_Box_1.setWindowTitle("Ошибка");
        message_Box_1.exec();// Показываем сообщение об ошибке
    }
}

void Main_Window_1::on_change_prices_but_clicked(){
    window_3->show();
    emit signal_1(current_prices);
}

void Main_Window_1::on_save_data_but_clicked()
{
    if(string_to_double(ui->lineEdit_enter_area->text()) > 0){
        window_4->show();
        emit signal_3(current_prices, house_2);
    }
    else{
        QMessageBox message_Box_1;
        message_Box_1.setText("Ошибка");
        message_Box_1.setInformativeText("Некорректная площадь");
        message_Box_1.setWindowTitle("Ошибка");
        message_Box_1.setIcon(QMessageBox::Critical);
        QFont font("Helvetica", 16);
        message_Box_1.setFont(font);
        message_Box_1.setInformativeText("Некорректная площадь");
        message_Box_1.setWindowTitle("Ошибка");
        message_Box_1.exec();// Показываем сообщение об ошибке
    }
}


void Main_Window_1::on_pushButton_clear_clicked()
{
    ui->lineEdit_enter_area->setText("");
    ui->the_final_prices->setText("0");
}


void Main_Window_1::on_pushButton_exit_clicked()
{
    this->close();
}

