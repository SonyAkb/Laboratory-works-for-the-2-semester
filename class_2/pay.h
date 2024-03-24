#pragma once //предотвращает повторную загрузку заголовочного файла, если он уже был включен
#include <iostream> //стандартные потоки ввода и вывода
using namespace std;

class Pay { //объявление класса Pay
	string name;//фио
	double salary;//з/п
	int bonus;//премия
public:
	Pay(); //конструктор класса Pay по умолчанию
	Pay(string, double, int); //конструктор класса Pay с параметрами
	Pay(const Pay&);//конструктор копирования класса Pay 
	~Pay();//деструктор класса Pay

	string get_Name();//извлечение фио
	void set_Name(string);//присвоение фио
	double get_Salary();//извлечение з/п
	void set_Salary(double);//присвоение з/п
	int get_Bonus();//извлечение премии
	void set_Bonus(int);//присвоение премии
	void Print(); //вывод параметров класса
};