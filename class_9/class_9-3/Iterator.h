#pragma once //������������� ��������� �������� ������������� �����, ���� �� ��� ��� �������
#include "List.h"
#include <iostream> //����������� ������ ����� � ������
using namespace std;

class Iterator {
private:
	friend struct Node;
	friend class List;
	Node* elem;
public:
	Iterator(); //����������� �� ���������
	Iterator(const Iterator& iter);//����������� �����������
	~Iterator() {}
	Iterator& operator =(const Iterator& iter);//������� ��������
	bool operator == (const Iterator& iter);//�������� �����?
	bool operator != (const Iterator& iter);//�������� �� �����?
	Iterator& operator ++(int);//��������� �������
	Iterator& operator --(int);//���������� �������
	Iterator& operator +(const int number);//������� �� �������
	Iterator& operator -(const int number);//������� �� �������
	int& operator *();//������ � ������ �������� �� ���������
};