#pragma once //предотвращает повторную загрузку заголовочного файла, если он уже был включен
#include "List.h"
#include <iostream> //стандартные потоки ввода и вывода
using namespace std;

class Iterator {
private:
	friend struct Node;
	friend class List;
	Node* elem;
public:
	Iterator(); //конструктор по умолчанию
	Iterator(const Iterator& iter);//конструктор копирования
	~Iterator() {}
	Iterator& operator =(const Iterator& iter);//текущий итератор
	bool operator == (const Iterator& iter);//элементы равны?
	bool operator != (const Iterator& iter);//элементы НЕ равны?
	Iterator& operator ++(int);//следующий элемент
	Iterator& operator --(int);//предыдущий элемент
	Iterator& operator +(const int number);//элемент по индексу
	Iterator& operator -(const int number);//элемент по индексу
	int& operator *();//доступ к данным элемента по итератору
};