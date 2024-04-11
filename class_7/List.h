#pragma once //������������� ��������� �������� ������������� �����, ���� �� ��� ��� �������
#include <iostream> //����������� ������ ����� � ������
using namespace std;

template <typename T>
struct Node {
	T data; //������
	Node* ptr_to_prev_node = nullptr; //��������� �� ���������� �������
	Node* ptr_to_next_node = nullptr; //��������� �� ��������� �������
};

template <typename T>
class List {
private:
	int size; //������
	Node<T>* head; //��������� �� ������
	Node<T>* tail; //��������� �� �����
public:
	List() {
		this->size = 0;
		this->head = nullptr; //��������� �� ������
		this->tail = nullptr; //��������� �� �����
		
	};
	List(int size) {//����������� � ������
		this->size = size;
		if (size > 0) {//���� ����� ������ 0
			Node<T>* node = new Node<T>;//������ ����
			this->head = node; //��������� �� ������
			this->tail = node; //��������� �� �����
			for (int i = 1; i < size; i++) {//�������� �� ������� ������
				Node<T>* New_Node = new Node<T>;//����� ����
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
	}

	List(int size, T data) {//����������� � ������ � �������
		this->size = size;
		if (size > 0) {//���� ����� ������ 0
			Node<T>* node = new Node<T>;//������ ����
			node->data = data; //������ ��� ����
			this->head = node; //��������� �� ������
			this->tail = node; //��������� �� �����
			for (int i = 1; i < size; i++) {//�������� �� ������� ������
				Node* New_Node = new Node<T>;//����� ����
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
	}

	List(const List<T>& list) {//����������� �����������
		this->head = nullptr; //��������� �� ������
		this->tail = nullptr; //��������� �� �����
		this->size = 0;

		Node<T>* current_node = list.head;//������ ����
		while (current_node != nullptr) {//���� �� ������ ���� ������
			push_bask(current_node->data);//�������� � ����� ��-�
			current_node = current_node->ptr_to_next_node;//���� ��������� �������
		}
	}

	~List() {//����������
		Node<T>* current_node = head;//������
		while (current_node != nullptr) {//���� �� ������ ���� ������
			Node<T>* next_node = current_node->ptr_to_next_node;//��������� �������
			delete current_node;//������ ������� �������
			current_node = next_node;//���� ����� �������
		}
		head = nullptr; //������ ������
	}

	void push_bask(T data) {//������� �������� � �����
		Node<T>* New_Node = new Node<T>;//����� ����
		New_Node->data = data; //������ ��� ������ ����
		New_Node->ptr_to_next_node = nullptr;//����� ���� ���� ������ �� ���������
		if (this->head == nullptr) {//���� ������ ������
			this->head = New_Node;//����� ���� - ������
			this->tail = New_Node;//����� ���� - �����
		}
		else {
			tail->ptr_to_next_node = New_Node;//����� ��������� �� ����
			New_Node->ptr_to_prev_node = tail;
			tail = New_Node; ////����� ���� - �����
		}
		this->size++;//���������� �����
	}

	void push_front(T data) {//������� �������� � ������
		Node<T>* New_Node = new Node<T>;//����� ����
		New_Node->data = data; //������ ��� ������ ����

		if (this->head == nullptr) {//���� ������ ������
			this->head = New_Node;//����� ���� - ������
			this->tail = New_Node;//����� ���� - �����
		}
		else {
			head->ptr_to_prev_node = New_Node;//������ ��������� �� ����
			New_Node->ptr_to_next_node = head;
			head = New_Node; //����� ���� - ������
		}
		this->size++;//���������� �����
	}

	T pop_bask() {//�������� ����������
		T temp;
		if (this->tail != nullptr) {//���� ������ �� ������
			Node<T>* current_node = this->tail;//���� ����������
			tail = current_node->ptr_to_prev_node;//����� �����
			temp = current_node->data;
			tail->ptr_to_next_node = nullptr;
			this->size--;//�������� ������
		}
		return temp;//�������� �� ��������� ����������
	}

	T pop_front() {//�������� �������
		T temp;
		if (this->tail != nullptr) {//���� ������ �� ������
			Node<T>* current_node = this->head;//���� ����������
			head = current_node->ptr_to_next_node;//����� �����
			temp = current_node->data;
			head->ptr_to_prev_node = nullptr;
			this->size--;//�������� ������
		}
		return temp;//�������� �� ��������� ����������
	}

	bool is_empty() {
		return this->size == 0;//���� ������, �� ������ 1 ����� 0
	}

	int operator () () {//������ ������
		return this->size;
	}

	T& operator[](int index) {
		if (index < this->size && index >= 0) {//���� ������ ������ ������� � ������ -
			Node<T>* current_node = this->head;
			for (int i = 0; i != index; i++) {
				current_node = current_node->ptr_to_next_node;//���� ��������� �������
			}
			return current_node->data;
		}
		else {
			cout << "������ ��� �����";
			exit(0);
		}
	}

	List& operator = (const List<T>& list) {
		if (this == &list) {//���� �������� � ��� ��� �����
			return *this;
		}
		while (head != nullptr) {//������� ������ ������ ���������
			Node<T>* temp = head;
			head = head->ptr_to_next_node;
			delete temp;
		}
		size = 0;

		Node<T>* current_node = list.head;//������
		while (current_node != nullptr) {//���� �� ������ ���� �����
			push_bask(current_node->data);//�������� ��������� ������� � ������
			current_node = current_node->ptr_to_next_node;//���� ��������� �������
		}
		return *this;
	}

	List operator *(List<T>& list) {
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

	friend ostream& operator <<(ostream& stream, const List<T>& list) {//�����
		cout << "����� ��������� ������:" << endl;
		Node<T>* current_node = list.head;
		while (current_node != nullptr) {//���� �� ������ ���� ������
			stream << current_node->data << ' ';
			current_node = current_node->ptr_to_next_node;//���� ��������� �������
		}
		cout << endl;
		return stream;
	}

	friend istream& operator >>(istream& stream, List<T>& list) {//����
		cout << "������� �������� ������" << endl;
		Node<T>* current_node = list.head;
		while (current_node != nullptr) {//���� �� ������ ���� ������
			cin >> current_node->data;
			current_node = current_node->ptr_to_next_node;//���� ��������� �������
		}
		return stream;
	}
};

