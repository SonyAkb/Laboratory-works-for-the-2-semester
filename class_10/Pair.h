#pragma once //предотвращает повторную загрузку заголовочного файла, если он уже был включен
#include <iostream> //стандартные потоки ввода и вывода
#include <fstream>
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

	Pair operator+(Pair& p);
	Pair operator-(const Pair& para);
	Pair operator+(const int& x);
	Pair operator+(const double& y);

	void setFirst(const int& x);
	void setSecond(const double& y);
	int getFirst();
	double getSecond();
	void operator=(const Pair& para);
	friend ostream& operator <<(ostream& stream, const Pair& p);
	friend istream& operator >>(istream& stream, Pair& p);
	bool operator >(const Pair& p);
	bool operator <(const Pair& p);
	friend fstream& operator<<(fstream& stream, Pair& para);
	friend fstream& operator>>(fstream& stream, Pair& para);
};