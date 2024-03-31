#pragma once //предотвращает повторную загрузку заголовочного файла, если он уже был включен
#include <iostream> //стандартные потоки ввода и вывода
#include "object.h"
using namespace std;

class VECTOR {
	Object** beg;
	int size;//размер вектора
	int current;
public:
	VECTOR() {//конструктор по умолчанию
		beg = 0;
		size = 0;//всего элементов
		current = 0;//элементов сейчас
	};

	VECTOR(int line) {//конструктор с длиной
		beg = new Object * [line];
		current = 0;
		size = line;
	}

	~VECTOR() {};//деструктор

	void add_el(Object* ptr) {//добавление элемента в вектор
		if (current < size) {//если вектор не заполнен
			beg[current] = ptr;
			current++;//увеличиваю текущее количество элементов
		}
	};

	friend ostream& operator <<(ostream& stream, const VECTOR& v) {//оператор для потока вывода
		if (v.size == 0) {
			cout << endl << "Вектор пустой(";
		}
		else {
			Object** ptr = v.beg;
			for (int i = 0; i < v.current; i++) {
				(*ptr)->Out_put();
				cout << endl << endl;
				ptr++;
			}
		}
		return stream;
	}
};