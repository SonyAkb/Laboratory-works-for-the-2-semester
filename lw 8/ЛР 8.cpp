#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct student { //структура Студент
	string name; //имя
	string last_name; //фамилия
	string patronymic; //отчество
	string data; //дата рождения в формате ДД.ММ.ГГГГ
	string address; //домашний адрес
	int rating; //рейтинг от 0 до 100

	void enter_inform(string n, string l, string p, string d, string a, int r) { //ввод информации о студенте
		name = n; //имя
		last_name = l; //фамилия
		patronymic = p; //отчество
		data = d; //дата рождения в формате ДД.ММ.ГГГГ
		address = a; //домашний адрес
		rating = r; //рейтинг от 0 до 100
	}
};

bool check_mas(int* ptr, int index, int len); //проверяю наличие элемента в массиве
void create_student(string& name_st, string& last_n_st, string& patr_st, string& data_st, string& addr_st, int& rat);
	//ввод параметров студента
int last_name_search(struct student* N, int quantity, string last_name); //проверяю наличие фамилии
void writing_to_a_file(ofstream& file, struct student* N, int index); //запись в файл студента
void all_surnames(struct student* N, int quantity); //вывод фамилий всех студентов

int main() {
	setlocale(LC_ALL, "Russian"); //локализация
	system("chcp 1251");
	system("cls");

	const int max_size = 50; //максимальное количество студентов
	student mas_students[max_size]; //массив всех студентов
	int population; //количество студентов

	string name_st, last_n_st, patr_st, data_st, addr_st;
	int rat = 0; 

	do {
		cout << "Введите количество студентов (от 1 до " << max_size << "): ";
		cin >> population; //количество студентов
	} while (population < 1 || population>max_size);
	cout << endl;

	for (int i = 0; i < population; i++) { //ввожу данные всех студентов
		create_student(name_st, last_n_st, patr_st, data_st, addr_st, rat);
		mas_students[i].enter_inform(name_st, last_n_st, patr_st, data_st, addr_st, rat);
	}

	int mas_index_del[max_size * 2]; //массив удаленных индексов
	int k = 0; //текущий индекс последнего удаленного
	bool check; //промежуточная переменная

	for (int i = 0; i < population - 1; i++) { //прохожу по всем студентам
		for (int j = i + 1; j < population; j++) {
			if (mas_students[i].data == mas_students[j].data) { //сравниваю первого и второго студентов
				if (!check_mas(mas_index_del, i, k)) {
					mas_index_del[k] = i;
					++k;
				}
				if (!check_mas(mas_index_del, j, k)) {
					mas_index_del[k] = j;
					++k;
				}
			}
		}
	}

	string surname; //необходимая фамилия
	int index_new_surname; //индекс необходимой фамилии

	all_surnames(mas_students, population); //вывод доступных фамилий
	cout << "Введите фамилию студента, перед которым необходимо записать нового студента: "; 
	cin >> surname; //ввожу новую фамилию
	index_new_surname = last_name_search(mas_students, population, surname); //индекс нужной фамилии

	while (index_new_surname == -1) { //если введенной фамилии нет
		cout << endl << "Такой фамилии нет!";
		all_surnames(mas_students, population); //вывод доступных фамилий
		cout << "Введите существующую фамилию студента: ";
		cin >> surname;
		index_new_surname = last_name_search(mas_students, population, surname); //индекс нужной фамилии
	}

	cout << endl;
	create_student(name_st, last_n_st, patr_st, data_st, addr_st, rat); //запрашиваю данные о студенте
	mas_students[population].enter_inform(name_st, last_n_st, patr_st, data_st, addr_st, rat); //добавляю нового студента

	ofstream output("F3.txt"); // включение файла для записи

	for (int i = 0; i < index_new_surname; i++) { //перебираю студентов
		if (!check_mas(mas_index_del, i, population)) { //если студента нет в массиве удаленных
			writing_to_a_file(output, mas_students, i); //записываю студента в файл
		}
	}
	writing_to_a_file(output, mas_students, population); //записываю в файл нового студента
	for (int i = index_new_surname; i < population; i++) { //перебираю студентов
		if (!check_mas(mas_index_del, i, population)) { //если студента нет в массиве удаленных
			writing_to_a_file(output, mas_students, i); //записываю студента в файл
		}
	}
	cout << "Запись в файл завершена!" << endl;

	return 0;
}

bool check_mas(int* ptr, int index, int len) { //проверяю наличие элемента в массиве
	bool flag = false; //элемент не найден
	for (int i = 0; i < len && !flag; i++) { //перебираю элементы в массиве
		if (index == ptr[i]) { //если элемент найден
			flag = true; //флаг меняется, элемент найден
		}
	}
	return flag;
}

void create_student(string& name_st, string& last_n_st, string& patr_st, string& data_st, string& addr_st, int& rat) {
	//ввод параметров студента

	cout << "Введите Фамилию студента: ";
	cin >> last_n_st; //фамилия
	cout << "Введите Имя студента: ";
	cin >> name_st; //имя
	cout << "Введите Отчество студента: ";
	cin >> patr_st; //отчество
	cout << "Введите дату рождения студента (в формате ДД.ММ.ГГГГ): ";
	cin >> data_st; //дата рождения в формате ДД.ММ.ГГГГ
	cout << "Введите домашний адрес студента: ";
	cin.ignore();
	getline(cin, addr_st); //домашний адрес

	do {
		cout << "Введите рейтинг студента: ";
		cin >> rat; //рейтинг студента от 0 до 100
	} while (rat < 0 || rat > 100);
	cout << endl;
}

int last_name_search(struct student* N, int quantity, string last_name) { //проверяю наличие фамилии
	int index = -1; //фамилия не найдена
	for (int i = 0; i < quantity && index == -1; i++) {
		if (last_name == N[i].last_name) { //если фамилия найдена
			index = i; //индекс найденной фамилии
		}
	}
	return index;
}

void writing_to_a_file(ofstream& file, struct student* N, int index) { //запись в файл студента
	file << N[index].last_name << ' ' << N[index].name << ' ' << N[index].patronymic << ' ' << N[index].data << ' ' << N[index].address << "; рейтинг - " << N[index].rating << endl;
}

void all_surnames(struct student* N, int quantity) { //вывод фамилий фсех студентов
	cout << endl << "Допустимые фамилии студентов:" << endl;
	cout << N[0].last_name; //вывод первой фамилии
	for (int i = 1; i < quantity; i++) {
		cout << ", " << N[i].last_name; //вывод каждой фамилии
	}
	cout << endl;
}