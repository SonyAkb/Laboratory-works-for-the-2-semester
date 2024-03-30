#include "person.h"
#include <iostream>
#include <string>
using namespace std;

Person::Person() {//конструктор по умолчанию
	this->name = "";
	this->age = 0;
	cout << "Конструктор по умолчанию для объекта " << this << endl;
}

Person::Person(string name, int age) {//конструктор с параметрами
	this->name = name; //сначала передается имя, потом возраст
	this->age = age;
	cout << "Конструктор с параметрами для объекта " << this << endl;
}

Person::Person(const Person& p) {
	this->name = p.name;
	this->age = p.age;
	cout << "Конструктор копирования для объекта " << this << endl;
}

Person::~Person() {//деструктор
	cout << "Деструктор для объекта " << this << endl;
}

void Person::Print() {//вывод параметров класса person
	cout << "ФИО: " << this->name << endl << "Возраст: " << this->age << endl << endl;
}

void Person::set_name(const string& name) {//установка имени
	this->name = name;
}

void Person::set_age(const int& age) {//установка возраста
	this->age = age;
}

Person& Person::operator=(const Person& p) {//оператор присваивания
	this->name = p.name;
	this->age = p.age;
	return *this;
};

ostream& operator <<(ostream& stream, const Person& p) {//оператор для потока вывода
	stream << "Имя " << p.name << endl;
	stream << "Возраст " << p.age << endl;
	return stream;
}

istream& operator >>(istream& stream, Person& p) {//оператор для потока ввода
	string temp;
	int a;

	cout << "Введите имя: ";
	stream.ignore();
	getline(stream, temp);
	p.set_name(temp);

	cout << "Введите возраст: ";
	stream >> a;
	p.set_age(a);

	return stream;
}

