#include <iostream>
#include <SFML/Graphics.hpp>
#include "Graph.h"
using namespace std;

int main() {
    system("chcp 1251 > Null");
    cout << "Hello World!\n";

    Graph<int> Graf_1;
    Graph<int> Graf_2;

    //cout << Graf_1.get_amount_verts() << endl;

    int amount_verys, amount_edges;
    int tmp_1, tmp_2;

    Graf_2.insert_vertex(1);
    Graf_2.insert_vertex(2);
    Graf_2.insert_vertex(3);
    Graf_2.insert_vertex(6);
    Graf_2.insert_vertex(5);
    Graf_2.insert_vertex(4);

    Graf_2.insert_edge_orient(1, 3, 13);
    Graf_2.insert_edge_orient(1, 4, 15);
    Graf_2.insert_edge_orient(2, 4, 20);
    Graf_2.insert_edge_orient(2, 1, 28);
    Graf_2.insert_edge_orient(3, 5, 30);

    Graf_2.all_matr();
    Graf_2.Floyd();
    Graf_2.PrintSP();

    Graf_2.insert_edge_orient(4, 6, 31);
    Graf_2.insert_edge_orient(4, 5, 39);
    Graf_2.insert_edge_orient(5, 4, 39);
    Graf_2.insert_edge_orient(5, 2, 21);
    Graf_2.insert_edge_orient(6, 1, 18);
    

    Graf_2.all_matr();
    cout << endl;
    cout << endl;
    
    Graf_2.erase_vertex(7);
    //Graf_2.erase_edge_orient(6, 5);

    Graf_2.all_matr();
    cout << endl;
    cout << endl;
    //Graf_2.print_matrix();
    //Graf_2.erase_vertex(2);
    //Graf_2.print_matrix();
    cout << endl;
    tmp_1 = 2;

    cout << "количество ребер " << Graf_2.get_amount_edge_orient() << endl;
    cout << "соседи " << endl;
    vector<bool> vect_1(6, false);


    vector<int> vect_1_1;
    vect_1_1 = Graf_2.DFS(tmp_1, vect_1, vect_1_1);

    for (int i = 0; i < vect_1_1.size(); i++) {
        cout << vect_1_1[i] << " ";
    }
    cout << endl;
    cout << endl;


    vector<bool> vect_2(6, false);
    vector<int> vect_2_1;
    vect_2_1 = Graf_2.BFS(tmp_1, vect_2, vect_2_1);
    for (int i = 0; i < vect_2_1.size(); i++) {
        cout << vect_2_1[i] << " ";
    }
    cout << endl;
    cout << endl;
    int tmp_5 = 5;
    vector<pair<int,int>> vect_pair = Graf_2.Dijkstra(tmp_5);
    for (int i = 0; i < vect_pair.size(); i++) {
        cout << vect_pair[i].first << " " << vect_pair[i].second << endl;
    }
    cout << endl;
    cout << "-----------------"<<endl;

    Graf_2.Floyd();
    Graf_2.PrintSP();
    vector<tuple<int, int, vector<int>>> vector_of_dists = Graf_2.PrintSP();

    for (int i = 0; i < vector_of_dists.size(); i++) {
        cout << get<0>(vector_of_dists[i]) << " " << get<1>(vector_of_dists[i]) << ": ";
        for (int j = 0; j < (get<2>(vector_of_dists[i]).size()); j++) {
            cout << (get<2>(vector_of_dists[i]))[j] << " ";
        }
        cout << endl;
        if (i != vector_of_dists.size() - 1) {
            if (get<0>(vector_of_dists[i]) != get<0>(vector_of_dists[i + 1])) {
                cout << "***" << endl;
            }
        }
    }

}
