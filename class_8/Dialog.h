#pragma once //предотвращает повторную загрузку заголовочного файла, если он уже был включен
#include <iostream> //стандартные потоки ввода и вывода
#include <string>
#include "VECTOR.h"
#include "TEvent.h"
#include "Magazin.h"
using namespace std;

class Dialog : public VECTOR {
private:
	bool end_of_work = false;//надо ли закончить работу
public:
	Dialog();//конструктор без параметров
	~Dialog() {};//деструктор
	void Execute();
	void Get_Event(TEvent& event);//ставлю событие
	void Handle_Event(TEvent& Event);//выбираю событие
	void ClearEvent(TEvent& event); //очищаю текущую команду
	void choosing_an_action();
protected:
	bool End_State;
};