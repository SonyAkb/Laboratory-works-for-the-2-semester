#pragma once
#include <vector>
#include <queue>
#include <iomanip>
#include <set>
using namespace std;


template <class T>
class Graph {
private:
	vector<T> vertex_list; //вектор вершин
	vector<vector<int>> adjMatrix;//матрица смежности
	vector<vector<int>> shortest_paths_matrix; //матрица кратчайших расстояний
	vector<vector<int>> second_matrix;//вторая матрица для флойда
	vector<int> label_list;
public:
	Graph(const int& size = 0);//конструктор с размером графа
	~Graph() {};//деструктор
	bool is_empty();//граф пуст?
	void insert_vertex(const T& vert);//вставка вершины
	void erase_vertex(const T& vert);//удаление вершины
	int get_vert_pos(const T& data);//ИНДЕКС вершины с переданными данными
	int get_amount_verts();//количество существующих вершин
	int get_weight(const T& vert_1, const T& vert_2);//вес пути между вершинами
	vector<T> get_neighbors(const T& data);//вектор соседей элемента с переданными данными
	void insert_edge_orient(const T& vert_1, const T& vert_2, int weight = 1); //вставка ребра между двумя узлами - ОРИЕНТИРОВАННЫЙ граф
	//void insert_edge_not_orient(const T& vert_1, const T& vert_2, int weight = 1); //вставка ребра между двумя узлами - НЕ ориентированный граф
	void erase_edge_orient(const T& vert_1, const T& vert_2);//удаление ребра между двумя узлами
	
	void print_matrix();//печать матрицы смежности
	int get_amount_edge_orient();//количество ребер - ОРИЕНТИРОВАННЫЙ граф
	//int get_amount_edge_not_orient();//количество ребер - НЕ ориентированный граф
	vector<T> DFS(T& start_verts, vector<bool>& visited_verts, vector<T>& vect);//обход графа в ГЛУБИНУ
	vector<T> BFS(T& start_verts, vector<bool>& visited_verts, vector<T>& vect);//обход графа в ШИРИНУ
	
	void all_matr() {
		this->print_matrix();

		cout << "Матрица кратчайших расстояний" << endl;
		cout << setw(7) << "*";
		for (int i = 0; i < this->vertex_list.size(); i++) {
			cout << setw(7) << vertex_list[i];
		}
		cout << endl;
		for (int i = 0; i < this->vertex_list.size(); i++) {
			cout << setw(7) << vertex_list[i];
			for (int j = 0; j < this->vertex_list.size(); j++) {
				cout << setw(7) << this->shortest_paths_matrix[i][j];	
			}
			cout << endl;
		}
		cout << endl;
		cout << "Вторая матрица" << endl;
		cout << setw(7) << "*";
		for (int i = 0; i < this->vertex_list.size(); i++) {
			cout << setw(7) << vertex_list[i];
		}
		cout << endl;
		for (int i = 0; i < this->vertex_list.size(); i++) {
			cout << setw(7) << vertex_list[i];
			for (int j = 0; j < this->vertex_list.size(); j++) {
				cout << setw(7) << this->second_matrix[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}
	
	//алгоритм дейкстеры
	void fill_labels(T& start_vertex);//заполнение меток расстояния
	bool all_visited(vector<bool>& visited_verts);//все вершины посещены?
	vector<pair<T,int>> Dijkstra(T& start_vertex);//алгоритм дейкстры
	//void shortestPath(int src);

	//флойд
	void Floyd();
	vector<tuple<T, T, vector<T>>> PrintSP();
};

template <class T>
Graph<T>::Graph(const int& size) {//конструктор с размером графа
	this->adjMatrix = vector<vector<T>>(size, vector<T>(size));//устанавливаю матрицу смежности
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
	vector<int> tmp_1(vertex_list.size(), 0);//вектор с 0 для добавленного узла
	vector<int> tmp_2(vertex_list.size(), 0);
	
	vector<int> tmp_3(vertex_list.size(), 10000);
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
		cout << "Один из узлов не существует" << endl;
		return 0;
	}
	return this->adjMatrix[position_1][position_2];
}

template <class T>
vector<T> Graph<T>::get_neighbors(const T& data) {//вектор соседей элемента с переданными данными, только те соседи куда можно перейти
	vector<T> nbrs_list;//вектор соседей
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
		cout << "Один из узлов не существует" << endl;
		return;
	}
	else {
		int position_1 = this->get_vert_pos(vert_1);//индекс узла
		int position_2 = this->get_vert_pos(vert_2);//индекс узла
		if (this->adjMatrix[position_1][position_2] != 0 && this->adjMatrix[position_1][position_2] != 10000) {
			cout << "Ребро уже есть!!" << endl;
			return;
		}
		else {
			this->adjMatrix[position_1][position_2] = weight;
			this->second_matrix[position_1][position_2] = vert_2;
		}
	}
}
template <class T>
void  Graph<T>::erase_edge_orient(const T& vert_1, const T& vert_2) {
	if (this->get_vert_pos(vert_1) == -1 || this->get_vert_pos(vert_2) == -1) {
		cout << "Один из узлов не существует" << endl;
		return;
	}
	else {
		int position_1 = this->get_vert_pos(vert_1);//индекс узла
		int position_2 = this->get_vert_pos(vert_2);//индекс узла
		this->adjMatrix[position_1][position_2] = 0;
		this->shortest_paths_matrix[position_1][position_2] = 10000;
	}
}

//template <class T>
//void Graph<T>::insert_edge_not_orient(const T& vert_1, const T& vert_2, int weight) { //вставка ребра между двумя узлами
//	if (this->get_vert_pos(vert_1) == -1 || this->get_vert_pos(vert_2) == -1) {
//		cout << "Один из узлов не существует" << endl;
//		return;
//	}
//	else {
//		int position_1 = this->get_vert_pos(vert_1);//индекс узла
//		int position_2 = this->get_vert_pos(vert_2);//индекс узла
//		if (this->adjMatrix[position_1][position_2] != 0 && this->adjMatrix[position_2][position_1] != 0) {
//			cout << "Ребро уже есть!!" << endl;
//			return;
//		}
//		else {
//			this->adjMatrix[position_1][position_2] = weight;
//			this->adjMatrix[position_2][position_1] = weight;
//		}
//	}
//}

template <class T>
void Graph<T>::print_matrix() {//печать матрицы смежности
	if (this->is_empty()) {
		cout << "Граф пуст" << endl;
		return;
	}
	else {
		cout << "Матрица смежности графа" << endl;
		cout << setw(4) << "*";
		for (int i = 0; i < this->vertex_list.size(); i++) {
			cout << setw(4) << vertex_list[i];
		}
		cout << endl;
		for (int i = 0; i < this->vertex_list.size(); i++) {
			cout << setw(4) << vertex_list[i];
			for (int j = 0; j < this->vertex_list.size(); j++) {
				if (this->adjMatrix[i][j] == 10000) {
					cout << "    ";
				}
				else {
					cout << setw(4) << this->adjMatrix[i][j];
				}
			}
			cout << endl;
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

//template <class T>
//int Graph<T>::get_amount_edge_not_orient() {//количество ребер - НЕ ОРИЕНТИРОВАННЫЙ граф
//	int amount = 0;
//	if (!this->is_empty()) {
//		for (int i = 0; i < this->vertex_list.size(); i++) {//иду по строкам
//			for (int j = 0; j < this->vertex_list.size(); j++) {//иду по столбцам
//				if (this->adjMatrix[i][j] != 0) {
//
//					amount++;
//					
//				}
//			}
//		}
//	}
//	return amount / 2;
//}

template <class T>
vector<T> Graph<T>::DFS(T& start_verts, vector<bool>& visited_verts, vector<T>& vect) {//обход графа в глубину
	cout << "Вершина " << start_verts << " посещена" << endl;
	vect.push_back(start_verts);
	visited_verts[this->get_vert_pos(start_verts)] = true;//отмечаю, что вершина посещена
	vector<T> neigbors = this->get_neighbors(start_verts);//соседи данной вершины
	for (int i = 0; i < neigbors.size(); ++i) {
		if (!visited_verts[this->get_vert_pos(neigbors[i])]) {//если узел еще не посещен
			this->DFS(neigbors[i], visited_verts, vect);//посещаю узел
		}
	}
	return vect;
}

template <class T>
vector<T> Graph<T>::BFS(T& start_verts, vector<bool>& visited_verts, vector<T>& vect) {
	queue<T> q; // Используем очередь для хранения вершин
	q.push(start_verts); // Начинаем обход с начальной вершины
	visited_verts[get_vert_pos(start_verts)] = true; // Помечаем начальную вершину как посещенную

	while (!q.empty()) {//пока очередь не опустеет
		T current = q.front();//первый элемент в очереди
		q.pop();//удаляю первый элемент
		cout << "Вершина " << current << " обработана" << endl; // Выводим текущую вершину
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


template <class T>
void Graph<T>::fill_labels(T& start_vertex) {//заполнение меток расстояния
	vector<int> tmp_1(this->vertex_list.size(), 1000000);//метки расстояния
	this->label_list = tmp_1;//устанавливаю
	int pos = this->get_vert_pos(start_vertex);//считываю позицию индекс начальной вершины
	cout << "начальная вершина " << pos << endl;
	this->label_list[pos] = 0;//начальная вершина, поэтому 0
}

template <class T>
bool Graph<T>::all_visited(vector<bool>& visited_verts) {//все вершины посещены?
	bool flag = true;
	for (int i = 0; i < this->vertex_list.size() && flag; i++) {//прохожу по всем вершинам
		if (visited_verts[i] != true) {//проверяю каждую вершину на посещение
			flag = false;
		}
	}

	for (int i = 0; i < this->vertex_list.size(); i++) {//прохожу по всем вершинам
		cout << visited_verts[i] << " ";
	}

	cout << endl << "-------" << endl;
	return flag;
}

template <class T>
vector<pair<T, int>> Graph<T>::Dijkstra(T& start_vertex) {//алгоритм дейкстры
	vector<pair<T, int>> vect_of_distances;
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
	vector<bool> visited_verts(this->vertex_list.size(), false);
	//vector<bool> visited_verts(this->vertex_list.size());
	//fill(visited_verts.begin(), visited_verts.end(), false);
	

	this->fill_labels(start_vertex);
	T current_src = start_vertex;
	vector<T> neighbors;
	//T* min_neighbor_ptr = nullptr;


	while (!this->all_visited(visited_verts)) {

		neighbors = this->get_neighbors(current_src);
		//cout << "neighbors" << neighbors[0] << " " << neighbors[1] << " " << neighbors[2] << " " << endl;
		int start_label = this->label_list[this->get_vert_pos(current_src)];
		//cout << "start_label" << start_label << endl;
		//T* min_neighbor_ptr = nullptr;//самый близкий сосед
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
	pair<T, int> para_dist;
	for (int i = 0; i < this->get_vert_pos(start_vertex); i++) {
		cout << "Кратчайшее расстояние от вершины " << start_vertex <<
			" до вершины " << vertex_list[i] << " равно " <<
			label_list[this->get_vert_pos(this->vertex_list[i])] << endl;
		para_dist.first = vertex_list[i];
		para_dist.second = label_list[this->get_vert_pos(this->vertex_list[i])];
		vect_of_distances.push_back(para_dist);
	}
	for (int i = this->get_vert_pos(start_vertex) + 1; i < this->vertex_list.size(); i++) {
		cout << "Кратчайшее расстояние от вершины " << start_vertex <<
			" до вершины " << vertex_list[i] << " равно " <<
			label_list[this->get_vert_pos(this->vertex_list[i])] << endl;
		para_dist.first = vertex_list[i];
		para_dist.second = label_list[this->get_vert_pos(this->vertex_list[i])];
		vect_of_distances.push_back(para_dist);
	}
	return vect_of_distances;
}

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
vector<tuple<T, T, vector<T>>> Graph<T>::PrintSP() {
	int cur = 0, col = 0;
	vector<tuple<T, T, vector<T>>> vector_of_dists;
	for (int i = 0, size = this->vertex_list.size(); i < size; ++i) {
		std::cout << "Кратчайший путь от вершины " << this->vertex_list[i]; // Вывод исходной вершины на экран
		for (int j = 0; j < size; ++j) {
			
			if (this->second_matrix[i][j] != 0) {// Проверка, что есть следующая(промежуточная) вершина
				col = j;// Запоминаем конечную вершину (в которую идем) 
				
				cur = this->second_matrix[i][j];// Присвоение в cur промежуточной вершины
				

				std::cout << " к вершине " << this->vertex_list[j]	<< ": ";// Вывод промежуточной вершины на экран
				std::cout << this->vertex_list[i] << " ";//Вывод на экран исходной вершины
				vector<T> vect_of_way;
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
				/*cout << endl;
				for (int i = 0; i < vect_of_way.size(); i++) {
					cout << vect_of_way[i] << " ";
				}
				cout << endl;*/

				std::cout << std::endl;
				std::tuple < T, T, vector<T>> tuple_1(this->vertex_list[i], this->vertex_list[j], vect_of_way);
				vector_of_dists.push_back(tuple_1);
			}
			
			//std::tuple<int, std::string> t2(1, "hello");
		}
		std::cout << std::endl;
	}
	return vector_of_dists;
}