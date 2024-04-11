#include <iostream>
#include <fstream>
#include "Pair.h"
#include "file_work.h"

using namespace std;

int main() {
	system("chcp 1251 > Null");
	srand(time(0));
	int N;
	do
	{
		cout << "Введите кол-в0 элементов: ";
		cin >> N;
	} while (N < 1);

	cout << endl;

	error_mes(write_to_a_file(N));

	bool flag = true;
	while (flag) {
		int current_action = choosing_an_action();
		int tmp_1;
		double tmp_2;

		Pair p_2;
		switch (current_action){
		case 1://содержимое файла
			cout << "Текущее содержимое файла" << endl;
			error_mes(print_file());
			cout << endl;
			break;
		case 2:
			do {
				cout << "Введите кол-в0 элементов: ";
				cin >> tmp_1;
			} while (tmp_1 < 1);
			error_mes(write_to_a_file(tmp_1));
			break;
		case 3:
			cout << "Введите значение, меньше которого, будут удалены все записи " << endl;
			cin >> p_2;
			error_mes(removing_el_smaller_than(p_2));
			break;
		case 4:
			do{
				cout << "Какое число вы хотите ввести?" << endl;
				cout << "1 - целое" << endl << "2 - вещественное" << endl;
				cin >> N;
			} while (N < 1 || N>2);
			switch (N){
			case 1:
				cout << "Введите ЦЕЛОЕ число: ";
				cin >> tmp_1;
				error_mes(add_L(tmp_1));
				break;
			default:
				cout << "Введите ВЕЩЕСТВЕННОЕ число: ";
				cin >> tmp_2;
				error_mes(add_L(tmp_2));
				break;
			}
			break;
		case 5:
			do {
				cout << "Введите НОМЕР, после которого необходимо ввести k элементов" << endl;
				cin >> N;
			} while (N < 1);

			do {
				cout << "Введите количество элементов, которые необходимо добавить" << endl;
				cin >> tmp_1;
			} while (tmp_1 < 1);
			error_mes(add_k_el_after(N, tmp_1));
			break;
		default:
			flag = false;
			break;
		}
	}
	return 0;
}