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
	std::vector<T> vertex_list; //������ ������
	std::vector<std::vector<int>> adjMatrix;//������� ���������
	std::vector<std::vector<int>> shortest_paths_matrix; //������� ���������� ����������
	std::vector<std::vector<int>> second_matrix;//������ ������� ��� ������
	std::vector<int> label_list;
public:
	Graph(const int& size = 0);//����������� � �������� �����
	~Graph() {};//����������
	bool is_empty();//���� ����?
	void insert_vertex(const T& vert);//������� �������
	void erase_vertex(const T& vert);//�������� �������
	int get_vert_pos(const T& data);//������ ������� � ����������� �������
	int get_amount_verts();//���������� ������������ ������
	int get_weight(const T& vert_1, const T& vert_2);//��� ���� ����� ���������
	std::vector<T> get_neighbors(const T& data);//������ ������� �������� � ����������� �������
	void insert_edge_orient(const T& vert_1, const T& vert_2, int weight = 1); //������� ����� ����� ����� ������ - ��������������� ����
	//void insert_edge_not_orient(const T& vert_1, const T& vert_2, int weight = 1); //������� ����� ����� ����� ������ - �� ��������������� ����
	void erase_edge_orient(const T& vert_1, const T& vert_2);//�������� ����� ����� ����� ������
	
	void print_matrix();//������ ������� ���������
	int get_amount_edge_orient();//���������� ����� - ��������������� ����
	//int get_amount_edge_not_orient();//���������� ����� - �� ��������������� ����
	std::vector<T> DFS(T& start_verts, std::vector<bool>& visited_verts, std::vector<T>& vect);//����� ����� � �������
	std::vector<T> BFS(T& start_verts, std::vector<bool>& visited_verts, std::vector<T>& vect);//����� ����� � ������
	
	void all_matr() {
		this->print_matrix();

		std::cout << "������� ���������� ����������" << std::endl;
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
		std::cout << "������ �������" << std::endl;
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
	
	//�������� ���������
	void fill_labels(T& start_vertex);//���������� ����� ����������
	bool all_visited(std::vector<bool>& visited_verts);//��� ������� ��������?
	std::vector<std::pair<T,int>> Dijkstra(T& start_vertex);//�������� ��������
	//�������� ������
	void Floyd();
	std::vector<std::tuple<T, T, std::vector<T>>> PrintSP();

	void Draw(sf::RenderWindow& window);
	void Draw_node(sf::RenderWindow& window, std::map < T, sf::Vector2f>& positions, T vertex);
	void Draw_edge(sf::RenderWindow& window, std::map < T, sf::Vector2f>& positions, T vertex_1, T vertex_2);
};

template <class T>
void Graph<T>::Draw(sf::RenderWindow& window) {
	sf::Vector2u size_window = window.getSize();
	unsigned int width = size_window.x;
	unsigned int height = size_window.y;

	unsigned int zero_x = width / 2 + 170;//�������� ����� ����� �� x
	unsigned int zero_y = height / 2;//�������� ����� ����� �� y

	int default_radius = 80 + this->vertex_list.size() * 15;
	float default_angle = 360 / this->vertex_list.size();
	//std::cout << default_angle << "---" << std::endl;

	std::map<T, sf::Vector2f> Positions;
	int x = 50, y = 50;
	for (int i = 0; i < this->vertex_list.size(); i++) {//��� �� ���� ��������
		Positions[this->vertex_list[i]] = calculating_node_coordinates(sf::Vector2f(zero_x, zero_y - default_radius), sf::Vector2f(zero_x, zero_y), default_angle * i);
		Draw_node(window, Positions, this->vertex_list[i]);
	}

	for (int i = 0; i < this->adjMatrix.size(); i++) {
		for (int j = 0; j < this->adjMatrix.size(); j++) {
			if (this->adjMatrix[i][j] != 0 && this->adjMatrix[i][j] != 10000) {
				Draw_edge(window, Positions, vertex_list[i], vertex_list[j]);
			}
		}
	}
}

template <class T>
void Graph<T>::Draw_node(sf::RenderWindow& window, std::map < T, sf::Vector2f>& positions, T vertex) {
	sf::Vector2f position = positions[vertex];//������� ����
	int radiys = 20;
	sf::CircleShape circle_1(radiys);//��������� ����
	circle_1.setFillColor(button_color);//���� ������ �����
	circle_1.setOutlineColor(text_color);//���� ������� �����
	circle_1.setOutlineThickness(2);//������� �������� �������
	circle_1.setPosition(position.x - radiys, position.y - radiys);//�������

	sf::Text text_1;
	sf::Font font;
	font.loadFromFile("ofont.ru_Expressway.ttf");//�������� �����
	text_1.setFont(font);

	text_1.setString(std::to_string(vertex));//���������� �����
	text_1.setFillColor(text_color);
	text_1.setCharacterSize(radiys);

	sf::FloatRect textRect = text_1.getLocalBounds();//������� �����
	text_1.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	text_1.setPosition(sf::Vector2f(position.x, position.y));


	window.draw(circle_1);//����� ����
	window.draw(text_1);//����� �����
}


template <class T>
void Graph<T>::Draw_edge(sf::RenderWindow& window, std::map < T, sf::Vector2f>& positions, T vertex_1, T vertex_2) {
	sf::Vector2f positions_1 = positions[vertex_1];
	sf::Vector2f positions_2 = positions[vertex_2];

	positions_1 = point_on_the_node_boundary(positions_2, positions_1, 22);
	positions_2 = point_on_the_node_boundary(positions_1, positions_2, 22);
	
	sf::ConvexShape line_2;
	line_2.setPointCount(4);

	if ((positions_1.x < positions_2.x && positions_1.y < positions_2.y) ||
		(positions_1.x > positions_2.x && positions_1.y > positions_2.y)) {
		line_2.setPoint(0, sf::Vector2f(positions_1.x - 2, positions_1.y - 2));
		line_2.setPoint(1, sf::Vector2f(positions_1.x + 2, positions_1.y + 2));

		line_2.setPoint(2, sf::Vector2f(positions_2.x + 2, positions_2.y + 2));
		line_2.setPoint(3, sf::Vector2f(positions_2.x - 2, positions_2.y - 2));

		
	}
	else {
		line_2.setPoint(0, sf::Vector2f(positions_1.x - 1, positions_1.y - 1));
		line_2.setPoint(1, sf::Vector2f(positions_1.x + 1, positions_1.y + 1));

		line_2.setPoint(2, sf::Vector2f(positions_2.x + 1, positions_2.y + 1));
		line_2.setPoint(3, sf::Vector2f(positions_2.x - 1, positions_2.y - 1));

		
	}
	line_2.setFillColor(sf::Color(117, 90, 87));
	
	sf::VertexArray myTriangles(Triangles, 3);
	myTriangles[0].position = Vector2f(positions[vertex_2].x, positions[vertex_2].y);
	myTriangles[1].position = Vector2f(positions[vertex_2].x - 10, positions[vertex_2].y + 20);
	myTriangles[2].position = Vector2f(positions[vertex_2].x - 10, positions[vertex_2].y + 20);

	//sf::VertexArray line(sf::Lines, 2);
	//line[0].position = positions[vertex_1];
	//line[1].position = positions[vertex_2];

	//line[0].position.x -= 1;
	//line[1].position.x -= 1;

	////line[0].position.y -= 1;
	////line[1].position.y -= 1;

	//line[0].color = sf::Color(117, 90, 87);
	//line[1].color = sf::Color(193, 135, 107);

	//for (int i = 0; i < 3; i++) {
	//	line[0].position.x += 1;
	//	line[1].position.x += 1;

	//	//line[0].position.y += 1;
	//	//line[1].position.y += 1;

	//	window.draw(line, 2);
	//}

	window.draw(line_2);
	
}
template <class T>
Graph<T>::Graph(const int& size) {//����������� � �������� �����
	this->adjMatrix = std::vector<std::vector<T>>(size, std::vector<T>(size));//������������ ������� ���������
	for (int i = 0; i < size; i++) {//��� �� �������
		for (int j = 0; j < size; j++) {//��� �� ��������
			this->adjMatrix[i][j] = 0;
		}
	}
}

template <class T>
bool Graph<T>::is_empty() {//���� ����?
	return this->vertex_list.size() == 0;
}

template <class T>
void Graph<T>::insert_vertex(const T& data) {//������� �������
	this->vertex_list.push_back(data);//�������� ����� ���� � ������ ���� �����
	std::vector<int> tmp_1(vertex_list.size(), 0);//������ � 0 ��� ������������ ����
	std::vector<int> tmp_2(vertex_list.size(), 0);
	
	std::vector<int> tmp_3(vertex_list.size(), 10000);
	tmp_3[vertex_list.size() - 1] = 0;
	this->adjMatrix.push_back(tmp_1);//�������� � ������� ����� ������
	this->second_matrix.push_back(tmp_2);
	this->shortest_paths_matrix.push_back(tmp_3);
	for (int i = 0; i < vertex_list.size() - 1; i++) {
		this->adjMatrix[i].push_back(0);//�������� ����� ������� ��� ������ ����
		this->second_matrix[i].push_back(0);

		this->shortest_paths_matrix[i].push_back(10000);

	}
}

template <class T>
void Graph<T>::erase_vertex(const T& data) {//�������� �������
	int index_vert = this->get_vert_pos(data);
	if (index_vert != -1) {//���� ����� ������� ����������
		this->vertex_list.erase(this->vertex_list.begin() + index_vert);//������ ������� �� ������� �����
		
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
int Graph<T>::get_vert_pos(const T& data) {//������ ������� � ����������� �������
	for (int i = 0; i < this->vertex_list.size(); i++) {//��� �� ���� ��������
		if (this->vertex_list[i] == data) {//���� ������� �������
			return i;//��������� ������
		}
	}
	return -1;//���� ����� ������� ���
}

template <class T>
int Graph<T>::get_amount_verts() {//���������� ������������ ������
	return this->vertex_list.size();//������ ������� ������
}

template <class T>
int Graph<T>::get_weight(const T& vert_1, const T& vert_2) {//��� ���� ����� ���������
	if (this->is_empty()) {//���� ��� ������
		return 0;
	}
	int position_1 = this->get_vert_pos(vert_1);//������ ����
	int position_2 = this->get_vert_pos(vert_2);//������ ����
	if (position_1 == -1 || position_2 == -1) {//���� �-� ���� ���
		std::cout << "���� �� ����� �� ����������" << std::endl;
		return 0;
	}
	return this->adjMatrix[position_1][position_2];
}

template <class T>
std::vector<T> Graph<T>::get_neighbors(const T& data) {//������ ������� �������� � ����������� �������, ������ �� ������ ���� ����� �������
	std::vector<T> nbrs_list;//������ �������
	int pos = this->get_vert_pos(data);//������ ���� � ������� ���������
	if (pos != -1) {//���� ���� ����������
		for (int i = 0; i < this->vertex_list.size(); i++) {//������� �� ���� �����
			if (this->adjMatrix[pos][i] != 0 && this->adjMatrix[pos][i] != 10000) {//���� ���� ���� ����� ����������� ����� � �-� ������
				nbrs_list.push_back(this->vertex_list[i]);
			}
		}
	}
	return nbrs_list;
}

template <class T>
void Graph<T>::insert_edge_orient(const T& vert_1, const T& vert_2, int weight) { //������� ����� ����� ����� ������
	if (this->get_vert_pos(vert_1) == -1 || this->get_vert_pos(vert_2) == -1) {
		std::cout << "���� �� ����� �� ����������" << std::endl;
		return;
	}
	else {
		int position_1 = this->get_vert_pos(vert_1);//������ ����
		int position_2 = this->get_vert_pos(vert_2);//������ ����
		if (this->adjMatrix[position_1][position_2] != 0 && this->adjMatrix[position_1][position_2] != 10000) {
			std::cout << "����� ��� ����!!" << std::endl;
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
		std::cout << "���� �� ����� �� ����������" << std::endl;
		return;
	}
	else {
		int position_1 = this->get_vert_pos(vert_1);//������ ����
		int position_2 = this->get_vert_pos(vert_2);//������ ����
		this->adjMatrix[position_1][position_2] = 0;
		this->shortest_paths_matrix[position_1][position_2] = 10000;
	}
}

//template <class T>
//void Graph<T>::insert_edge_not_orient(const T& vert_1, const T& vert_2, int weight) { //������� ����� ����� ����� ������
//	if (this->get_vert_pos(vert_1) == -1 || this->get_vert_pos(vert_2) == -1) {
//		cout << "���� �� ����� �� ����������" << endl;
//		return;
//	}
//	else {
//		int position_1 = this->get_vert_pos(vert_1);//������ ����
//		int position_2 = this->get_vert_pos(vert_2);//������ ����
//		if (this->adjMatrix[position_1][position_2] != 0 && this->adjMatrix[position_2][position_1] != 0) {
//			cout << "����� ��� ����!!" << endl;
//			return;
//		}
//		else {
//			this->adjMatrix[position_1][position_2] = weight;
//			this->adjMatrix[position_2][position_1] = weight;
//		}
//	}
//}

template <class T>
void Graph<T>::print_matrix() {//������ ������� ���������
	if (this->is_empty()) {
		std::cout << "���� ����" << std::endl;
		return;
	}
	else {
		std::cout << "������� ��������� �����" << std::endl;
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
int Graph<T>::get_amount_edge_orient() {//���������� ����� - ��������������� ����
	int amount = 0;
	if (!this->is_empty()) {
		for (int i = 0; i < this->vertex_list.size(); i++) {//��� �� �������
			for (int j = 0; j < this->vertex_list.size(); j++) {//��� �� ��������
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
//int Graph<T>::get_amount_edge_not_orient() {//���������� ����� - �� ��������������� ����
//	int amount = 0;
//	if (!this->is_empty()) {
//		for (int i = 0; i < this->vertex_list.size(); i++) {//��� �� �������
//			for (int j = 0; j < this->vertex_list.size(); j++) {//��� �� ��������
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
std::vector<T> Graph<T>::DFS(T& start_verts, std::vector<bool>& visited_verts, std::vector<T>& vect) {//����� ����� � �������
	std::cout << "������� " << start_verts << " ��������" << std::endl;
	vect.push_back(start_verts);
	visited_verts[this->get_vert_pos(start_verts)] = true;//�������, ��� ������� ��������
	std::vector<T> neigbors = this->get_neighbors(start_verts);//������ ������ �������
	for (int i = 0; i < neigbors.size(); ++i) {
		if (!visited_verts[this->get_vert_pos(neigbors[i])]) {//���� ���� ��� �� �������
			this->DFS(neigbors[i], visited_verts, vect);//������� ����
		}
	}
	return vect;
}

template <class T>
std::vector<T> Graph<T>::BFS(T& start_verts, std::vector<bool>& visited_verts, std::vector<T>& vect) {
	std::queue<T> q; // ���������� ������� ��� �������� ������
	q.push(start_verts); // �������� ����� � ��������� �������
	visited_verts[get_vert_pos(start_verts)] = true; // �������� ��������� ������� ��� ����������

	while (!q.empty()) {//���� ������� �� ��������
		T current = q.front();//������ ������� � �������
		q.pop();//������ ������ �������
		std::cout << "������� " << current << " ����������" << std::endl; // ������� ������� �������
		vect.push_back(current);
		for (int i = 0; i < adjMatrix[get_vert_pos(current)].size(); ++i) {//���� �� ������ ��� �������� � ������ ������� ������
			if (adjMatrix[get_vert_pos(current)][i] > 0 && !visited_verts[i]) {//���� ����� ��������� ���� ������� � ������� ��� �� ��������
				q.push(vertex_list[i]);//�������� ������� � ������� �������� ���������
				visited_verts[i] = true;//�������, ��� ������� ��������
			}
		}
	}
	return vect;
}


template <class T>
void Graph<T>::fill_labels(T& start_vertex) {//���������� ����� ����������
	std::vector<int> tmp_1(this->vertex_list.size(), 1000000);//����� ����������
	this->label_list = tmp_1;//������������
	int pos = this->get_vert_pos(start_vertex);//�������� ������� ������ ��������� �������
	std::cout << "��������� ������� " << pos << std::endl;
	this->label_list[pos] = 0;//��������� �������, ������� 0
}

template <class T>
bool Graph<T>::all_visited(std::vector<bool>& visited_verts) {//��� ������� ��������?
	bool flag = true;
	for (int i = 0; i < this->vertex_list.size() && flag; i++) {//������� �� ���� ��������
		if (visited_verts[i] != true) {//�������� ������ ������� �� ���������
			flag = false;
		}
	}

	for (int i = 0; i < this->vertex_list.size(); i++) {//������� �� ���� ��������
		std::cout << visited_verts[i] << " ";
	}

	std::cout << std::endl << "-------" << std::endl;
	return flag;
}

template <class T>
std::vector<std::pair<T, int>> Graph<T>::Dijkstra(T& start_vertex) {//�������� ��������
	std::vector<std::pair<T, int>> vect_of_distances;
	for (int i = 0; i < this->vertex_list.size(); i++) {
		for (int j = 0; j < this->vertex_list.size(); j++) {
			if (this->adjMatrix[i][j] < 0) {//�������� �� ������������ ���������� ����� ������
				return vect_of_distances;
			}
		}
	}
	if (this->get_vert_pos(start_vertex) == -1) {//�������� �� ������������
		return vect_of_distances;
	}
	std::vector<bool> visited_verts(this->vertex_list.size(), false);
	//vector<bool> visited_verts(this->vertex_list.size());
	//fill(visited_verts.begin(), visited_verts.end(), false);
	

	this->fill_labels(start_vertex);
	T current_src = start_vertex;
	std::vector<T> neighbors;
	//T* min_neighbor_ptr = nullptr;


	while (!this->all_visited(visited_verts)) {

		neighbors = this->get_neighbors(current_src);
		//cout << "neighbors" << neighbors[0] << " " << neighbors[1] << " " << neighbors[2] << " " << endl;
		int start_label = this->label_list[this->get_vert_pos(current_src)];
		//cout << "start_label" << start_label << endl;
		//T* min_neighbor_ptr = nullptr;//����� ������� �����
		T* min_neighbor_ptr = nullptr;//����� ������� �����

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
		std::cout << "���������� ���������� �� ������� " << start_vertex <<
			" �� ������� " << vertex_list[i] << " ����� " <<
			label_list[this->get_vert_pos(this->vertex_list[i])] << std::endl;
		para_dist.first = vertex_list[i];
		para_dist.second = label_list[this->get_vert_pos(this->vertex_list[i])];
		vect_of_distances.push_back(para_dist);
	}
	for (int i = this->get_vert_pos(start_vertex) + 1; i < this->vertex_list.size(); i++) {
		std::cout << "���������� ���������� �� ������� " << start_vertex <<
			" �� ������� " << vertex_list[i] << " ����� " <<
			label_list[this->get_vert_pos(this->vertex_list[i])] << std::endl;
		para_dist.first = vertex_list[i];
		para_dist.second = label_list[this->get_vert_pos(this->vertex_list[i])];
		vect_of_distances.push_back(para_dist);
	}
	return vect_of_distances;
}

template<class T>
void Graph<T>::Floyd() {
	struct Route {
		std::vector<T> Verts; // ������� ��������
		int weight{ 0 }; // ��� ��������
		bool isVertexExists(const T vertex) const {//��������: ������� �������� ����� ��� ������� ��� ���?
			return std::find(Verts.cbegin(), Verts.cend(), vertex) != Verts.cend();
		}
	};
	for (int i = 0, size = this->vertex_list.size(); i < size; ++i) {//������� �� ���� ��������
		std::vector<Route> routes;// ������ ������������ ��������� �� ������� �������
		{
			std::queue<Route> routesToWatch;// ������� ������, ������� ����� ����������� 
			{
				Route route; // �������� ������ ��������
				route.Verts.push_back(this->vertex_list[i]);// ���������� � ������� ������� �������
				routesToWatch.push(route);// ���������� �������� � �������
			}
			while (!routesToWatch.empty()) {// ���� ��������, ���� ������� �� �����
				Route currentRoute = routesToWatch.front();//����������� ��������, ������������ � ������ �������
				routesToWatch.pop();// �������� �������� �� ������ �������
				routes.push_back(currentRoute);// ���������� ������ �������� � ������ ���������
				const T lastRouteVertex = currentRoute.Verts.back();//�������� � ������������� ��������� ������� ��������
				for (const T& neighbor : this->get_neighbors(lastRouteVertex)) {//���� �������� ��� ���� ������� ��������� ������� �������� ���������������� ��������
					if (!currentRoute.isVertexExists(neighbor)) {//���� � ������� �������� ��� �������, �������� � ��������� �������� ��������, �� ������� ����� �������(�����)
						Route routeToWatch = currentRoute;
						routeToWatch.Verts.push_back(neighbor);//����� � �������-����� ���������� ����� ��������� ������� currentRoute
						routeToWatch.weight += this->adjMatrix[this->get_vert_pos(lastRouteVertex)][this->get_vert_pos(neighbor)];//� ������ �������� ������������� ���	(��� ��� � ���� ������ ��� �������� ��� ���� �������)
						routesToWatch.push(routeToWatch);// � ������� ��������� ���� �������-�����
					}
				}
			}
			routes.erase(routes.begin());//�������� ������� �������� �� �������	���������
		}
		// ������ ����������: 
		std::map<T, std::pair<T, int>> shortestRoutes;
		{
			for (const Route& route : routes) {// � ����� ����� �������� ���������� ��������
				const T endVertex = route.Verts.back();//�������� � ������������� ���������	������� ��������
				const T stepVertex = route.Verts[1];//�������� � ������������� ������������� �������, � ������� ���� ������ ���
				/* ����� ���������� shortestRoutes:
				���� ��� �� endVertex ��������� ����� �������� ����,
				�� ��� �� �������; ���� ��� ��� ��� ���
				endVertex, �� �������� ����; ���� �� ����,
				�� �������, �� ��� �������� */
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
		for (const std::pair<const T, std::pair<T, int>>& shortestRoute : shortestRoutes) {// ���� ���������� ������ �������
			const T endVertex = shortestRoute.first;//���������� �������� ������� �������� ���������������� ����������� ����
			const T stepVertex = shortestRoute.second.first;// ���������� ������������� �������
			const int minWeight = shortestRoute.second.second;// ���������� ���� ����������� ��������
			this->shortest_paths_matrix[i][this->get_vert_pos(endVertex)] = minWeight;// ���������� ������ �������
			this->second_matrix[i][this->get_vert_pos(endVertex)] = stepVertex; // ���������� ������ �������
		}
	}
}

template<class T>
std::vector<std::tuple<T, T, std::vector<T>>> Graph<T>::PrintSP() {
	int cur = 0, col = 0;
	std::vector<std::tuple<T, T, std::vector<T>>> vector_of_dists;
	for (int i = 0, size = this->vertex_list.size(); i < size; ++i) {
		std::cout << "���������� ���� �� ������� " << this->vertex_list[i]; // ����� �������� ������� �� �����
		for (int j = 0; j < size; ++j) {
			
			if (this->second_matrix[i][j] != 0) {// ��������, ��� ���� ���������(�������������) �������
				col = j;// ���������� �������� ������� (� ������� ����) 
				
				cur = this->second_matrix[i][j];// ���������� � cur ������������� �������
				

				std::cout << " � ������� " << this->vertex_list[j]	<< ": ";// ����� ������������� ������� �� �����
				std::cout << this->vertex_list[i] << " ";//����� �� ����� �������� �������
				std::vector<T> vect_of_way;
				vect_of_way.push_back(this->vertex_list[i]);
				

				while (cur != 0) {//����, ������� ���� �� ������ �������; � ��� ���������� ������������� �������
					std::cout << cur << " ";// ����� ������� ������������� ������� �� �����
					vect_of_way.push_back(cur);
						if (this->second_matrix[this ->get_vert_pos(cur)][col] != 0) {// ��������, ��� ���� ��������� ������������� �������
							cur = this->second_matrix[this ->get_vert_pos(cur)][col];// ���� ����, �� ��� ������������� � cur
						}
						else { // ���� ���, �� cur ����������, ���� ����������
							cur = 0; 
						}
				}
				/*cout << endl;
				for (int i = 0; i < vect_of_way.size(); i++) {
					cout << vect_of_way[i] << " ";
				}
				cout << endl;*/

				std::cout << std::endl;
				std::tuple < T, T, std::vector<T>> tuple_1(this->vertex_list[i], this->vertex_list[j], vect_of_way);
				vector_of_dists.push_back(tuple_1);
			}
			
			//std::tuple<int, std::string> t2(1, "hello");
		}
		std::cout << std::endl;
	}
	return vector_of_dists;
}