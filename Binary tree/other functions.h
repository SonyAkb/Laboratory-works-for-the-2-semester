#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Tree.h"
#include "textbox.hpp"
#include "sfml_button.hpp"
#include <sstream>

using namespace sf;
using namespace std;

sf::Color background_color(236, 205, 177);//фон
sf::Color button_color(231, 221, 213);//кнопка
sf::Color button_press_color(169, 105, 70);//кнопка нажата
sf::Color text_color(39, 16, 7);//текст

void print_spaces(int start, int end) {
	for (int j = start; j < end; j++) {//пробелы до узла
		cout << " ";
	}
}

double string_to_double(const std::string& s){ //из строки делаю double
    std::istringstream i(s);
    double x;
    if (!(i >> x))
        return -1;
    return x;
}

bool string_to_double_bool(const std::string& s) { //проверяю можно ли сделать double из string
    std::istringstream i(s);
    double x;
    if (!(i >> x))
        return false;
    return true;
}

string enter_the_data(wstring mes) {//получение данных от пользователя
    RenderWindow window(VideoMode(700, 350), L"Ведите...", Style::Titlebar | Style::Close);

    Font font;
    font.loadFromFile("ofont.ru_American TextC.ttf");//загружаю шрифт

    RectButton button_1(sf::Vector2f(340, 40), sf::Vector2f(325, 240));
    button_1.setButtonFont(font);
    button_1.setButtonLable(L"Продолжить", text_color, 30);

    Text text_mes;
    text_mes.setFont(font);
    text_mes.setString(mes);
    text_mes.setFillColor(text_color);
    text_mes.setCharacterSize(30);
    text_mes.setPosition(30, 70);

    sdx::TextBox::Text text("", 124, 220);//Текстовый бокс
    text.setSize(20);
    sdx::TextBox textBox(440, 32, 130, 160, 2);

    while (window.isOpen()) {
        Vector2i mousePoz = Mouse::getPosition(window);//позиция мыши в окне
        sf::Event event;
        button_1.getButtonStatus(window, event);
        while (window.pollEvent(event)) {
            textBox.handleEvent(event);

            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == Event::MouseButtonPressed) {
                if (event.key.code == Mouse::Left) {
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
    return textBox.getCurrentText();//извлекаю введенный текст
}

void error_or_success_message(std::wstring message, std::wstring title) {//сообщение о выполнении операции
    RenderWindow window(sf::VideoMode(message.size() * 20, 250), title);

    Font font;
    font.loadFromFile("ofont.ru_American TextC.ttf");//загружаю шрифт

    Text mes;
    mes.setFont(font);
    mes.setString(message);
    mes.setFillColor(Color::Black);
    mes.setCharacterSize(40);
    mes.setPosition(30, 45);

    RectButton button1(sf::Vector2f(150, 60), sf::Vector2f(window.getSize().x / 2 - 75, 140));//Вертикальная печать дерева
    button1.setButtonFont(font);
    button1.setButtonLable(L"Ok", sf::Color::Black, 30);

    while (window.isOpen())
    {
        Vector2i mousePoz = Mouse::getPosition(window);//позиция мыши в окне
        sf::Event event;
        button1.getButtonStatus(window, event);

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == Event::MouseButtonPressed) {
                if (event.key.code == Mouse::Left) {
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