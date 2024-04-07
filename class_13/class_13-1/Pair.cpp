#include "Pair.h"
#include <iostream>
#include <string>
using namespace std;

Pair::Pair() {
	this->first = 0;
	this->second = 0;
}

Pair::Pair(int first, double second) {
	this->first = first;
	this->second = second;
}

Pair::Pair(const Pair& other) {//конструктор копирования
	this->first = other.first;
	this->second = other.second;
}

Pair::~Pair() {//деструктор
}

void Pair::Print() {//вывод параметров класса person
	cout << "(" << this->first << " : " << this->second << ")" << endl;
}

Pair Pair::operator+(Pair& p) {
	return (Pair(this->first + p.first, this->second + p.second));
}

Pair Pair::operator-(const Pair& para) {
	return (Pair(this->first - para.first, this->second - para.second));
}

void Pair::setFirst(const int& x) {
	this->first = x;
}

void Pair::setSecond(const double& y) {
	this->second = y;
}

int Pair::getFirst() {
	return this->first;
}

double Pair::getSecond() {
	return this->second;
}

void Pair::operator=(const Pair& para) {
	this->first = para.first;
	this->second = para.second;
}

ostream& operator <<(ostream& stream, const Pair& p) {
	stream << "(" << p.first << " : " << p.second << ")";
	return stream;
}
istream& operator >>(istream& stream, Pair& p) {
	cout << "Введите число first и second через пробел: ";
	stream >> p.first >> p.second;
	return stream;
}

bool Pair::operator >(const Pair& p) {
	if (this->first < p.first) {
		return false;
	}
	if (this->first == p.first && this->second < p.second) {
		return false;
	}
	return true;
}
bool Pair::operator <(const Pair& p) {
	if (this->first > p.first) {
		return false;
	}
	if (this->first == p.first && this->second > p.second) {
		return false;
	}
	return true;
}