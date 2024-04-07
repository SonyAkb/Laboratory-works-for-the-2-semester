#include <iostream>
#include <functional>
#include <algorithm>
#include "Pair.h"
#include <map>
using namespace std;

void randomize(Pair& p) {
    int x = rand() % 1001;
    double y = (rand() % 100001) * 0.01;
    p = Pair(x, y);
}

void generate_M(map<Pair, Pair>& my_M, int M_size) {
    Pair qwe_1(0, 0), qwe_2(0, 0);
    for (int i = 0; i < M_size; i++) {
        randomize(qwe_1);
        randomize(qwe_2);
        my_M[qwe_1] = qwe_2;
    }
}

ostream& operator<<(ostream& stream, const pair<Pair, Pair> p){
    stream <<"Ключ - " << p.first << "     Значение  - " << p.second << "\n";
    return stream;
}

ostream& operator<<(ostream& stream, const map<Pair, Pair>& my_M) {
    map<Pair, Pair>::const_iterator It = my_M.begin();
    while (It != my_M.end())
        cout << *It++;
    return stream;
}

bool isInRange(Pair& key, Pair& lower, Pair& upper) {
    return key > lower && key < upper;
}

void remove_from_range(map<Pair, Pair>& my_M, Pair& range_1, Pair& range_2) {
    auto it = my_M.begin();
    Pair ptr;
    while (it != my_M.end()) { // Перебор всех пар ключ-значение
        ptr = it->first;
        if (!isInRange(ptr, range_1, range_2)) {
            ++it;
        }
        else {
            it = my_M.erase(it);
        }
    }
}

Pair minimum_pair(map<Pair, Pair>& my_M) {
    auto it = my_M.begin();
    Pair ptr;
    ptr = it->first;
    return ptr;
}

Pair maximum_pair(map<Pair, Pair>& my_M) {
    auto it = my_M.begin();
    Pair ptr;
    while (it != my_M.end()) { // Перебор всех пар ключ-значение
        ptr = it->first;
        ++it;
    }
    return ptr;
}

void all_sum(map<Pair, Pair>& my_M, Pair& key, Pair& value) {
    for (const auto& pair : my_M) { // Перебор всех пар ключ-значение
        Pair asd = pair.first;
        key = key + asd;
        asd = pair.second;
        value = value + asd;
    }
}

map<Pair, Pair> add_to_all(map<Pair, Pair>& my_M, Pair& key, Pair& value) {
    map<Pair, Pair> ptr;
    for (const auto& pair : my_M) { // Перебор всех пар ключ-значение
        Pair asd_1 = pair.first;
        Pair asd_2 = pair.second;
        ptr[asd_1 + key] = (asd_2 + value);
    }
    return ptr;
}

bool findPair(map<Pair, Pair>& my_M, Pair& key, Pair& value) {
    auto it = my_M.find(key);
    if (it != my_M.end()) {
        value = Pair(it->second);
        return true;
    }
    else {
        return false;
    }
}

int main() {
    system("chcp 1251 > Null");
    srand(time(0));
    /*Задание 3 - Словарь из Pair*/

    int N;
    do {
        cout << "Введите размер словаря ";
        cin >> N;
    } while (N < 1);

    Pair sum_1(0,0), sum_2(0,0), sum_key(0, 0), sum_value(0, 0);
    
    map<Pair, Pair> adj;//словарь пар
    generate_M(adj, N);
    
    cout << "Сгенерированный словарь:" << endl << adj << endl; //вывод словаря
    
    //добавляем каждый элемент к сумме пар чисел
    all_sum(adj, sum_1, sum_2); //общая сумма
    sum_1 / adj.size();//Среднее арифметическое ключей
    sum_2 / adj.size();//Среднее арифметическое значений

    cout << "Среднее арифметическое ключей " << sum_1 << endl;
    cout << "Среднее арифметическое значений " << sum_2 << endl << endl;

    adj[sum_1] = sum_2;//добавляю в конец среднее арифметическое
    cout << "После добавления среднего арифметического:" << endl << adj << endl;

    Pair one_el, two_el;//пары для диапазона

    cout << "Введите две пары чисел (ключей), из диапазона которых будут удалены пары из списка" << endl;
    cout << "Первая пара: " << endl;
    cin >> one_el;
    cout << "Вторая пара: " << endl;
    cin >> two_el;

    if (one_el > two_el) {//если числа не по возрастанию, то меняю их местами
        swap(one_el, two_el);
    }

    remove_from_range(adj, one_el, two_el);
    cout << endl << "После удаления из диапазона" << endl << adj << endl;

    Pair max_el = maximum_pair(adj);
    Pair min_el = minimum_pair(adj);

    findPair(adj, min_el, sum_1); // Вызываем функцию поиска
    findPair(adj, max_el, sum_2); // Вызываем функцию поиска

    cout << "Минимальный элемент по ключу: " << min_el << endl;
    cout << "Ключ - " << min_el << " Значение - " << sum_1 << endl;
    cout << "Максимальный элемент по ключу: " << max_el << endl;
    cout << "Ключ - " << max_el << " Значение - " << sum_2 << endl << endl;

    sum_key = min_el + max_el;
    sum_value = sum_1 + sum_2;
    cout << "Сумма максимального и минимального элементов:" << endl;
    cout << "Ключ - " << sum_key << " Значение - " << sum_value << endl << endl;

    adj = add_to_all(adj, sum_key, sum_value);
    cout << "После добавления суммы максимального и минимального к каждой паре чисел: " << endl;
    cout << adj << endl;

    cout << "Введите ключевое значение, по которому необходимо найти пару" << endl;
    cin >> one_el;
    
    bool found = findPair(adj, one_el, two_el); // Вызываем функцию поиска
    
    cout << endl;
    if (found) {
        cout << "Элемент найден." << endl;
        cout << "Ключ - " << one_el << " Значение - " << two_el << endl;
    }
    else {
        cout << "Элемент не найден(" << endl;
    }

    return 0;
}
