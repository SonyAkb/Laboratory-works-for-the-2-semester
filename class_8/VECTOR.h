#pragma once //������������� ��������� �������� ������������� �����, ���� �� ��� ��� �������
#include <iostream> //����������� ������ ����� � ������
#include "Object.h"
#include "Print.h"
#include "Magazin.h"
using namespace std;

class VECTOR {
	Object** beg;
	int size;//������ �������
	int current;
public:
	VECTOR();//����������� �� ���������
	VECTOR(int line);//����������� � ������
	~VECTOR() {};//����������

	void RE_create(int len);//���������� ������
	void add_el(Object* ptr);//���������� �������� � ������
	void Add();//���������� ��������
	bool Del();//�������� ��������
	void print(bool only_name = false);//�����
	friend ostream& operator <<(ostream& stream, const VECTOR& v);//�������� ��� ������ ������
};