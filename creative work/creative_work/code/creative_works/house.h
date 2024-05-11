#ifndef HOUSE_H
#define HOUSE_H
#include "prices.h"
#include <cmath>
class House : public QObject {//класс дом
    Q_OBJECT
public:
    int floor;//этаж: 0 - первый, 1 - первый + мансарда, 2 - второй
    double S_external_first;//плащадь внешняя 1 этаж
    double S_internal_first;//плащадь внутренняя 1 этаж
    double S_external_all = 0;//плащадь внешняя ВСЯ
    double S_internal_all = 0;//плащадь внутренняя ВСЯ
    int foundation_i;//вид фундамента - индекс
    int number_of_piles;//количество свай
    int sheathing_i;//вид обшивки - индекс
    int electrics_i;//электрика нужна или нет - индекс
    int plumbing_i;//сантехника нужна или нет - индекс
    int underfloor_heating_i;//теплый пол нужен или нет - индекс
    double last_cost = 0;//цена дома

    House(){
        floor = 0;//этаж: 0 - первый, 1 - первый + мансарда, 2 - второй
        S_external_first = 0;//плащадь внешняя 1 этаж
        S_internal_first = 0;//плащадь внутренняя ВСЯ
        foundation_i = 0;//вид фундамента - индекс
        sheathing_i = 0;//вид обшивки - индекс
        electrics_i = 0;//электрика нужна или нет - индекс
        plumbing_i = 0;//сантехника нужна или нет - индекс
        underfloor_heating_i = 0;//теплый пол нужен или нет - индекс
    }
    ~House(){};
    void assemble_the_house(std::vector<int> list_index, double cur_S){//характеристики дома
        floor = list_index[0];//этажность
        if(list_index[1] == 0){
            S_external_first = cur_S;//внешняя площадь
            S_internal_first = S_external_first * 0.87;//внутренняя площадь - меньше внешней на 13%
        }
        else{
            S_internal_first = cur_S;//внутренняя площадь - меньше внешней на 13%
            S_external_first = (S_internal_first / 87) * 100;//внешняя площадь
        }
        if(list_index[0] == 0){//1 этаж
            S_external_all = S_external_first;//снаружи вся S
            S_internal_all = S_internal_first;//внутри вся S
        }
        else if (list_index[0] == 1){//1 этаж + мансарда
            double approximate_width = sqrt(S_external_first);//примерная длина по квадрату
            S_external_all = S_external_first + ((approximate_width - 2) * approximate_width);//снаружи вся S
            S_internal_all = S_internal_all * 0.87;//внутри вся S
        }
        else{//2 этажа
            S_external_all = S_external_first * 2;//снаружи вся S
            S_internal_all = S_internal_first * 2;//внутри вся S
        }
        foundation_i = list_index[2];//вид фундамента
        number_of_piles = std::ceil(S_external_first / 3);//количество свай
        sheathing_i = list_index[3];//вид обшивки
        electrics_i = list_index[4];//вид электрики
        plumbing_i = list_index[5];//вид сантехники
        underfloor_heating_i = list_index[6];//вид
    }

    double the_final_price_of_the_house(Prices& price_catalog){//цена дома итоговая
        double the_entire_amount = 0;//цена дома
        if(S_external_all>0){//если площадь дома адекватная
            double cost_floor = S_external_all * price_catalog.q_floor[floor];//домокомплект
            the_entire_amount += cost_floor;
            double cost_foundation = number_of_piles * price_catalog.foundation[foundation_i];//фундамент
            the_entire_amount += cost_foundation;
            double cost_sheathing = S_internal_all * price_catalog.sheathing[sheathing_i];//обшивка
            the_entire_amount += cost_sheathing;
            double cost_electrics = S_internal_all * price_catalog.electrics[electrics_i];//электрика
            the_entire_amount += cost_electrics;
            double cost_plumbing = S_internal_first * price_catalog.plumbing[plumbing_i];//сантехника
            the_entire_amount += cost_plumbing;
            double cost_underfloor_heating = S_internal_first * price_catalog.underfloor_heating[underfloor_heating_i];//теплый пол
            the_entire_amount += cost_underfloor_heating;
            double cost_delivery;
            if(S_external_all <= 60.0){
                cost_delivery = price_catalog.delivery;
            }
            else{
                cost_delivery = price_catalog.delivery * std::ceil(S_external_all / 60 / 0.5 ) * 0.5;
            }
            the_entire_amount += cost_delivery;
            last_cost = the_entire_amount;
        }
        return the_entire_amount;
    }
};
#endif // HOUSE_H
