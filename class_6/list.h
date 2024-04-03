#pragma once //предотвращает повторную загрузку заголовочного файла, если он уже был включен
#include <iostream> //стандартные потоки ввода и вывода
#include <string>
#include "iterator.h"
using namespace std;

struct Node {
	int data; //данные
	Node* ptr_to_prev_node = nullptr; //указатель на предыдущий элемент
	Node* ptr_to_next_node = nullptr; //указатель на следующий элемент
};

class List {
private:
	int size; //размер
	Node* head; //указатель на голову
	Node* tail; //указатель на хвост
	Iterator begin;//указатель на начальный элемент
	Iterator end;//указатель на последний элемент
public:
	List(int size); //конструктор с длиной
	List(int size, int data);//конструктор с длиной и данными
	List(const List& list);//конструктор копирования
	~List();//деструктор

	void push_bask(int data);//вставка элемента в конец
	void push_front(int data);//вставка элемента в НАЧАЛО

	Iterator first_el();//последний элемент
	Iterator last_el();//первый элемент

	int pop_bask();//удалить последний элемент
	int pop_front();//удалить первый элемент

	bool is_empty();//список пустой иль нет

	int operator () ();//размер списка
	int& operator[](int index);//данные по индексу
	List& operator = (const List& list);//оператор присваивания
	List operator *(List& list);

	friend ostream& operator << (ostream& stream, const List& list);//ВЫВОД
	friend istream& operator >> (istream& stream, const List& list);//ВВОД
};

