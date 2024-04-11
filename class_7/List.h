#pragma once //предотвращает повторную загрузку заголовочного файла, если он уже был включен
#include <iostream> //стандартные потоки ввода и вывода
using namespace std;

template <typename T>
struct Node {
	T data; //данные
	Node* ptr_to_prev_node = nullptr; //указатель на предыдущий элемент
	Node* ptr_to_next_node = nullptr; //указатель на следующий элемент
};

template <typename T>
class List {
private:
	int size; //размер
	Node<T>* head; //указатель на голову
	Node<T>* tail; //указатель на хвост
public:
	List() {
		this->size = 0;
		this->head = nullptr; //указатель на голову
		this->tail = nullptr; //указатель на хвост
		
	};
	List(int size) {//конструктор с длиной
		this->size = size;
		if (size > 0) {//если длина больше 0
			Node<T>* node = new Node<T>;//создаю узел
			this->head = node; //указатель на голову
			this->tail = node; //указатель на хвост
			for (int i = 1; i < size; i++) {//заполняю со второго номера
				Node<T>* New_Node = new Node<T>;//новый узел
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
	}

	List(int size, T data) {//конструктор с длиной и данными
		this->size = size;
		if (size > 0) {//если длина больше 0
			Node<T>* node = new Node<T>;//создаю узел
			node->data = data; //данные для узла
			this->head = node; //указатель на голову
			this->tail = node; //указатель на хвост
			for (int i = 1; i < size; i++) {//заполняю со второго номера
				Node* New_Node = new Node<T>;//новый узел
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
	}

	List(const List<T>& list) {//конструктор копирования
		this->head = nullptr; //указатель на голову
		this->tail = nullptr; //указатель на хвост
		this->size = 0;

		Node<T>* current_node = list.head;//создаю узел
		while (current_node != nullptr) {//пока не пройду весь список
			push_bask(current_node->data);//добавляю в конец эл-т
			current_node = current_node->ptr_to_next_node;//беру следующий элемент
		}
	}

	~List() {//деструктор
		Node<T>* current_node = head;//голова
		while (current_node != nullptr) {//пока не пройду весь список
			Node<T>* next_node = current_node->ptr_to_next_node;//следующий элемент
			delete current_node;//удаляю текущий элемент
			current_node = next_node;//беру новый элемент
		}
		head = nullptr; //голова пустая
	}

	void push_bask(T data) {//вставка элемента в конец
		Node<T>* New_Node = new Node<T>;//новый узел
		New_Node->data = data; //данные для нового узла
		New_Node->ptr_to_next_node = nullptr;//новый узел пока никуда не указывает
		if (this->head == nullptr) {//если список пустой
			this->head = New_Node;//новый узел - голова
			this->tail = New_Node;//новый узел - хвост
		}
		else {
			tail->ptr_to_next_node = New_Node;//хвост указывает на узел
			New_Node->ptr_to_prev_node = tail;
			tail = New_Node; ////новый узел - хвост
		}
		this->size++;//увеличиваю длину
	}

	void push_front(T data) {//вставка элемента в НАЧАЛО
		Node<T>* New_Node = new Node<T>;//новый узел
		New_Node->data = data; //данные для нового узла

		if (this->head == nullptr) {//если список пустой
			this->head = New_Node;//новый узел - голова
			this->tail = New_Node;//новый узел - хвост
		}
		else {
			head->ptr_to_prev_node = New_Node;//голова указывает на узел
			New_Node->ptr_to_next_node = head;
			head = New_Node; //новый узел - голова
		}
		this->size++;//увеличиваю длину
	}

	T pop_bask() {//удаление последнего
		T temp;
		if (this->tail != nullptr) {//если список не пустой
			Node<T>* current_node = this->tail;//узел предыдущий
			tail = current_node->ptr_to_prev_node;//меняю хвост
			temp = current_node->data;
			tail->ptr_to_next_node = nullptr;
			this->size--;//уменьшаю размер
		}
		return temp;//значение из удаленной переменной
	}

	T pop_front() {//удаление первого
		T temp;
		if (this->tail != nullptr) {//если список не пустой
			Node<T>* current_node = this->head;//узел предыдущий
			head = current_node->ptr_to_next_node;//меняю хвост
			temp = current_node->data;
			head->ptr_to_prev_node = nullptr;
			this->size--;//уменьшаю размер
		}
		return temp;//значение из удаленной переменной
	}

	bool is_empty() {
		return this->size == 0;//если пустой, то вернет 1 иначе 0
	}

	int operator () () {//размер списка
		return this->size;
	}

	T& operator[](int index) {
		if (index < this->size && index >= 0) {//если индекс меньше размера и больше -
			Node<T>* current_node = this->head;
			for (int i = 0; i != index; i++) {
				current_node = current_node->ptr_to_next_node;//беру следующий элемент
			}
			return current_node->data;
		}
		else {
			cout << "Индекс вне цикла";
			exit(0);
		}
	}

	List& operator = (const List<T>& list) {
		if (this == &list) {//если элементы и так уже равны
			return *this;
		}
		while (head != nullptr) {//сначала очищаю список полностью
			Node<T>* temp = head;
			head = head->ptr_to_next_node;
			delete temp;
		}
		size = 0;

		Node<T>* current_node = list.head;//голова
		while (current_node != nullptr) {//пока не рпойду весь спиок
			push_bask(current_node->data);//добавляю очередной элемент в список
			current_node = current_node->ptr_to_next_node;//беру следующий элемент
		}
		return *this;
	}

	List operator *(List<T>& list) {
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

	friend ostream& operator <<(ostream& stream, const List<T>& list) {//вывод
		cout << "Вывод элементов списка:" << endl;
		Node<T>* current_node = list.head;
		while (current_node != nullptr) {//пока не пройду весь список
			stream << current_node->data << ' ';
			current_node = current_node->ptr_to_next_node;//беру следующий элемент
		}
		cout << endl;
		return stream;
	}

	friend istream& operator >>(istream& stream, List<T>& list) {//ввод
		cout << "Введите элементы списка" << endl;
		Node<T>* current_node = list.head;
		while (current_node != nullptr) {//пока не пройду весь список
			cin >> current_node->data;
			current_node = current_node->ptr_to_next_node;//беру следующий элемент
		}
		return stream;
	}
};

