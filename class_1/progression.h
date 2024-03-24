#pragma once //предотвращает повторную загрузку заголовочного файла, если он уже был включен
#include <iostream> //стандартные потоки ввода и вывода
using namespace std;

class Progression { //объ€вление класса Progression
private: //объ€вление private полей класса Progression
	double first;//объ€вл€ет private поле first типа double
	double second;//объ€вл€ет private поле second типа double
public://объ€вление public методов класса Progression.
	Progression(double, double); //объ€вл€ет конструктор класса Progression, который принимает два double параметра.
	double element(int); //объ€вл€ет метод element(), который принимает int параметр и возвращает double значение.
	void setFirst(double);//объ€вл€ет метод setFirst(), который принимает double параметр.
	void setSecond(double); //объ€вл€ет метод setSecond(), который принимает double параметр.
};