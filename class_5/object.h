#pragma once //предотвращает повторную загрузку заголовочного файла, если он уже был включен
#include <iostream> //стандартные потоки ввода и вывода
#include <string>

using namespace std;

class Object {
public:
	Object() {};
	virtual ~Object() {};
	virtual void Out_put() = 0;
};