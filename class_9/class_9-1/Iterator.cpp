#include "list.h"
#include "iterator.h"
#include <iostream>
#include <string>
using namespace std;

Iterator::Iterator() {//конструктор по умолчанию
	this->elem = nullptr;
}

Iterator::Iterator(const Iterator& iter) {//конструктор копирования
	this->elem = iter.elem;
}

Iterator& Iterator:: operator = (const Iterator& iter) {//текущий итератор
	this->elem = iter.elem;
	return *this;
}

bool Iterator::operator == (const Iterator& iter) {//элементы равны?
	return this->elem == iter.elem;
}

bool Iterator::operator != (const Iterator& iter) {//элементы НЕ равны?
	return this->elem != iter.elem;
}

Iterator& Iterator::operator ++(int) {//следующий элемент
	this->elem = this->elem->ptr_to_next_node;
	return *this;
}

Iterator& Iterator::operator --(int) {
	this->elem = this->elem->ptr_to_prev_node;//предыдущий элемент
	return *this;
}

Iterator& Iterator::operator +(const int number) {//элемент по индексу
	Iterator temp(*this);
	int i = 0;
	for (i; i < number; i++) {
		if (temp.elem == nullptr) throw 2;
		temp.elem = temp.elem->ptr_to_next_node;
	}
	return temp;
}

Iterator& Iterator::operator -(const int number) {//элемент по индексу
	Iterator temp(*this);
	for (int i = 0; i < number; i++) {
		if (temp.elem == nullptr) throw 1;
		temp.elem = temp.elem->ptr_to_prev_node;
	}
	return temp;
}

int& Iterator::operator *() {//доступ к данным элемента по итератору
	return this->elem->data;
}