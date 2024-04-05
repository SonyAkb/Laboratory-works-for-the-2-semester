#include "list.h"
#include "iterator.h"
#include <iostream>
#include <string>

using namespace std;

void creature_list_rand(List& list);
void print_list_iterator_start(List& list);
void print_list_iterator_end(List& list);

int main(){
    system("chcp 1251 > Null");
    srand(time(0));
    
    List list_1(10, 0);
    cout << "list_1" << endl;
    cout << list_1 << endl << endl;
    
    creature_list_rand(list_1);
    cout << "list_1" << endl;
    cout << list_1 << endl << endl;
    cout << "Первый элемент: " << *(list_1.first_el()) << endl;
    cout << "Последний элемент: " << *(list_1.last_el()) << endl << endl;

    List list_2(list_1);
    cout << "list_2" << endl;
    cout << list_2 << endl << endl;

    list_2.push_front(100);
    list_2.pop_bask();
    cout << list_2 << endl << endl;

    cout << "Первый элемент: " << *(list_2.first_el()) << endl;
    cout << "Последний элемент: " << *(list_2.last_el()) << endl << endl;

    List list_3(5);
    cout << "list_3" << endl;
    cin >> list_3;
    cout << list_3 << endl << endl;

    cout << "Первый элемент: " << *(list_3.first_el()) << endl;
    cout << "Последний элемент: " << *(list_3.last_el()) << endl << endl;

    List list_4 = list_2 * list_3;
    cout << "list_4" << endl;
    cout << list_4 << endl << endl;

    cout << "Первый элемент: " << *(list_4.first_el()) << endl;
    cout << "Последний элемент: " << *(list_4.last_el()) << endl << endl;

    cout << "Вывод элементов list_1 с помощью Iterator с НАЧАЛА" << endl;
    print_list_iterator_start(list_1);
    cout << endl;

    cout << "Вывод элементов list_1 с помощью Iterator с КОНЦА" << endl;
    print_list_iterator_end(list_1);
    cout << endl << endl;

    cout << "Вывод элемента 2 list_3 с помощью Iterator с НАЧАЛА" << endl;
    Iterator iter = list_3.first_el();
    cout << *(iter + 1);
    cout << endl;
    
    cout << "Вывод элемента 2 list_3 с помощью Iterator с КОНЦА" << endl;
    iter = list_3.last_el();
    cout << *(iter - 3);
    cout << endl << endl;

    cout << "Сравнение элемента 2 и 3 list_3 с помощью Iterator" << endl;
    iter = list_3.first_el();
    if (*(iter + 1) == *(iter + 2)) {
        cout << *(iter + 1) << " == " << *(iter + 2) <<" элементы равны";
    }
    else {
        cout << *(iter + 1) << " != " << *(iter + 2) << " элементы не равны";
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
