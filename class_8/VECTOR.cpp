#include "VECTOR.h"
using namespace std;

VECTOR::VECTOR() {//����������� �� ���������
	beg = 0;
	size = 0;//����� ���������
	current = 0;//��������� ������
};

VECTOR::VECTOR(int line) {//����������� � ������
	beg = new Object * [line];
	current = 0;
	size = line;
}

void VECTOR::RE_create(int len) {//���������� ������
	if (beg != 0) {
		for (int i = 0; i < current; i++) {//������ ������� ������
			delete beg[i];
		}
		delete[] beg;
	}
	size = len;
	beg = new Object * [len];
	current = 0;
}

void VECTOR::add_el(Object* ptr) {//���������� �������� � ������
	if (current < size) {//���� ������ �� ��������
		beg[current] = ptr;
		current++;//���������� ������� ���������� ���������
	}
};

void VECTOR::Add() {
	if (current == size) {
		cout << "����� ���!" << endl;
		if (beg == NULL) {
			cout << "������ �� ������!" << endl;
		}
	}
	else {
		Object* p;
		int choice;
		do {
			cout << "����� ����� �������?" << endl;
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
		cout << "������ �� ������!" << endl;
	}
	else {
		if (current == 0) {
			cout << "������� ������, ������ ������" << endl;
		}
		else {
			string NName;
			cout << "������� ��������, �� �������� ���� ������� ";
			cin.ignore();
			getline(cin, NName);
			for (int i = 0; i < current && !flag; i++) {
				if (beg[i]->get_name() == NName) {
					flag = true;
					Object* tmp = beg[i];
					for (int j = i; j < current - 1; j++) {//��������� ������� �� ����� ���������
						beg[i] = beg[j + 1];
					}
					delete tmp;
					current--;//�������� �����
				}
			}
			if (flag) {
				cout << "�������� ������� ���������" << endl;
			}
			else {
				cout << "������ ��� �������� �� ������" << endl;
			}
		}
	}
	return flag;
}

void VECTOR::print(bool only_name) {
	if (current == 0) {
		cout << "������ ����(";
	}
	else {
		for (int i = 0; i < current; i++) {
			beg[i]->Show(only_name);
			cout << endl;
		}
	}
}

ostream& operator <<(ostream& stream, const VECTOR& v) {//�������� ��� ������ ������
	if (v.size == 0) {
		cout << endl << "������ ����(";
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