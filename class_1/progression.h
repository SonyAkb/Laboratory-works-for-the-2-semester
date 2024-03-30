#pragma once //предотвращает повторную загрузку заголовочного файла, если он уже был включен
#include <iostream> //стандартные потоки ввода и вывода
using namespace std;

class Progression { //объявление класса Progression
private: //объявление private полей класса Progression
	double first;//объявляет private поле first типа double
	double second;//объявляет private поле second типа double
public://объявление public методов класса Progression.
	Progression(double, double); //объявляет конструктор класса Progression, который принимает два double параметра.
	double element(int); //объявляет метод element(), который принимает int параметр и возвращает double значение.
	void setFirst(double);//объявляет метод setFirst(), который принимает double параметр.
	void setSecond(double); //объявляет метод setSecond(), который принимает double параметр.
};