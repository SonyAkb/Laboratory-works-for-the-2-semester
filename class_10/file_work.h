#pragma once
using namespace std;

void randomize(Pair& p) {
	int x = rand() % 1001;
	double y = (rand() % 100001) * 0.01;
	p = Pair(x, y);
}

bool write_to_a_file(int N) {
	fstream F1("Class_10.txt", ios::out | ios::trunc); //открываю файл для записи
	//out - перезаписывание
	//trunk - удалить старое содержимое файла (по умолчанию для оfstream) 
	if (!F1) {//если файл не открылся
		cout << "Ошибка открытия файла" << endl;
		return 0;
	}

	for (int i = 0; i < N; i++) {//записываю N пар
		Pair p_1;
		randomize(p_1);
		F1 << p_1 << endl;
	}
	F1.close();//закрываю файл
	return 1;
}

bool print_file() {
	fstream F1("Class_10.txt", ios::in);//открываю файл для чтения
	//in чтение

	if (!F1) {
		cout << "Ошибка открытия файла" << endl;
		return 0;
	}

	Pair p_1;

	while (F1 >> p_1) {//пока не считаю весь файл
		cout << p_1 << endl;
	}
	return 1;
}
void error_mes(bool N) {
	if (!N) {
		cout << "Файл не найден" << endl;
	}
}

bool removing_el_smaller_than(Pair& para) {
	fstream F1("Class_10.txt", ios::in);
	//in чтение
	if (!F1) {
		cout << "Ошибка открытия файла" << endl;
		return 0;
	}

	fstream tmp("temporary_file.txt", ios::out | ios::trunc); //создаю временный файл
	//out - перезаписывание
	//trunk - удалить старое содержимое файла (по умолчанию для оfstream) 

	Pair p_3;

	while (F1 >> p_3) {//пока не пройду весь файл
		if (p_3 > para) { //если меньше элемента
			tmp << p_3 << endl;//записываю в tmp
		}
	}

	F1.close();//закрываю файл
	tmp.close();//закрываю файл

	remove("Class_10.txt");//удаляю основной файл
	rename("temporary_file.txt", "Class_10.txt");//переназначаю основной файл
	return 1;
}

template<typename T>
bool add_L(T L) {
	fstream F1("Class_10.txt", ios::in);
	//in чтение

	if (!F1) {
		cout << "Ошибка открытия файла" << endl;
		return 0;
	}

	fstream tmp("temporary_file.txt", ios::out | ios::trunc); //создаю временный файл
	//out - перезаписывание
	//trunk - удалить старое содержимое файла (по умолчанию для оfstream) 

	Pair p_4;

	while (F1 >> p_4) {
		p_4 = p_4 + L;
		tmp << p_4 << endl;
	}

	F1.close();//закрываю файл
	tmp.close();//закрываю файл

	remove("Class_10.txt");//удаляю основной файл
	rename("temporary_file.txt", "Class_10.txt");//переназначаю основной файл
	return 1;
}

bool add_k_el_after(int number, int quantity) {
	fstream F1("Class_10.txt", ios::in);
	//in чтение

	if (!F1) {
		cout << "Ошибка открытия файла" << endl;
		return 0;
	}

	fstream tmp("temporary_file.txt", ios::out | ios::trunc); //создаю временный файл
	//out - перезаписывание
	//trunk - удалить старое содержимое файла (по умолчанию для оfstream) 

	Pair p_4;

	int counter = 0;

	while (F1 >> p_4) {
		counter++;
		tmp << p_4 << endl;

		if (counter == number) {//когда достигаю заданного номера
			for (int i = 0; i < quantity; i++) {
				Pair new_pair;
				randomize(new_pair);
				tmp << new_pair << endl;
			}
		}
	}

	if (counter < number)
		cout << "Достигнут конец файла! Элемент с номером " << number << "не найден" << endl;

	F1.close();//закрываю файл
	tmp.close();//закрываю файл

	remove("Class_10.txt");//удаляю основной файл
	rename("temporary_file.txt", "Class_10.txt");//переназначаю основной файл
	return 1;
}

int choosing_an_action() {
	cout << "--------------------------------------------------------" << endl;
	cout << "Выберите действие" << endl;
	cout << "1 - Вывести содержимое файла" << endl;//+
	cout << "2 - Перезаписать содержимое файла" << endl;//+
	cout << "3 - Удалить все записи меньшие заданного значения" << endl;//+
	cout << "4 - Увеличить все записи с заданным значением на число L" << endl;
	cout << "5 - Добавить K записей после элемента с заданным номером" << endl;
	cout << "0 - Конец работы" << endl;//+
	int choice;
	do {
		cout << ">  ";
		cin >> choice;
	} while (choice < 0 || choice > 6);
	cout << endl;
	return choice;
}