#include "change_the_directory.h"
#include "ui_change_the_directory.h"
#include <iomanip>
#include <QString>
#include <QFile>
#include <QLineEdit>

change_the_directory::change_the_directory(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::change_the_directory)
{
    ui->setupUi(this);
    this->setWindowTitle("Изменение цен");
}

change_the_directory::~change_the_directory()
{
    delete ui;
}

void change_the_directory::slot_1(Prices &catalog_1)
{
    ui->lineEdit_1_floor->setText(QString::number(catalog_1.q_floor[0], 'f', 2));//1 этаж
    ui->lineEdit_1_floor_attic->setText(QString::number(catalog_1.q_floor[1], 'f', 2));//1 этаж + веранда
    ui->lineEdit_2_floor->setText(QString::number(catalog_1.q_floor[2], 'f', 2));//2 этажа
    ui->lineEdit_pile->setText(QString::number(catalog_1.foundation[1], 'f', 2));//фундамент свайный
    ui->lineEdit_screw->setText(QString::number(catalog_1.foundation[0], 'f', 2));//фундамент винтовой
    ui->lineEdit_gkl->setText(QString::number(catalog_1.sheathing[1], 'f', 2));//обшивка ГКЛ
    ui->lineEdit_board_well->setText(QString::number(catalog_1.sheathing[2], 'f', 2));//обшивка вагонка стены
    ui->lineEdit_board_well_celing->setText(QString::number(catalog_1.sheathing[3], 'f', 2));//обшивка вагонка стены + потолок
    ui->lineEdit_plumbing->setText(QString::number(catalog_1.plumbing[1], 'f', 2));//сантехника
    ui->lineEdit_electrics->setText(QString::number(catalog_1.electrics[1], 'f', 2));//электрика
    ui->lineEdit_floor_hot->setText(QString::number(catalog_1.underfloor_heating[1], 'f', 2));//теплый пол
    ui->lineEdit_delivery->setText(QString::number(catalog_1.delivery, 'f', 2));//доставка
}

void change_the_directory::on_pushButton_change_cost_clicked()
{
    QFile file_1(QCoreApplication::applicationDirPath() + "/additional_files/all_the_prices.txt");//открываю файл с ценами
    if (!file_1.open(QIODevice::ReadOnly | QIODevice::Text)){
            return;
    }
    QTextStream in_1(&file_1);//чтение каталога цен
    QFile file_2(QCoreApplication::applicationDirPath() + "/additional_files/temporary_file.txt");
    if (file_2.open(QIODevice::WriteOnly)) {
        QString the_value_in_question;
        QString line;
        foreach (const QString &name, QStringList({"lineEdit_1_floor", "lineEdit_1_floor_attic", "lineEdit_2_floor",
     "lineEdit_screw", "lineEdit_pile", "lineEdit_electrics", "lineEdit_plumbing", "lineEdit_floor_hot",
    "lineEdit_gkl", "lineEdit_board_well", "lineEdit_board_well_celing", "lineEdit_delivery"})) { // Список имен текстовых полей
            QLineEdit  * lineEdit = this->findChild<QLineEdit * >(name); // Находим текстовое поле с данным именем
            the_value_in_question = lineEdit->text();
            line = in_1.readLine();

            if (lineEdit != nullptr) { // Проверяем, было ли найдено текстовое поле
                if(the_value_in_question.toDouble() > 0){//1 этаж
                    file_2.write(QString::number(the_value_in_question.toDouble(), 'f', 2).toStdString().c_str());
                    file_2.write("\n");
                }
                else{
                    file_2.write(line.toStdString().c_str());
                    file_2.write("\n");
                }
            }
        }
        file_2.close();//закрываю
        file_1.close();//закрываю
        file_1.open(QIODevice::WriteOnly);
        file_2.open(QIODevice::ReadOnly | QIODevice::Text);

        QByteArray data;
        while (!file_2.atEnd()) {
            data += file_2.read(1024); // Читаем данные блоками по 1 КБ
        }
        file_1.write(data); // Записываем данные в новый файл
        file_1.close();//закрываю
        file_2.close();//закрываю
        file_2.remove();//удаляю временный файл
        emit signal_2();
    }// не удалось создать/открыть файл
    else{
        file_1.close();
    }
    this->close();
}

void change_the_directory::on_pushButton_cansel_clicked()
{
    this->close();
}

