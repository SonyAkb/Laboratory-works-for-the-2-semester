#include "List.h"
using namespace std;

List::List(int size) {//конструктор с длиной
	if (size <= 0) throw error_size_is_too_small();
	this->size = size;
	if (size > 0) {//если длина больше 0
		Node* node = new Node;//создаю узел
		this->head = node; //указатель на голову
		this->tail = node; //указатель на хвост
		for (int i = 1; i < size; i++) {//заполняю со второго номера
			Node* New_Node = new Node;//новый узел
			tail->ptr_to_next_node = New_Node;//хвост указывает на новый узел
			New_Node->ptr_to_prev_node = tail;//новый узел ук-т на хвост как на пред-й
			tail = New_Node;//новый узел становится хвостом
		}
		tail->ptr_to_next_node = nullptr;//до хвоста элементов нет
	}
	else {
		this->head = nullptr; //указатель на голову
		this->tail = nullptr; //указатель на хвост
	}
	this->begin.elem = this->head;
	this->end.elem = this->tail;
}

List::List(int size, int data) {//конструктор с длиной и данными
	if (size <= 0) throw error_size_is_too_small();
	this->size = size;
	if (size > 0) {//если длина больше 0
		Node* node = new Node;//создаю узел
		node->data = data; //данные для узла
		this->head = node; //указатель на голову
		this->tail = node; //указатель на хвост
		for (int i = 1; i < size; i++) {//заполняю со второго номера
			Node* New_Node = new Node;//новый узел
			New_Node->data = data; //данные для нового узла
			tail->ptr_to_next_node = New_Node;//хвост указывает на новый узел
			New_Node->ptr_to_prev_node = tail;//новый узел ук-т на хвост как на пред-й
			tail = New_Node;//новый узел становится хвостом
		}
		tail->ptr_to_next_node = nullptr;//до хвоста элементов нет
	}
	else {
		this->head = nullptr; //указатель на голову
		this->tail = nullptr; //указатель на хвост
	}
	this->begin.elem = this->head;
	this->end.elem = this->tail;
}

List::List(const List& list) {//конструктор копирования
	this->head = nullptr; //указатель на голову
	this->tail = nullptr; //указатель на хвост
	this->size = 0;

	Node* current_node = list.head;//создаю узел
	while (current_node != nullptr) {//пока не пройду весь список
		push_bask(current_node->data);//добавляю в конец эл-т
		current_node = current_node->ptr_to_next_node;//беру следующий элемент
	}
	this->begin.elem = this->head;
	this->end.elem = this->tail;
}

List::~List() {//деструктор
	Node* current_node = head;//голова
	while (current_node != nullptr) {//пока не пройду весь список
		Node* next_node = current_node->ptr_to_next_node;//следующий элемент
		delete current_node;//удаляю текущий элемент
		current_node = next_node;//беру новый элемент
	}
	head = nullptr; //голова пустая
}

void List::push_bask(int data) {//вставка элемента в конец
	Node* New_Node = new Node;//новый узел
	New_Node->data = data; //данные для нового узла
	New_Node->ptr_to_next_node = nullptr;//новый узел пока никуда не указывает
	if (this->head == nullptr) {//если список пустой
		this->head = New_Node;//новый узел - голова
		this->tail = New_Node;//новый узел - хвост
		this->begin.elem = this->head;
		this->end.elem = this->tail;
	}
	else {
		tail->ptr_to_next_node = New_Node;//хвост указывает на узел
		New_Node->ptr_to_prev_node = tail;
		tail = New_Node; ////новый узел - хвост
		this->end.elem = this->tail;
	}
	this->size++;//увеличиваю длину
}

void List::push_front(int data) {//вставка элемента в НАЧАЛО
	Node* New_Node = new Node;//новый узел
	New_Node->data = data; //данные для нового узла

	if (this->head == nullptr) {//если список пустой
		this->head = New_Node;//новый узел - голова
		this->tail = New_Node;//новый узел - хвост
		this->begin.elem = this->head;
		this->end.elem = this->tail;
	}
	else {
		head->ptr_to_prev_node = New_Node;//голова указывает на узел
		New_Node->ptr_to_next_node = head;
		head = New_Node; //новый узел - голова
		this->begin.elem = this->head;
	}
	this->size++;//увеличиваю длину
}

Iterator List::first_el() {//первый элемент
	return this->begin;
}

Iterator List::last_el() {//первый элемент
	return this->end;
}

int List::pop_bask() {//удаление последнего
	int temp;
	if (this->tail != nullptr) {//если список не пустой
		Node* current_node = this->tail;//узел предыдущий
		tail = current_node->ptr_to_prev_node;//меняю хвост
		temp = current_node->data;
		tail->ptr_to_next_node = nullptr;
		this->size--;//уменьшаю размер
		this->end.elem = tail;
	}
	return temp;//значение из удаленной переменной
}

int List::pop_front() {//удаление первого
	int temp;
	if (this->tail != nullptr) {//если список не пустой
		Node* current_node = this->head;//узел предыдущий
		head = current_node->ptr_to_next_node;//меняю хвост
		temp = current_node->data;
		head->ptr_to_prev_node = nullptr;
		this->size--;//уменьшаю размер
		this->begin.elem = head;
	}
	return temp;//значение из удаленной переменной
}

bool List::is_empty() {
	return this->size == 0;//если пустой, то вернет 1 иначе 0
}

int List::operator () () {//размер списка
	return this->size;
}

int& List::operator[](int index) {
	if (index < this->size && index >= 0) {//если индекс меньше размера и больше -
		Node* current_node = this->head;
		for (int i = 0; i != index; i++) {
			current_node = current_node->ptr_to_next_node;//беру следующий элемент
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
	if (this == &list) {//если элементы и так уже равны
		return *this;
	}
	while (head != nullptr) {//сначала очищаю список полностью
		Node* temp = head;
		head = head->ptr_to_next_node;
		delete temp;
	}
	size = 0;

	Node* current_node = list.head;//голова
	while (current_node != nullptr) {//пока не рпойду весь спиок
		push_bask(current_node->data);//добавляю очередной элемент в список
		current_node = current_node->ptr_to_next_node;//беру следующий элемент
	}
	this->begin = list.begin;
	this->end = list.end;
	return *this;
}

List List::operator *(List& list) {
	int temp_size;
	if (this->size > list.size) {//если первый размер списка больше размера 2 списка
		temp_size = list.size;//наименьший размер из двух
	}
	else {
		temp_size = this->size;//наименьший размер из двух
	}

	List temp(temp_size, 0);//список с наименьшей длиной
	for (int i = 0; i < temp_size; i++) {//пока не пройду по списку наименьшей длины
		temp[i] = (*this)[i] * list[i];
	}
	return temp;
}

ostream& operator <<(ostream& stream, const List& list) {//вывод
	cout << "Вывод элементов списка:" << endl;
	Node* current_node = list.head;
	while (current_node != nullptr) {//пока не пройду весь список
		stream << current_node->data << ' ';
		current_node = current_node->ptr_to_next_node;//беру следующий элемент
	}
	return stream;
}

istream& operator >>(istream& stream, const List& list) {//ввод
	cout << "Введите элементы списка" << endl;
	Node* current_node = list.head;
	while (current_node != nullptr) {//пока не пройду весь список
		stream >> current_node->data;
		current_node = current_node->ptr_to_next_node;//беру следующий элемент
	}
	return stream;
}