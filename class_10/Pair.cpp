#include "Pair.h"
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

Pair Pair::operator+(const int& x) {
	return (Pair(this->first + x, this->second));
}

Pair Pair::operator+(const double& y) {
	return (Pair(this->first, this->second + y));
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
	stream << p.first << " : " << p.second;
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

fstream& operator<<(fstream& stream, Pair& para) {
	stream << para.first << endl << para.second << endl;
	return stream;
}

fstream& operator>>(fstream& stream, Pair& para) {
	stream >> para.first;
	stream >> para.second;
	return stream;
}