#include "pair.h"
#include <iostream>
#include <string>
using namespace std;

Pair::Pair() {
	this->first = 0;
	this->second = 0;
	cout << "Конструктор по умолчанию для объекта " << this << endl;
}

Pair::Pair(int first, double second) {
	this->first = first;
	this->second = second;
	cout << "Конструктор с параметрами для объекта " << this << endl;
}

Pair::Pair(const Pair& other) {//конструктор копирования
	this->first = other.first;
	this->second = other.second;
	cout << "Конструктор копирования для объекта " << this << endl;
}

Pair::~Pair() {//деструктор
	cout << "Деструктор для объекта " << this << endl;
}

void Pair::Print() {//вывод параметров класса person
	cout << "(" << this->first <<  " ; " << this->second << ")" << endl;
}

