#include "save_data_window.h"
#include "ui_save_data_window.h"

save_data_window::save_data_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::save_data_window)
{
    ui->setupUi(this);
    this->setWindowTitle("Сохранить...");

}

save_data_window::~save_data_window()
{
    delete ui;
}

void save_data_window::slot_3(Prices &catalog_3, House &house_3)
{
    int i = 0;
    ui->label_amount_floor_2->setText(catalog_3.the_text_catalog[i++][house_3.floor]);//этажность
    ui->label_S_out_1f_2->setText(QString::number(house_3.S_external_first, 'f', 2));//внешняя 1 этаж
    ui->label_S_in_1f_2->setText(QString::number(house_3.S_internal_first, 'f', 2));//внутренняя 1 этаж
    ui->label_S_in_all_2->setText(QString::number(house_3.S_internal_all, 'f', 2));//внутренняя вся
    ui->label_found_2->setText(catalog_3.the_text_catalog[i++][house_3.foundation_i]);//фундамент
    ui->label_sheathing_2->setText(catalog_3.the_text_catalog[i++][house_3.sheathing_i]);//обшивка
    ui->label_plumbing_2->setText(catalog_3.the_text_catalog[i++][house_3.plumbing_i]);//сантехника
    ui->label_electrics_2->setText(catalog_3.the_text_catalog[i++][house_3.electrics_i]);//электрика
    ui->label_hot_floor_2->setText(catalog_3.the_text_catalog[i++][house_3.underfloor_heating_i]);//теплый пол
    ui->label_result_2->setText(QString::number(house_3.last_cost, 'f', 2));//итог
}

void save_data_window::on_pushButton_cansel_clicked()
{
    this->close();
}

void save_data_window::on_pushButton_save_clicked()
{
    const QString defaultPath = QStandardPaths::standardLocations(QStandardPaths::DesktopLocation).first();
    // Создание объекта QFileDialog для выбора пути к файлу
    QString file_Path = QFileDialog::getSaveFileName(nullptr,
                                                    "Сохранить файл",
                                                    defaultPath + "/file_name",
                                                    ".txt ( * .txt * )");
    if (file_Path.isEmpty()) {// Пользователь отменил сохранение
        return;
    }
    if (!(file_Path[file_Path.length() - 1] == 't' && file_Path[file_Path.length() - 2] == 'x' &&
            file_Path[file_Path.length() - 3] == 't' && file_Path[file_Path.length() - 4] == '.')){
        file_Path += ".txt";
    }

    QFile file_1(file_Path);//открываю файл с расширением txt
    if (file_1.open(QIODevice::WriteOnly | QIODevice::Append)){
        file_1.write((QDateTime::currentDateTime().toString("yyyy-MM-dd_hh-mm-ss").toStdString() + "\n").c_str());
        file_1.write((ui->label_name->text().toStdString() + " " + ui->lineEdit_name->text().toStdString() + "\n").c_str());
        file_1.write((ui->label_phone->text().toStdString() + " " + ui->lineEdit_phone->text().toStdString() + "\n").c_str());
        file_1.write((ui->label_found_1->text().toStdString() + ": " + ui->label_found_2->text().toStdString() + "\n").c_str());
        file_1.write((ui->label_S_out_1f_1->text().toStdString() + ": " + ui->label_S_out_1f_2->text().toStdString() + "\n").c_str());
        file_1.write((ui->label_S_in_1f_1->text().toStdString() + ": " + ui->label_S_in_1f_2->text().toStdString() + "\n").c_str());
        file_1.write((ui->label_S_in_all_1->text().toStdString() + ": " + ui->label_S_in_all_2->text().toStdString() + "\n").c_str());
        file_1.write((ui->label_found_1->text().toStdString() + ": " + ui->label_found_2->text().toStdString() + "\n").c_str());
        file_1.write((ui->label_sheathing_1->text().toStdString() + ": " + ui->label_sheathing_2->text().toStdString() + "\n").c_str());
        file_1.write((ui->label_plumbing_1->text().toStdString() + ": " + ui->label_plumbing_2->text().toStdString() + "\n").c_str());
        file_1.write((ui->label_electrics_1->text().toStdString() + ": " + ui->label_electrics_2->text().toStdString() + "\n").c_str());
        file_1.write((ui->label_hot_floor_1->text().toStdString() + ": " + ui->label_hot_floor_2->text().toStdString() + "\n").c_str());
        file_1.write((ui->label_result_1->text().toStdString() + ": " + ui->label_result_2->text().toStdString() + "\n\n").c_str());
    }
    this->close();
}

