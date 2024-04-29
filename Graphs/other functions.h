#pragma once
#include <vector>
#include <cmath>
#include "sfml_button.hpp"
#include "textbox.hpp"

sf::Color background_color(236, 205, 177);//���
sf::Color button_color(231, 221, 213);//������
sf::Color button_press_color(169, 105, 70);//������ ������
sf::Color text_color(39, 16, 7);//�����

sf::Vector2f calculating_node_coordinates(sf::Vector2f first_point, sf::Vector2f second_point, float angle) {//��������� ���������� 3 �����

	sf::Vector2f third_point;
	float angle_in_radians = angle * (3.14 / 180);
	//third_point.x = std::cos(angle_in_radians) * (first_point.x - second_point.x) + std::sin(angle_in_radians) * (first_point.y - second_point.y) + second_point.x;
	//third_point.y = std::cos(angle_in_radians) * (first_point.x - second_point.x) - std::sin(angle_in_radians) * (first_point.y - second_point.y) + second_point.y;
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

