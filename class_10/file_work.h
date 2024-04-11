#pragma once
using namespace std;

void randomize(Pair& p) {
	int x = rand() % 1001;
	double y = (rand() % 100001) * 0.01;
	p = Pair(x, y);
}

bool write_to_a_file(int N) {
	fstream F1("Class_10.txt", ios::out | ios::trunc); //�������� ���� ��� ������
	//out - ���������������
	//trunk - ������� ������ ���������� ����� (�� ��������� ��� �fstream) 
	if (!F1) {//���� ���� �� ��������
		cout << "������ �������� �����" << endl;
		return 0;
	}

	for (int i = 0; i < N; i++) {//��������� N ���
		Pair p_1;
		randomize(p_1);
		F1 << p_1 << endl;
	}
	F1.close();//�������� ����
	return 1;
}

bool print_file() {
	fstream F1("Class_10.txt", ios::in);//�������� ���� ��� ������
	//in ������

	if (!F1) {
		cout << "������ �������� �����" << endl;
		return 0;
	}

	Pair p_1;

	while (F1 >> p_1) {//���� �� ������ ���� ����
		cout << p_1 << endl;
	}
	return 1;
}
void error_mes(bool N) {
	if (!N) {
		cout << "���� �� ������" << endl;
	}
}

bool removing_el_smaller_than(Pair& para) {
	fstream F1("Class_10.txt", ios::in);
	//in ������
	if (!F1) {
		cout << "������ �������� �����" << endl;
		return 0;
	}

	fstream tmp("temporary_file.txt", ios::out | ios::trunc); //������ ��������� ����
	//out - ���������������
	//trunk - ������� ������ ���������� ����� (�� ��������� ��� �fstream) 

	Pair p_3;

	while (F1 >> p_3) {//���� �� ������ ���� ����
		if (p_3 > para) { //���� ������ ��������
			tmp << p_3 << endl;//��������� � tmp
		}
	}

	F1.close();//�������� ����
	tmp.close();//�������� ����

	remove("Class_10.txt");//������ �������� ����
	rename("temporary_file.txt", "Class_10.txt");//������������ �������� ����
	return 1;
}

template<typename T>
bool add_L(T L) {
	fstream F1("Class_10.txt", ios::in);
	//in ������

	if (!F1) {
		cout << "������ �������� �����" << endl;
		return 0;
	}

	fstream tmp("temporary_file.txt", ios::out | ios::trunc); //������ ��������� ����
	//out - ���������������
	//trunk - ������� ������ ���������� ����� (�� ��������� ��� �fstream) 

	Pair p_4;

	while (F1 >> p_4) {
		p_4 = p_4 + L;
		tmp << p_4 << endl;
	}

	F1.close();//�������� ����
	tmp.close();//�������� ����

	remove("Class_10.txt");//������ �������� ����
	rename("temporary_file.txt", "Class_10.txt");//������������ �������� ����
	return 1;
}

bool add_k_el_after(int number, int quantity) {
	fstream F1("Class_10.txt", ios::in);
	//in ������

	if (!F1) {
		cout << "������ �������� �����" << endl;
		return 0;
	}

	fstream tmp("temporary_file.txt", ios::out | ios::trunc); //������ ��������� ����
	//out - ���������������
	//trunk - ������� ������ ���������� ����� (�� ��������� ��� �fstream) 

	Pair p_4;

	int counter = 0;

	while (F1 >> p_4) {
		counter++;
		tmp << p_4 << endl;

		if (counter == number) {//����� �������� ��������� ������
			for (int i = 0; i < quantity; i++) {
				Pair new_pair;
				randomize(new_pair);
				tmp << new_pair << endl;
			}
		}
	}

	if (counter < number)
		cout << "��������� ����� �����! ������� � ������� " << number << "�� ������" << endl;

	F1.close();//�������� ����
	tmp.close();//�������� ����

	remove("Class_10.txt");//������ �������� ����
	rename("temporary_file.txt", "Class_10.txt");//������������ �������� ����
	return 1;
}

int choosing_an_action() {
	cout << "--------------------------------------------------------" << endl;
	cout << "�������� ��������" << endl;
	cout << "1 - ������� ���������� �����" << endl;//+
	cout << "2 - ������������ ���������� �����" << endl;//+
	cout << "3 - ������� ��� ������ ������� ��������� ��������" << endl;//+
	cout << "4 - ��������� ��� ������ � �������� ��������� �� ����� L" << endl;
	cout << "5 - �������� K ������� ����� �������� � �������� �������" << endl;
	cout << "0 - ����� ������" << endl;//+
	int choice;
	do {
		cout << ">  ";
		cin >> choice;
	} while (choice < 0 || choice > 6);
	cout << endl;
	return choice;
}