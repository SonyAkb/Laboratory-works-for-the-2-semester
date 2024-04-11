#include <iostream>
#include "Pair.h"
#include "List.h"

using namespace std;

int main(){
    system("chcp 1251 > Null");
    srand(time(0));

    List<int> list_1(5);
    List<double> list_2(5);
    List<float> list_3(5);
    List<Pair> list_4(3);
    List<int> list_5(5);

    cout << "list_1 - int" << endl;
    cin >> list_1;
    cout << list_1;
    cout << "Вывод элемента под номером 2" << endl;
    cout << list_1[1] << endl;
    
    cout << endl << "list_2 - double" << endl;
    cin >> list_2;
    cout << list_2;
    cout << "Вывод элемента под номером 3" << endl;
    cout << list_2[2] << endl;

    cout << endl << "list_3 - float" << endl;
    cin >> list_3;
    cout << list_3;
    cout << "Вывод элемента под номером 4" << endl;
    cout << list_3[3] << endl;
    
    cout << endl << "list_4" << endl;
    cin >> list_4;
    cout << list_4;
    cout << "Вывод элемента под номером 1" << endl;
    cout << list_4[0] << endl;

    cout << endl << "list_5 - int" << endl;
    list_5 = list_1;
    cout << list_5;
}

