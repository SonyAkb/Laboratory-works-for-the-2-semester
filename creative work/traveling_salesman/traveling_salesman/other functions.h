#pragma once
#include <vector>
#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <utility>
#include "sfml_button.hpp"
#include "textbox.hpp"
#define PI 3.14159265

sf::Color background_color(247, 247, 232);//фон
sf::Color button_color(199, 207, 183);//кнопка
sf::Color button_press_color(157, 173, 127);//кнопка нажата
sf::Color text_color(37, 64, 65);//текст

sf::Vector2f calculating_node_coordinates(sf::Vector2f first_point, sf::Vector2f second_point, float angle) {//вычислияю координаты 3 точки
	sf::Vector2f third_point;
	float angle_in_radians = angle * (PI / 180);
	third_point.x = std::cos(angle_in_radians) * (first_point.x - second_point.x) - std::sin(angle_in_radians) * (first_point.y - second_point.y) + second_point.x;
	third_point.y = std::sin(angle_in_radians) * (first_point.x - second_point.x) + std::cos(angle_in_radians) * (first_point.y - second_point.y) + second_point.y;
	return third_point;
}

double beam_length(sf::Vector2f first_point, sf::Vector2f second_point) {//длина вектора
	double dx = second_point.x - first_point.x;
	double dy = second_point.y - first_point.y;
	double distSq = dx * dx + dy * dy;// Вычисляем квадрат расстояния между точками
	double length = sqrt(distSq);// Извлекаем квадратный корень, чтобы получить длину луча
	return length;
}

sf::Vector2f point_on_the_node_boundary(sf::Vector2f first_point, sf::Vector2f second_point, double minus) {//координаты до точки
	double distance = beam_length(first_point, second_point) - minus;
	double alpha = atan2(second_point.y - first_point.y, second_point.x - first_point.x);// Находим угол альфа между лучом и осью X
	double x = first_point.x + distance * cos(alpha);
	double y = first_point.y + distance * sin(alpha);
	return sf::Vector2f(x, y);
}

double sideLength(sf::Vector2f pos_1, sf::Vector2f pos_2) {// Функция для вычисления длины стороны треугольника
	return sqrt(pow(pos_2.x - pos_1.x, 2) + pow(pos_2.y - pos_1.y, 2));
}

double find_angle(sf::Vector2f pos_1, sf::Vector2f pos_2, sf::Vector2f pos_3) {//ищу угол по трем координатам треугольника
	double ab = sideLength(pos_1, pos_2);// Вычисление длин сторон треугольника
	double ac = sideLength(pos_1, pos_3);
	double bc = sideLength(pos_2, pos_3);

	double angle = acos((ab * ab + ac * ac - bc * bc) / (2 * ab * ac));// Вычисление угла между сторонами AB и AC
	return angle * 180 / PI;

}

int string_to_int(const std::string& s) { //из строки делаю int
    std::istringstream i(s);
    int x;
    if (!(i >> x))
        return -1;
    return x;
}

bool string_to_int_bool(const std::string& s) { //проверяю можно ли сделать int из string
    std::istringstream i(s);
    int x;
    if (!(i >> x))
        return false;
    return true;
}

std::string enter_the_data(std::wstring mes) {//получение данных от пользователя
    sf::RenderWindow window(sf::VideoMode(700, 350), L"Ведите...", sf::Style::Titlebar | sf::Style::Close);

    sf::Font font;
    font.loadFromFile("ofont.ru_Expressway.ttf");//загружаю шрифт

    RectButton button_1(sf::Vector2f(340, 40), sf::Vector2f(325, 240));
    button_1.setButtonFont(font);
    button_1.setButtonLable(L"Продолжить", text_color, 30);

    sf::Text text_mes;
    text_mes.setFont(font);
    text_mes.setString(mes);
    text_mes.setFillColor(text_color);
    text_mes.setCharacterSize(30);
    text_mes.setPosition(30, 70);

    sdx::TextBox::Text text("", 124, 220);//Текстовый бокс
    text.setSize(20);
    sdx::TextBox textBox(440, 32, 130, 160, 2);

    while (window.isOpen()) {
        sf::Vector2i mousePoz = sf::Mouse::getPosition(window);//позиция мыши в окне
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
    return textBox.getCurrentText();//извлекаю введенный текст
}

void enter_the_three_data(std::wstring title, std::wstring mes_1, std::wstring mes_2, std::wstring mes_3, std::string& content_1, std::string& content_2, std::string& content_3) {//получение данных от пользователя
    sf::RenderWindow window(sf::VideoMode(700, 470), title, sf::Style::Titlebar | sf::Style::Close);

    sf::Font font;
    font.loadFromFile("ofont.ru_Expressway.ttf");//загружаю шрифт

    RectButton button_1(sf::Vector2f(260, 40), sf::Vector2f(window.getSize().x / 2 - 130, window.getSize().y - 80));
    button_1.setButtonFont(font);
    button_1.setButtonLable(L"Продолжить", text_color, 30);

    int def_pos_y = 20;

    sf::Text text_mes_1;
    text_mes_1.setFont(font);
    text_mes_1.setString(mes_1);
    text_mes_1.setFillColor(text_color);
    text_mes_1.setCharacterSize(30);
    text_mes_1.setPosition(30, def_pos_y);

    sdx::TextBox::Text text_1("", 124, 220);//Текстовый бокс
    text_1.setSize(20);
    sdx::TextBox textBox_1(440, 32, 130, def_pos_y += 60, 2);

    sf::Text text_mes_2;
    text_mes_2.setFont(font);
    text_mes_2.setString(mes_2);
    text_mes_2.setFillColor(text_color);
    text_mes_2.setCharacterSize(30);
    text_mes_2.setPosition(30, def_pos_y += 60);

    sdx::TextBox::Text text_2("", 130, 210);//Текстовый бокс
    text_2.setSize(20);
    sdx::TextBox textBox_2(440, 32, 130, def_pos_y += 60, 2);

    sf::Text text_mes_3;
    text_mes_3.setFont(font);
    text_mes_3.setString(mes_3);
    text_mes_3.setFillColor(text_color);
    text_mes_3.setCharacterSize(30);
    text_mes_3.setPosition(30, def_pos_y += 60);

    sdx::TextBox::Text text_3("", 130, 210);//Текстовый бокс
    text_3.setSize(20);
    sdx::TextBox textBox_3(440, 32, 130, def_pos_y += 60, 2);

    while (window.isOpen()) {
        sf::Vector2i mousePoz = sf::Mouse::getPosition(window);//позиция мыши в окне
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
    content_1 = textBox_1.getCurrentText();//извлекаю введенный текст
    content_2 = textBox_2.getCurrentText();//извлекаю введенный текст
    content_3 = textBox_3.getCurrentText();//извлекаю введенный текст
}

void enter_the_two_data(std::wstring title, std::wstring mes_1, std::wstring mes_2, std::string& content_1, std::string& content_2) {//получение данных от пользователя
    sf::RenderWindow window(sf::VideoMode(700, 370), title, sf::Style::Titlebar | sf::Style::Close);

    sf::Font font;
    font.loadFromFile("ofont.ru_Expressway.ttf");//загружаю шрифт

    RectButton button_1(sf::Vector2f(260, 40), sf::Vector2f(window.getSize().x / 2 - 130, window.getSize().y - 80));
    button_1.setButtonFont(font);
    button_1.setButtonLable(L"Продолжить", text_color, 30);

    int def_pos_y = 20;

    sf::Text text_mes_1;
    text_mes_1.setFont(font);
    text_mes_1.setString(mes_1);
    text_mes_1.setFillColor(text_color);
    text_mes_1.setCharacterSize(30);
    text_mes_1.setPosition(30, def_pos_y);

    sdx::TextBox::Text text_1("", 124, 220);//Текстовый бокс
    text_1.setSize(20);
    sdx::TextBox textBox_1(440, 32, 130, def_pos_y += 60, 2);

    sf::Text text_mes_2;
    text_mes_2.setFont(font);
    text_mes_2.setString(mes_2);
    text_mes_2.setFillColor(text_color);
    text_mes_2.setCharacterSize(30);
    text_mes_2.setPosition(30, def_pos_y += 60);

    sdx::TextBox::Text text_2("", 130, 210);//Текстовый бокс
    text_2.setSize(20);
    sdx::TextBox textBox_2(440, 32, 130, def_pos_y += 60, 2);

    while (window.isOpen()) {
        sf::Vector2i mousePoz = sf::Mouse::getPosition(window);//позиция мыши в окне
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
    content_1 = textBox_1.getCurrentText();//извлекаю введенный текст
    content_2 = textBox_2.getCurrentText();//извлекаю введенный текст
}

void error_or_success_message(std::wstring message, std::wstring title) {//сообщение о выполнении операции
    sf::RenderWindow window(sf::VideoMode(message.size() * 20, 250), title);

    sf::Font font;
    font.loadFromFile("ofont.ru_Expressway.ttf");//загружаю шрифт

    sf::Text mes;
    mes.setFont(font);
    mes.setString(message);
    mes.setFillColor(sf::Color::Black);
    mes.setCharacterSize(40);
    mes.setPosition(30, 45);

    RectButton button1(sf::Vector2f(150, 60), sf::Vector2f(window.getSize().x / 2 - 75, 140));//Вертикальная печать дерева
    button1.setButtonFont(font);
    button1.setButtonLable(L"Ok", sf::Color::Black, 30);

    while (window.isOpen())
    {
        sf::Vector2i mousePoz = sf::Mouse::getPosition(window);//позиция мыши в окне
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

int a_random_number() {//случайное число от 1 до 100
    return rand() % 100 + 1;
}

template<typename T>
std::vector<std::vector<T>> copyNestedVector(const std::vector<std::vector<T>>& nested) {
    std::vector<std::vector<T>> result;
    for (const auto& inner : nested) {
        std::vector<T> copiedInner;
        copiedInner.reserve(inner.size()); // Предварительное выделение памяти
        for (const auto& value : inner) {
            copiedInner.push_back(value); // Копирование каждого элемента
        }
        result.push_back(copiedInner); // Добавление скопированного внутреннего вектора в результат
    }
    return result;
}

void makebase(int i_current, int j_current, std::vector<std::vector<int>>& matrix_of_conditions, int quantity_of_nodes) {//обновления матрицы смежности при нахождении базового значения
    int i, j;
    for (i = 0; i < quantity_of_nodes; i++) {//проход по всем столбцам
        if (matrix_of_conditions[i][j_current] >= 0) { //если есть путь - положительное значение
            matrix_of_conditions[i][j_current] = -1; //блокирую путь через этот столбец
        }
    }
    for (j = 0; j < quantity_of_nodes; j++) {//проход по всем строкам
        if (matrix_of_conditions[i_current][j] >= 0) {//если есть путь - положительное значение
            matrix_of_conditions[i_current][j] = -1;//блокирую путь через эту строку
        }
    }
    matrix_of_conditions[i_current][j_current] = -2;//элемент отмечен как часть решения
    if (matrix_of_conditions[j_current][i_current] >= 0) { //если есть неотмеченный обратный путь
        matrix_of_conditions[j_current][i_current] = -1; //если обратный путь положителен, он также блокируется
    }
}

bool has_Duplicates_vector(std::vector<int> vec) {//проверяю наличие дубликатов не учитывая первый элемент
    if (vec.size() > 1) {
        std::sort(vec.begin() + 1, vec.end());// Сортировка вектора
        for (int i = 2; i < vec.size(); ++i) {// Проверка наличия дубликатов
            if (vec[i] == vec[i - 1]) {
                return true; // Найден дубликат
            }
        }
    }
    return false; // Дубликаты отсутствуют
}