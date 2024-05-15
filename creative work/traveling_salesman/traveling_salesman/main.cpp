#include <SFML/Graphics.hpp>
#include "Graph.h"
#include "other functions.h"

int main() {
    system("chcp 1251 > Null");
    srand(time(0));
    sf::Font jackInput;

    sf::RenderWindow window(sf::VideoMode(1300, 700), "Graph - menu");//������� ����
    jackInput.loadFromFile("ofont.ru_Nikoleta.ttf");
    int tmp_size_y = window.getSize().y / 2 - 310;
   
    Graph<int> Graf_2;//������ ����

    int tmp_1 = 1;
   
    sf::Text explanation;
    explanation.setFont(jackInput);
    explanation.setString(L"");
    explanation.setFillColor(text_color);
    explanation.setCharacterSize(40);
    explanation.setPosition(380, 20);

    sf::Text menu;
    menu.setFont(jackInput);
    menu.setString(L"����");
    menu.setFillColor(text_color);
    menu.setCharacterSize(40);
    menu.setPosition(150, tmp_size_y);

    RectButton button_2(sf::Vector2f(360, 40), sf::Vector2f(20, tmp_size_y += 50));
    button_2.setButtonFont(jackInput);
    button_2.setButtonLable(L"������ ������������", text_color, 30);

    RectButton button_1(sf::Vector2f(360, 40), sf::Vector2f(20, tmp_size_y += 50));
    button_1.setButtonFont(jackInput);
    button_1.setButtonLable(L"������� ���� ��������", text_color, 30);

    RectButton button_10(sf::Vector2f(360, 40), sf::Vector2f(20, tmp_size_y += 50));
    button_10.setButtonFont(jackInput);
    button_10.setButtonLable(L"���� ��� ������������", text_color, 30);

    RectButton button_8(sf::Vector2f(360, 40), sf::Vector2f(20, tmp_size_y += 50));
    button_8.setButtonFont(jackInput);
    button_8.setButtonLable(L"�������� ����", text_color, 30);

    RectButton button_3(sf::Vector2f(360, 40), sf::Vector2f(20, tmp_size_y += 50));
    button_3.setButtonFont(jackInput);
    button_3.setButtonLable(L"�������� �������", text_color, 30);

    RectButton button_4(sf::Vector2f(360, 40), sf::Vector2f(20, tmp_size_y += 50));
    button_4.setButtonFont(jackInput);
    button_4.setButtonLable(L"�������� ������� � ����", text_color, 30);

    RectButton button_5(sf::Vector2f(360, 40), sf::Vector2f(20, tmp_size_y += 50));
    button_5.setButtonFont(jackInput);
    button_5.setButtonLable(L"������� ������� �� �����", text_color, 30);

    RectButton button_9(sf::Vector2f(360, 40), sf::Vector2f(20, tmp_size_y += 50));
    button_9.setButtonFont(jackInput);
    button_9.setButtonLable(L"������������� �������", text_color, 30);

    RectButton button_6(sf::Vector2f(360, 40), sf::Vector2f(20, tmp_size_y += 50));
    button_6.setButtonFont(jackInput);
    button_6.setButtonLable(L"��������(��������) �����", text_color, 30);

    RectButton button_7(sf::Vector2f(360, 40), sf::Vector2f(20, tmp_size_y += 50));
    button_7.setButtonFont(jackInput);
    button_7.setButtonLable(L"������� ����� �� �����", text_color, 30);

    RectButton button_exit(sf::Vector2f(360, 40), sf::Vector2f(20, tmp_size_y += 80));
    button_exit.setButtonFont(jackInput);
    button_exit.setButtonLable(L"�����", text_color, 30);

    bool flag_add_vert = false;//���� �������� �������
    bool flag_move_vert = false;//���� �������� �������
    bool flag_motion_tracking = false;//���� ����������� �������� ����
    bool flag_return_the_normal_but = false;//��� ������� �� ������ ������������ ������ ������������
    bool flag_rename = false;//���� ������������� ��������
    
    int is_it_coord_vert = -1;//������ �������
    int vert_cont_T = -1;//��� �������

    while (window.isOpen()) {
        sf::Vector2i mousePoz = sf::Mouse::getPosition(window);//������� ���� � ����
        sf::Event event;

        button_1.getButtonStatus(window, event);
        button_2.getButtonStatus(window, event);
        button_3.getButtonStatus(window, event);
        button_4.getButtonStatus(window, event);
        button_5.getButtonStatus(window, event);
        button_6.getButtonStatus(window, event);
        button_7.getButtonStatus(window, event);
        button_8.getButtonStatus(window, event);
        button_9.getButtonStatus(window, event);
        button_10.getButtonStatus(window, event);
        button_exit.getButtonStatus(window, event);

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)//�������
                window.close();

            if (flag_add_vert) {//���� ���� �������� �������
                if (event.type == sf::Event::MouseButtonPressed) {//���� ������ ������
                    if (event.key.code == sf::Mouse::Left) {//���� ������ ����� ������
                        flag_add_vert = false;
                        add_a_vertex_completely(Graf_2, sf::Vector2f(mousePoz.x, mousePoz.y));//������� ���� � ������� ������� ����
                        explanation.setString(L"");
                    }
                }
            }
            else if (flag_move_vert) {//���� ���� ����������� ������� 
                if (event.type == sf::Event::MouseButtonPressed) {//���� ���� ������
                    if (event.key.code == sf::Mouse::Left) {//���� ������ ����� ������
                        flag_return_the_normal_but = true;
                        is_it_coord_vert = Graf_2.this_is_node(sf::Vector2f(mousePoz.x, mousePoz.y));//������ ������� 
                        if (is_it_coord_vert != -1) {//���� ������ ������ �������
                            flag_motion_tracking = true;//���� ����������� ��������
                        }
                    }
                }
                if (event.type == sf::Event::MouseMoved && flag_motion_tracking) {//���� ���� �������� � ���� ��������� ��������
                    int vert_cont_T = Graf_2.get_vert_T(is_it_coord_vert);//��� �������
                    Graf_2.change_the_vertex_position(vert_cont_T, sf::Vector2f(mousePoz.x, mousePoz.y));//����� ������������ �������
                }
                if (event.type == sf::Event::MouseButtonReleased && flag_motion_tracking) {//���� ������
                    if (event.key.code == sf::Mouse::Left) {//������ ����� ������
                        flag_motion_tracking = false;//�������� ���� �� ���� �����������
                    }
                }
                if (button_3.isPressed && flag_return_the_normal_but) {//��������� ������� �������
                    flag_move_vert = false;
                    explanation.setString(L"");
                    button_3.setButtonLable(L"�������� �������", text_color, 30);
                    flag_return_the_normal_but = false;
                }
            }
            else if (flag_rename) {//������������� �������
                if (event.type == sf::Event::MouseButtonPressed) {//���� ���� ������
                    if (event.key.code == sf::Mouse::Left) {//���� ������ ����� ������
                        rename_the_vertex_completely(Graf_2, sf::Vector2f(mousePoz.x, mousePoz.y));
                        flag_rename = false;
                        explanation.setString(L"");
                    }
                }
            }
            else {
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.key.code == sf::Mouse::Left) {
                        if (button_exit.isPressed) {
                            window.close();
                        }
                        else if (button_1.isPressed) {//��������� ����
                            a_random_graph(Graf_2, window);//������ ��������� ����
                        }
                        else if (button_2.isPressed) {//�����������
                            traveling_salesman_is_completely(Graf_2);
                        }
                        else if (button_3.isPressed) {//�������� �������

                            flag_move_vert = true;//���� ����������� �������
                            explanation.setString(L"����������� �������");//���������
                            button_3.setButtonLable(L"��������� �������", text_color, 30);
                        }
                        else if (button_4.isPressed) {//�������� ������� � ����
                            flag_add_vert = true;
                            explanation.setString(L"���� �������� �������?");
                        }
                        else if (button_5.isPressed) {//������� �������
                            delete_a_vertex_completely(Graf_2);
                        }
                        else if (button_6.isPressed) {//�������� �����
                            add_an_edge_completely(Graf_2);
                        }
                        else if (button_7.isPressed) {//������� �����
                            delete_an_edge_completely(Graf_2);
                        }
                        else if (button_8.isPressed) {//�������� ����
                            Graf_2.clear_the_graph();
                        }
                        else if (button_9.isPressed) {//������������� �������
                            flag_rename = true;
                            explanation.setString(L"�������� �������");
                        }
                        else if (button_10.isPressed) {//���� �� ���������
                            THE_SAME_GRAPH(Graf_2, window);
                        }
                    }
                }
            }
        }
        window.clear(background_color);
        if (!Graf_2.is_empty()) {//���� ���� �� ������
            Graf_2.Draw(window);
        }
        window.draw(menu);
        window.draw(explanation);
        button_1.draw(window);
        button_2.draw(window);
        button_3.draw(window);
        button_4.draw(window);
        button_5.draw(window);
        button_6.draw(window);
        button_7.draw(window);
        button_8.draw(window);
        button_9.draw(window);
        button_10.draw(window);
        button_exit.draw(window);

        window.display();
    }
}