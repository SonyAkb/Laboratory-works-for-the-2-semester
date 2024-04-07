#pragma once //предотвращает повторную загрузку заголовочного файла, если он уже был включен
#include <iostream> //стандартные потоки ввода и вывода
#include <string>

using namespace std;

class Object {
public:
	Object() {}; //конструктор
	virtual ~Object() {};//деструктор
	virtual void Show(bool only_name = false) = 0;
	virtual void Input() = 0;
	virtual string get_name() = 0;
};