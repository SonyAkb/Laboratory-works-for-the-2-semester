#include "progression.h" //объявления классов

int main() {
	system("chcp 1251 > Null"); //кодировка
	double first;
	int second, j_elem;
	cout << "Последовательность aj = a0 * r^j" << endl << endl;

	cout << "Введите дробное число - a(0):   ";
	cin >> first;

	do {
		cout << "Введите целое положительное число - r:   ";
		cin >> second;
	} while (second < 0);

	do {
		cout << "Введите номер элемента геометрической прогрессии  - j:   ";
		cin >> j_elem;
	} while (j_elem < 1);
	cout << endl;

	Progression prog(2, 2); //объект класса Progression с параметрами 1 и 1.
	prog.setFirst(first); //устанавливает значение private поля first объекта prog на 3
	prog.setSecond(second); //устанавливает значение private поля second объекта prog на 2
	cout << "Значение функции = " << prog.element(j_elem) << endl;
	return 0; //завершение программы
}