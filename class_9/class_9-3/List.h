#pragma once //������������� ��������� �������� ������������� �����, ���� �� ��� ��� �������
#include <iostream> //����������� ������ ����� � ������
#include <string>
#include "Iterator.h"
#include "Error.h"
using namespace std;

struct Node {
	int data; //������
	Node* ptr_to_prev_node = nullptr; //��������� �� ���������� �������
	Node* ptr_to_next_node = nullptr; //��������� �� ��������� �������
};

class List {
private:
	int size; //������
	Node* head; //��������� �� ������
	Node* tail; //��������� �� �����
	Iterator begin;//��������� �� ��������� �������
	Iterator end;//��������� �� ��������� �������
public:
	List(int size); //����������� � ������
	List(int size, int data);//����������� � ������ � �������
	List(const List& list);//����������� �����������
	~List();//����������

	void push_bask(int data);//������� �������� � �����
	void push_front(int data);//������� �������� � ������

	Iterator first_el();//��������� �������
	Iterator last_el();//������ �������

	int pop_bask();//������� ��������� �������
	int pop_front();//������� ������ �������

	bool is_empty();//������ ������ ��� ���

	int operator () ();//������ ������
	int& operator[](int index);//������ �� �������
	List& operator = (const List& list);//�������� ������������
	List operator *(List& list);

	friend ostream& operator << (ostream& stream, const List& list);//�����
	friend istream& operator >> (istream& stream, const List& list);//����
};

