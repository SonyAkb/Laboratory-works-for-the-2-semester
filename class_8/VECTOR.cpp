#include "VECTOR.h"
using namespace std;

VECTOR::VECTOR() {//конструктор по умолчанию
	beg = 0;
	size = 0;//всего элементов
	current = 0;//элементов сейчас
};

VECTOR::VECTOR(int line) {//конструктор с длиной
	beg = new Object * [line];
	current = 0;
	size = line;
}

void VECTOR::RE_create(int len) {//пересоздаю вектор
	if (beg != 0) {
		for (int i = 0; i < current; i++) {//удаляю текущий вектор
			delete beg[i];
		}
		delete[] beg;
	}
	size = len;
	beg = new Object * [len];
	current = 0;
}

void VECTOR::add_el(Object* ptr) {//добавление элемента в вектор
	if (current < size) {//если вектор не заполнен
		beg[current] = ptr;
		current++;//увеличиваю текущее количество элементов
	}
};

void VECTOR::Add() {
	if (current == size) {
		cout << "Места нет!" << endl;
		if (beg == NULL) {
			cout << "Вектор не создан!" << endl;
		}
	}
	else {
		Object* p;
		int choice;
		do {
			cout << "Какой класс создать?" << endl;
			cout << "1. Print" << endl;
			cout << "2. Magazine" << endl;
			cin >> choice;
		} while (choice < 1 || choice > 2);
		cout << endl;
		if (choice == 1) {
			Print* a = new Print;
			a->Input();
			p = a;
			add_el(p);
		}
		else {
			Magazin* b = new Magazin;
			b->Input();
			p = b;
			add_el(p);
		}
	}
}

bool VECTOR::Del() {
	bool flag = false;
	if (beg == NULL) {
		cout << "Вектор не создан!" << endl;
	}
	else {
		if (current == 0) {
			cout << "Удалять нечего, вектор пустой" << endl;
		}
		else {
			string NName;
			cout << "Введите название, по которому надо удалить ";
			cin.ignore();
			getline(cin, NName);
			for (int i = 0; i < current && !flag; i++) {
				if (beg[i]->get_name() == NName) {
					flag = true;
					Object* tmp = beg[i];
					for (int j = i; j < current - 1; j++) {//перемещаю объекты за место удаленого
						beg[i] = beg[j + 1];
					}
					delete tmp;
					current--;//уменьшаю длину
				}
			}
			if (flag) {
				cout << "Удаление успешно завершено" << endl;
			}
			else {
				cout << "Объект для удаления не найден" << endl;
			}
		}
	}
	return flag;
}

void VECTOR::print(bool only_name) {
	if (current == 0) {
		cout << "Вектор пуст(";
	}
	else {
		for (int i = 0; i < current; i++) {
			beg[i]->Show(only_name);
			cout << endl;
		}
	}
}

ostream& operator <<(ostream& stream, const VECTOR& v) {//оператор для потока вывода
	if (v.size == 0) {
		cout << endl << "Вектор пуст(";
	}
	else {
		Object** ptr = v.beg;
		for (int i = 0; i < v.current; i++) {
			(*ptr)->Show();
			cout << endl << endl;
			ptr++;
		}
	}
	return stream;
}