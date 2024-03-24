#include "Pay.h"
#include <iostream>
#include <string>
using namespace std;

Pay::Pay() {//����������� �� ���������
	name = "John Doe";
	salary = 10;
	bonus = 0;
	cout << "����������� �� ��������� ��� ������� " << this << endl;
}

Pay::Pay(string name = "Jhon", double salary = 0, int bonus = 0) { //����������� � �����������
	this->name = name;//���������� ���
	this->salary = salary;//���������� �/�
	this->bonus = bonus;//���������� ������
	cout << "����������� � ����������� ��� ������� " << this << endl;
}

Pay::Pay(const Pay& other) {//����������� �����������
	this->name = other.name;//����������� ���
	this->salary = other.salary;//����������� �/�
	this->bonus = other.bonus;//���������� ������
	cout << "����������� ����������� ��� ������� " << this << endl;
}
Pay::~Pay() {//����������
	cout << "���������� ��� ������� " << this << endl;
}

string Pay::get_Name() {//���������� ���
	return this->name;
}
void Pay::set_Name(string name) {//���������� ���
	this->name = name;
}
double Pay::get_Salary() {//���������� �/�
	return this->salary;
}
void Pay::set_Salary(double salary) {//���������� �/�
	this->salary = salary;
}
int Pay::get_Bonus() {//���������� ������
	return this->bonus;
}
void Pay::set_Bonus(int bonus) {//���������� ������
	this->bonus = bonus;
}
void Pay::Print() {//����� ���������� ������ Pay
	cout << "���: " << this->name << endl << "�����: " << this->salary << endl << "������: " << this->bonus << " %" << endl << endl;
}
