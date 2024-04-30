#include <SFML/Graphics.hpp>
#include "Graph.h"
#include "other functions.h"

sf::Font jackInput;

int main() {
    system("chcp 1251 > Null");

    Graph<int> Graf_2;//создаю граф

    Graf_2.insert_vertex(1);
    Graf_2.insert_vertex(2);
    Graf_2.insert_vertex(3);
    Graf_2.insert_vertex(4);
    Graf_2.insert_vertex(5);
    Graf_2.insert_vertex(6);


    Graf_2.insert_edge_orient(1, 3, 13);
    Graf_2.insert_edge_orient(1, 4, 15);
    Graf_2.insert_edge_orient(2, 4, 20);
    Graf_2.insert_edge_orient(2, 1, 28);
    Graf_2.insert_edge_orient(3, 5, 30);
    Graf_2.insert_edge_orient(4, 6, 31);
    Graf_2.insert_edge_orient(4, 5, 39);
    Graf_2.insert_edge_orient(5, 4, 39);
    Graf_2.insert_edge_orient(5, 2, 21);
    Graf_2.insert_edge_orient(6, 1, 18);

    sf::RenderWindow window(sf::VideoMode(1000, 570), "Graph - menu");//главное окно
    jackInput.loadFromFile("ofont.ru_Nikoleta.ttf");
    int tmp_size_y = window.getSize().y / 2 - 230;

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
    button_6.setButtonLable(L"Добавить(Изменить) ребро", text_color, 30);

    RectButton button_7(sf::Vector2f(360, 40), sf::Vector2f(20, tmp_size_y += 50));
    button_7.setButtonFont(jackInput);
    button_7.setButtonLable(L"Удалить ребро из графа", text_color, 30);

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
                        running_Dijkstra_algorithm(Graf_2);
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
                        delete_an_edge_completely(Graf_2);
                    }
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
        button_exit.draw(window);

        window.display();
    }
}
