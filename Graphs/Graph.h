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
	std::vector<T> vertex_list; //вектор вершин
	std::vector<std::vector<int>> adjMatrix;//матрица смежности
	std::vector<std::vector<int>> shortest_paths_matrix; //матрица кратчайших расстояний
	std::vector<std::vector<int>> second_matrix;//вторая матрица для флойда
	std::vector<int> label_list;
public:
	Graph(const int& size = 0);//конструктор с размером графа
	~Graph() {};//деструктор
	bool is_empty();//граф пуст?
	void insert_vertex(const T& vert);//вставка вершины
	void erase_vertex(const T& vert);//удаление вершины
	int get_vert_pos(const T& data);//ИНДЕКС вершины с переданными данными
	int get_amount_verts();//количество существующих вершин
	int get_weight(const T& vert_1, const T& vert_2);//вес пути между вершинами
	std::vector<T> get_neighbors(const T& data);//вектор соседей элемента с переданными данными
	void insert_edge_orient(const T& vert_1, const T& vert_2, int weight = 1); //вставка ребра между двумя узлами - ОРИЕНТИРОВАННЫЙ граф
	void erase_edge_orient(const T& vert_1, const T& vert_2);//удаление ребра между двумя узлами
	
	void print_matrix();//печать матрицы смежности
	int get_amount_edge_orient();//количество ребер - ОРИЕНТИРОВАННЫЙ граф
	std::vector<T> DFS(T& start_verts, std::vector<bool>& visited_verts, std::vector<T>& vect);//обход графа в ГЛУБИНУ
	std::vector<T> BFS(T& start_verts, std::vector<bool>& visited_verts, std::vector<T>& vect);//обход графа в ШИРИНУ

	bool all_vertices_are_available(T vertex);//можно ли попасть во все вершины?
	
	void all_matr() {/////////////////////////убрать
		this->print_matrix();

		std::cout << "Матрица кратчайших расстояний" << std::endl;
		std::cout << std::setw(7) << "*";
		for (int i = 0; i < this->vertex_list.size(); i++) {
			std::cout << std::setw(7) << vertex_list[i];
		}
		std::cout << std::endl;
		for (int i = 0; i < this->vertex_list.size(); i++) {
			std::cout << std::setw(7) << vertex_list[i];
			for (int j = 0; j < this->vertex_list.size(); j++) {
				std::cout << std::setw(7) << this->shortest_paths_matrix[i][j];
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
		std::cout << "Вторая матрица" << std::endl;
		std::cout << std::setw(7) << "*";
		for (int i = 0; i < this->vertex_list.size(); i++) {
			std::cout << std::setw(7) << vertex_list[i];
		}
		std::cout << std::endl;
		for (int i = 0; i < this->vertex_list.size(); i++) {
			std::cout << std::setw(7) << vertex_list[i];
			for (int j = 0; j < this->vertex_list.size(); j++) {
				std::cout << std::setw(7) << this->second_matrix[i][j];
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	//алгоритм дейкстеры
	void fill_labels(T& start_vertex);//заполнение меток расстояния
	bool all_visited(std::vector<bool>& visited_verts);//все вершины посещены?
	std::vector<std::pair<T,int>> Dijkstra(T& start_vertex);//алгоритм дейкстры
	//*********
	bool AllVisited(bool* visitedVerts);
	void FillLabels(T& startVertex);
	int Dijkstra_1(T& startVertex);

	//алгоритм флойда
	void Floyd();
	std::vector<std::tuple<T, T, std::vector<T>>> PrintSP();

	void Draw(sf::RenderWindow& window);//отрисовываю граф полностью
	void Draw_node(sf::RenderWindow& window, std::map < T, sf::Vector2f>& positions, T vertex);//отрисовываю вершину
	void Draw_edge(sf::RenderWindow& window, std::map < T, sf::Vector2f>& positions, T vertex_1, T vertex_2);//отрисовываю ребро
	void Draw_distance(sf::RenderWindow& window, std::map < T, sf::Vector2f>& positions, T vertex_1, T vertex_2);//отрисовываю расстояние
};

template <class T>
bool Graph<T>::all_vertices_are_available(T vertex_0) {//можно ли попасть во все вершины? : проверка для дейкстеры
	std::vector<T> vector_graf;
	std::vector<bool> v_bool_1(this->get_amount_verts(), false);
	this->DFS(vertex_0, v_bool_1, vector_graf);//обход в глубину
	return vector_graf.size() == this->get_amount_verts();
}

template <class T>
void Graph<T>::Draw_distance(sf::RenderWindow& window, std::map < T, sf::Vector2f>& positions, T vertex_1, T vertex_2) {
	if (!((this->adjMatrix[this->get_vert_pos(vertex_2)][this->get_vert_pos(vertex_1)] == this->adjMatrix[this->get_vert_pos(vertex_1)][this->get_vert_pos(vertex_2)]) && 
		this->get_vert_pos(vertex_1) > this->get_vert_pos(vertex_2))){ //чтоб дубликатов не было
		sf::Color arrow_color(100, 100, 100);//циферки
		sf::Vector2f positions_1 = positions[vertex_1];
		sf::Vector2f positions_2 = positions[vertex_2];

		positions_1 = point_on_the_node_boundary(positions_2, positions_1, 22);
		positions_2 = point_on_the_node_boundary(positions_1, positions_2, 22);

		positions_1 = point_on_the_node_boundary(positions_2, positions_1, sideLength(positions_1, positions_2) / 3 * 2);

		sf::Text text_1;
		sf::Font font;
		font.loadFromFile("ofont.ru_Desyatiy.ttf");//загружаю шрифт
		text_1.setFont(font);

		text_1.setString(std::to_string(this->adjMatrix[this->get_vert_pos(vertex_1)][this->get_vert_pos(vertex_2)]));//настраиваю текст
		text_1.setFillColor(text_color);
		text_1.setCharacterSize(25);

		sf::FloatRect textRect = text_1.getLocalBounds();//центрую текст
		text_1.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
		text_1.setPosition(positions_1);

		window.draw(text_1);
	}
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

	std::map<T, sf::Vector2f> Positions;
	int x = 50, y = 50;
	for (int i = 0; i < this->vertex_list.size(); i++) {//иду по всем вершинам
		Positions[this->vertex_list[i]] = calculating_node_coordinates(sf::Vector2f(zero_x, zero_y - default_radius), sf::Vector2f(zero_x, zero_y), default_angle * i);
		Draw_node(window, Positions, this->vertex_list[i]);
	}

	for (int i = 0; i < this->adjMatrix.size(); i++) {//прохожу по матрице смежности
		for (int j = 0; j < this->adjMatrix.size(); j++) {//прохожу по матрице смежности
			if (this->adjMatrix[i][j] != 0 && this->adjMatrix[i][j] != 10000) {
				Draw_edge(window, Positions, vertex_list[i], vertex_list[j]);//рисую стрелку
			}
		}
	}
	for (int i = 0; i < this->adjMatrix.size(); i++) {//прохожу по матрице смежности
		for (int j = 0; j < this->adjMatrix.size(); j++) {//прохожу по матрице смежности
			if (this->adjMatrix[i][j] != 0 && this->adjMatrix[i][j] != 10000) {
				Draw_distance(window, Positions, vertex_list[i], vertex_list[j]);//пишу расстояние
			}
		}
	}
}

template <class T>
void Graph<T>::Draw_node(sf::RenderWindow& window, std::map < T, sf::Vector2f>& positions, T vertex) {
	sf::Vector2f position = positions[vertex];//позиция узла
	int radiys = 20;
	sf::CircleShape circle_1(radiys);//генерирую круг
	circle_1.setFillColor(button_color);//цвет внутри круга
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
	
	sf::Color arrow_color(117, 90, 87);//стрелка
	
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
void Graph<T>::insert_vertex(const T& data) {//вставка вершины
	this->vertex_list.push_back(data);//добавляю новый узел в вектор весх узлов
	std::vector<int> tmp_1(vertex_list.size(), 0);//вектор с 0 для добавленного узла
	std::vector<int> tmp_2(vertex_list.size(), 0);
	
	std::vector<int> tmp_3(vertex_list.size(), 10000);
	tmp_3[vertex_list.size() - 1] = 0;
	this->adjMatrix.push_back(tmp_1);//добавляю в матрицу новую строку
	this->second_matrix.push_back(tmp_2);
	this->shortest_paths_matrix.push_back(tmp_3);
	for (int i = 0; i < vertex_list.size() - 1; i++) {
		this->adjMatrix[i].push_back(0);//добавляю новый столбец для нового узла
		this->second_matrix[i].push_back(0);
		this->shortest_paths_matrix[i].push_back(10000);

	}
}

template <class T>
void Graph<T>::erase_vertex(const T& data) {//удаление вершины
	int index_vert = this->get_vert_pos(data);
	if (index_vert != -1) {//если такая вершина существует
		this->vertex_list.erase(this->vertex_list.begin() + index_vert);//удаляю вершину из вектора узлов
		
		this->adjMatrix[index_vert].erase(this->adjMatrix[index_vert].begin(), this->adjMatrix[index_vert].end());
		this->adjMatrix.erase(this->adjMatrix.begin() + index_vert);

		this->shortest_paths_matrix[index_vert].erase(this->shortest_paths_matrix[index_vert].begin(), this->shortest_paths_matrix[index_vert].end());
		this->shortest_paths_matrix.erase(this->shortest_paths_matrix.begin() + index_vert);

		this->second_matrix[index_vert].erase(this->second_matrix[index_vert].begin(), this->second_matrix[index_vert].end());
		this->second_matrix.erase(this->second_matrix.begin() + index_vert);

		for (int i = 0; i < vertex_list.size(); i++) {
			this->adjMatrix[i].erase(this->adjMatrix[i].begin() + index_vert);
			this->shortest_paths_matrix[i].erase(this->shortest_paths_matrix[i].begin() + index_vert);
			this->second_matrix[i].erase(this->second_matrix[i].begin() + index_vert);
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
		std::cout << "Один из узлов не существует" << std::endl;
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
			if (this->adjMatrix[pos][i] != 0 && this->adjMatrix[pos][i] != 10000) {//если есть путь между необходимым узлом и к-л другим
				nbrs_list.push_back(this->vertex_list[i]);
			}
		}
	}
	return nbrs_list;
}

template <class T>
void Graph<T>::insert_edge_orient(const T& vert_1, const T& vert_2, int weight) { //вставка ребра между двумя узлами
	if (this->get_vert_pos(vert_1) == -1 || this->get_vert_pos(vert_2) == -1) {
		std::cout << "Один из узлов не существует" << std::endl;
		return;
	}
	else {
		int position_1 = this->get_vert_pos(vert_1);//индекс узла
		int position_2 = this->get_vert_pos(vert_2);//индекс узла
		/*if (this->adjMatrix[position_1][position_2] != 0 && this->adjMatrix[position_1][position_2] != 10000) {
			std::cout << "Ребро уже есть!!" << std::endl;
			return;
		}
		else {
			this->adjMatrix[position_1][position_2] = weight;
			this->second_matrix[position_1][position_2] = vert_2;
		}*/
		if (this->adjMatrix[position_2][position_1] != 0 && this->adjMatrix[position_2][position_1] != 10000) {
			this->adjMatrix[position_1][position_2] = weight;
			this->adjMatrix[position_2][position_1] = weight;
		}
		else {
			this->adjMatrix[position_1][position_2] = weight;
		}

		this->second_matrix[position_1][position_2] = vert_2;
	}
}
template <class T>
void  Graph<T>::erase_edge_orient(const T& vert_1, const T& vert_2) {
	if (this->get_vert_pos(vert_1) == -1 || this->get_vert_pos(vert_2) == -1) {
		std::cout << "Один из узлов не существует" << std::endl;
		return;
	}
	else {
		int position_1 = this->get_vert_pos(vert_1);//индекс узла
		int position_2 = this->get_vert_pos(vert_2);//индекс узла
		this->adjMatrix[position_1][position_2] = 0;
		this->shortest_paths_matrix[position_1][position_2] = 10000;
	}
}

template <class T>
void Graph<T>::print_matrix() {//печать матрицы смежности
	if (this->is_empty()) {
		std::cout << "Граф пуст" << std::endl;
		return;
	}
	else {
		std::cout << "Матрица смежности графа" << std::endl;
		std::cout << std::setw(4) << "*";
		for (int i = 0; i < this->vertex_list.size(); i++) {
			std::cout << std::setw(4) << vertex_list[i];
		}
		std::cout << std::endl;
		for (int i = 0; i < this->vertex_list.size(); i++) {
			std::cout << std::setw(4) << vertex_list[i];
			for (int j = 0; j < this->vertex_list.size(); j++) {
				if (this->adjMatrix[i][j] == 10000) {
					std::cout << "    ";
				}
				else {
					std::cout << std::setw(4) << this->adjMatrix[i][j];
				}
			}
			std::cout << std::endl;
		}
	}
}

template <class T>
int Graph<T>::get_amount_edge_orient() {//количество ребер - ОРИЕНТИРОВАННЫЙ граф
	int amount = 0;
	if (!this->is_empty()) {
		for (int i = 0; i < this->vertex_list.size(); i++) {//иду по строкам
			for (int j = 0; j < this->vertex_list.size(); j++) {//иду по столбцам
				if (this->adjMatrix[i][j] != 0) {
					if (!(this->adjMatrix[i][j] != 0 && this->adjMatrix[i][j] != 10000 && this->adjMatrix[j][i] != 10000 && this->adjMatrix[j][i] != 0 && i > j)) {
						amount++;
					}
					
				}
			}
		}
	}
	return amount;
}

template <class T>
std::vector<T> Graph<T>::DFS(T& start_verts, std::vector<bool>& visited_verts, std::vector<T>& vect) {//обход графа в глубину
	std::cout << "Вершина " << start_verts << " посещена" << std::endl;
	vect.push_back(start_verts);
	visited_verts[this->get_vert_pos(start_verts)] = true;//отмечаю, что вершина посещена
	std::vector<T> neigbors = this->get_neighbors(start_verts);//соседи данной вершины
	for (int i = 0; i < neigbors.size(); ++i) {
		if (!visited_verts[this->get_vert_pos(neigbors[i])]) {//если узел еще не посещен
			this->DFS(neigbors[i], visited_verts, vect);//посещаю узел
		}
	}
	return vect;
}

template <class T>
std::vector<T> Graph<T>::BFS(T& start_verts, std::vector<bool>& visited_verts, std::vector<T>& vect) {
	std::queue<T> q; // Используем очередь для хранения вершин
	q.push(start_verts); // Начинаем обход с начальной вершины
	visited_verts[get_vert_pos(start_verts)] = true; // Помечаем начальную вершину как посещенную

	while (!q.empty()) {//пока очередь не опустеет
		T current = q.front();//первый элемент в очереди
		q.pop();//удаляю первый элемент
		std::cout << "Вершина " << current << " обработана" << std::endl; // Выводим текущую вершину
		vect.push_back(current);
		for (int i = 0; i < adjMatrix[get_vert_pos(current)].size(); ++i) {//пока не пройду все элементы в строке матрицы графов
			if (adjMatrix[get_vert_pos(current)][i] > 0 && !visited_verts[i]) {//если между вершинами есть дорогоа и вершина еще не посещена
				q.push(vertex_list[i]);//добавляю вершину в очередь ожидания посещения
				visited_verts[i] = true;//отмечаю, что вершина посещена
			}
		}
	}
	return vect;
}

//***********
template<class T>
bool Graph<T>::AllVisited(bool* visitedVerts) {
	/* Устанавливаем в флажок начальное значение false,
	так как при объявлении переменные лучше
	инициализировать сразу */
	bool flag = true;
	/* В цикле проверяем, если в массиве посещенных
	вершин есть хотя бы одно значение false, то флажок
	переводится в значение false */
	for (int i = 0, size = this->vertex_list.size(); i < size;	++i) {
		if (visitedVerts[i] != true)
			flag = false;
	}
	if (flag == false)
		return false;
	/* Если флажок равен false, то не все вершины
	посещены, функция возвращает значение false */
	else return true;
	/* Если флажок равен true, то все вершины
	посещены, функция возвращает true */
}

template<class T>
void Graph<T>::FillLabels(T& startVertex) {
	this->label_list.clear();
	for (int i = 0, size = vertex_list.size(); i < size;++i) {
		this->label_list.push_back(1000000);
		/* Заполнение списка меток значениями 1000000 */
	}
	int pos = this->get_vert_pos(startVertex);
	/* По индексу вершины, от которой требуется найти
	кратчайшие расстояния до всех остальных,
	устанавливается метка 0 */
	this->label_list[pos] = 0;
}

template<class T>
int Graph<T>::Dijkstra_1(T& startVertex) {
	for (int i = 0, size = this->vertex_list.size(); i <
		size; ++i) {
		for (int j = 0; j < size; ++j) {
			if (this->adjMatrix[i][j] < 0)
				/* Проверяем, что граф не содержит ребер
				отрицательного веса */
				return -1;
		}
	}
	/* Объявление опорной вершины абстрактного типа T,
	счетчика, переменной для определения
	минимальной метки */
	T curSrc; int counter = 0;
	int minLabel = 1000000;
	// Создаем вектор из соседей текущей начальной вершины
	std::vector<T> neighbors = this->get_neighbors(startVertex);
	this->FillLabels(startVertex);
	/* Проверяем, если в векторе меток метка по индексу,
   соответствующему индексу соседа в векторе вершин vertList,
   больше, чем сумма метки текущей начальной вершины и ребра
	от этой вершины до соседа, то нужно в векторе меток
	по этому индексу поставить сумму метки начальной вершины
	и ребра от нее до соседа */
	for (int i = 0; i < neighbors.size(); ++i) {
		if (this->label_list[this->get_vert_pos(startVertex)] + this->get_weight(startVertex, neighbors[i]) < this->label_list[this->get_vert_pos(neighbors[i])]){
			this->label_list[this->get_vert_pos(neighbors[i])] = this->get_weight(startVertex, neighbors[i]);
		}
		if (this->label_list[this->get_vert_pos(neighbors[i])] < minLabel)
			minLabel = this->label_list[this->get_vert_pos(neighbors[i])];
		/* Определяем наименьшую метку у соседних
		опорной вершине вершин */
	}
	// Проверяем, что рассмотрели всех соседей
	for (int i = 0; i < neighbors.size(); ++i) {
		if (this->label_list[this->get_vert_pos(neighbors[i])]	!= 1000000)
			counter += 1;
	}
	/* Фиксируем, что начальная вершина теперь считается
	посещенной (так как всех соседей посмотрели) */
	std::vector<bool> visitedVerts(this->get_amount_verts(), false);
	if (counter == neighbors.size())
		visitedVerts[this->get_vert_pos(startVertex)] = true;
	/* Ищем новую опорную вершину – такую, у которой из
	всех соседей метка наименьшая */
	for (int i = 0; i < neighbors.size(); ++i) {
		if (this->label_list[this->get_vert_pos(neighbors[i])] == minLabel)
			curSrc = neighbors[i];
	}
	/* Так как начальная вершина новая, то теперь мы
	будем рассматривать ее соседей */
	neighbors = this->get_neighbors(curSrc);
	// Работаем, пока все вершины не будут считатьсяпосещенными
	while (!all_visited(visitedVerts)) {
		int count = 0;
		minLabel = 10000;
		for (int i = 0; i < neighbors.size(); ++i) {
			// Проверяем, была ли вершина-сосед	уже рассмотрена ранее
				if (visitedVerts[this ->get_vert_pos(neighbors[i])] != true) {
					/* Проверяем, если в векторе меток метка по индексу,
					соответствующему индексу соседа в векторе вершин
					vertList, больше, чем сумма метки текущей начальной
					вершины и ребра от этой вершины до соседа, то нужно
					в векторе меток по этому индексу поставить сумму
					метки начальной вершины и ребра от нее до соседа */
					if (this->label_list[this->get_vert_pos(curSrc)]+ get_weight(curSrc, neighbors[i]) <	this->label_list[this->get_vert_pos(neighbors[i])]) {
						this->label_list[this->get_vert_pos(neighbors[i])] = (this -> label_list[this->get_vert_pos(curSrc)] + this->get_weight(curSrc, neighbors[i]));
					}
					if (this->label_list[this->get_vert_pos(neighbors[i])] < minLabel) {
						minLabel = this -> label_list[this->get_vert_pos(neighbors[i])];
					}
				}
			count += 1; // Считаем соседей
		}
		/* Проверяем, что посетили всех соседей
		текущей опорной вершины: если да, то текущая опорная
		вершина отмечается как посещенная */
		if (count == neighbors.size())
			visitedVerts[this->get_vert_pos(curSrc)] = true;
		// Ищем среди соседей новую опорную вершину
		for (int i = 0; i < neighbors.size(); ++i) {
			if (this->label_list[this -> get_vert_pos(neighbors[i])] == minLabel)
				curSrc = neighbors[i];
		}
		// Заносим в вектор соседей соседей новой опорной вершины
			neighbors = this->get_neighbors(curSrc);
	}
	// Вывод результатов на экран
	for (int i = 0; i < this->get_vert_pos(startVertex); ++i) {
		std::cout << "Кратчайшее расстояние от вершины "
			<< startVertex
			<< " до вершины " << this->vertex_list[i]
			<< " равно "
			<< this->label_list[this ->get_vert_pos(this->vertex_list[i])] << std::endl;
	}
	
	for (int i = this->get_vert_pos(startVertex) + 1; i < this->vertex_list.size(); ++i) {
		std::cout << "Кратчайшее расстояние от вершины "
			<< startVertex
			<< " до вершины " << this->vertex_list[i]
			<< " равно "
			<< this->label_list[this ->get_vert_pos(this->vertex_list[i])] << std::endl;
	}
}

//***********
//----------------------------------
template <class T>
void Graph<T>::fill_labels(T& start_vertex) {//заполнение меток расстояния
	std::vector<int> tmp_1(this->vertex_list.size(), 1000000);//метки расстояния
	this->label_list = tmp_1;//устанавливаю
	int pos = this->get_vert_pos(start_vertex);//считываю позицию индекс начальной вершины
	std::cout << "начальная вершина " << pos << std::endl;
	this->label_list[pos] = 0;//начальная вершина, поэтому 0
}

template <class T>
bool Graph<T>::all_visited(std::vector<bool>& visited_verts) {//все вершины посещены?
	bool flag = true;
	for (int i = 0; i < this->vertex_list.size() && flag; i++) {//прохожу по всем вершинам
		if (visited_verts[i] != true) {//проверяю каждую вершину на посещение
			flag = false;
		}
	}
	for (int i = 0; i < this->vertex_list.size(); i++) {//прохожу по всем вершинам
		std::cout << visited_verts[i] << " ";
	}
	std::cout << std::endl << "-------" << std::endl;
	return flag;
}



template <class T>
std::vector<std::pair<T, int>> Graph<T>::Dijkstra(T& start_vertex) {//алгоритм дейкстры
	std::vector<std::pair<T, int>> vect_of_distances;
	for (int i = 0; i < this->vertex_list.size(); i++) {
		for (int j = 0; j < this->vertex_list.size(); j++) {
			if (this->adjMatrix[i][j] < 0) {//проверка на недопустимое расстояние между узлами
				return vect_of_distances;
			}
		}
	}
	if (this->get_vert_pos(start_vertex) == -1) {//проверка на корректность
		return vect_of_distances;
	}
	std::vector<bool> visited_verts(this->vertex_list.size(), false);
	this->fill_labels(start_vertex);
	T current_src = start_vertex;
	std::vector<T> neighbors;

	while (!this->all_visited(visited_verts)) {
		neighbors = this->get_neighbors(current_src);
		int start_label = this->label_list[this->get_vert_pos(current_src)];
		T* min_neighbor_ptr = nullptr;//самый близкий сосед
		int min_W = 1000000;
		for (int i = 0; i < neighbors.size(); i++) {
			int weight = this->get_weight(current_src, neighbors[i]);
			int n_index = this->get_vert_pos(neighbors[i]);
			int next_label = this->label_list[n_index];
			if (start_label + weight < next_label) {
				this->label_list[n_index] = start_label + weight;
			}
			if (!visited_verts[n_index] && min_W > this->label_list[n_index]) {
				min_W = this->label_list[n_index];
				min_neighbor_ptr = &neighbors[i];
			}
		}
		visited_verts[this->get_vert_pos(current_src)] = true;
		if (min_neighbor_ptr != nullptr) {
			current_src = *min_neighbor_ptr;
		}
	}
	std::pair<T, int> para_dist;
	for (int i = 0; i < this->get_vert_pos(start_vertex); i++) {
		std::cout << "Кратчайшее расстояние от вершины " << start_vertex <<
			" до вершины " << vertex_list[i] << " равно " <<
			label_list[this->get_vert_pos(this->vertex_list[i])] << std::endl;
		para_dist.first = vertex_list[i];
		para_dist.second = label_list[this->get_vert_pos(this->vertex_list[i])];
		vect_of_distances.push_back(para_dist);
	}
	for (int i = this->get_vert_pos(start_vertex) + 1; i < this->vertex_list.size(); i++) {
		std::cout << "Кратчайшее расстояние от вершины " << start_vertex <<
			" до вершины " << vertex_list[i] << " равно " <<
			label_list[this->get_vert_pos(this->vertex_list[i])] << std::endl;
		para_dist.first = vertex_list[i];
		para_dist.second = label_list[this->get_vert_pos(this->vertex_list[i])];
		vect_of_distances.push_back(para_dist);
	}
	return vect_of_distances;
}
//---------------------------------------
template<class T>
void Graph<T>::Floyd() {
	struct Route {
		std::vector<T> Verts; // Вершины маршрута
		int weight{ 0 }; // Вес маршрута
		bool isVertexExists(const T vertex) const {//проверка: маршрут проходит через эту вершину или нет?
			return std::find(Verts.cbegin(), Verts.cend(), vertex) != Verts.cend();
		}
	};
	for (int i = 0, size = this->vertex_list.size(); i < size; ++i) {//прохожу по всем вершинам
		std::vector<Route> routes;// Вектор всевозможных маршрутов из текущей вершины
		{
			std::queue<Route> routesToWatch;// Очередь вершин, которые нужно просмотреть 
			{
				Route route; // Создание нового маршрута
				route.Verts.push_back(this->vertex_list[i]);// Добавление в маршрут текущей вершины
				routesToWatch.push(route);// Добавление маршрута в очередь
			}
			while (!routesToWatch.empty()) {// Цикл работает, пока очередь не пуста
				Route currentRoute = routesToWatch.front();//Запоминание маршрута, находящегося в голове очереди
				routesToWatch.pop();// Удаление маршрута из головы очереди
				routes.push_back(currentRoute);// Добавление нового маршрута в вектор маршрутов
				const T lastRouteVertex = currentRoute.Verts.back();//Создание и инициализация последней вершины маршрута
				for (const T& neighbor : this->get_neighbors(lastRouteVertex)) {//Цикл работает для всех соседей последней вершины текущего рассматриваемого маршрута
					if (!currentRoute.isVertexExists(neighbor)) {//Если в текущем маршруте нет вершины, соседней с последней вершиной маршрута, то создаем новый маршрут(копия)
						Route routeToWatch = currentRoute;
						routeToWatch.Verts.push_back(neighbor);//Затем в маршрут-копию помещается сосед последней вершины currentRoute
						routeToWatch.weight += this->adjMatrix[this->get_vert_pos(lastRouteVertex)][this->get_vert_pos(neighbor)];//У нового маршрута увеличивается вес	(так как в него только что добавили еще одну вершину)
						routesToWatch.push(routeToWatch);// В очередь заносится этот маршрут-копия
					}
				}
			}
			routes.erase(routes.begin());//Удаление первого маршрута из вектора	маршрутов
		}
		// Массив ассоциаций: 
		std::map<T, std::pair<T, int>> shortestRoutes;
		{
			for (const Route& route : routes) {// В цикле будут выявлены кратчайшие маршруты
				const T endVertex = route.Verts.back();//Создание и инициализация последней	вершины маршрута
				const T stepVertex = route.Verts[1];//Создание и инициализация промежуточной вершины, в которую надо делать шаг
				/* Нужно посмотреть shortestRoutes:
				если там до endVertex находится более короткий путь,
				то его не трогать; если его там нет для
				endVertex, то добавить пару; если он есть,
				но длиннее, то его изменить */
				if (shortestRoutes.find(endVertex) == shortestRoutes.end()) {
					shortestRoutes.insert(std::make_pair(endVertex,	std::make_pair(stepVertex, route.weight)));
				}
				else {
					const int minimWeight =	shortestRoutes[endVertex].second;
					if (minimWeight > route.weight) {
						shortestRoutes[endVertex] = std::make_pair(stepVertex, route.weight);
					}
				}
			}
		}
		for (const std::pair<const T, std::pair<T, int>>& shortestRoute : shortestRoutes) {// Цикл заполнения матриц данными
			const T endVertex = shortestRoute.first;//Извлечение конечной вершины текущего рассматриваемого кратчайшего пути
			const T stepVertex = shortestRoute.second.first;// Извлечение промежуточной вершины
			const int minWeight = shortestRoute.second.second;// Извлечение веса кратчайшего маршрута
			this->shortest_paths_matrix[i][this->get_vert_pos(endVertex)] = minWeight;// Заполнение первой матрицы
			this->second_matrix[i][this->get_vert_pos(endVertex)] = stepVertex; // Заполнение второй матрицы
		}
	}
}

template<class T>
std::vector<std::tuple<T, T, std::vector<T>>> Graph<T>::PrintSP() {
	int cur = 0, col = 0;
	std::vector<std::tuple<T, T, std::vector<T>>> vector_of_dists;
	for (int i = 0, size = this->vertex_list.size(); i < size; ++i) {
		std::cout << "Кратчайший путь от вершины " << this->vertex_list[i]; // Вывод исходной вершины на экран
		for (int j = 0; j < size; ++j) {
			if (this->second_matrix[i][j] != 0) {// Проверка, что есть следующая(промежуточная) вершина
				col = j;// Запоминаем конечную вершину (в которую идем) 
				cur = this->second_matrix[i][j];// Присвоение в cur промежуточной вершины

				std::cout << " к вершине " << this->vertex_list[j]	<< ": ";// Вывод промежуточной вершины на экран
				std::cout << this->vertex_list[i] << " ";//Вывод на экран исходной вершины
				std::vector<T> vect_of_way;
				vect_of_way.push_back(this->vertex_list[i]);
				while (cur != 0) {//Цикл, который идет по второй матрице; в нем изменяется промежуточная вершина
					std::cout << cur << " ";// Вывод текущей промежуточной вершины на экран
					vect_of_way.push_back(cur);
						if (this->second_matrix[this ->get_vert_pos(cur)][col] != 0) {// Проверка, что есть следующая промежуточная вершина
							cur = this->second_matrix[this ->get_vert_pos(cur)][col];// Если есть, то она присваивается в cur
						}
						else { // Если нет, то cur обнуляется, цикл завершится
							cur = 0; 
						}
				}
				std::cout << std::endl;
				std::tuple < T, T, std::vector<T>> tuple_1(this->vertex_list[i], this->vertex_list[j], vect_of_way);
				vector_of_dists.push_back(tuple_1);
			}
		}
		std::cout << std::endl;
	}
	return vector_of_dists;
}

template <class T>
void Graph_traversal(Graph<T> Graf_1, T vertex_0) {//вывод всех обходов дерева
	std::vector<std::vector<T>> vector_graf(2);
	std::vector<bool> v_bool_1(Graf_1.get_amount_verts(), false);
	std::vector<bool> v_bool_2(Graf_1.get_amount_verts(), false);
	std::vector<std::string> vect_wstring;
	
	Graf_1.DFS(vertex_0, v_bool_1, vector_graf[0]);//обход в глубину
	Graf_1.BFS(vertex_0, v_bool_2, vector_graf[1]);//обход в ширину

	for (int i = 0; i < 2; i++) {//иду по всем обходам
		std::string all_str = "";//собираю строку
		for (int j = 0; j < vector_graf[i].size(); j++) {
			std::ostringstream buffet;//обрабатываю число с .
			buffet << std::fixed << std::setprecision(0) << vector_graf[i][j];
			all_str = all_str + buffet.str() + " ";//собираю строку
		}
		vect_wstring.push_back(all_str);
	}

	sf::RenderWindow window(sf::VideoMode(500 + Graf_1.get_amount_verts() * 10, 380), L"Обходы бинарного дерева");

	sf::Font font;
	font.loadFromFile("ofont.ru_Expressway.ttf");//загружаю шрифт

	sf::Text obxod_binary_tree;
	obxod_binary_tree.setFont(font);
	obxod_binary_tree.setString(L"Обходы графа с вершины " + std::to_wstring(vertex_0));
	obxod_binary_tree.setFillColor(text_color);
	obxod_binary_tree.setCharacterSize(50);
	obxod_binary_tree.setPosition(30, 10);

	sf::Text obxod_1_name;
	obxod_1_name.setFont(font);
	obxod_1_name.setString(L"Обход в ширину");
	obxod_1_name.setFillColor(text_color);
	obxod_1_name.setCharacterSize(40);
	obxod_1_name.setPosition(30, 80);

	sf::Text obxod_1_value;
	obxod_1_value.setFont(font);
	obxod_1_value.setString(vect_wstring[0]);
	obxod_1_value.setFillColor(text_color);
	obxod_1_value.setCharacterSize(40);
	obxod_1_value.setPosition(30, 130);

	sf::Text obxod_2_name;
	obxod_2_name.setFont(font);
	obxod_2_name.setString(L"Обход в глубину");
	obxod_2_name.setFillColor(text_color);
	obxod_2_name.setCharacterSize(40);
	obxod_2_name.setPosition(30, 190);

	sf::Text obxod_2_value;
	obxod_2_value.setFont(font);
	obxod_2_value.setString(vect_wstring[1]);
	obxod_2_value.setFillColor(text_color);
	obxod_2_value.setCharacterSize(40);
	obxod_2_value.setPosition(30, 240);

	RectButton button1(sf::Vector2f(150, 60), sf::Vector2f(window.getSize().x - 180, 300));
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
		window.draw(obxod_binary_tree);
		window.draw(obxod_1_name);
		window.draw(obxod_1_value);
		window.draw(obxod_2_name);
		window.draw(obxod_2_value);
		window.display();
	}
}

template <class T>
void all_actions_to_bypass(Graph<T>& Graf_1) {//функция для обходов дерева
	std::string vertex = enter_the_data(L"Введите вершину, с которой реализовать обходы");
	if (string_to_int_bool(vertex)) {
		int vert_int = string_to_int(vertex);//вершина
		int index_vert = Graf_1.get_vert_pos(vert_int);
		if (index_vert != -1) {
			Graph_traversal(Graf_1, vert_int);
		}
		else {
			error_or_success_message(L"Такой вершины нет!", L"Ошибка");
		}
	}
	else {
		error_or_success_message(L"Такой вершины нет!", L"Ай-ай-ай");
	}
}

template <class T>
void running_Dijkstra_algorithm(Graph<T>& Graf_1) {
	std::string vertex = enter_the_data(L"Введите вершину, с которой реализовать алгоритм Дейкстеры");
	if (string_to_int_bool(vertex)) {
		int vert_int = string_to_int(vertex);//вершина
		int index_vert = Graf_1.get_vert_pos(vert_int);
		if (index_vert != -1) {
			if (Graf_1.all_vertices_are_available(vert_int)) {
				std::vector<std::pair<T, int>> vect_of_distances = Graf_1.Dijkstra(vert_int);
				std::vector<std::string> vect_wstring;
				
				for (int i = 0; i < vect_of_distances.size(); i++) {//иду по всем обходам
					//std::string all_str = "от вершины " + vertex + " до вершины " + std::to_string(vect_of_distances[i].first) " = " + std::to_string(vect_of_distances[i].second);
					std::string all_str = "от вершины " + vertex;
					//собираю строку


					//for (int j = 0; j < vector_graf[i].size(); j++) {
					//	std::ostringstream buffet;//обрабатываю число с .
					//	buffet << std::fixed << std::setprecision(0) << vector_graf[i][j];
					//	all_str = all_str + buffet.str() + " ";//собираю строку
					//}
					vect_wstring.push_back(all_str);
					std::cout << vect_wstring[i] << std::endl;
				}
			}
			else {
				error_or_success_message(L"Для данного графа нельзя реализовать алгоритм Дейкстеры(", L"Ошибка");
			}
		}
		else {
			error_or_success_message(L"Такой вершины нет!", L"Ошибка");
		}
	}
	else {
		error_or_success_message(L"Такой вершины нет!", L"Ай-ай-ай");
	}
}

template <class T>
void running_Floyd_algorithm(Graph<T> Graf_1) {//запуск алгоритма флойда
	std::string vertex = enter_the_data(L"Введите вершину, с которой реализовать алгоритм Флойда");
	if (string_to_int_bool(vertex)) {
		int vert_int = string_to_int(vertex);//вершина
		int index_vert = Graf_1.get_vert_pos(vert_int);
		if (index_vert != -1) {
			std::vector<T> vector_graf;
			std::vector<bool> v_bool_1(Graf_1.get_amount_verts(), false);
			Graf_1.DFS(vert_int, v_bool_1, vector_graf);//обход в глубину
			if(vector_graf.size() != 1){
				Graf_1.Floyd();
				std::vector<std::tuple<T, T, std::vector<T>>>  vect_of_way = Graf_1.PrintSP();
				bool flag = true;
				int index_t, count = 0;
				for (int i = 0; i < vect_of_way.size(); i++) {
					if (std::get<0>(vect_of_way[i]) == vert_int) {
						if (flag) {
							index_t = i;
						}
						flag = false;
						count++;
					}	
				}

				std::wstring first_str = L"Кратчайший путь от вершины " + std::to_wstring(vert_int);
				sf::RenderWindow window(sf::VideoMode(600, 270 + count * 40), L"Алгоритм Флойда");

				sf::Font font;
				font.loadFromFile("ofont.ru_Expressway.ttf");//загружаю шрифт

				sf::Text mes;
				mes.setFont(font);
				mes.setString(L"Алгоритм Флойда");
				mes.setFillColor(sf::Color::Black);
				mes.setCharacterSize(40);
				mes.setPosition(30, 15);

				sf::Text text_1;
				text_1.setFont(font);
				text_1.setFillColor(sf::Color::Black);
				text_1.setCharacterSize(40);

				sf::Text text_2;
				text_2.setFont(font);
				text_2.setString(first_str);
				text_2.setFillColor(sf::Color::Black);
				text_2.setCharacterSize(40);
				text_2.setPosition(30, 70);
			
				RectButton button1(sf::Vector2f(150, 60), sf::Vector2f(window.getSize().x / 2 - 75, window.getSize().y - 80));//Вертикальная печать дерева
				button1.setButtonFont(font);
				button1.setButtonLable(L"Ok", sf::Color::Black, 30);

				while (window.isOpen())
				{
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
					window.draw(mes);
					window.draw(text_2);

					int def_pos_y = 80;

					for (int i = index_t; i < vect_of_way.size(); i++) {
						int cur_ver = std::get<0>(vect_of_way[i]);
						if (cur_ver == vert_int) {
							std::wstring second_str = L"  к вершине " + std::to_wstring(std::get<1>(vect_of_way[i])) + L" : ";
							std::vector<T> vect_dist_way = std::get<2>(vect_of_way[i]);
							for (int j = 0; j < vect_dist_way.size(); j++) {
								second_str = second_str + std::to_wstring(vect_dist_way[j]) + L"  ";
							}
							text_1.setString(second_str);
							text_1.setPosition(30, def_pos_y += 40);
							window.draw(text_1);
						}

					}

					window.display();
				}
			}
			else {
				error_or_success_message(L"Вершина ни с чем не связана", L"...");
			}

		}
		else {
			error_or_success_message(L"Такой вершины нет!", L"Ошибка");
		}
	}
	else {
		error_or_success_message(L"Такой вершины нет!", L"Ай-ай-ай");
	}
}


template <class T>
void add_a_vertex_completely(Graph<T>& Graf_1) {
	std::string str_vertex = enter_the_data(L"Введите название вершины, которую хотите добавить (int)");
	if (string_to_int_bool(str_vertex)) {
		int vert_int = string_to_int(str_vertex);//вершина
		if (Graf_1.get_vert_pos(vert_int) == -1) {
			Graf_1.insert_vertex(vert_int);
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
void delete_a_vertex_completely(Graph<T>& Graf_1) {
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
void add_an_edge_completely(Graph<T>& Graf_1) {
	std::string vertex_1, vertex_2, content;
	enter_the_three_data(L"Введите первую вершину", L"Введите вторую вершину", L"Введите расстояние между вершинами", vertex_1, vertex_2, content);
	if (string_to_int_bool(vertex_1) && string_to_int_bool(vertex_2)) {//вершины-числа?
		if (string_to_int_bool(content)) {//расстояние - число?
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

template <class T>
void delete_an_edge_completely(Graph<T>& Graf_1) {
	std::string vertex_1, vertex_2;
	enter_the_two_data(L"Введите первую вершину", L"Введите вторую вершину", vertex_1, vertex_2);
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