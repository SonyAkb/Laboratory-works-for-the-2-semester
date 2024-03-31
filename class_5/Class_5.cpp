#include <iostream>
#include <string>
#include "person.h"
#include "vector.h"

int main(){
    system("chcp 1251 > Null");
    VECTOR vec(2);

    Person p1;//класс человек
    cin >> p1;
    cout << endl << p1 << endl ;

    Student st1;//класс студент
    cin >> st1;
    cout << st1 << endl ;


    Object* ob = &p1;//класс указателей на классы
    vec.add_el(ob);
    ob = &st1;
    vec.add_el(ob);
    cout << vec;

    cout << endl;
    
}