#pragma once //предотвращает повторную загрузку заголовочного файла, если он уже был включен
#include <iostream> //стандартные потоки ввода и вывода
using namespace std;

class Pair {
	int first;
	double second;

public:
	Pair() {
		this->first = 0;
		this->second = 0;
	}

	Pair(int first, double second) {
		this->first = first;
		this->second = second;
	}

	Pair(const Pair& other) {//конструктор копирования
		this->first = other.first;
		this->second = other.second;
	}

	~Pair() {}

	void Print() {//вывод параметров класса person
		cout << "(" << this->first << " : " << this->second << ")" << endl;
	}

	Pair operator+(const int& x) {
		return (Pair(this->first + x, this->second));
	}

	Pair operator+(const double& y) {
		return (Pair(this->first, this->second + y));
	}

	Pair operator-(const Pair& para) {
		return (Pair(this->first - para.first, this->second - para.second));
	}

	void operator=(const Pair& para) {
		this->first = para.first;
		this->second = para.second;
	}

	friend ostream& operator <<(ostream& stream, const Pair& p) {
		stream << "(" << p.first << ":" << p.second << ")";
		return stream;
	}

	friend istream& operator >>(istream& stream, Pair& p) {
		cout << "Введите число first и second через пробел: ";
		stream >> p.first >> p.second;
		return stream;
	}
};