#include "List.h"
using namespace std;

List::List(int size) {//����������� � ������
	if (size <= 0) throw error_size_is_too_small();
	this->size = size;
	if (size > 0) {//���� ����� ������ 0
		Node* node = new Node;//������ ����
		this->head = node; //��������� �� ������
		this->tail = node; //��������� �� �����
		for (int i = 1; i < size; i++) {//�������� �� ������� ������
			Node* New_Node = new Node;//����� ����
			tail->ptr_to_next_node = New_Node;//����� ��������� �� ����� ����
			New_Node->ptr_to_prev_node = tail;//����� ���� ��-� �� ����� ��� �� ����-�
			tail = New_Node;//����� ���� ���������� �������
		}
		tail->ptr_to_next_node = nullptr;//�� ������ ��������� ���
	}
	else {
		this->head = nullptr; //��������� �� ������
		this->tail = nullptr; //��������� �� �����
	}
	this->begin.elem = this->head;
	this->end.elem = this->tail;
}

List::List(int size, int data) {//����������� � ������ � �������
	if (size <= 0) throw error_size_is_too_small();
	this->size = size;
	if (size > 0) {//���� ����� ������ 0
		Node* node = new Node;//������ ����
		node->data = data; //������ ��� ����
		this->head = node; //��������� �� ������
		this->tail = node; //��������� �� �����
		for (int i = 1; i < size; i++) {//�������� �� ������� ������
			Node* New_Node = new Node;//����� ����
			New_Node->data = data; //������ ��� ������ ����
			tail->ptr_to_next_node = New_Node;//����� ��������� �� ����� ����
			New_Node->ptr_to_prev_node = tail;//����� ���� ��-� �� ����� ��� �� ����-�
			tail = New_Node;//����� ���� ���������� �������
		}
		tail->ptr_to_next_node = nullptr;//�� ������ ��������� ���
	}
	else {
		this->head = nullptr; //��������� �� ������
		this->tail = nullptr; //��������� �� �����
	}
	this->begin.elem = this->head;
	this->end.elem = this->tail;
}

List::List(const List& list) {//����������� �����������
	this->head = nullptr; //��������� �� ������
	this->tail = nullptr; //��������� �� �����
	this->size = 0;

	Node* current_node = list.head;//������ ����
	while (current_node != nullptr) {//���� �� ������ ���� ������
		push_bask(current_node->data);//�������� � ����� ��-�
		current_node = current_node->ptr_to_next_node;//���� ��������� �������
	}
	this->begin.elem = this->head;
	this->end.elem = this->tail;
}

List::~List() {//����������
	Node* current_node = head;//������
	while (current_node != nullptr) {//���� �� ������ ���� ������
		Node* next_node = current_node->ptr_to_next_node;//��������� �������
		delete current_node;//������ ������� �������
		current_node = next_node;//���� ����� �������
	}
	head = nullptr; //������ ������
}

void List::push_bask(int data) {//������� �������� � �����
	Node* New_Node = new Node;//����� ����
	New_Node->data = data; //������ ��� ������ ����
	New_Node->ptr_to_next_node = nullptr;//����� ���� ���� ������ �� ���������
	if (this->head == nullptr) {//���� ������ ������
		this->head = New_Node;//����� ���� - ������
		this->tail = New_Node;//����� ���� - �����
		this->begin.elem = this->head;
		this->end.elem = this->tail;
	}
	else {
		tail->ptr_to_next_node = New_Node;//����� ��������� �� ����
		New_Node->ptr_to_prev_node = tail;
		tail = New_Node; ////����� ���� - �����
		this->end.elem = this->tail;
	}
	this->size++;//���������� �����
}

void List::push_front(int data) {//������� �������� � ������
	Node* New_Node = new Node;//����� ����
	New_Node->data = data; //������ ��� ������ ����

	if (this->head == nullptr) {//���� ������ ������
		this->head = New_Node;//����� ���� - ������
		this->tail = New_Node;//����� ���� - �����
		this->begin.elem = this->head;
		this->end.elem = this->tail;
	}
	else {
		head->ptr_to_prev_node = New_Node;//������ ��������� �� ����
		New_Node->ptr_to_next_node = head;
		head = New_Node; //����� ���� - ������
		this->begin.elem = this->head;
	}
	this->size++;//���������� �����
}

Iterator List::first_el() {//������ �������
	return this->begin;
}

Iterator List::last_el() {//������ �������
	return this->end;
}

int List::pop_bask() {//�������� ����������
	int temp;
	if (this->tail != nullptr) {//���� ������ �� ������
		Node* current_node = this->tail;//���� ����������
		tail = current_node->ptr_to_prev_node;//����� �����
		temp = current_node->data;
		tail->ptr_to_next_node = nullptr;
		this->size--;//�������� ������
		this->end.elem = tail;
	}
	return temp;//�������� �� ��������� ����������
}

int List::pop_front() {//�������� �������
	int temp;
	if (this->tail != nullptr) {//���� ������ �� ������
		Node* current_node = this->head;//���� ����������
		head = current_node->ptr_to_next_node;//����� �����
		temp = current_node->data;
		head->ptr_to_prev_node = nullptr;
		this->size--;//�������� ������
		this->begin.elem = head;
	}
	return temp;//�������� �� ��������� ����������
}

bool List::is_empty() {
	return this->size == 0;//���� ������, �� ������ 1 ����� 0
}

int List::operator () () {//������ ������
	return this->size;
}

int& List::operator[](int index) {
	if (index < this->size && index >= 0) {//���� ������ ������ ������� � ������ -
		Node* current_node = this->head;
		for (int i = 0; i != index; i++) {
			current_node = current_node->ptr_to_next_node;//���� ��������� �������
		}
		return current_node->data;
	}
	else {
		if (index > this->size) throw error_index_is_too_big();
		if (index < 0) throw error_index_is_too_small();
		exit(0);
	}
}

List& List::operator = (const List& list) {
	if (this == &list) {//���� �������� � ��� ��� �����
		return *this;
	}
	while (head != nullptr) {//������� ������ ������ ���������
		Node* temp = head;
		head = head->ptr_to_next_node;
		delete temp;
	}
	size = 0;

	Node* current_node = list.head;//������
	while (current_node != nullptr) {//���� �� ������ ���� �����
		push_bask(current_node->data);//�������� ��������� ������� � ������
		current_node = current_node->ptr_to_next_node;//���� ��������� �������
	}
	this->begin = list.begin;
	this->end = list.end;
	return *this;
}

List List::operator *(List& list) {
	int temp_size;
	if (this->size > list.size) {//���� ������ ������ ������ ������ ������� 2 ������
		temp_size = list.size;//���������� ������ �� ����
	}
	else {
		temp_size = this->size;//���������� ������ �� ����
	}

	List temp(temp_size, 0);//������ � ���������� ������
	for (int i = 0; i < temp_size; i++) {//���� �� ������ �� ������ ���������� �����
		temp[i] = (*this)[i] * list[i];
	}
	return temp;
}

ostream& operator <<(ostream& stream, const List& list) {//�����
	cout << "����� ��������� ������:" << endl;
	Node* current_node = list.head;
	while (current_node != nullptr) {//���� �� ������ ���� ������
		stream << current_node->data << ' ';
		current_node = current_node->ptr_to_next_node;//���� ��������� �������
	}
	return stream;
}

istream& operator >>(istream& stream, const List& list) {//����
	cout << "������� �������� ������" << endl;
	Node* current_node = list.head;
	while (current_node != nullptr) {//���� �� ������ ���� ������
		stream >> current_node->data;
		current_node = current_node->ptr_to_next_node;//���� ��������� �������
	}
	return stream;
}