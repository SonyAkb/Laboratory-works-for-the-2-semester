#pragma once //предотвращает повторную загрузку заголовочного файла, если он уже был включен
#include <iostream> //стандартные потоки ввода и вывода
#include "object.h"
using namespace std;

class Person : public Object {
	friend istream& operator >>(istream& stream, Person& p){//друж-я ф-я для потока ввода
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

	friend ostream& operator <<(ostream& stream, const Person& p) {//оператор для потока вывода
		stream << "Имя " << p.name << endl;
		stream << "Возраст " << p.age << endl;
		return stream;
	}

protected:
	string name;
	int age;
public:
	Person() {//конструктор по умолчанию
		this->name = "";
		this->age = 0;
	}
	Person(string name, int age) {//конструктор с параметрами
		this->name = name; //сначала передается имя, потом возраст
		this->age = age;
	}
	Person(const Person& p) {//конструктор копирования
		this->name = p.name;
		this->age = p.age;
	}
	~Person() {};//деструктор

	void set_name(const string& name) {//установка имени
		this->name = name;
	}
	void set_age(const int& age) {//установка возраста
		this->age = age;
	}

	string get_name() {//получение имени
		return name;
	}
	int get_age() {//получение возраста
		return age;
	}

	Person& operator=(const Person& p) {//оператор присваивания
		this->name = p.name;
		this->age = p.age;
		return *this;
	};

	void Out_put() override {//вывод параметров класса person
		cout << "ФИО: " << this->name << endl << "Возраст: " << this->age;
	}
};

class Student : public Person {
	friend ostream& operator <<(ostream& stream, const Student& s) {//оператор для потока вывода
		const Person* human_stud = &s;
		stream << *human_stud;
		stream << "Предмет " << s.subject << endl;
		stream << "Оценка " << s.mark << endl;

		if (s.mark) {
			if (s.mark < 1 || s.mark > 5) {
				cout << "Оценка неправильная!" << endl;
			}
			else if (s.mark < 3) {
				cout << "Отметка неудовлетворительна!" << endl;
			}
			else if (s.mark == 3) {
				cout << "Зачет." << endl;
			}
			else if (s.mark == 4) {
				cout << "Хорошая оценка" << endl;
			}
			else {
				cout << "Отличная оценка" << endl;
			}
		}
		return stream;
	}

	friend istream& operator >>(istream& stream, Student& s) {//оператор для потока ввода
		string temp;
		int a;

		Person* const human_stud = &s;
		stream >> *human_stud;

		cout << "Введите предмет: ";
		stream >> temp;
		s.set_subject(temp);

		cout << "Введите оценку: ";
		stream >> a;
		s.set_mark(a);
		cout << endl;

		return stream;
	}
protected:
	string subject;
	int mark;
public:
	Student() {//конструктор по умолчанию
		this->mark = 0;
		this->subject = "";
	}
	Student(const Student& p) {//конструктор копирования
		this->subject = p.subject;
		this->mark = p.mark;
	}
	Student(const string& name, const int& age, const string& sub, const int& mark) : Person(name, age) {//конструктор с параметрами
		this->set_mark(mark);
		this->set_subject(sub);
	}
	Student(const int& age, const string& name, const string& sub, const int& mark) : Student(name, age, sub, mark) {};
	~Student() {};//деструктор

	string get_sub() const {//получение предмета
		return this->subject;
	}
	int get_mark() const {//получение оценки
		return this->mark;
	}
	void set_mark(const int& mark) {//установка предмета
		this->mark = mark;
	}
	void set_subject(const string& str) {//установка оценки
		this->subject = str;
	};
};