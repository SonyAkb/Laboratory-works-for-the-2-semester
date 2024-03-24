#pragma once //предотвращает повторную загрузку заголовочного файла, если он уже был включен.
#include "progression.h" //объ€влени€ классов
#include <cmath> //дл€ возведени€ в степень

Progression::Progression(double first = 1, double second = 1) { //объ€вление конструктора класса Progression
	cout << "¬ызов конструктора класса Progression("<<first<<", "<<second<<")" << endl;
	this->first = first;//присваивает значение параметра first конструктора полю first объекта
	this->second = second;//присваивает значение параметра second конструктора полю second объекта
};

double Progression::element(int j) {//вычисл€ю aj = a0 * r^j (j-ый элемент прогрессии)
	cout << "¬ызов метода element("<<j<<")" << endl;
	return first * pow(second, j);
}

void Progression::setFirst(double a0) {//устанавливаю число a0
	cout << "Private поле first(a0) = "<< a0 << endl;
	this->first = a0;
}

void Progression::setSecond(double r) { //устанавливаю число r
	cout << "Private поле second(r) = " << r << endl;
	this->second = r;
}