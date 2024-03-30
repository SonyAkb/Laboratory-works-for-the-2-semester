#include "person.h"
#include <iostream>
#include <string>
using namespace std;

Student::Student() { 
	this->mark = 0; 
	this->subject = ""; 
	cout << "Конструктор по умолчанию для объекта " << this << endl;
}

Student::Student(const string& name, const int& age, const string& sub, const int& mark) {
	this->set_name(name);
	this->set_age(age);
	this->set_mark(mark);
	this->set_subject(sub);
	cout << "Конструктор с параметрами для объекта " << this << endl;
}

void Student::set_mark(const int& mark) {//установка предмета
	this->mark = mark;
}

void Student::set_subject(const string& str) {//установка оценки
	this->subject = str;
};

void Student::Print() {//вывод параметров класса student
	cout << "ФИО: " << this->name << endl << "Возраст: " << this->age << endl;
	cout << "Предмет: " << this->subject << endl << "Оценка: " << this->mark << endl;
	(*this).Student::good_bad_mark();
	cout << endl;
}

void Student::good_bad_mark() { //сообщение о низкой оценке
	if (this->mark < 3) {
		cout << "Отметка неудовлетворительна!" << endl;
	}
}

ostream& operator <<(ostream& stream, const Student& s) {//оператор для потока вывода
	const Person* human_stud = &s;
	stream << *human_stud;
	stream << "Предмет " << s.subject << endl;
	stream << "Оценка " << s.mark << endl;

	return stream;
}

istream& operator >>(istream& stream, Student& s) {//оператор для потока ввода
	string temp;
	int a;

	Person* const human_stud = &s;
	stream >> *human_stud;

	cout << "Предмет: ";
	stream >> temp;
	s.set_subject(temp);

	cout << "Оценка: ";
	stream >> a;
	s.set_mark(a);

	cout << endl << endl;

	return stream;
}