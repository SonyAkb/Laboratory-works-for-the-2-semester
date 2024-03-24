#include<iostream>
#include<string>
#include<ctime>
#define _USE_MATH_DEFINES//��� ������������ ��������
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

double fractional_part(double k); //������� ����� �� �����
int get_Hash(double k);
int get_Hash(string line);
bool add(Hash_Table& table, string key, string elem); //���������� ��������
bool remove_By_Key(Hash_Table& table, string key);//�������� �������� �� �����
bool remove_By_Value(Hash_Table& table, string elem);//�������� �������� �� ��������
Node* get(Hash_Table& table, string key); //��� �������
void print(Hash_Table& table); //����� ���� ��������� ��� �������

string generator_Full_Name(); //����������
string correct_Str(int n, int lenght);
string generate_Birthday();
string generate_Passport_Num();

void create_Human(Hash_Table& table);
string enter_el(string value_1, string value_2);
int choice_action();
int random_element(Hash_Table& table);
void writing_to_a_file(Hash_Table& table, ofstream& file);//������ � ����
void clean_all_table(Hash_Table& table);//�������� �������
void recovery(Hash_Table& table, ifstream& file);//������������� �� �����

string surname[30] = { "������", "���������", "������","������","������","�������","������",
	"��������","��������","�����","��������","��������","�����","����","���������","��������",
	"�����","�������","�������","�������","�������","�����","�������","��������","��������","���������",
	"�������","������","����������","�������" };
string name[30] = { "����", "������", "�����", "����", "������", "�������", "�����", "���������",
	"�������", "������", "������", "�����", "������", "������", "����", "��������", "�����", "�����",
	"�������", "���������", "�������", "�����", "������", "����������", "�������", "������", "����������",
	"������", "���������", "������" };
string patronymic[30] = { "��������", "���������", "���������", "��������", "����������", "����������",
	"���������", "�������������", "����������", "���������","���������", "���������", "����������", "���������",
	"�����", "�����������", "���������", "���������", "����������", "�������������", "����������", "���������",
	"����������", "��������������", "����������", "����������", "�������������",
	"����������", "�������������", "����������" };



int main() {
	system("chcp 1251 > Null");
	srand(time(0));

	Hash_Table myTable;//�������
	int mas_size, choice;
	ofstream output("hash table.txt"); //�������� �������� �����

	do {
		cout << "������� ���������� ��������� ";
		cin >> mas_size; //���������� ��������� � ������
	} while (mas_size < 1 || mas_size > M);

	for (int i = 0; i < mas_size; i++) { //�������� ��� �������
		create_Human(myTable);
	}

	cout << "���-������� �������! " << endl;
	print(myTable);

	do {
		do {
			cout << endl << "------------------------------------------" << endl;
			cout << "��� �� ������ �������? " << endl;
			cout << "0 - �����(" << endl;//////
			cout << "1 - �������� �������" << endl;////
			cout << "2 - ������� �������" << endl;/////
			cout << "3 - ������� ��� �������" << endl;//////
			cout << "4 - ����� �������" << endl;/////
			cout << "5 - ������ ����� ��������" << endl;/////////
			cout << "6 - ��������� ��� ������� � ����" << endl;
			cout << "7 - �������� ��� �������" << endl;
			cout << "8 - ��������� ������ �� �����" << endl;
			cin >> choice;
		} while (choice < 0 || choice > 8);
		cout << endl;

		if (choice == 1) {//�������� �������
			bool flag;
			int choice_2 = choice_action();
			if (choice_2 == 1) {
				string birthday = generate_Birthday();
				string newHuman = generator_Full_Name() + " | " + birthday + " | " + generate_Passport_Num();
				flag = add(myTable, birthday, newHuman);
			}
			else {
				string birthday, fio, passport;
				cout << "������� ���� �������� � ������� ��.MM.����:   ";
				cin >> birthday;
				cout << "������� ���:   ";
				cin.ignore();
				getline(cin, fio);
				cout << "������� ����� � ����� ���������:   ";
				cin.ignore();
				getline(cin, passport);
				flag = add(myTable, birthday, fio + " | " + birthday + " | " + passport);
			}

			if (flag) {
				cout << "������� ������� ��������!" << endl;
			}
			else {
				cout << "��� ������� �����������(" << endl;
				cout << "� ������ ������ ������ �������� ����� �������" << endl;
			}
		}
		else if (choice == 2) {//������� �������
			int choice_1, choice_2;
			do {
				cout << "������� �� ����� ��� �� ��������?" << endl;
				cout << "1 - �� �����" << endl;
				cout << "2 - �� ��������" << endl;
				cin >> choice_1;
			} while (choice_1 < 1 || choice_1 > 2);

			choice_2 = choice_action();

			if (choice_2 == 1) { //������� ��������
				int existring_Ind = random_element(myTable);

				Node* randomHuman = myTable.table[existring_Ind];
				if (choice_1 == 1) {//������� �� �����
					string keyToRemove = randomHuman->key;

					cout << "�������� �� �����: '" << keyToRemove << "':" << endl;
					if (remove_By_Key(myTable, keyToRemove)) {
						cout << "������� � ������: '" << keyToRemove << "' ������� ������" << endl;
					}
					else {
						cout << "������� � ������: '" << keyToRemove << "' �� ������" << endl;
					}
				}
				else {
					string valueToRemove = randomHuman->value;

					cout << "�������� �� �������� '" << valueToRemove << "': " << endl;
					if (remove_By_Value(myTable, valueToRemove)) {
						cout << "������� �� ��������� '" << valueToRemove << "' ������� ������ " << endl;
					}
					else {
						cout << "������� �� ��������� '" << valueToRemove << "' �� ������ " << endl;
					}
				}
			}
			else {//������ � ����������
				if (choice_1 == 1) {//�� �����
					string key_To_Remove;
					cout << endl << "������� ���� ��� �������� " << endl;
					cin >> key_To_Remove;

					cout << "�������� �� �����: '" << key_To_Remove << "':" << endl;
					if (remove_By_Key(myTable, key_To_Remove)) {
						cout << "������� � ������: '" << key_To_Remove << "' ������� ������" << endl;
					}
					else {
						cout << "������� � ������: '" << key_To_Remove << "' �� ������" << endl;
					}
				}
				else {//�� ��������
					string value_To_Remove;
					cout << "������� �������� ��� �������� " << endl;
					cin.ignore();
					getline(cin, value_To_Remove);

					cout << "�������� �� �������� '" << value_To_Remove << "': " << endl;
					if (remove_By_Value(myTable, value_To_Remove)) {
						cout << "������� �� ��������� '" << value_To_Remove << "' ������� ������ " << endl;
					}
					else {
						cout << "������� �� ��������� '" << value_To_Remove << "' �� ������ " << endl;
					}
				}
			}
		}
		else if (choice == 3) { //����� �������
			print(myTable);
		}
		else if (choice == 4) {//����� �������
			int choice = choice_action();
			string keyToGet;
			if (choice == 1) {
				int existring_Ind = random_element(myTable);
				Node* randomHuman = myTable.table[existring_Ind];
				keyToGet = randomHuman->key;
			}
			else {
				cout << "������� ���� ��� �������� " << endl;
				cin >> keyToGet;
			}
			cout << "��������� �������� �� ����� '" << keyToGet << "': " << endl;
			Node* node = get(myTable, keyToGet);
			if (node != nullptr) {
				cout << "������ �������: " << node->value << endl;
			}
			else {
				cout << "������� � ������ '" << keyToGet << "' �� ������ " << endl;
			}
		}
		else if (choice == 5) {
			cout << "����� �������� " << Collision_Counter << endl;
		}
		else if (choice == 6) {

			cout << "������ ������ � ���� ..." << endl;
			writing_to_a_file(myTable, output);
			cout << "���������" << endl;

		}
		else if (choice == 7) {
			cout << "�������� ������ ..." << endl;
			clean_all_table(myTable);
			cout << "���������" << endl;
		}
		else if (choice == 8) {
			ifstream input("hash table.txt");
			cout << "�������� �� ����� ..." << endl;
			cin.ignore();
			recovery(myTable, input);
			cout << "���������" << endl;
			input.close();
		}

	} while (choice != 0);

	output.close();//�������� ����

	return 0;
}

double fractional_part(double k) { //������� ����� �� �����
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

bool add(Hash_Table& table, string key, string elem) { //���������� ��������
	Node* newNode = new Node;//����� ����
	newNode->key = key;//���������� �������� ����
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
	else {//��� �����
		return false;
	}
}

bool remove_By_Key(Hash_Table& table, string key) {//�������� �������� �� �����
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

bool remove_By_Value(Hash_Table& table, string elem) {//�������� �������� �� ��������
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

Node* get(Hash_Table& table, string key) { //��� �������
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

void print(Hash_Table& table) { //����� ���� ��������� ��� �������
	cout << endl << "��� �������:" << endl;
	bool flag = true;
	for (int i = 0; i < M; i++) {
		if (table.table[i] != nullptr) {
			flag = false;
			cout << "[" << table.table[i]->key << ": " << table.table[i]->value << "] " << endl;
		}
	}
	if (flag) {
		cout << "[   ��� ������� �����   ]" << endl;
	}
}

string generator_Full_Name() {
	return surname[rand() % 30] + ' ' + name[rand() % 30] + ' ' + patronymic[rand() % 30];
}

string correct_Str(int n, int lenght) {//���������� ����������� ������
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
	cout << "������� " << value_1 << " ��� " << value_2 << endl;
	cin >> str;
	return str;
}

int choice_action() {
	int choice_2;
	do {
		cout << "��� ������� �������?" << endl;
		cout << "1 - ������� ��������" << endl;
		cout << "2 - ������ � ����������" << endl;
		cin >> choice_2;
	} while (choice_2 < 1 || choice_2 > 2);
	return choice_2;
}

int random_element(Hash_Table& table) {//����� ���������� ��������
	int existring_Ind = rand() % M;
	while (table.table[existring_Ind] == nullptr) {//���� �� ����� ������������ �������
		existring_Ind = rand() % M;
	}
	return existring_Ind;
}

void writing_to_a_file(Hash_Table& table, ofstream& file) { //������ ������ � ����
	for (int i = 0; i < M; i++) {//������� ��� ������
		if (table.table[i] != nullptr) {
			file << table.table[i]->key << endl;//������ �����
			file << table.table[i]->value << endl;//������ ������
		}
	}
}

void clean_all_table(Hash_Table& table) {//�������� �������
	for (int i = 0; i < M; i++) {
		Node* current = table.table[i];
		if (current != nullptr) {//���� �� ������ ��� ��������
			//Node* temp = current;//����������� ����

			delete current;
		}
		table.table[i] = nullptr;
	}
}

void recovery(Hash_Table& table, ifstream& file) {//�������������� �� �����
	string key, value;
	getline(file, key); //�������� ����
	if (key != "") {//���� ���� �� ������
		getline(file, value);//�������� ������
		add(table, key, value);
		while (getline(file, key)) { //���� �� ������ ���� ����
			getline(file, value);//�������� ������
			add(table, key, value);
		} 
	}
}