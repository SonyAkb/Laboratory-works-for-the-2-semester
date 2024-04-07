#pragma once //предотвращает повторную загрузку заголовочного файла, если он уже был включен
#include <iostream> //стандартные потоки ввода и вывода
#include <string>
#include "Object.h"
using namespace std;

class Print : public Object {
protected:
	string Author;
	string Name;
public:
	Print() {};//конструктор без параметров
	Print(string author, string name);//конструктор с параметрами
	virtual ~Print() {};//деструктор

	string get_author();//получение имени автора
	string get_name();//получение названия

	void set_author(string author);//установка автора
	void set_name(string name);//установка названия
	void Show(bool only_name = false) override;//вывод данных
	void Input() override;
	Print& operator=(Print& another);
};