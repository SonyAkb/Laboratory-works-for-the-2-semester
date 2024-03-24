#include<iostream>
#include<string>
#include<ctime>
#define _USE_MATH_DEFINES//для спользования констант
#include<math.h>
#include <fstream>

using namespace std;

const int M = 100;
const double A = M_PI_4;
int Collision_Counter = 0;

struct Node {
	string key = "";
	string value = "";
};

struct Hash_Table {
	Node* table[M];
	Hash_Table() {
		for (int i = 0; i < M; ++i) {
			table[i] = nullptr;
		}
	}
};

double fractional_part(double k); //дробная часть от числа
int get_Hash(double k);
int get_Hash(string line);
bool add(Hash_Table& table, string key, string elem); //добавление элемента
bool remove_By_Key(Hash_Table& table, string key);//удаление элемента по КЛЮЧУ
bool remove_By_Value(Hash_Table& table, string elem);//удаление элемента по ЗНАЧЕНИЮ
Node* get(Hash_Table& table, string key); //ищу элемент
void print(Hash_Table& table); //вывод всех элементов хеш таблицы

string generator_Full_Name(); //генераторы
string correct_Str(int n, int lenght);
string generate_Birthday();
string generate_Passport_Num();

void create_Human(Hash_Table& table);
string enter_el(string value_1, string value_2);
int choice_action();
int random_element(Hash_Table& table);
void writing_to_a_file(Hash_Table& table, ofstream& file);//запись в файл
void clean_all_table(Hash_Table& table);//очищение таблицы
void recovery(Hash_Table& table, ifstream& file);//востановление из файла

string surname[30] = { "Карпов", "Афанасьев", "Власов","Маслов","Исаков","Тихонов","Аксёнов",
	"Гаврилов","Родионов","Котов","Горбунов","Кудряшов","Быков","Зуев","Третьяков","Савельев",
	"Панов","Рыбаков","Суворов","Абрамов","Воронов","Мухин","Архипов","Трофимов","Мартынов","Емельянов",
	"Горшков","Чернов","Овчинников","Селезнёв" };
string name[30] = { "Иван", "Андрей", "Антон", "Амин", "Роберт", "Георгий", "Борис", "Владислав",
	"Дмитрий", "Никита", "Данила", "Артем", "Парвиз", "Сергей", "Илья", "Григорий", "Артур", "Денис",
	"Алексей", "Александр", "Валерий", "Дамир", "Михаил", "Константин", "Николай", "Герман", "Иннокентий",
	"Богдан", "Станислав", "Сурман" };
string patronymic[30] = { "Иванович", "Андреевич", "Антонович", "Аминович", "Робертович", "Георгиевич",
	"Борисович", "Владиславович", "Дмитриевич", "Никитович","Данилович", "Артемович", "Парвизович", "Сергеевич",
	"Ильич", "Григорьевич", "Артурович", "Денисович", "Алексеевич", "Александрович", "Валерьевич", "Дамирович",
	"Михайлович", "Константинович", "Николаевич", "Германович", "Иннокентьевич",
	"Богданович", "Станиславович", "Сурманович" };



int main() {
	system("chcp 1251 > Null");
	srand(time(0));

	Hash_Table myTable;//таблица
	int mas_size, choice;
	ofstream output("hash table.txt"); //выходной файловый поток

	do {
		cout << "Введите количество элементов ";
		cin >> mas_size; //количество элементов в списке
	} while (mas_size < 1 || mas_size > M);

	for (int i = 0; i < mas_size; i++) { //создание хеш таблицы
		create_Human(myTable);
	}

	cout << "Хеш-Таблица создана! " << endl;
	print(myTable);

	do {
		do {
			cout << endl << "------------------------------------------" << endl;
			cout << "Что вы хотите сделать? " << endl;
			cout << "0 - Выход(" << endl;//////
			cout << "1 - Добавить элемент" << endl;////
			cout << "2 - Удалить элемент" << endl;/////
			cout << "3 - Вывести Хеш таблицу" << endl;//////
			cout << "4 - Найти элемент" << endl;/////
			cout << "5 - Узнать число коллизий" << endl;/////////
			cout << "6 - Сохранить Хеш таблицу в файл" << endl;
			cout << "7 - Очистить Хеш таблицу" << endl;
			cout << "8 - Выгрузить данные из файла" << endl;
			cin >> choice;
		} while (choice < 0 || choice > 8);
		cout << endl;

		if (choice == 1) {//Добавить элемент
			bool flag;
			int choice_2 = choice_action();
			if (choice_2 == 1) {
				string birthday = generate_Birthday();
				string newHuman = generator_Full_Name() + " | " + birthday + " | " + generate_Passport_Num();
				flag = add(myTable, birthday, newHuman);
			}
			else {
				string birthday, fio, passport;
				cout << "Введите дату рождения в формате ДД.MM.ГГГГ:   ";
				cin >> birthday;
				cout << "Введите ФИО:   ";
				cin.ignore();
				getline(cin, fio);
				cout << "Введите номер и серию пасспорта:   ";
				cin.ignore();
				getline(cin, passport);
				flag = add(myTable, birthday, fio + " | " + birthday + " | " + passport);
			}

			if (flag) {
				cout << "Элемент успешно добавлен!" << endl;
			}
			else {
				cout << "Хеш таблица переполнена(" << endl;
				cout << "В данный момент нельзя добавить новый элемент" << endl;
			}
		}
		else if (choice == 2) {//Удалить элемент
			int choice_1, choice_2;
			do {
				cout << "Удалить по ключу или по значению?" << endl;
				cout << "1 - по КЛЮЧУ" << endl;
				cout << "2 - по ЗНАЧЕНИЮ" << endl;
				cin >> choice_1;
			} while (choice_1 < 1 || choice_1 > 2);

			choice_2 = choice_action();

			if (choice_2 == 1) { //выбрать случайно
				int existring_Ind = random_element(myTable);

				Node* randomHuman = myTable.table[existring_Ind];
				if (choice_1 == 1) {//удалить по ключу
					string keyToRemove = randomHuman->key;

					cout << "Удаление по ключу: '" << keyToRemove << "':" << endl;
					if (remove_By_Key(myTable, keyToRemove)) {
						cout << "Элемент с ключом: '" << keyToRemove << "' успешно удален" << endl;
					}
					else {
						cout << "Элемент с ключом: '" << keyToRemove << "' не найден" << endl;
					}
				}
				else {
					string valueToRemove = randomHuman->value;

					cout << "Удаление по значению '" << valueToRemove << "': " << endl;
					if (remove_By_Value(myTable, valueToRemove)) {
						cout << "Элемент со значением '" << valueToRemove << "' успешно удален " << endl;
					}
					else {
						cout << "Элемент со значением '" << valueToRemove << "' не найден " << endl;
					}
				}
			}
			else {//ввести с клавиатуры
				if (choice_1 == 1) {//по ключу
					string key_To_Remove;
					cout << endl << "Введите КЛЮЧ для удаления " << endl;
					cin >> key_To_Remove;

					cout << "Удаление по ключу: '" << key_To_Remove << "':" << endl;
					if (remove_By_Key(myTable, key_To_Remove)) {
						cout << "Элемент с ключом: '" << key_To_Remove << "' успешно удален" << endl;
					}
					else {
						cout << "Элемент с ключом: '" << key_To_Remove << "' не найден" << endl;
					}
				}
				else {//по значению
					string value_To_Remove;
					cout << "Введите ЗНАЧЕНИЕ для удаления " << endl;
					cin.ignore();
					getline(cin, value_To_Remove);

					cout << "Удаление по значению '" << value_To_Remove << "': " << endl;
					if (remove_By_Value(myTable, value_To_Remove)) {
						cout << "Элемент со значением '" << value_To_Remove << "' успешно удален " << endl;
					}
					else {
						cout << "Элемент со значением '" << value_To_Remove << "' не найден " << endl;
					}
				}
			}
		}
		else if (choice == 3) { //вывод таблицы
			print(myTable);
		}
		else if (choice == 4) {//найти элемент
			int choice = choice_action();
			string keyToGet;
			if (choice == 1) {
				int existring_Ind = random_element(myTable);
				Node* randomHuman = myTable.table[existring_Ind];
				keyToGet = randomHuman->key;
			}
			else {
				cout << "Введите КЛЮЧ для удаления " << endl;
				cin >> keyToGet;
			}
			cout << "Получение элемента по ключу '" << keyToGet << "': " << endl;
			Node* node = get(myTable, keyToGet);
			if (node != nullptr) {
				cout << "Найден элемент: " << node->value << endl;
			}
			else {
				cout << "Элемент с ключом '" << keyToGet << "' не найден " << endl;
			}
		}
		else if (choice == 5) {
			cout << "Число коллизий " << Collision_Counter << endl;
		}
		else if (choice == 6) {

			cout << "Запись данных в файл ..." << endl;
			writing_to_a_file(myTable, output);
			cout << "Завершено" << endl;

		}
		else if (choice == 7) {
			cout << "Очищение памяти ..." << endl;
			clean_all_table(myTable);
			cout << "Завершено" << endl;
		}
		else if (choice == 8) {
			ifstream input("hash table.txt");
			cout << "Выгрузка из файла ..." << endl;
			cin.ignore();
			recovery(myTable, input);
			cout << "Завершено" << endl;
			input.close();
		}

	} while (choice != 0);

	output.close();//закрываю файл

	return 0;
}

double fractional_part(double k) { //дробная часть от числа
	int intPart = static_cast<int>(k);
	return k - intPart;
}

int get_Hash(double k) {
	return static_cast<int>(M * fractional_part(k * A));
}

int get_Hash(string line) {
	int n = 0;
	for (int i = 0; i < line.size(); i++) {
		n += static_cast<int>(pow(line[i], 2) * M_2_SQRTPI + abs(line[i]) * M_SQRT1_2);
	}
	return get_Hash(abs(n));
}

bool add(Hash_Table& table, string key, string elem) { //добавление элемента
	Node* newNode = new Node;//новый узел
	newNode->key = key;//присвоение значений узлу
	newNode->value = elem;
	int hash = get_Hash(key);
	int counter = 0;
	if (table.table[hash] == nullptr) {
		table.table[hash] = newNode;
		return true;
	}
	counter++;
	while (table.table[(hash + counter) % M] != nullptr && ((hash + counter) % M) != hash) {
		counter++;
		Collision_Counter++;
	}
	if (table.table[(hash + counter) % M] == nullptr) {
		table.table[(hash + counter) % M] = newNode;
		return true;
	}
	else {//нет места
		return false;
	}
}

bool remove_By_Key(Hash_Table& table, string key) {//удаление элемента по КЛЮЧУ
	int hash = get_Hash(key);
	int memory_hash = hash;
	if (table.table[hash] != nullptr) {
		if (table.table[hash]->key == key) {
			table.table[hash] = nullptr;
			return true;
		}
		hash++;
	}
	else {
		hash++;
	}
	while ((hash % M) != memory_hash) {
		if (table.table[hash % M] != nullptr) {
			if (table.table[hash % M]->key == key) {
				table.table[hash % M] = nullptr;
				return true;
			}
			else {
				hash++;
			}
		}
		else {
			hash++;
		}
	}
	return false;

}

bool remove_By_Value(Hash_Table& table, string elem) {//удаление элемента по ЗНАЧЕНИЮ
	int hash = get_Hash(elem);
	int memory_hash = hash;
	if (table.table[hash] != nullptr) {
		if (table.table[hash]->value == elem) {
			table.table[hash] = nullptr;
			return true;
		}
		hash++;
	}
	else {
		hash++;
	}
	while ((hash % M) != memory_hash) {
		if (table.table[hash % M] != nullptr) {
			if (table.table[hash % M]->value == elem) {
				table.table[hash % M] = nullptr;
				return true;
			}
			else {
				hash++;
			}
		}
		else {
			hash++;
		}
	}
	return false;
}

Node* get(Hash_Table& table, string key) { //ищу элемент
	int hash = get_Hash(key);
	int memory_hash = hash;
	if (table.table[hash] != nullptr) {
		if (table.table[hash]->key == key) {
			return table.table[hash];
		}
		hash++;
	}
	else {
		hash++;
	}
	while ((hash % M) != memory_hash) {
		if (table.table[hash % M] != nullptr) {
			if (table.table[hash % M]->key == key) {
				return table.table[hash % M];
			}
			else {
				hash++;
			}
		}
		else {
			hash++;
		}
	}
	return nullptr;
}

void print(Hash_Table& table) { //вывод всех элементов хеш таблицы
	cout << endl << "Хеш таблица:" << endl;
	bool flag = true;
	for (int i = 0; i < M; i++) {
		if (table.table[i] != nullptr) {
			flag = false;
			cout << "[" << table.table[i]->key << ": " << table.table[i]->value << "] " << endl;
		}
	}
	if (flag) {
		cout << "[   Хеш таблица пуста   ]" << endl;
	}
}

string generator_Full_Name() {
	return surname[rand() % 30] + ' ' + name[rand() % 30] + ' ' + patronymic[rand() % 30];
}

string correct_Str(int n, int lenght) {//дополнение незначащими нулями
	string strn = to_string(n);
	while (strn.size() < lenght) {
		strn = '0' + strn;
	}
	while (strn.size() > lenght) {
		strn.erase(0, 1);
	}
	return strn;
}
string generate_Birthday() {
	return correct_Str(rand() % 28 + 1, 2) + '.' + correct_Str(rand() % 12 + 1, 2) + '.' + to_string(rand() % 74 + 1950);
}

string generate_Passport_Num() {
	return correct_Str(rand() % 10000, 4) + ' ' + correct_Str(rand() % 1000000 * 100 + rand(), 6);
}

void create_Human(Hash_Table& table) {
	string birthday = generate_Birthday();
	string newHuman = generator_Full_Name() + " | " + birthday + " | " + generate_Passport_Num();
	add(table, birthday, newHuman);
}

string enter_el(string value_1, string value_2) {
	string str;
	cout << "Введите " << value_1 << " для " << value_2 << endl;
	cin >> str;
	return str;
}

int choice_action() {
	int choice_2;
	do {
		cout << "Как выбрать элемент?" << endl;
		cout << "1 - выбрать случайно" << endl;
		cout << "2 - ввести с клавиатуры" << endl;
		cin >> choice_2;
	} while (choice_2 < 1 || choice_2 > 2);
	return choice_2;
}

int random_element(Hash_Table& table) {//выбор случайного элемента
	int existring_Ind = rand() % M;
	while (table.table[existring_Ind] == nullptr) {//пока не найду существующий элемент
		existring_Ind = rand() % M;
	}
	return existring_Ind;
}

void writing_to_a_file(Hash_Table& table, ofstream& file) { //запись данных в файл
	for (int i = 0; i < M; i++) {//прохожу все ячейки
		if (table.table[i] != nullptr) {
			file << table.table[i]->key << endl;//запись ключа
			file << table.table[i]->value << endl;//запись данных
		}
	}
}

void clean_all_table(Hash_Table& table) {//очищение таблицы
	for (int i = 0; i < M; i++) {
		Node* current = table.table[i];
		if (current != nullptr) {//пока не пройду все элементы
			//Node* temp = current;//перевязываю узла

			delete current;
		}
		table.table[i] = nullptr;
	}
}

void recovery(Hash_Table& table, ifstream& file) {//восстановление из файла
	string key, value;
	getline(file, key); //считываю ключ
	if (key != "") {//если файл не пустой
		getline(file, value);//считываю данные
		add(table, key, value);
		while (getline(file, key)) { //пока не пройду весь файл
			getline(file, value);//считываю данные
			add(table, key, value);
		} 
	}
}