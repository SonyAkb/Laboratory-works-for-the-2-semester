#ifndef PRICES_H
#define PRICES_H
#include <vector>
#include <QtGui>
#include <fstream>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <Qt>

class Prices: public QObject{
    Q_OBJECT
public:
    std::vector<std::vector<QString>> the_text_catalog{{"1 этаж", "1 этаж + мансарда", "2 этажа"},
                                                           {"винтовой","свайный"},
                                                           {"нет", "ГКЛ", "вагонка (стены)", "вагонка (стены и потолок)"},
                                                           {"нет", "да"}, {"нет", "да"}, {"нет", "да"}};
    std::vector<double> q_floor{43000,36000,43000};//цены за этажность
    std::vector<double> foundation{6000,8000};//цены за фундамент
    std::vector<double> sheathing{0, 2400,3000,5000};//цены за обшивку
    std::vector<double> electrics = {0, 1500};//электрика
    std::vector<double> plumbing = {0, 1100};//сантехника
    std::vector<double> underfloor_heating = {0, 2300};//теплый пол
    double delivery = 160000;//доставка домокомплекта

public:
    Prices(){
        change_current_prices();
    }
    ~Prices(){};
    bool change_current_prices(){//поменять цены в классе сейчас
        QFile file(QCoreApplication::applicationDirPath() + "/additional_files/all_the_prices.txt");//открываю файл с ценами
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
                return false;
        }
        QTextStream in(&file);
        q_floor = std::vector<double>{in.readLine().toDouble(), in.readLine().toDouble(), in.readLine().toDouble()};
        foundation = std::vector<double>{in.readLine().toDouble(), in.readLine().toDouble()};
        electrics = std::vector<double>{ 0, in.readLine().toDouble()};
        plumbing = std::vector<double>{0, in.readLine().toDouble()};
        underfloor_heating = std::vector<double>{0, in.readLine().toDouble()};
        sheathing = std::vector<double>{0, in.readLine().toDouble(), in.readLine().toDouble(), in.readLine().toDouble()};
        delivery = in.readLine().toDouble();
        file.close();
        return true;
    }
};

/*
43000
36000
43000
6000
8000
1500
1100
2300
3120
3000
5000
160000
*/
#endif // PRICES_H
