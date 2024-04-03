#pragma once //предотвращает повторную загрузку заголовочного файла, если он уже был включен
#include <iostream> //стандартные потоки ввода и вывода
using namespace std;

class Pair {
	int first;
	double second;

public:
	Pair();//конструктор класса по умолчанию
	Pair(int, double);//конструктор класса с параметрами
	Pair(const Pair&);//конструктор копирования класса
	~Pair();//деструктор класса
	void Print();

	Pair operator+(const int& x){
		cout << endl << "Вызов оператора + для " << this << endl;
		return (Pair(this->first + x, this->second));
	}

	Pair operator+(const double& y){
		cout << endl << "Вызов оператора + для " << this << endl;
		return (Pair(this->first, this->second + y));
	}

	Pair operator-(const Pair& para) {
		cout << "Вызов оператора - для " << this << endl;
		return (Pair(this->first - para.first, this->second - para.second));
	}

	void operator=(const Pair& para) {
		cout << "Вызов оператора = для " << this << endl;
		this->first = para.first;
		this->second = para.second;
	}

	friend ostream& operator <<(ostream& stream, const Pair& p) {
		stream << "(" << p.first << ":" << p.second << ")";
		return stream;
	}
};