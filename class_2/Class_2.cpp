#include <iostream>
#include <string>
#include "pay.h"

using namespace std;

Pay make_pay() {
	string name;
	double salary;
	int bonus;

	cout << endl << "Введите имя: ";
	getline(cin, name);
	cout << "Введите оклад: ";
	cin >> salary;
	cout << "Введите премию в % от оклада: ";
	cin >> bonus;
	Pay pay(name, salary, bonus);
	return pay;
}

int main() {
	system("chcp 1251 > Null");

	Pay p1;
	p1.Print();

	Pay p2("Дурбажева Мария Михайловна", 100000, 2);
	p2.Print();

	Pay p3;
	p3.set_Name("Петров Петр Петрович");
	p3.set_Salary(30000);
	p3.set_Bonus(200);
	p3.Print();

	Pay p4 = make_pay();
	p4.Print();
	cout << endl;
	return 0;
}