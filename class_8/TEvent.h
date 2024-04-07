#pragma once //предотвращает повторную загрузку заголовочного файла, если он уже был включен

using namespace std;

const int CM_create_a_group = 1; //m создать группу
const int CM_Add_to_a_group = 2; //+ добавить в группу элемента
const int CM_Remove_from_the_group = 3; //- удалить элемент из группы
const int CM_Print = 4; //s	Вывести информацию об элементах груп
const int CM_inform_all_el_of_the_group = 5; //z Вывести информацию о названиях всех элементов группы 
const int CM_Quit = 6; //q Конец работы 

const int EV_Nothing = 0; //левый символ
const int EV_Message = 100; //


class TEvent {
public:
	int what; //тип события
	int Command;
};