#include <iostream>
#include <queue>
#include <functional>
#include <algorithm>
#include "Pair.h"
#include <random>
using namespace std;

void randomize(Pair& p) {
    int x = rand() % 1001;
    double y = (rand() % 100001) * 0.01;
    p = Pair(x, y);
}

class Greater_Than_Pair{
public:
    bool operator()(Pair& p1, Pair& p2){
        return p1 < p2;
    }
};

void generate_Q(priority_queue<Pair, vector<Pair>, Greater_Than_Pair>& my_Q, int Q_size) {
    Pair qwe(0,0);
    for (int i = 0; i < Q_size; i++) {
        randomize(qwe);
        my_Q.push(qwe);
    }
}

ostream& operator<<(ostream& stream, priority_queue<Pair, vector<Pair>, Greater_Than_Pair> my_Q) {
    while (!my_Q.empty()) {
        Pair user = my_Q.top();
        std::cout << user << endl;
        my_Q.pop();
    }
    return stream;
}

Pair all_sum(priority_queue<Pair, vector<Pair>, Greater_Than_Pair> my_Q) {
    Pair p(0, 0);
    while (!my_Q.empty()) {
        Pair upp = my_Q.top();
        p = p + upp;
        my_Q.pop();
    }
    return p;
}

void remove_from_range(priority_queue<Pair, vector<Pair>, Greater_Than_Pair>& my_Q, Pair& range_1, Pair& range_2) {
    priority_queue<Pair, vector<Pair>, Greater_Than_Pair> queue_1;
    while (!my_Q.empty()) {
        Pair upp = my_Q.top();
        if (!(upp > range_1 && upp < range_2)) {
            queue_1.push(upp);
        }
        my_Q.pop();
    }
    my_Q = queue_1;
}

Pair maximum_pair(priority_queue<Pair, vector<Pair>, Greater_Than_Pair> my_Q) {
    Pair max_p = my_Q.top();
    return max_p;
}

Pair minimum_pair(priority_queue<Pair, vector<Pair>, Greater_Than_Pair> my_Q) {
    Pair min_p;
    while (!my_Q.empty()) {
        min_p = my_Q.top();
        my_Q.pop();
    }
    return min_p;
}

priority_queue<Pair, vector<Pair>, Greater_Than_Pair> add_to_all(priority_queue<Pair, 
    vector<Pair>, Greater_Than_Pair>& my_Q, Pair& para) {
    priority_queue<Pair, vector<Pair>, Greater_Than_Pair> queue_1;
    Pair upp = my_Q.top();
    while (!my_Q.empty()) {
        upp = my_Q.top();
        queue_1.push(upp + para);
        my_Q.pop();
    }
    return queue_1;
}

bool find_para(priority_queue<Pair, vector<Pair>, Greater_Than_Pair> my_Q, int& x, Pair& p) {
    bool flag = false;
    while (!my_Q.empty() && !flag) {
        p = my_Q.top();
        if (x == p.getFirst()) {
            flag = true;
        }
        my_Q.pop();
    }
    return flag;
}

int main() {
    system("chcp 1251 > Null");
    srand(time(0));
    /*Задание 2 - очередь с приоритетами из Pair*/

    int N;
    do {
        cout << "Введите размер очереди ";
        cin >> N;
    } while (N < 1);

    priority_queue<Pair, vector<Pair>, Greater_Than_Pair> qst;
    generate_Q(qst, N);

    cout << qst;

    Pair sum = all_sum(qst);

    //вычисляем среднее арифметическое
    sum.setFirst(sum.getFirst() / qst.size());//первое число
    sum.setSecond(((sum.getSecond() * 1000) /qst.size()) * 0.001);//второе число
    cout << endl << "Среднее арифметическое " << sum << endl << endl;
    
    qst.push(sum);//добавляю в конец среднее арифметическое
    cout << "После добавления среднего арифметического:" << endl << qst << endl;

    Pair one_el, two_el;//пары для диапазона

    cout << "Введите две пары чисел, из диапазона которых будут удалены пары из списка" << endl;
    cout << "Первая пара: " << endl;
    cin >> one_el;
    cout << "Вторая пара: " << endl;
    cin >> two_el;

    if (one_el > two_el) {//если числа не по возрастанию, то меняю их местами
        swap(one_el, two_el);
    }

    remove_from_range(qst, one_el, two_el);
    cout << endl << "После удаления из диапазона" << endl << qst << endl;

    Pair max_el = maximum_pair(qst);
    Pair min_el = minimum_pair(qst);

    cout << "Минимальный элемент: " << min_el << endl;
    cout << "Максимальный элемент: " << max_el << endl << endl;

    sum = max_el + min_el;
    cout << "Сумма максимального и минимального элементов " << sum << endl;
    qst = add_to_all(qst, sum);
    cout << "После добавления суммы максимального и минимального к каждой паре чисел: " << endl << qst;


    cout << "Введите значение first, по которому необходимо найти пару: ";
    int ptr;
    cin >> ptr;

    bool flag = find_para(qst, ptr, sum);

    if (flag) {
        cout << "Элемент найден: " << sum << endl;
    }
    else {
        cout << "Элемент не найден(" << endl;
    }

    return 0;
}
