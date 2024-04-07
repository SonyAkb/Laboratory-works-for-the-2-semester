#include "List.h"
#include "Iterator.h"
#include "Error.h"
#include <iostream>
#include <string>

using namespace std;

void creature_list_rand(List& list);
void print_list_iterator_start(List& list);
void print_list_iterator_end(List& list);

int main() {
    system("chcp 1251 > Null");
    srand(time(0));

    List list_1(10, 0);
    cout << "list_1" << endl;
    cout << list_1 << endl << endl;

    creature_list_rand(list_1);
    cout << "list_1" << endl;
    cout << list_1 << endl;
    cout << "Первый элемент: " << *(list_1.first_el()) << endl;
    cout << "Последний элемент: " << *(list_1.last_el()) << endl << endl;

    List list_2(list_1);
    cout << "list_2" << endl;
    cout << list_2 << endl << endl;

    list_2.push_front(100);
    list_2.pop_bask();
    cout << list_2 << endl << endl;

    try {//недопустимый размер множества, отрицательный размер
        List list_3(-1);
        cout << "list_3" << endl;
        cin >> list_3;
        cout << list_3 << endl << endl;
    
    }
    catch (Error& er) {
        er.what();
    }

    List list_4(11);
    creature_list_rand(list_4);
    cout << "list_4" << endl;
    cout << list_4 << endl << endl;

    List list_5 = list_2 * list_4;
    cout << "list_5" << endl;
    cout << list_5 << endl << endl;

    Iterator iter = list_1.first_el();
    try {
        cout << "Вывод элемента с индексом 100 list_1 с помощью Iterator с НАЧАЛА" << endl;
        cout << *(iter + 100);
        cout << endl;
    }
    catch (Error& er) {
        er.what();
    }

    iter = list_1.last_el();
    try {
        cout << "Вывод элемента с индексом -100 list_1 с помощью Iterator с КОНЦА" << endl;
        cout << *(iter - 100);
        cout << endl;
    }
    catch (Error& er) {
        er.what();
    }

    try {
        cout << "Вывод элемента с индексом 20 list_5 с помощью перегрузки операции" << endl;
        cout << list_5[20];
        cout << endl;
    }
    catch (Error& er) {
        er.what();
    }

    try {
        cout << "Вывод элемента с индексом -1 list_5 с помощью перегрузки операции" << endl;
        cout << list_5[-1];
        cout << endl;
    }
    catch (Error& er) {
        er.what();
    }

    cout << endl;

    return 0;
}

void creature_list_rand(List& list) {
    for (int i = 0; i < list(); i++) {
        list[i] = rand() % (100 + 1) - 50;
    }
}

void print_list_iterator_start(List& list) {
    for (Iterator iter = list.first_el(); iter != list.last_el() + 1; iter++) {
        cout << *iter << ' ';
    }
}

void print_list_iterator_end(List& list) {
    for (Iterator iter = list.last_el(); iter != list.first_el() - 1; iter--) {
        cout << *iter << ' ';
    }
}
