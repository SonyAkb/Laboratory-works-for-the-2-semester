#pragma once
#include <vector>
//#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include "sfml_button.hpp"
#include "textbox.hpp"
#define PI 3.14159265

sf::Color background_color(236, 205, 177);//���
sf::Color button_color(231, 221, 213);//������
sf::Color button_press_color(169, 105, 70);//������ ������
sf::Color text_color(39, 16, 7);//�����

sf::Vector2f calculating_node_coordinates(sf::Vector2f first_point, sf::Vector2f second_point, float angle) {//��������� ���������� 3 �����

	sf::Vector2f third_point;
	float angle_in_radians = angle * (PI / 180);
	third_point.x = std::cos(angle_in_radians) * (first_point.x - second_point.x) - std::sin(angle_in_radians) * (first_point.y - second_point.y) + second_point.x;
	third_point.y = std::sin(angle_in_radians) * (first_point.x - second_point.x) + std::cos(angle_in_radians) * (first_point.y - second_point.y) + second_point.y;

	
	return third_point;
}

double beam_length(sf::Vector2f first_point, sf::Vector2f second_point) {//����� �������
	double dx = second_point.x - first_point.x;
	double dy = second_point.y - first_point.y;
	double distSq = dx * dx + dy * dy;// ��������� ������� ���������� ����� �������
	double length = sqrt(distSq);// ��������� ���������� ������, ����� �������� ����� ����
	return length;
}

sf::Vector2f point_on_the_node_boundary(sf::Vector2f first_point, sf::Vector2f second_point, double minus) {//���������� �� �����
	double distance = beam_length(first_point, second_point) - minus;
	
	double alpha = atan2(second_point.y - first_point.y, second_point.x - first_point.x);// ������� ���� ����� ����� ����� � ���� X
	double x = first_point.x + distance * cos(alpha);
	double y = first_point.y + distance * sin(alpha);
	return sf::Vector2f(x, y);
}

double triangleArea(sf::Vector2f pos_1, sf::Vector2f pos_2, sf::Vector2f pos_3) {// ������� ��� ���������� ������� ������������
	return fabs((pos_1.x * (pos_2.y - pos_3.y) + pos_2.x * (pos_3.y - pos_1.y) + pos_3.x * (pos_1.y - pos_2.y)) / 2.0);
}

double sideLength(sf::Vector2f pos_1, sf::Vector2f pos_2) {// ������� ��� ���������� ����� ������� ������������
	return sqrt(pow(pos_2.x - pos_1.x, 2) + pow(pos_2.y - pos_1.y, 2));
}

double find_angle(sf::Vector2f pos_1, sf::Vector2f pos_2, sf::Vector2f pos_3) {//��� ���� �� ���� ����������� ������������
	double area = triangleArea(pos_1, pos_2, pos_3);
	
	double ab = sideLength(pos_1, pos_2);// ���������� ���� ������ ������������
	double ac = sideLength(pos_1, pos_3);
	double bc = sideLength(pos_2, pos_3);

	double angle = acos((ab * ab + ac * ac - bc * bc) / (2 * ab * ac));// ���������� ���� ����� ��������� AB � AC
	return angle * 180 / PI;

}

int string_to_int(const std::string& s) { //�� ������ ����� int
    std::istringstream i(s);
    int x;
    if (!(i >> x))
        return -1;
    return x;
}

bool string_to_int_bool(const std::string& s) { //�������� ����� �� ������� int �� string
    std::istringstream i(s);
    int x;
    if (!(i >> x))
        return false;
    return true;
}

std::string enter_the_data(std::wstring mes) {//��������� ������ �� ������������
    sf::RenderWindow window(sf::VideoMode(700, 350), L"������...", sf::Style::Titlebar | sf::Style::Close);

    sf::Font font;
    font.loadFromFile("ofont.ru_Expressway.ttf");//�������� �����

    RectButton button_1(sf::Vector2f(340, 40), sf::Vector2f(325, 240));
    button_1.setButtonFont(font);
    button_1.setButtonLable(L"����������", text_color, 30);

    sf::Text text_mes;
    text_mes.setFont(font);
    text_mes.setString(mes);
    text_mes.setFillColor(text_color);
    text_mes.setCharacterSize(30);
    text_mes.setPosition(30, 70);

    sdx::TextBox::Text text("", 124, 220);//��������� ����
    text.setSize(20);
    sdx::TextBox textBox(440, 32, 130, 160, 2);

    while (window.isOpen()) {
        sf::Vector2i mousePoz = sf::Mouse::getPosition(window);//������� ���� � ����
        sf::Event event;
        button_1.getButtonStatus(window, event);
        while (window.pollEvent(event)) {
            textBox.handleEvent(event);

            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.key.code == sf::Mouse::Left) {
                    if (button_1.isPressed) {
                        window.close();
                    }
                }
            }

        }
        window.clear(background_color);
        button_1.draw(window);
        textBox.draw(window);
        window.draw(text_mes);
        window.display();
    }
    return textBox.getCurrentText();//�������� ��������� �����
}

void enter_the_three_data(std::wstring mes_1, std::wstring mes_2, std::wstring mes_3, std::string& content_1, std::string& content_2, std::string& content_3) {//��������� ������ �� ������������
    sf::RenderWindow window(sf::VideoMode(700, 470), L"�������� �����...", sf::Style::Titlebar | sf::Style::Close);

    sf::Font font;
    font.loadFromFile("ofont.ru_Expressway.ttf");//�������� �����

    RectButton button_1(sf::Vector2f(260, 40), sf::Vector2f(window.getSize().x / 2 - 130, window.getSize().y - 80));
    button_1.setButtonFont(font);
    button_1.setButtonLable(L"����������", text_color, 30);

    int def_pos_y = 20;

    sf::Text text_mes_1;
    text_mes_1.setFont(font);
    text_mes_1.setString(mes_1);
    text_mes_1.setFillColor(text_color);
    text_mes_1.setCharacterSize(30);
    text_mes_1.setPosition(30, def_pos_y);

    sdx::TextBox::Text text_1("", 124, 220);//��������� ����
    text_1.setSize(20);
    sdx::TextBox textBox_1(440, 32, 130, def_pos_y += 60, 2);

    sf::Text text_mes_2;
    text_mes_2.setFont(font);
    text_mes_2.setString(mes_2);
    text_mes_2.setFillColor(text_color);
    text_mes_2.setCharacterSize(30);
    text_mes_2.setPosition(30, def_pos_y += 60);

    sdx::TextBox::Text text_2("", 130, 210);//��������� ����
    text_2.setSize(20);
    sdx::TextBox textBox_2(440, 32, 130, def_pos_y += 60, 2);

    sf::Text text_mes_3;
    text_mes_3.setFont(font);
    text_mes_3.setString(mes_3);
    text_mes_3.setFillColor(text_color);
    text_mes_3.setCharacterSize(30);
    text_mes_3.setPosition(30, def_pos_y += 60);

    sdx::TextBox::Text text_3("", 130, 210);//��������� ����
    text_3.setSize(20);
    sdx::TextBox textBox_3(440, 32, 130, def_pos_y += 60, 2);

    while (window.isOpen()) {
        sf::Vector2i mousePoz = sf::Mouse::getPosition(window);//������� ���� � ����
        sf::Event event;
        button_1.getButtonStatus(window, event);
        while (window.pollEvent(event)) {
            textBox_1.handleEvent(event);
            textBox_2.handleEvent(event);
            textBox_3.handleEvent(event);

            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.key.code == sf::Mouse::Left) {
                    if (button_1.isPressed) {
                        window.close();
                    }
                }
            }
        }
        window.clear(background_color);

        button_1.draw(window);
        textBox_1.draw(window);
        textBox_2.draw(window);
        textBox_3.draw(window);
        
        window.draw(text_mes_1);
        window.draw(text_mes_2);
        window.draw(text_mes_3);

        window.display();
    }
    content_1 = textBox_1.getCurrentText();//�������� ��������� �����
    content_2 = textBox_2.getCurrentText();//�������� ��������� �����
    content_3 = textBox_3.getCurrentText();//�������� ��������� �����
}

void enter_the_two_data(std::wstring mes_1, std::wstring mes_2, std::string& content_1, std::string& content_2) {//��������� ������ �� ������������
    sf::RenderWindow window(sf::VideoMode(700, 370), L"������� �����...", sf::Style::Titlebar | sf::Style::Close);

    sf::Font font;
    font.loadFromFile("ofont.ru_Expressway.ttf");//�������� �����

    RectButton button_1(sf::Vector2f(260, 40), sf::Vector2f(window.getSize().x / 2 - 130, window.getSize().y - 80));
    button_1.setButtonFont(font);
    button_1.setButtonLable(L"����������", text_color, 30);

    int def_pos_y = 20;

    sf::Text text_mes_1;
    text_mes_1.setFont(font);
    text_mes_1.setString(mes_1);
    text_mes_1.setFillColor(text_color);
    text_mes_1.setCharacterSize(30);
    text_mes_1.setPosition(30, def_pos_y);

    sdx::TextBox::Text text_1("", 124, 220);//��������� ����
    text_1.setSize(20);
    sdx::TextBox textBox_1(440, 32, 130, def_pos_y += 60, 2);

    sf::Text text_mes_2;
    text_mes_2.setFont(font);
    text_mes_2.setString(mes_2);
    text_mes_2.setFillColor(text_color);
    text_mes_2.setCharacterSize(30);
    text_mes_2.setPosition(30, def_pos_y += 60);

    sdx::TextBox::Text text_2("", 130, 210);//��������� ����
    text_2.setSize(20);
    sdx::TextBox textBox_2(440, 32, 130, def_pos_y += 60, 2);

    while (window.isOpen()) {
        sf::Vector2i mousePoz = sf::Mouse::getPosition(window);//������� ���� � ����
        sf::Event event;
        button_1.getButtonStatus(window, event);
        while (window.pollEvent(event)) {
            textBox_1.handleEvent(event);
            textBox_2.handleEvent(event);

            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.key.code == sf::Mouse::Left) {
                    if (button_1.isPressed) {
                        window.close();
                    }
                }
            }
        }
        window.clear(background_color);

        button_1.draw(window);
        textBox_1.draw(window);
        textBox_2.draw(window);

        window.draw(text_mes_1);
        window.draw(text_mes_2);

        window.display();
    }
    content_1 = textBox_1.getCurrentText();//�������� ��������� �����
    content_2 = textBox_2.getCurrentText();//�������� ��������� �����
}

void error_or_success_message(std::wstring message, std::wstring title) {//��������� � ���������� ��������
    sf::RenderWindow window(sf::VideoMode(message.size() * 20, 250), title);

    sf::Font font;
    font.loadFromFile("ofont.ru_Expressway.ttf");//�������� �����

    sf::Text mes;
    mes.setFont(font);
    mes.setString(message);
    mes.setFillColor(sf::Color::Black);
    mes.setCharacterSize(40);
    mes.setPosition(30, 45);

    RectButton button1(sf::Vector2f(150, 60), sf::Vector2f(window.getSize().x / 2 - 75, 140));//������������ ������ ������
    button1.setButtonFont(font);
    button1.setButtonLable(L"Ok", sf::Color::Black, 30);

    while (window.isOpen())
    {
        sf::Vector2i mousePoz = sf::Mouse::getPosition(window);//������� ���� � ����
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

        window.display();
    }
}

