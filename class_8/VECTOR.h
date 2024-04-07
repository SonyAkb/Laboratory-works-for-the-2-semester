#pragma once //предотвращает повторную загрузку заголовочного файла, если он уже был включен
#include <iostream> //стандартные потоки ввода и вывода
#include "Object.h"
#include "Print.h"
#include "Magazin.h"
using namespace std;

class VECTOR {
	Object** beg;
	int size;//размер вектора
	int current;
public:
	VECTOR();//конструктор по умолчанию
	VECTOR(int line);//конструктор с длиной
	~VECTOR() {};//деструктор

	void RE_create(int len);//пересоздаю вектор
	void add_el(Object* ptr);//добавление элемента в вектор
	void Add();//добавление элемента
	bool Del();//удаление элемента
	void print(bool only_name = false);//вывод
	friend ostream& operator <<(ostream& stream, const VECTOR& v);//оператор для потока вывода
};