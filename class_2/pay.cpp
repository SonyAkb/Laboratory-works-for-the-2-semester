#include "Pay.h"
#include <iostream>
#include <string>
using namespace std;

Pay::Pay() {//конструктор по умолчанию
	name = "John Doe";
	salary = 10;
	bonus = 0;
	cout << "Конструктор по умолчанию для объекта " << this << endl;
}

Pay::Pay(string name = "Jhon", double salary = 0, int bonus = 0) { //конструктор с параметрами
	this->name = name;//присвоение фио
	this->salary = salary;//присвоение з/п
	this->bonus = bonus;//присвоение премии
	cout << "Конструктор с параметрами для объекта " << this << endl;
}

Pay::Pay(const Pay& other) {//конструктор копирования
	this->name = other.name;//копирование фио
	this->salary = other.salary;//копирование з/п
	this->bonus = other.bonus;//присвоение премии
	cout << "Конструктор копирования для объекта " << this << endl;
}
Pay::~Pay() {//деструктор
	cout << "Деструктор для объекта " << this << endl;
}

string Pay::get_Name() {//извлечение фио
	return this->name;
}
void Pay::set_Name(string name) {//присвоение фио
	this->name = name;
}
double Pay::get_Salary() {//извлечение з/п
	return this->salary;
}
void Pay::set_Salary(double salary) {//присвоение з/п
	this->salary = salary;
}
int Pay::get_Bonus() {//извлечение премии
	return this->bonus;
}
void Pay::set_Bonus(int bonus) {//присвоение премии
	this->bonus = bonus;
}
void Pay::Print() {//вывод параметров класса Pay
	cout << "ФИО: " << this->name << endl << "ОКЛАД: " << this->salary << endl << "ПРЕМИЯ: " << this->bonus << " %" << endl << endl;
}
