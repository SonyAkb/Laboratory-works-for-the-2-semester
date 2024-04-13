﻿#include <iostream>
#include <cmath>
using namespace std;

double side(int x1, int y1, int x2, int y2);
double square(int x1, int y1, int x2, int y2, int x3, int y3);
void print_k(double* ptr, double n, double start);
double square1(double n, ...);

int main() {
    setlocale(LC_ALL, "Russian");
    //10.0, 2.0, 3.0, 7.0, 2.0, 9.0, 4.0, 8.0, 7.0, 3.0, 5.0 = 13
    //16.0, 1.0, 2.0, 4.0, 9.0, 6.0, 11.0, 14.0, 13.0, 22.0, 9.0, 20.0, 5.0, 14.0, -2.0, 4.0, -3.0 = 87.5
    
    double y = square1(10.0, 2.0, 3.0, 7.0, 2.0, 9.0, 4.0, 8.0, 7.0, 3.0, 5.0);
    //double y = square1(16.0, 1.0, 2.0, 4.0, 9.0, 6.0, 11.0, 14.0, 13.0, 22.0, 9.0, 20.0, 5.0, 14.0, -2.0, 4.0, -3.0);
    //первое число - количество передаваемых данных, последующие - координаты вершин, расположенные попарно (x и y)

    cout << "Площадь треугольника содержащего диагональ наибольшей длины выпуклого многоугольника: " << y;
    return 0;
}

double side(int x1, int y1, int x2, int y2) { //длина стороны по координатам начала и конца
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    //x1 - координата по x начала стороны
    //y1 - координата по y начала стороны
    //x2 - координата по x конца стороны
    //y2 - координата по y конца стороны
}

double square(int x1, int y1, int x2, int y2, int x3, int y3) { //площадь треугольника по координатам
    return 0.5 * abs((x1 - x3) * (y2 - y3) - (x2 - x3) * (y1 - y3));
    //x1 - координата по x первой вершины
    //y1 - координата по y первой вершины
    //x2 - координата по x второй вершины
    //y2 - координата по y второй вершины
    //x3 - координата по x третьей вершины
    //y3 - координата по y третьей вершины

}

void print_k(double* ptr, double n, double start) { //вывожу координаты вершин
    for (int i = start; i < n; i += 2) {
        cout << "x: " << *(ptr + i) << "   y: " << *(ptr + i + 1) << endl;
    }
    cout << endl;
    //ptr - массив, где хранятся координаты
    //n - количество координат попарно
    //start - от какого индекса выводить координаты
}

double square1(double n, ...) { //площадь треугольника по наибольшей диагонали
    double* p = &n; //указатель на адрес параметров
    double max_side = 0, new_side, k_max_side[] = { 0, 0, 0, 0, 0, 0 }, maxS = 0, newS = 0;

    cout << "Задан выпуклый многоугольник с такими координатами вершин: " << endl;
    print_k(p, n, 1);
    //нахожу наибольшую диагональ и ее координаты
    for (int i = 1; i <= n; i += 2) {  //изменение указателя на следующий параметр - начало стороны
        for (int j = i + 4; j <= n; j += 2) {  //изменение указателя на следующий параметр - конец стороны
            new_side = side(*(p + i), *(p + i + 1), *(p + j), *(p + j + 1)); //длина новой диагонали
            if (new_side > max_side) { //проверка - новая диагональ больше текущей максимальной?
                max_side = new_side; //новая максимальная диагональ
                k_max_side[0] = { *(p + i) }, k_max_side[1] = { *(p + i + 1) }; //координаты начала стороны
                k_max_side[2] = { *(p + j) }, k_max_side[3] = { *(p + j + 1) }; //координаты конца стороны
            }
        }
    }
    cout << "Длина наибольшей диагонали: " << max_side << endl << endl;
    //нахожу наибольшую S треугольника
    for (int i = 1; i <= n; i += 2) { //прохожу по всем сторонам многоугольника и ищу max S треугольника
        if (k_max_side[0] != *(p + i) && k_max_side[1] != *(p + i + 1) && k_max_side[2] != *(p + i) && k_max_side[3] != *(p + i + 1)) {
            newS = square(k_max_side[0], k_max_side[1], k_max_side[2], k_max_side[3], *(p + i), *(p + i + 1)); //новая S
            if (newS > maxS) { //проверяю - новая S больше текущей?
                maxS = newS; //новая максимальная S
                k_max_side[4] = { *(p + i) }, k_max_side[5] = { *(p + i + 1) }; //координаты последней вершины треугольника
            }
        }
    }
    cout << "Координаты вершин треугольника " << endl;
    print_k(k_max_side, 6, 0); //вывод координат треугольника с наибольшей диагональю и наибольшей S

    return maxS; //возвращаю S треугольника
}