#pragma once
#include <vector>
#include <queue>
#include <iomanip>
#include <set>
using namespace std;


template <class T>
class Graph {
private:
	vector<T> vertex_list; //������ ������
	vector<vector<int>> adjMatrix;//������� ���������
	vector<vector<int>> shortest_paths_matrix; //������� ���������� ����������
	vector<vector<int>> second_matrix;//������ ������� ��� ������
	vector<int> label_list;
public:
	Graph(const int& size = 0);//����������� � �������� �����
	~Graph() {};//����������
	bool is_empty();//���� ����?
	void insert_vertex(const T& vert);//������� �������
	void erase_vertex(const T& vert);//�������� �������
	int get_vert_pos(const T& data);//������ ������� � ����������� �������
	int get_amount_verts();//���������� ������������ ������
	int get_weight(const T& vert_1, const T& vert_2);//��� ���� ����� ���������
	vector<T> get_neighbors(const T& data);//������ ������� �������� � ����������� �������
	void insert_edge_orient(const T& vert_1, const T& vert_2, int weight = 1); //������� ����� ����� ����� ������ - ��������������� ����
	//void insert_edge_not_orient(const T& vert_1, const T& vert_2, int weight = 1); //������� ����� ����� ����� ������ - �� ��������������� ����
	void erase_edge_orient(const T& vert_1, const T& vert_2);//�������� ����� ����� ����� ������
	
	void print_matrix();//������ ������� ���������
	int get_amount_edge_orient();//���������� ����� - ��������������� ����
	//int get_amount_edge_not_orient();//���������� ����� - �� ��������������� ����
	vector<T> DFS(T& start_verts, vector<bool>& visited_verts, vector<T>& vect);//����� ����� � �������
	vector<T> BFS(T& start_verts, vector<bool>& visited_verts, vector<T>& vect);//����� ����� � ������
	
	void all_matr() {
		this->print_matrix();

		cout << "������� ���������� ����������" << endl;
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
		cout << "������ �������" << endl;
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
	
	//�������� ���������
	void fill_labels(T& start_vertex);//���������� ����� ����������
	bool all_visited(vector<bool>& visited_verts);//��� ������� ��������?
	vector<pair<T,int>> Dijkstra(T& start_vertex);//�������� ��������
	//void shortestPath(int src);

	//�����
	void Floyd();
	vector<tuple<T, T, vector<T>>> PrintSP();
};

template <class T>
Graph<T>::Graph(const int& size) {//����������� � �������� �����
	this->adjMatrix = vector<vector<T>>(size, vector<T>(size));//������������ ������� ���������
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
	vector<int> tmp_1(vertex_list.size(), 0);//������ � 0 ��� ������������ ����
	vector<int> tmp_2(vertex_list.size(), 0);
	
	vector<int> tmp_3(vertex_list.size(), 10000);
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
		cout << "���� �� ����� �� ����������" << endl;
		return 0;
	}
	return this->adjMatrix[position_1][position_2];
}

template <class T>
vector<T> Graph<T>::get_neighbors(const T& data) {//������ ������� �������� � ����������� �������, ������ �� ������ ���� ����� �������
	vector<T> nbrs_list;//������ �������
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
		cout << "���� �� ����� �� ����������" << endl;
		return;
	}
	else {
		int position_1 = this->get_vert_pos(vert_1);//������ ����
		int position_2 = this->get_vert_pos(vert_2);//������ ����
		if (this->adjMatrix[position_1][position_2] != 0 && this->adjMatrix[position_1][position_2] != 10000) {
			cout << "����� ��� ����!!" << endl;
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
		cout << "���� �� ����� �� ����������" << endl;
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
		cout << "���� ����" << endl;
		return;
	}
	else {
		cout << "������� ��������� �����" << endl;
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
vector<T> Graph<T>::DFS(T& start_verts, vector<bool>& visited_verts, vector<T>& vect) {//����� ����� � �������
	cout << "������� " << start_verts << " ��������" << endl;
	vect.push_back(start_verts);
	visited_verts[this->get_vert_pos(start_verts)] = true;//�������, ��� ������� ��������
	vector<T> neigbors = this->get_neighbors(start_verts);//������ ������ �������
	for (int i = 0; i < neigbors.size(); ++i) {
		if (!visited_verts[this->get_vert_pos(neigbors[i])]) {//���� ���� ��� �� �������
			this->DFS(neigbors[i], visited_verts, vect);//������� ����
		}
	}
	return vect;
}

template <class T>
vector<T> Graph<T>::BFS(T& start_verts, vector<bool>& visited_verts, vector<T>& vect) {
	queue<T> q; // ���������� ������� ��� �������� ������
	q.push(start_verts); // �������� ����� � ��������� �������
	visited_verts[get_vert_pos(start_verts)] = true; // �������� ��������� ������� ��� ����������

	while (!q.empty()) {//���� ������� �� ��������
		T current = q.front();//������ ������� � �������
		q.pop();//������ ������ �������
		cout << "������� " << current << " ����������" << endl; // ������� ������� �������
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
	vector<int> tmp_1(this->vertex_list.size(), 1000000);//����� ����������
	this->label_list = tmp_1;//������������
	int pos = this->get_vert_pos(start_vertex);//�������� ������� ������ ��������� �������
	cout << "��������� ������� " << pos << endl;
	this->label_list[pos] = 0;//��������� �������, ������� 0
}

template <class T>
bool Graph<T>::all_visited(vector<bool>& visited_verts) {//��� ������� ��������?
	bool flag = true;
	for (int i = 0; i < this->vertex_list.size() && flag; i++) {//������� �� ���� ��������
		if (visited_verts[i] != true) {//�������� ������ ������� �� ���������
			flag = false;
		}
	}

	for (int i = 0; i < this->vertex_list.size(); i++) {//������� �� ���� ��������
		cout << visited_verts[i] << " ";
	}

	cout << endl << "-------" << endl;
	return flag;
}

template <class T>
vector<pair<T, int>> Graph<T>::Dijkstra(T& start_vertex) {//�������� ��������
	vector<pair<T, int>> vect_of_distances;
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
	pair<T, int> para_dist;
	for (int i = 0; i < this->get_vert_pos(start_vertex); i++) {
		cout << "���������� ���������� �� ������� " << start_vertex <<
			" �� ������� " << vertex_list[i] << " ����� " <<
			label_list[this->get_vert_pos(this->vertex_list[i])] << endl;
		para_dist.first = vertex_list[i];
		para_dist.second = label_list[this->get_vert_pos(this->vertex_list[i])];
		vect_of_distances.push_back(para_dist);
	}
	for (int i = this->get_vert_pos(start_vertex) + 1; i < this->vertex_list.size(); i++) {
		cout << "���������� ���������� �� ������� " << start_vertex <<
			" �� ������� " << vertex_list[i] << " ����� " <<
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
vector<tuple<T, T, vector<T>>> Graph<T>::PrintSP() {
	int cur = 0, col = 0;
	vector<tuple<T, T, vector<T>>> vector_of_dists;
	for (int i = 0, size = this->vertex_list.size(); i < size; ++i) {
		std::cout << "���������� ���� �� ������� " << this->vertex_list[i]; // ����� �������� ������� �� �����
		for (int j = 0; j < size; ++j) {
			
			if (this->second_matrix[i][j] != 0) {// ��������, ��� ���� ���������(�������������) �������
				col = j;// ���������� �������� ������� (� ������� ����) 
				
				cur = this->second_matrix[i][j];// ���������� � cur ������������� �������
				

				std::cout << " � ������� " << this->vertex_list[j]	<< ": ";// ����� ������������� ������� �� �����
				std::cout << this->vertex_list[i] << " ";//����� �� ����� �������� �������
				vector<T> vect_of_way;
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
				std::tuple < T, T, vector<T>> tuple_1(this->vertex_list[i], this->vertex_list[j], vect_of_way);
				vector_of_dists.push_back(tuple_1);
			}
			
			//std::tuple<int, std::string> t2(1, "hello");
		}
		std::cout << std::endl;
	}
	return vector_of_dists;
}