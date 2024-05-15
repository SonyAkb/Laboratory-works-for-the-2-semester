#pragma once
#include "other functions.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <queue>
#include <iomanip>
#include <set>

template <class T>
class Graph {
private:
	std::map<T, sf::Vector2f> Positions_vert;
	std::vector<sf::Vector2f> coord_of_the_vert;//координаты вершин
	std::vector<T> vertex_list; //вектор вершин
	std::vector<std::vector<int>> adjMatrix;//матрица смежности
public:
	Graph(const int& size = 0);//конструктор с размером графа
	~Graph() {};//деструктор
	bool is_empty();//граф пуст?
	void insert_vertex(const T& vert, sf::Vector2f coords);//вставка вершины
	void erase_vertex(const T& vert);//удаление вершины

	void change_the_vertex_position(T vertex_0, sf::Vector2f new_coords);//изменение позиции вершины
	void rename_a_vertex(int index, T new_name);//периименование вершины

	T get_vert_T(const int& index);
	bool is_it_possible_to_solve_the_traveling_salesman_problem();//проверяю можно ли запустить коммивояжера

	int get_vert_pos(const T& data);//ИНДЕКС вершины с переданными данными
	int get_amount_verts();//количество существующих вершин
	int get_weight(const T& vert_1, const T& vert_2);//вес пути между вершинами
	std::vector<T> get_neighbors(const T& data);//вектор соседей элемента с переданными данными
	void insert_edge_orient(const T& vert_1, const T& vert_2, int weight = 1); //вставка ребра между двумя узлами - ОРИЕНТИРОВАННЫЙ граф
	void erase_edge_orient(const T& vert_1, const T& vert_2);//удаление ребра между двумя узлами
	int get_amount_edge_orient();//количество ребер - ОРИЕНТИРОВАННЫЙ граф

	void clear_the_graph();//очищаю граф
	int this_is_node(sf::Vector2f cur_coord);//это корды вершины?

	void Draw(sf::RenderWindow& window);//отрисовываю граф полностью
	void Draw_node(sf::RenderWindow& window, std::map < T, sf::Vector2f>& positions, T vertex);//отрисовываю вершину
	void Draw_edge(sf::RenderWindow& window, std::map < T, sf::Vector2f>& positions, T vertex_1, T vertex_2);//отрисовываю ребро
	void Draw_distance(sf::RenderWindow& window, std::map < T, sf::Vector2f>& positions, T vertex_1, T vertex_2);//отрисовываю расстояние

	std::vector<T> the_traveling_salesman_task(T& vertex_start);//решение задачи коммивояжера
	std::vector<T> DFS(T& start_verts, std::vector<bool>& visited_verts, std::vector<T>& vect);//обход графа в ГЛУБИНУ
	int path_length(std::vector<T> vect_1); //длина пути
};

template <class T>
int Graph<T>::path_length(std::vector<T> vect_1) {//общая длина маршрута
	int the_sum_of_the_lengths = 0;
	for (int i = 0; i < this->get_amount_verts(); i++) {
		the_sum_of_the_lengths += this->adjMatrix[get_vert_pos(vect_1[i])][get_vert_pos(vect_1[i + 1])];
	}
	return the_sum_of_the_lengths;
}

template <class T>
std::vector<T> Graph<T>::the_traveling_salesman_task(T& vertex_start) {//решение задачи коммивояжера
	int memory_i_1, memory_j_1, memory_i_2 = -1, memory_j_2 = -1, num_of_positive_paths;
	int min_path, min_i_path, min_j_path, max_zero;
	bool flag_status = false;//найден ли нормальный путь
	int quantity_of_nodes = this->get_amount_verts();
	std::vector<std::vector<int>> matrix_of_conditions = copyNestedVector(this->adjMatrix);
	std::vector<T> vect_of_paths;
	for (int i = 0; i < quantity_of_nodes; i++) {//заполняю матрицу смежности
		for (int j = 0; j < quantity_of_nodes; j++) {
			if (matrix_of_conditions[i][j] == 0) {//если нет пути
				matrix_of_conditions[i][j] = -1;//заполняю, т.к. нет пути из текущего города 1 в текущий город 2
			}
		}
	}
	for (int v = 0; v < quantity_of_nodes; v++) {//прохожу по всем городам
		// необходим один элемент в столбце или строке, который будет единственным возможным путем
		flag_status = false;//найден искомый элемент?
		for (int i = 0; (i < quantity_of_nodes) && (flag_status == false); i++) {//пока не пройду все элементы или не найден необходимый элемент
			num_of_positive_paths = 0;//количество положительных путей
			for (int j = 0; j < quantity_of_nodes && num_of_positive_paths < 2; j++) {//прохожу по столбцам
				if (matrix_of_conditions[i][j] >= 0) {//если есть неотмеченный путь между этими узлами
					memory_i_1 = i;//запоминаю строку
					memory_j_1 = j;//запоминаю столбец
					num_of_positive_paths++;//увеличиваю количество положительных путей
				}
			}
			if (num_of_positive_paths == 1) {//если есть только одно положительное значение в столбце
				flag_status = true;//найден только 1 путь
			}
		}
		for (int j = 0; (j < quantity_of_nodes) && (flag_status == false); j++) {//пока не пройду все элементы или не найден необходимый элемент
			num_of_positive_paths = 0;//количество положительных путей
			for (int i = 0; i < quantity_of_nodes && num_of_positive_paths < 2; i++) {//прохожу по строкам
				if (matrix_of_conditions[i][j] >= 0) {//если есть неотмеченный путь между этими узлами
					memory_i_1 = i;//запоминаю строку
					memory_j_1 = j;//запоминаю столбец
					num_of_positive_paths++;//увеличиваю количество положительных путей
				}
			}
			if (num_of_positive_paths == 1) {//если есть только одно положительное значение в строке
				flag_status = true;//найден только 1 путь
			}
		}
		if (flag_status == true) {//найден только один нормальный путь
			makebase(memory_i_1, memory_j_1, matrix_of_conditions, quantity_of_nodes);//пересобираю матрицу смежности с учетом найденного пути, помечаю элемент как базовый
		}
		else {//если не найден ни одного нормального пути
			for (int i = 0; i < quantity_of_nodes; i++) {//иду по строкам матрицы - редукция строк
				min_path = 100000;//недостижимый максимум
				for (int j = 0; j < quantity_of_nodes; j++) {//ищу минимум в строке
					if (matrix_of_conditions[i][j] >= 0 && matrix_of_conditions[i][j] < min_path) {//если меньше текущего минимума (нули не учитываю)
						min_path = matrix_of_conditions[i][j];//обновляю минимум
					}
				}
				for (int j = 0; j < quantity_of_nodes; j++) {//иду по строке
					if (matrix_of_conditions[i][j] >= 0) { //если положительное значение, т.е. существует неотмеченный путь
						matrix_of_conditions[i][j] -= min_path; //из каждого нормального значения в строке вычитаю найденный минимум
					}
				}
			}
			for (int j = 0; j < quantity_of_nodes; j++) {//иду по столбцам матрицы - редукция столбцов
				min_path = 100000;//недостижимый максимум
				for (int i = 0; i < quantity_of_nodes; i++) {//ищу минимум в столбце
					if (matrix_of_conditions[i][j] >= 0 && matrix_of_conditions[i][j] < min_path) {//если меньше текущего минимума (нули не учитываю)
						min_path = matrix_of_conditions[i][j];//обновляю минимум
					}
				}
				for (int i = 0; i < quantity_of_nodes; i++) {//иду по столбцу
					if (matrix_of_conditions[i][j] >= 0) {//если положительное значение, т.е. существует неотмеченный путь
						matrix_of_conditions[i][j] -= min_path;//из каждего нормального значения в столбце вычитаю найденный минимум
					}
				}
			}
			//проверка нулевых значений и поиск базовых значений
			max_zero = -1;//недостижимый минимум
			for (int i = 0; i < quantity_of_nodes; i++) {//иду по строкам матрицы
				for (int j = 0; j < quantity_of_nodes; j++) {//иду по столбцам матрицы
					if (matrix_of_conditions[i][j] == 0) {//если найден зануленый элемент
						min_i_path = 100000;//недостижимый максимум строки
						min_j_path = 100000;//недостижимый максимум столбца
						for (int i_2 = 0; i_2 < quantity_of_nodes; i_2++) {//оцениваю нули строк
							if (matrix_of_conditions[i_2][j] >= 0 && i_2 != i && matrix_of_conditions[i_2][j] < min_i_path) {//если есть путь, элемент не равен текущему, меньше текущего минимума
								min_i_path = matrix_of_conditions[i_2][j];//текущий минимум обновлен
							}
						}
						for (int j_2 = 0; j_2 < quantity_of_nodes; j_2++) {//оцениваю нули столбцов
							if (matrix_of_conditions[i][j_2] >= 0 && j_2 != j && matrix_of_conditions[i][j_2] < min_j_path) {//если есть путь, элемент не равен текущему, меньше текущего минимума
								min_j_path = matrix_of_conditions[i][j_2];//текущий минимум обновлен
							}
						}
						if (min_i_path + min_j_path > max_zero) {
							max_zero = min_i_path + min_j_path;//обновляю максимум - сумма индексов минимальных элементов в текущих строке и столбце
							memory_i_2 = i;//запоминаю строку
							memory_j_2 = j;//запоминаю столбец
						}
					}
				}
			}
			if (memory_i_2 == -1 || memory_j_2 == -1) {
				return vect_of_paths;
			}
			makebase(memory_i_2, memory_j_2, matrix_of_conditions, quantity_of_nodes);//пересобираю матрицу смежности с учетом найденного пути, помечаю элемент как базовый
		}
	}
	memory_i_1 = this->get_vert_pos(vertex_start);//вектор пути
	vect_of_paths.push_back(this->vertex_list[memory_i_1]);//добавляю первоначальный город
	for (int c = 0; c < quantity_of_nodes; c++) {//проход по всем городам
		bool flag_1 = true;
		for (int j = 0; j < quantity_of_nodes && flag_1; j++) {//поиск следующего города, который является базовым значением
			if (matrix_of_conditions[memory_i_1][j] == -2) {//является ли текущий город базовым значением
				vect_of_paths.push_back(this->vertex_list[j]);
				memory_i_1 = j; //обновление значения переменной
				flag_1 = false;//выход из цикла поиска следующего города.
			}
		}
	}
	return vect_of_paths;
}

template <class T>
int Graph<T>::this_is_node(sf::Vector2f cur_coord) {//это корды вершины?
	int x_cur = cur_coord.x;
	int y_cur = cur_coord.y;
	for (int i = 0; i < this->vertex_list.size(); i++) {
		if (this->coord_of_the_vert[i].x + 22 > cur_coord.x && this->coord_of_the_vert[i].x - 22 < cur_coord.x &&
			this->coord_of_the_vert[i].y + 22 > cur_coord.y && this->coord_of_the_vert[i].y - 22 < cur_coord.y) {

			return i;//индекс вершины
		}
	}
	return -1;
}

template <class T>
void Graph<T>::clear_the_graph() {//очищаю граф
	this->adjMatrix = std::vector<std::vector<T>>(0, std::vector<T>(0));
	this->Positions_vert = std::map<T, sf::Vector2f>();
	this->vertex_list = std::vector<T>();
	this->coord_of_the_vert = std::vector<sf::Vector2f>();
}

template <class T>
std::vector<T> Graph<T>::DFS(T& start_verts, std::vector<bool>& visited_verts, std::vector<T>& vect) {//обход графа в глубину
	vect.push_back(start_verts);//добавляю текущую вершину в вектор
	visited_verts[this->get_vert_pos(start_verts)] = true;//отмечаю, что вершина посещена
	std::vector<T> neigbors = this->get_neighbors(start_verts);//соседи данной вершины
	for (int i = 0; i < neigbors.size(); ++i) {//прохожу по всем соседям
		if (!visited_verts[this->get_vert_pos(neigbors[i])]) {//если узел еще не посещен
			this->DFS(neigbors[i], visited_verts, vect);//посещаю узел
		}
	}
	return vect;
}

template <class T>
bool Graph<T>::is_it_possible_to_solve_the_traveling_salesman_problem() {//проверяю можно ли запустить коммивояжера
	bool flag = true;
	for (int i = 0; i < this->get_amount_verts() && flag; i++) {//возможно ли из каждой вершины попасть в каждую?
		std::vector<T> vect;
		std::vector<bool> visited_verts( this->get_amount_verts() , false );
		if (!(DFS(this->vertex_list[i], visited_verts, vect).size() == this->get_amount_verts())) {
			flag = false;
		}
	}
	return flag;
}

template <class T>
T Graph<T>::get_vert_T(const int& index) {
	return this->vertex_list[index];
}

template <class T>
void Graph<T>::rename_a_vertex(int index, T new_name) {//смена имени для вершины
	T old_name = this->vertex_list[index];//старое имя
	sf::Vector2f static_coords = this->Positions_vert[old_name];//запоминаю корды
	this->Positions_vert.erase(old_name);//удаляю старое имя
	this->Positions_vert[new_name] = static_coords;//старые корды по новому имени
	this->vertex_list[index] = new_name;//меняю имя в списке вершин
}

template <class T>
void Graph<T>::change_the_vertex_position(T vertex_0, sf::Vector2f new_coords) {//изменяю позицию вершины
	this->Positions_vert[vertex_0] = new_coords;//присваиваю новые координаты
	this->coord_of_the_vert[this->get_vert_pos(vertex_0)] = new_coords;
}

template <class T>
Graph<T>::Graph(const int& size) {//конструктор с размером графа
	this->adjMatrix = std::vector<std::vector<T>>(size, std::vector<T>(size));//устанавливаю матрицу смежности
	for (int i = 0; i < size; i++) {//иду по строкам
		for (int j = 0; j < size; j++) {//иду по столбцам
			this->adjMatrix[i][j] = 0;
		}
	}
}

template <class T>
bool Graph<T>::is_empty() {//граф пуст?
	return this->vertex_list.size() == 0;
}

template <class T>
void Graph<T>::insert_vertex(const T& data, sf::Vector2f coords) {//вставка вершины
	this->vertex_list.push_back(data);//добавляю новый узел в вектор весх узлов
	std::vector<int> tmp_1(vertex_list.size(), 0);//вектор с 0 для добавленного узла
	this->adjMatrix.push_back(tmp_1);//добавляю в матрицу новую строку
	this->coord_of_the_vert.push_back(coords);
	this->Positions_vert[data] = coords;
	for (int i = 0; i < vertex_list.size() - 1; i++) {
		this->adjMatrix[i].push_back(0);//добавляю новый столбец для нового узла
	}
}

template <class T>
void Graph<T>::erase_vertex(const T& data) {//удаление вершины
	int index_vert = this->get_vert_pos(data);
	if (index_vert != -1) {//если такая вершина существует
		this->vertex_list.erase(this->vertex_list.begin() + index_vert);//удаляю вершину из вектора узлов
		this->coord_of_the_vert.erase(this->coord_of_the_vert.begin() + index_vert);//удаляю вершину из вектора координат
		
		this->adjMatrix[index_vert].erase(this->adjMatrix[index_vert].begin(), this->adjMatrix[index_vert].end());
		this->adjMatrix.erase(this->adjMatrix.begin() + index_vert);
		this->Positions_vert.erase(data);
		for (int i = 0; i < vertex_list.size(); i++) {
			this->adjMatrix[i].erase(this->adjMatrix[i].begin() + index_vert);
		}
	}
}

template <class T>
int Graph<T>::get_vert_pos(const T& data) {//ИНДЕКС вершины с переданными данными
	for (int i = 0; i < this->vertex_list.size(); i++) {//иду по всем вершинам
		if (this->vertex_list[i] == data) {//если вершина найдена
			return i;//возвращаю индекс
		}
	}
	return -1;//если такой вершины нет
}

template <class T>
int Graph<T>::get_amount_verts() {//количество существующих вершин
	return this->vertex_list.size();//размер вектора вершин
}

template <class T>
int Graph<T>::get_weight(const T& vert_1, const T& vert_2) {//вес пути между вершинами
	if (this->is_empty()) {//если нет вершин
		return 0;
	}
	int position_1 = this->get_vert_pos(vert_1);//индекс узла
	int position_2 = this->get_vert_pos(vert_2);//индекс узла
	if (position_1 == -1 || position_2 == -1) {//если к-л узла нет
		return 0;
	}
	return this->adjMatrix[position_1][position_2];
}

template <class T>
std::vector<T> Graph<T>::get_neighbors(const T& data) {//вектор соседей элемента с переданными данными, только те соседи куда можно перейти
	std::vector<T> nbrs_list;//вектор соседей
	int pos = this->get_vert_pos(data);//индекс узла в матрице смежности
	if (pos != -1) {//если узел существует
		for (int i = 0; i < this->vertex_list.size(); i++) {//прохожу по всем узлам
			if (this->adjMatrix[pos][i] != 0) {//если есть путь между необходимым узлом и к-л другим
				nbrs_list.push_back(this->vertex_list[i]);
			}
		}
	}
	return nbrs_list;
}

template <class T>
void Graph<T>::insert_edge_orient(const T& vert_1, const T& vert_2, int weight) { //вставка ребра между двумя узлами
	if (this->get_vert_pos(vert_1) == -1 || this->get_vert_pos(vert_2) == -1) {//если вершин не существует
		return;
	}
	else {
		int position_1 = this->get_vert_pos(vert_1);//индекс узла
		int position_2 = this->get_vert_pos(vert_2);//индекс узла

		this->adjMatrix[position_1][position_2] = weight;
	}
}

template <class T>
void  Graph<T>::erase_edge_orient(const T& vert_1, const T& vert_2) {
	if (this->get_vert_pos(vert_1) == -1 || this->get_vert_pos(vert_2) == -1) {//если вершин не существует
		return;
	}
	else {
		int position_1 = this->get_vert_pos(vert_1);//индекс узла
		int position_2 = this->get_vert_pos(vert_2);//индекс узла
		this->adjMatrix[position_1][position_2] = 0;
	}
}

template <class T>
int Graph<T>::get_amount_edge_orient() {//количество ребер - ОРИЕНТИРОВАННЫЙ граф
	int amount = 0;
	if (!this->is_empty()) {
		for (int i = 0; i < this->vertex_list.size(); i++) {//иду по строкам
			for (int j = 0; j < this->vertex_list.size(); j++) {//иду по столбцам
				if (this->adjMatrix[i][j] != 0) {
					if (!(this->adjMatrix[i][j] != 0 && this->adjMatrix[j][i] != 0 && i > j)) {
						amount++;
					}
					
				}
			}
		}
	}
	return amount;
}

template <class T>
void Graph<T>::Draw_distance(sf::RenderWindow& window, std::map < T, sf::Vector2f>& positions, T vertex_1, T vertex_2) {
	sf::Vector2f positions_1 = positions[vertex_1];
	sf::Vector2f positions_2 = positions[vertex_2];

	positions_1 = point_on_the_node_boundary(positions_2, positions_1, 22);
	positions_2 = point_on_the_node_boundary(positions_1, positions_2, 22);
	sf::Vector2f positions_new = point_on_the_node_boundary(positions_1, positions_2, sideLength(positions_1, positions_2) / 4);

	sf::Text text_1;
	sf::Font font;
	font.loadFromFile("ofont.ru_Desyatiy.ttf");//загружаю шрифт
	text_1.setFont(font);

	text_1.setString(std::to_string(this->adjMatrix[this->get_vert_pos(vertex_1)][this->get_vert_pos(vertex_2)]));//настраиваю текст
	text_1.setFillColor(text_color);
	text_1.setCharacterSize(25);

	sf::FloatRect textRect = text_1.getLocalBounds();//центрую текст
	text_1.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	text_1.setPosition(positions_new);

	window.draw(text_1);
}

template <class T>
void Graph<T>::Draw(sf::RenderWindow& window) {
	sf::Vector2u size_window = window.getSize();
	unsigned int width = size_window.x;
	unsigned int height = size_window.y;

	unsigned int zero_x = width / 2 + 170;//условный центр графа по x
	unsigned int zero_y = height / 2;//условный центр графа по y

	int default_radius = 80 + this->vertex_list.size() * 15;
	float default_angle = 360 / this->vertex_list.size();
	for (int i = 0; i < this->vertex_list.size(); i++) {//иду по всем вершинам
		Draw_node(window, this->Positions_vert, this->vertex_list[i]);
	}

	for (int i = 0; i < this->adjMatrix.size(); i++) {//прохожу по матрице смежности
		for (int j = 0; j < this->adjMatrix.size(); j++) {//прохожу по матрице смежности
			if (this->adjMatrix[i][j] != 0) {
				Draw_edge(window, this->Positions_vert, vertex_list[i], vertex_list[j]);//рисую стрелку
			}
		}
	}
	for (int i = 0; i < this->adjMatrix.size(); i++) {//прохожу по матрице смежности
		for (int j = 0; j < this->adjMatrix.size(); j++) {//прохожу по матрице смежности
			if (this->adjMatrix[i][j] != 0) {
				Draw_distance(window, this->Positions_vert, vertex_list[i], vertex_list[j]);//пишу расстояние
			}
		}
	}
}

template <class T>
void Graph<T>::Draw_node(sf::RenderWindow& window, std::map < T, sf::Vector2f>& positions, T vertex) {
	sf::Color node_color(222, 232, 201);//вершина
	sf::Vector2f position = positions[vertex];//позиция узла
	int radiys = 20;
	sf::CircleShape circle_1(radiys);//генерирую круг
	circle_1.setFillColor(node_color);//цвет внутри круга
	circle_1.setOutlineColor(text_color);//цвет снаружи круга
	circle_1.setOutlineThickness(2);//толщина внешнего контура
	circle_1.setPosition(position.x - radiys, position.y - radiys);//позиция

	sf::Text text_1;
	sf::Font font;
	font.loadFromFile("ofont.ru_Expressway.ttf");//загружаю шрифт
	text_1.setFont(font);

	text_1.setString(std::to_string(vertex));//настраиваю текст
	text_1.setFillColor(text_color);
	text_1.setCharacterSize(radiys);

	sf::FloatRect textRect = text_1.getLocalBounds();//центрую текст
	text_1.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	text_1.setPosition(sf::Vector2f(position.x, position.y));

	window.draw(circle_1);//рисую круг
	window.draw(text_1);//рисую текст
}

template <class T>
void Graph<T>::Draw_edge(sf::RenderWindow& window, std::map < T, sf::Vector2f>& positions, T vertex_1, T vertex_2) {//рисую ребро

	sf::Color arrow_color(115, 135, 100);//стрелка

	sf::Vector2f positions_1 = positions[vertex_1];
	sf::Vector2f positions_2 = positions[vertex_2];

	positions_1 = point_on_the_node_boundary(positions_2, positions_1, 22);
	positions_2 = point_on_the_node_boundary(positions_1, positions_2, 22);

	sf::VertexArray triangleStrip(sf::TriangleStrip, 4);
	if ((positions_1.x < positions_2.x && positions_1.y < positions_2.y) ||
		(positions_1.x > positions_2.x && positions_1.y > positions_2.y)) {

		triangleStrip[0].position = sf::Vector2f(positions_1.x + 1, positions_1.y - 1);
		triangleStrip[1].position = sf::Vector2f(positions_1.x - 1, positions_1.y + 1);
		triangleStrip[2].position = sf::Vector2f(positions_2.x + 1, positions_2.y - 1);
		triangleStrip[3].position = sf::Vector2f(positions_2.x - 1, positions_2.y + 1);
	}
	else {
		triangleStrip[0].position = sf::Vector2f(positions_1.x - 1, positions_1.y - 1);
		triangleStrip[1].position = sf::Vector2f(positions_1.x + 1, positions_1.y + 1);
		triangleStrip[2].position = sf::Vector2f(positions_2.x - 1, positions_2.y - 1);
		triangleStrip[3].position = sf::Vector2f(positions_2.x + 1, positions_2.y + 1);
	}

	triangleStrip[0].color = arrow_color;
	triangleStrip[1].color = arrow_color;
	triangleStrip[2].color = arrow_color;
	triangleStrip[3].color = arrow_color;

	sf::VertexArray myTriangles(sf::Triangles, 3);//сама стрелка
	double arrow_angle = find_angle(sf::Vector2f(positions_2.x, positions_2.y), sf::Vector2f(positions_1.x, positions_1.y), sf::Vector2f(positions_2.x, positions_2.y + 20));
	if (positions_1.x > positions_2.x) {
		arrow_angle *= -1;
	}

	sf::Vector2f point_2 = calculating_node_coordinates(sf::Vector2f(positions_2.x - 10, positions_2.y + 20), positions_2, arrow_angle);
	sf::Vector2f point_3 = calculating_node_coordinates(sf::Vector2f(positions_2.x + 10, positions_2.y + 20), positions_2, arrow_angle);

	myTriangles[0].position = sf::Vector2f(positions_2.x, positions_2.y);
	myTriangles[1].position = point_2;
	myTriangles[2].position = point_3;

	myTriangles[0].color = arrow_color;
	myTriangles[1].color = arrow_color;
	myTriangles[2].color = arrow_color;

	window.draw(myTriangles);
	window.draw(triangleStrip);
}



template <class T>
void add_a_vertex_completely(Graph<T>& Graf_1, sf::Vector2f position) {//добавляю вершину
	std::string str_vertex = enter_the_data(L"Введите название вершины, которую хотите добавить (int)");
	if (string_to_int_bool(str_vertex)) {
		int vert_int = string_to_int(str_vertex);//вершина
		if (Graf_1.get_vert_pos(vert_int) == -1) {
			Graf_1.insert_vertex(vert_int, position);
			error_or_success_message(L"Вершина добавлена", L"Успех");
		}
		else {
			error_or_success_message(L"Такая вершина уже есть", L"Ошибка");
		}
	}
	else {
		error_or_success_message(L"Это не число", L"Ай-ай-ай");
	}
}

template <class T>
void delete_a_vertex_completely(Graph<T>& Graf_1) {//удаляю вершину
	std::string str_vertex = enter_the_data(L"Введите имя вершины, которую хотите удалить (int)");
	if (string_to_int_bool(str_vertex)) {
		int vert_int = string_to_int(str_vertex);//вершина
		if (Graf_1.get_vert_pos(vert_int) != -1) {
			Graf_1.erase_vertex(vert_int);
			error_or_success_message(L"Вершина удалена", L"Успех");
		}
		else {
			error_or_success_message(L"Такой вершины нет", L"Ошибка");
		}
	}
	else {
		error_or_success_message(L"Такой вершины нет!", L"Ай-ай-ай");
	}
}

template <class T>
void add_an_edge_completely(Graph<T>& Graf_1) {//добавляю ребро
	if (!Graf_1.is_empty()) {
		std::string vertex_1, vertex_2, content;
		enter_the_three_data(L"Добавить/Изменить ребро...", L"Введите первую вершину", L"Введите вторую вершину", L"Введите расстояние между вершинами", vertex_1, vertex_2, content);
		if (string_to_int_bool(vertex_1) && string_to_int_bool(vertex_2)) {//вершины-числа?
			if (string_to_int_bool(content) && vertex_1 != vertex_2) {//расстояние - число?
				int content_int = string_to_int(content);
				if (content_int > 0) {//растояние положительное?
					int vertex_1_int = string_to_int(vertex_1);
					int vertex_2_int = string_to_int(vertex_2);
					if (Graf_1.get_vert_pos(vertex_1_int) != -1 && Graf_1.get_vert_pos(vertex_2_int) != -1) {//вершины есть в графе?
						Graf_1.insert_edge_orient(vertex_1_int, vertex_2_int, content_int);
						error_or_success_message(L"Ребро добавлено", L"Успех");
					}
					else {
						error_or_success_message(L"Одной из вершин (или обеих) не существует", L"Ошибка");
					}
				}
				else {
					error_or_success_message(L"Расстояние между вершинами не корректно", L"Ошибка");
				}
			}
			else {
				error_or_success_message(L"Расстояние между вершинами не корректно", L"Ай-ай-ай");
			}
		}
		else {
			error_or_success_message(L"Одной из вершин (или обеих) не существует", L"Ай-ай-ай");
		}
	}
	else {
		error_or_success_message(L"Граф пуст!", L"Ошибка");
	}
}

template <class T>
void delete_an_edge_completely(Graph<T>& Graf_1) {//удаление ребра
	std::string vertex_1, vertex_2;
	enter_the_two_data(L"Удалить ребро...", L"Введите первую вершину", L"Введите вторую вершину", vertex_1, vertex_2);
	if (string_to_int_bool(vertex_1) && string_to_int_bool(vertex_2)) {//вершины-числа?
		int vertex_1_int = string_to_int(vertex_1);
		int vertex_2_int = string_to_int(vertex_2);
		if (Graf_1.get_vert_pos(vertex_1_int) != -1 && Graf_1.get_vert_pos(vertex_2_int) != -1) {//вершины есть в графе?
			Graf_1.erase_edge_orient(vertex_1_int, vertex_2_int);
			error_or_success_message(L"Ребро удалено", L"Успех");
		}
		else {
			error_or_success_message(L"Одной из вершин (или обеих) не существует", L"Ошибка");
		}
	}
	else {
		error_or_success_message(L"Одной из вершин (или обеих) не существует", L"Ай-ай-ай");
	}
}

template <class T>
void a_random_graph(Graph<T>& Graf_1, sf::RenderWindow& window) {//создаю случайный граф
	std::string number_of_vertices = enter_the_data(L"Сколько вершин у графа?");
	if (string_to_int_bool(number_of_vertices)) {
		int number = string_to_int(number_of_vertices);
		if (number > 0) {
			Graf_1.clear_the_graph();

			sf::Vector2u size_window = window.getSize();
			unsigned int width = size_window.x;
			unsigned int height = size_window.y;

			unsigned int zero_x = width / 2 + 170;//условный центр графа по x
			unsigned int zero_y = height / 2;//условный центр графа по y

			int default_radius = 100 + number * 15;
			float default_angle = 360 / number;

			std::vector< sf::Vector2f> def_pos_vert;
			for (int i = 0; i < number; i++) {//расчитываю позиции вершин
				def_pos_vert.push_back(calculating_node_coordinates(sf::Vector2f(zero_x, zero_y - default_radius), sf::Vector2f(zero_x, zero_y), default_angle * i));
			}
			for (int i = 0; i < number; i++) {//добавляю вершины
				Graf_1.insert_vertex(i + 1, def_pos_vert[i]);
			}
			for (int i = 1; i <= number; i++) {//добавляю ребра
				for (int j = 1; j <= number; j++) {
					if (i != j && rand()%2 == 0) {
						Graf_1.insert_edge_orient(i, j, a_random_number());
					}	
				}
			}
		}
		else {
			error_or_success_message(L"Число не корректно", L"Ошибка");
		}
	}
	else {
		error_or_success_message(L"Это не число", L"Ай-ай-ай");
	}
}

template <class T>
void THE_SAME_GRAPH(Graph<T>& Graf_1, sf::RenderWindow& window){//граф для демонстрации из методички (последний вариант)
	Graf_1.clear_the_graph();//очищаю текущий граф
	int number = 6;

	sf::Vector2u size_window = window.getSize();
	unsigned int width = size_window.x;
	unsigned int height = size_window.y;

	unsigned int zero_x = width / 2 + 170;//условный центр графа по x
	unsigned int zero_y = height / 2;//условный центр графа по y

	int default_radius = 100 + number * 15;
	float default_angle = 360 / number;

	std::vector< sf::Vector2f> def_pos_vert;
	for (int i = 0; i < number; i++) {
		def_pos_vert.push_back(calculating_node_coordinates(sf::Vector2f(zero_x, zero_y - default_radius), sf::Vector2f(zero_x, zero_y), default_angle * i));
	}
	for (int i = 0; i < number; i++) {//добавляю вершины
		Graf_1.insert_vertex(i + 1, def_pos_vert[i]);//создаю вершины
	}

	Graf_1.insert_edge_orient(1, 3, 13);//создаю все ребра
	Graf_1.insert_edge_orient(1, 4, 15);
	Graf_1.insert_edge_orient(2, 4, 20);
	Graf_1.insert_edge_orient(2, 1, 28);
	Graf_1.insert_edge_orient(3, 5, 30);
	Graf_1.insert_edge_orient(4, 6, 31);
	Graf_1.insert_edge_orient(4, 5, 39);
	Graf_1.insert_edge_orient(5, 4, 39);
	Graf_1.insert_edge_orient(5, 2, 21);
	Graf_1.insert_edge_orient(6, 1, 18);
}

template <class T>
void traveling_salesman_is_completely(Graph<T>& Graf_1) {//запуск алгоритма коммивояжера
	if (Graf_1.is_it_possible_to_solve_the_traveling_salesman_problem() && !Graf_1.is_empty()) {
		std::string start_vert_string = enter_the_data(L"С какой вершины начать?");
		if (string_to_int_bool(start_vert_string)) {
			int start_vert_int = string_to_int(start_vert_string);
			if (Graf_1.get_vert_pos(start_vert_int) != -1) {
				std::vector<T> vect_of_paths = Graf_1.the_traveling_salesman_task(start_vert_int);
				if (vect_of_paths.size() != 0) {
					if (!has_Duplicates_vector(vect_of_paths)) {
						std::string all_str = std::to_string(vect_of_paths[0]);
						for (int i = 1; i <= Graf_1.get_amount_verts(); i++) {//иду по всем обходам
							all_str = all_str + " -> " + std::to_string(vect_of_paths[i]);
						}
						sf::RenderWindow window(sf::VideoMode(650 + 20 * vect_of_paths.size(), 280), L"Задача Коммивояжера");

						sf::Font font;
						font.loadFromFile("ofont.ru_Expressway.ttf");//загружаю шрифт

						sf::Text mess;
						mess.setFont(font);
						mess.setString(L"Оптимальный путь, начиная с вершины " + std::to_wstring(vect_of_paths[0]));
						mess.setFillColor(text_color);
						mess.setCharacterSize(40);
						mess.setPosition(30, 10);

						sf::Text way;
						way.setFont(font);
						way.setString(all_str);
						way.setFillColor(text_color);
						way.setCharacterSize(39);
						way.setPosition(30, 80);

						sf::Text all_len;
						all_len.setFont(font);
						all_len.setString(L"Длина пути: " + std::to_wstring(Graf_1.path_length(vect_of_paths)));
						all_len.setFillColor(text_color);
						all_len.setCharacterSize(39);
						all_len.setPosition(30, 130);

						RectButton button1(sf::Vector2f(150, 60), sf::Vector2f(window.getSize().x / 2 - 75, window.getSize().y - 90));
						button1.setButtonFont(font);
						button1.setButtonLable(L"Ok", text_color, 30);

						while (window.isOpen()) {
							sf::Vector2i mousePoz = sf::Mouse::getPosition(window);//позиция мыши в окне
							sf::Event event;
							button1.getButtonStatus(window, event);
							while (window.pollEvent(event))
							{
								if (event.type == sf::Event::Closed)
									window.close();
								if (event.type == sf::Event::MouseButtonPressed) {
									if (event.key.code == sf::Mouse::Left) {
										if (button1.isPressed) {
											window.close();
										}
									}
								}
							}
							window.clear(background_color);
							button1.draw(window);
							window.draw(mess);
							window.draw(way);
							window.draw(all_len);
							window.display();
						}
					}
					else {
						error_or_success_message(L"Алгоритм запутался, не ругайте его ~(>_<.)~", L"Ой(");
					}
				}
				else {
					error_or_success_message(L"Для текущей вершины нельзя решить задачу коммивояжера", L"Ошибка");
				}
			}
			else {
				error_or_success_message(L"Такой вершины нет", L"Ошибка");
			}
		}
		else {
			error_or_success_message(L"Это не число", L"Ай-ай-ай");
		}
	}
	else {
		error_or_success_message(L"Для текущего графа нельзя решить задачу коммивояжера", L"Ошибка");
	}
}

template <class T>
void rename_the_vertex_completely(Graph<T>& Graf_1, sf::Vector2f coords) {
	int is_it_coord_vert = Graf_1.this_is_node(coords);//индекс вершины 
	if (is_it_coord_vert != -1) {//если переданы координаты вершины
		std::string new_name = enter_the_data(L"Введите новое имя (int)");
		if (string_to_int_bool(new_name)) {
			int new_vert_name_int = string_to_int(new_name);
			if (new_vert_name_int > 0 && new_vert_name_int < 10000) {
				if (Graf_1.get_vert_pos(new_vert_name_int) == -1) {//если такой вершины нет
					Graf_1.rename_a_vertex(is_it_coord_vert, new_vert_name_int);
				}
				else {
					error_or_success_message(L"Такая вершина уже есть", L"Ай-ай-ай");
				}
			}
			else {
				error_or_success_message(L"Некорректное значение", L"Ай-ай-ай");
			}
		}
		else {
			error_or_success_message(L"Это не число", L"Ай-ай-ай");
		}
	}
	else {
		error_or_success_message(L"Это не вершина", L"Атата");
	}
}