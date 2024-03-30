#include <iostream>
#include <string>
#include "person.h"

int main(){
    system("chcp 1251 > Null");

    Person p1("Иванов Иван", 5);
    p1.Print();
    Person p3;
    p3.Print();
    Person p4(p1);
    p4.Print();

    cout << "------------------" << endl << endl;

    Student st1("Сергеев Сергей", 5, "math", 2);
    cout << st1;
    cout << endl;

    Student st2;
    cout << st2 << endl;
    cin >> st2;
    cout << endl;

    Student st3(st1);
    cout << st3;
    cout << "------------------" << endl << endl;

    st1.Print();
    st2.Print();
    st3.Print();
}
