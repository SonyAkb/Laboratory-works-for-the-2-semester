#include <SFML/Graphics.hpp>
#include <iostream>
#include "Tree.h"
#include "other functions.h"
#include "textbox.hpp"
#include "sfml_button.hpp"

using namespace std;

sf::Font jackInput;

int main() {
    system("chcp 1251 > Null");
    sf::RenderWindow window(sf::VideoMode(750, 570), "Binary tree - menu");//главное окно
    jackInput.loadFromFile("ofont.ru_American TextC.ttf");

    Text menu;
    menu.setFont(jackInput);
    menu.setString(L"Меню");
    menu.setFillColor(Color(39, 16, 7));
    menu.setCharacterSize(40);
    menu.setPosition(320, 10);

    RectButton button_1(sf::Vector2f(340, 40), sf::Vector2f(205, 70));//Вертикальная печать дерева
    button_1.setButtonFont(jackInput);
    button_1.setButtonLable(L"Вертикальная печать дерева", text_color, 30);

    RectButton button_2(sf::Vector2f(340, 40), sf::Vector2f(205, 120));//Горизонтальная печать дерева
    button_2.setButtonFont(jackInput);
    button_2.setButtonLable(L"Горизонтальная печать дерева", text_color, 30);

    RectButton button_3(sf::Vector2f(340, 40), sf::Vector2f(205, 170)); //Обходы бинарного дерева
    button_3.setButtonFont(jackInput);
    button_3.setButtonLable(L"Обходы бинарного дерева", text_color, 30);

    RectButton button_4(sf::Vector2f(340, 40), sf::Vector2f(205, 220)); //Вставка узла в дерево
    button_4.setButtonFont(jackInput);
    button_4.setButtonLable(L"Добавить узел в дерево", text_color, 30);

    RectButton button_5(sf::Vector2f(340, 40), sf::Vector2f(205, 270)); //Удаление узла из дерева дерева
    button_5.setButtonFont(jackInput);
    button_5.setButtonLable(L"Удалить узел из дерева", text_color, 30);

    RectButton button_6(sf::Vector2f(340, 40), sf::Vector2f(205, 320)); //теперь это дерево поиска
    button_6.setButtonFont(jackInput);
    button_6.setButtonLable(L"Сделать деревом поиска", text_color, 30);

    RectButton button_7(sf::Vector2f(340, 40), sf::Vector2f(205, 370)); //Найти минимальный элемент
    button_7.setButtonFont(jackInput);
    button_7.setButtonLable(L"Найти минимальный элемент", text_color, 30);

    RectButton button_8(sf::Vector2f(340, 40), sf::Vector2f(205, 420)); //Найти элемент по ключу
    button_8.setButtonFont(jackInput);
    button_8.setButtonLable(L"Найти элемент по ключу", text_color, 30);

    RectButton button_exit(sf::Vector2f(340, 40), sf::Vector2f(205, 500)); //Найти элемент по ключу
    button_exit.setButtonFont(jackInput);
    button_exit.setButtonLable(L"Выход", text_color, 30);

    bool flag = false;

    Tree<double>* root_1 = new Tree<double>;

    vector<double> vect_node{ 20,14,2,78,56,3,-10 };
    root_1 = root_1->build_balanced_bst(vect_node, 0, vect_node.size() - 1);//строю дерево

    while (window.isOpen())
    {
        Vector2i mousePoz = Mouse::getPosition(window);//позиция мыши в окне

        sf::Event event;

        button_1.getButtonStatus(window, event);
        button_2.getButtonStatus(window, event);
        button_3.getButtonStatus(window, event);
        button_4.getButtonStatus(window, event);
        button_5.getButtonStatus(window, event);
        button_6.getButtonStatus(window, event);
        if (flag) {//если дерево поиска
            button_7.getButtonStatus(window, event);
            button_8.getButtonStatus(window, event);
        }
        button_exit.getButtonStatus(window, event);

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == Event::MouseButtonPressed) {
                if (event.key.code == Mouse::Left) {
                    if (button_1.isPressed) {
                        root_1->Draw(L"Вертикальный вывод дерева", true);
                    }
                    else if (button_2.isPressed) {
                        root_1->Draw(L"Горизонтальный вывод дерева", false);
                    }
                    else if (button_3.isPressed) {
                        tree_traversal(root_1);
                    }
                    else if (button_4.isPressed) {
                        if (!flag) {
                            root_1 = add_node_to_tree_not_find(root_1);
                        }
                        else {
                            root_1 = add_node_to_tree_find(root_1);
                        }
                    }
                    else if (button_5.isPressed) {
                        root_1 = delete_node_from_tree(root_1);
                    }
                    else if (button_6.isPressed) {
                        root_1 = root_1->create_bst_from_balanced_tree(root_1);
                        flag = true;
                        error_or_success_message(L"Операция успешно завершена!", L"Успех");
                    }
                    else if (button_7.isPressed) {
                        root_1->find_by_min();
                    }
                    else if (button_8.isPressed) {
                        root_1->find_node_by_key();
                    }
                    else if (button_exit.isPressed) {
                        window.close();
                    }
                }
            }

        }
        window.clear(background_color);

        window.draw(menu);
        button_1.draw(window);
        button_2.draw(window);
        button_3.draw(window);
        button_4.draw(window);
        button_5.draw(window);
        button_6.draw(window);
        if (flag) {//если дерево поиска
            button_7.draw(window);
            button_8.draw(window);
        }
        button_exit.draw(window);

        window.display();
    }

    return 0;
}

