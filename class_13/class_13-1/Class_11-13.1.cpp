#include <iostream>
#include <list>
#include <functional>
#include <algorithm>
#include "Pair.h"
using namespace std;

ostream& operator<<(ostream& stream, list<Pair>& l) {
    for_each(l.begin(), l.end(), [](Pair& p) {cout << p << endl; });
    return stream;
}

void randomize(Pair& p) {
    int x = rand() % 1001;
    double y = (rand() % 100001)*0.01;
    p = Pair(x, y);
}

int main(){
    system("chcp 1251 > Null");
    srand(time(0));
    /*Задание 1 - Список из Pair*/

    int N;
    do {
        cout << "Введите размер списка ";
        cin >> N;
    } while (N < 1);

    Pair sum;
    list<Pair> list_1(N);//список пар
    //заполнение списка на основе функции, которая возвращает случайную пару чисел
    generate(list_1.begin(), list_1.end(), []() {Pair p; randomize(p); return p; });
    
    cout << "Сгенерированный список:" << endl << list_1 << endl; //вывод списка

    //добавляем каждый элемент к сумме пар чисел
    for_each(list_1.begin(), list_1.end(), [&sum](Pair& p) {sum = sum + p; }); //общая сумма

    //вычисляем среднее арифметическое
    sum.setFirst(sum.getFirst() / list_1.size());//первое число
    sum.setSecond(((sum.getSecond() * 10000) / list_1.size()) * 0.0001);//второе число
    cout << "Среднее арифметическое " << sum << endl << endl;

    list_1.push_back(sum);//добавляю в конец среднее арифметическое
    cout << "После добавления среднего арифметического:" << endl << list_1 << endl;

    Pair one_el, two_el;//пары для диапазона

    cout << "Введите две пары чисел, из диапазона которых будут удалены пары из списка" << endl;
    cout << "Первая пара: " << endl;
    cin >> one_el;
    cout << "Вторая пара: " << endl;
    cin >> two_el;

    if (one_el > two_el) {//если числа не по возрастанию, то меняю их местами
        swap(one_el, two_el);
    }

    list<Pair>::iterator s = remove_if(list_1.begin(), list_1.end(), [one_el, two_el](Pair& p) {return p > one_el && p < two_el; });
    list_1.erase(s, list_1.end());//удаляю из диапазона

    cout << endl << "После удаления из диапазона" << endl << list_1 << endl;

    //minmax_element возвращает пару из STL first и second это итераторы
    pair<list<Pair>::iterator, list<Pair>::iterator> stl_pair = minmax_element(list_1.begin(), list_1.end());
    cout << "Минимальный элемент: " << *stl_pair.first << endl;
    cout << "Максимальный элемент: " << *stl_pair.second << endl << endl;

    Pair sum_pair(stl_pair.first->getFirst() + stl_pair.second->getFirst(), stl_pair.first->getSecond() + stl_pair.second->getSecond());
    cout << "Сумма максимального и минимального элементов " << sum_pair << endl;

    for_each(list_1.begin(), list_1.end(), [&sum_pair](Pair& p) {p = p + sum_pair; });
    cout << "После добавления суммы максимального и минимального к каждой паре чисел: " << endl;
    cout << list_1 << endl;

    cout << "Сортировка по Возрастанию: " << endl;
    list_1.sort([](Pair& a, Pair& b) {return a < b; });
    cout << list_1 << endl;

    cout << "Сортировка по Убыванию: " << endl;
    list_1.sort([](Pair& a, Pair& b) {return a > b; });
    cout << list_1 << endl;

    cout << "Введите значение first, по которому необходимо найти пару: ";
    int ptr;
    cin >> ptr;

    auto i = find_if(list_1.begin(), list_1.end(), [&ptr](Pair& p) {return ptr == p.getFirst(); });
    if (i != end(list_1)) {
        cout <<"Элемент найден: "<< *i << endl;
    }
    else {
        cout << "Элемент не найден(" << endl;
    }

    return 0;
}
