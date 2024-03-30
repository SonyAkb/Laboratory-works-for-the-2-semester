#pragma once //предотвращает повторную загрузку заголовочного файла, если он уже был включен
#include <iostream> //стандартные потоки ввода и вывода
#include <string>
using namespace std;

class Person {
protected:
	string name;
	int age;
public:
	Person();//конструктор по умолчанию
	Person(string, int);//сначала передается имя, потом возраст
	Person(const Person&);//конструктор копирования
	~Person();//деструктор

	void Print(); //вывод
	void set_name(const string& name);//установка имени
	void set_age(const int& age);//установка возраста

	Person& operator=(const Person& p);//оператор присваивания

	friend ostream& operator <<(ostream& stream, const Person& p);//друж-я ф-я для потока вывода
	friend istream& operator >>(istream& stream, Person& p);//друж-я ф-я для потока ввода
};

class Student :public Person {
protected:
	string subject;
	int mark;
public:
	Student();//конструктор по умолчанию
	Student(const string& name, const int& age, const string& sub, const int& mark);
	void set_mark(const int& mark);//установка предмета
	void set_subject(const string& str); //установка оценки
	void Print();//вывод

	void good_bad_mark();//сообщение о низкой оценке

	friend ostream& operator <<(ostream& stream, const Student& s);//друж-я ф-я для потока вывода
	friend istream& operator >>(istream& stream, Student& s);//друж-я ф-я для потока ввода
};
