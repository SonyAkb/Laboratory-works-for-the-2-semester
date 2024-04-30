#include <iostream>
#include <SFML/Graphics.hpp>
#include "Graph.h"
#include "other functions.h"


sf::Font jackInput;

int main() {
    system("chcp 1251 > Null");
    std::cout << "Hello World!\n";

    Graph<int> Graf_1;
    Graph<int> Graf_2;

    //cout << Graf_1.get_amount_verts() << endl;

    int amount_verys, amount_edges;
    int tmp_1, tmp_2;

    Graf_2.insert_vertex(1);
    Graf_2.insert_vertex(2);
    Graf_2.insert_vertex(3);
    Graf_2.insert_vertex(4);
    Graf_2.insert_vertex(5);
    Graf_2.insert_vertex(6);
    //Graf_2.insert_vertex(7);
    //Graf_2.insert_vertex(8);
    /*Graf_2.insert_vertex(9);
    Graf_2.insert_vertex(10);
    Graf_2.insert_vertex(11);
    Graf_2.insert_vertex(12);*/


    Graf_2.insert_edge_orient(1, 3, 13);
    Graf_2.insert_edge_orient(1, 4, 15);
    Graf_2.insert_edge_orient(2, 4, 20);
    Graf_2.insert_edge_orient(2, 1, 28);
    Graf_2.insert_edge_orient(3, 5, 30);
    //Graf_2.insert_edge_orient(7, 8, 20);

    Graf_2.all_matr();
    Graf_2.Floyd();
    Graf_2.PrintSP();

    Graf_2.insert_edge_orient(4, 6, 31);
    Graf_2.insert_edge_orient(4, 5, 39);
    Graf_2.insert_edge_orient(5, 4, 39);
    Graf_2.insert_edge_orient(5, 2, 21);
    Graf_2.insert_edge_orient(6, 1, 18);
    

    Graf_2.all_matr();
    std::cout << std::endl;
    std::cout << std::endl;
    

    Graf_2.erase_edge_orient(6, 5);

    Graf_2.all_matr();
    std::cout << std::endl;
    std::cout << std::endl;
    Graf_2.print_matrix();
    //Graf_2.erase_vertex(2);
    Graf_2.print_matrix();
    std::cout << std::endl;
    tmp_1 = 6;

    std::cout << "количество ребер " << Graf_2.get_amount_edge_orient() << std::endl;
    std::cout << "соседи " << std::endl;
    std::vector<bool> vect_1(Graf_2.get_amount_verts(), false);


    std::vector<int> vect_1_1;
    vect_1_1 = Graf_2.DFS(tmp_1, vect_1, vect_1_1);

    for (int i = 0; i < vect_1_1.size(); i++) {
        std::cout << vect_1_1[i] << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    //Graf_2.Dijkstra_1(tmp_1);

    /*std::vector<bool> vect_2(6, false);
    std::vector<int> vect_2_1;
    vect_2_1 = Graf_2.BFS(tmp_1, vect_2, vect_2_1);
    for (int i = 0; i < vect_2_1.size(); i++) {
        std::cout << vect_2_1[i] << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
    int tmp_5 = 5;
    std::vector<std::pair<int,int>> vect_pair = Graf_2.Dijkstra(tmp_5);
    for (int i = 0; i < vect_pair.size(); i++) {
        std::cout << vect_pair[i].first << " " << vect_pair[i].second << std::endl;
    }
    std::cout << std::endl;
    std::cout << "-----------------"<< std::endl;

    Graf_2.Floyd();
    Graf_2.PrintSP();
    std::vector<std::tuple<int, int, std::vector<int>>> vector_of_dists = Graf_2.PrintSP();

    for (int i = 0; i < vector_of_dists.size(); i++) {
        std::cout << std::get<0>(vector_of_dists[i]) << " " << std::get<1>(vector_of_dists[i]) << ": ";
        for (int j = 0; j < (std::get<2>(vector_of_dists[i]).size()); j++) {
            std::cout << (std::get<2>(vector_of_dists[i]))[j] << " ";
        }
        std::cout << std::endl;
        if (i != vector_of_dists.size() - 1) {
            if (std::get<0>(vector_of_dists[i]) != std::get<0>(vector_of_dists[i + 1])) {
                std::cout << "***" << std::endl;
            }
        }
    }*/


    sf::RenderWindow window(sf::VideoMode(1000, 570), "Graph - menu");//главное окно
    jackInput.loadFromFile("ofont.ru_Nikoleta.ttf");
    int tmp_size_y = window.getSize().y / 2 - 265;

    sf::Text menu;
    menu.setFont(jackInput);
    menu.setString(L"Меню");
    menu.setFillColor(text_color);
    menu.setCharacterSize(40);
    menu.setPosition(150, tmp_size_y);

    

    RectButton button_1(sf::Vector2f(360, 40), sf::Vector2f(20, tmp_size_y+= 50));
    button_1.setButtonFont(jackInput);
    button_1.setButtonLable(L"Обходы графа", text_color, 30);

    RectButton button_2(sf::Vector2f(360, 40), sf::Vector2f(20, tmp_size_y += 50));
    button_2.setButtonFont(jackInput);
    button_2.setButtonLable(L"Алгоритм Дейкстеры", text_color, 30);

    RectButton button_3(sf::Vector2f(360, 40), sf::Vector2f(20, tmp_size_y += 50)); 
    button_3.setButtonFont(jackInput);
    button_3.setButtonLable(L"Алгоритм Флойда", text_color, 30);

    RectButton button_4(sf::Vector2f(360, 40), sf::Vector2f(20, tmp_size_y += 50));
    button_4.setButtonFont(jackInput);
    button_4.setButtonLable(L"Добавить вершину в граф", text_color, 30);

    RectButton button_5(sf::Vector2f(360, 40), sf::Vector2f(20, tmp_size_y += 50));
    button_5.setButtonFont(jackInput);
    button_5.setButtonLable(L"Удалить вершину из графа", text_color, 30);

    RectButton button_6(sf::Vector2f(360, 40), sf::Vector2f(20, tmp_size_y += 50));
    button_6.setButtonFont(jackInput);
    button_6.setButtonLable(L"Добавить ребро в граф", text_color, 30);

    RectButton button_7(sf::Vector2f(360, 40), sf::Vector2f(20, tmp_size_y += 50));
    button_7.setButtonFont(jackInput);
    button_7.setButtonLable(L"Удалить ребро из графа", text_color, 30);

    RectButton button_8(sf::Vector2f(360, 40), sf::Vector2f(20, tmp_size_y += 50));
    button_8.setButtonFont(jackInput);
    button_8.setButtonLable(L"Изменить вес ребра", text_color, 30);

    RectButton button_exit(sf::Vector2f(360, 40), sf::Vector2f(20, tmp_size_y += 80));
    button_exit.setButtonFont(jackInput);
    button_exit.setButtonLable(L"Выход", text_color, 30);

    while (window.isOpen()) {
        sf::Vector2i mousePoz = sf::Mouse::getPosition(window);//позиция мыши в окне

        sf::Event event;

        button_1.getButtonStatus(window, event);
        button_2.getButtonStatus(window, event);
        button_3.getButtonStatus(window, event);
        button_4.getButtonStatus(window, event);
        button_5.getButtonStatus(window, event);
        button_6.getButtonStatus(window, event);
        button_7.getButtonStatus(window, event);
        button_8.getButtonStatus(window, event);
        button_exit.getButtonStatus(window, event);

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.key.code == sf::Mouse::Left) {
                    if (button_exit.isPressed) {
                        window.close();
                    }
                    else if (button_1.isPressed) {//обходы дерева
                        all_actions_to_bypass(Graf_2);
                    }
                    else if (button_2.isPressed) {//алгоритм дейкстеры
                        //running_Dijkstra_algorithm(Graf_2);
                    }
                    else if (button_3.isPressed) {
                        running_Floyd_algorithm(Graf_2);
                    }
                    else if (button_4.isPressed) {//Добавить вершину в граф
                        add_a_vertex_completely(Graf_2);
                    }
                    else if (button_5.isPressed) {//удалить вершину
                        delete_a_vertex_completely(Graf_2);
                    }
                    else if (button_6.isPressed) {//добавить ребро
                        add_an_edge_completely(Graf_2);
                    }
                    else if (button_7.isPressed) {//удалить ребро
                        error_or_success_message(L"цццццц", L"ууууууу");
                    }
                    

                    //window.setSize(sf::Vector2u(640, 480));//изменение размера окна
                }
            }

        }
        window.clear(background_color);

        Graf_2.Draw(window);
        window.draw(menu);
        button_1.draw(window);
        button_2.draw(window);
        button_3.draw(window);
        button_4.draw(window);
        button_5.draw(window);
        button_6.draw(window);
        button_7.draw(window);
        button_8.draw(window);
        button_exit.draw(window);

        window.display();
    }
}
