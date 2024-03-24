#pragma once //������������� ��������� �������� ������������� �����, ���� �� ��� ��� �������.
#include "progression.h" //���������� �������
#include <cmath> //��� ���������� � �������

Progression::Progression(double first = 1, double second = 1) { //���������� ������������ ������ Progression
	cout << "����� ������������ ������ Progression("<<first<<", "<<second<<")" << endl;
	this->first = first;//����������� �������� ��������� first ������������ ���� first �������
	this->second = second;//����������� �������� ��������� second ������������ ���� second �������
};

double Progression::element(int j) {//�������� aj = a0 * r^j (j-�� ������� ����������)
	cout << "����� ������ element("<<j<<")" << endl;
	return first * pow(second, j);
}

void Progression::setFirst(double a0) {//������������ ����� a0
	cout << "Private ���� first(a0) = "<< a0 << endl;
	this->first = a0;
}

void Progression::setSecond(double r) { //������������ ����� r
	cout << "Private ���� second(r) = " << r << endl;
	this->second = r;
}