#include <iostream>
#include <stdio.h>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <string>

#include "SFML/Graphics.hpp"
//#include "SFML/System.hpp"

#include "Figure/Figure.h"
#include "Figure/Circle.h"
#include "Figure/Line.h"
#include "Figure/Segment.h"
#include "Figure/Polygon.h"

enum DRAW_FIGURE
{ FIGURE, CIRCLE, LINE, SEGMENT, POLYGON };

int main(){
	
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(1600, 900), "Figure-intersection", sf::Style::Close, settings);
	
	double O_x = window.getSize().x / 2;
	double O_y = window.getSize().y / 2;
	double mouse_x = 0;
	double mouse_y = 0;

	double cell_size = 100.0f;
	double koef_mas = 1.0f;
	double w_shift = 0.0f;
	double h_shift = 0.0f;
	double step_zoom = 0.001f;
	double step_move = 1.0f;

	int status = FIGURE;
	int polygon_vert = 3;

	std::vector<Figure*> figures;
	std::vector<std::pair<double,double>> temp_figure;
	
	sf::Font font;
	font.loadFromFile("calibri.ttf");
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);

	sf::Text stat;
	stat.setString("Point");
	stat.setFont(font);
	stat.setCharacterSize(24);
	stat.setFillColor(sf::Color::Red);
	stat.setPosition(1520, 850);

	sf::CircleShape dot(2.0f);
	dot.setFillColor(sf::Color::Red);

	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed: 
			{
				window.close();
			}
			break;
			case sf::Event::MouseMoved:
			{
				mouse_x = evnt.mouseMove.x;
				mouse_y = evnt.mouseMove.y;
			}
			break;
			
			case sf::Event::MouseButtonReleased:
			{
				std::pair<double, double> point = std::make_pair((evnt.mouseButton.x - O_x) / (cell_size*koef_mas), (O_y - evnt.mouseButton.y) / (cell_size*koef_mas));
				temp_figure.push_back(point);

				//std::cout << point.first <<", "<< point.second << std::endl;
				//std::cout << point.first*(cell_size*koef_mas) + O_x << ", " << - point.second*(cell_size*koef_mas) + O_y << std::endl;
				switch (status)
				{
				case FIGURE: 
				{
					if (temp_figure.size() == 1) {
						Figure* point = new Figure(temp_figure);
						figures.push_back(point);
						temp_figure.clear();
					}
				}
				break;
				case CIRCLE: 
				{
					if (temp_figure.size() == 2) {
						Figure* circle = new Circle(temp_figure[0],temp_figure[1]);
						figures.push_back(circle);
						temp_figure.clear();
					}
				}
				break;
				case LINE: 
				{
					if (temp_figure.size() == 2) {
						Figure* line = new Line(temp_figure[0],temp_figure[1]);
						figures.push_back(line);
						temp_figure.clear();
					}
				}
				break;
				case SEGMENT: 
				{
					if (temp_figure.size() == 2) {
						Figure* segment = new Segment(temp_figure[0],temp_figure[1]);
						figures.push_back(segment);
						temp_figure.clear();
					}
				}
				break;
				case POLYGON: 
				{
					if (temp_figure.size() == polygon_vert) {
						Figure* poly = new Polygon(temp_figure);
						figures.push_back(poly);
						temp_figure.clear();
					}
				}
				break;
				default:
					break;
				}
			}
			break;
			
			default:
				break;
			}
				
		}
		//zoom
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Add))
		{
			koef_mas += step_zoom;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Subtract))
		{
			if (koef_mas > step_zoom)
				koef_mas -= step_zoom;
		}

		//movement
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
		{
			O_y -= step_move;
		}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
		{
			O_y += step_move;
		}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
		{
			O_x -= step_move;
		}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
		{
			O_x += step_move;
		}
		
		//status
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num0)) {
			status = FIGURE; 
			temp_figure.clear();
			stat.setString("Point");
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1)) {
			status = CIRCLE; 
			temp_figure.clear();
			stat.setString("Circle");
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2)) {
			status = LINE; 
			temp_figure.clear();
			stat.setString("Line");
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num3)) {
			status = SEGMENT; 
			temp_figure.clear();
			stat.setString("Segment");
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num4)) {
			status = POLYGON; 
			temp_figure.clear();
			std::cout << "Polygon vertex count:" << std::endl;
			if (evnt.type == sf::Event::TextEntered)
			{
				std::cin >> polygon_vert;
				if (polygon_vert < 3) polygon_vert = 3;
			}
				
			stat.setString("Polygon");
		}
		
		//sets point O(0, 0)
		if (sf::Mouse::isButtonPressed(sf::Mouse::Right)){
				O_x = evnt.mouseButton.x;
				O_y = evnt.mouseButton.y;
		};



		//clrscr
		window.clear(); 

		//grid
		sf::RectangleShape rect(sf::Vector2f(cell_size*koef_mas, cell_size*koef_mas));
		rect.setFillColor(sf::Color::Transparent);
		rect.setOutlineThickness(0.1f);
		rect.setOutlineColor(sf::Color::Cyan);
		
		// x+ y-
		rect.setPosition(sf::Vector2f(O_x, O_y));
		for (int i = 0; (O_x + cell_size * koef_mas * i) <= (window.getSize().x); i++) {
			rect.move(cell_size*koef_mas*i, 0.0f);
			for (int j = 0; (O_y + cell_size * koef_mas * j) <= (window.getSize().y); j++) {
				window.draw(rect);
				rect.move(0.0f, cell_size*koef_mas);

				text.setString(std::to_string(-i));
				text.setPosition(sf::Vector2f(15.0f, O_y + cell_size * koef_mas*i + 1.0f));
				window.draw(text);
			}
			text.setString(std::to_string(i));
			text.setPosition(sf::Vector2f(O_x + cell_size * koef_mas*i + 1.0f, 15.0f));
			window.draw(text);
			rect.setPosition(sf::Vector2f(O_x, O_y));
		}
		
		// x- y-
		for (int i = 0; (O_x - cell_size * koef_mas * i) >= -cell_size * koef_mas; i++) {
			rect.move(-cell_size*koef_mas*i, 0.0f);
			for (int j = 0; (O_y + cell_size * koef_mas * j) <= (window.getSize().y); j++) {
				window.draw(rect);
				rect.move(0.0f, cell_size*koef_mas);
				
				text.setString(std::to_string(-i));
				text.setPosition(sf::Vector2f(15.0f, O_y + cell_size * koef_mas*i + 1.0f));
				window.draw(text);
			}
			text.setString(std::to_string(-i));
			text.setPosition(sf::Vector2f(O_x - cell_size * koef_mas*i + 1.0f, 15.0f));
			window.draw(text);
			rect.setPosition(sf::Vector2f(O_x, O_y));
		}

		// x- y+
		for (int i = 0; (O_x - cell_size * koef_mas * i) >= -cell_size * koef_mas; i++) {
			rect.move(-cell_size * koef_mas*i, 0.0f);
			for (int j = 0; (O_y - cell_size * koef_mas * j) >= -cell_size * koef_mas; j++) {
				window.draw(rect);
				rect.move(0.0f, -cell_size*koef_mas);
				
				text.setString(std::to_string(i));
				text.setPosition(sf::Vector2f(15.0f, O_y - cell_size * koef_mas*i + 1.0f));
				window.draw(text);
			}
			text.setString(std::to_string(-i));
			text.setPosition(sf::Vector2f(O_x - cell_size * koef_mas*i + 1.0f, 15.0f));
			window.draw(text);
			rect.setPosition(sf::Vector2f(O_x, O_y));
		}

		// x+ y+
		for (int i = 0; (O_x + cell_size * koef_mas * i) <= (window.getSize().x); i++) {
			rect.move(cell_size*koef_mas*i, 0.0f);
			for (int j = 0; (O_y - cell_size * koef_mas * j) >= -cell_size * koef_mas; j++) {
				window.draw(rect);
				rect.move(0.0f, -cell_size*koef_mas);
				text.setString(std::to_string(i));
				text.setPosition(sf::Vector2f(15.0f, O_y - cell_size * koef_mas*i + 1.0f));
				window.draw(text);
			}
			text.setString(std::to_string(i));
			text.setPosition(sf::Vector2f(O_x + cell_size * koef_mas*i + 1.0f, 15.0f));
			window.draw(text);
			rect.setPosition(sf::Vector2f(O_x, O_y));
		}

		//axis
		sf::RectangleShape axis (sf::Vector2f(3.0f, window.getSize().y));
		axis.setFillColor(sf::Color::Blue);
		axis.setPosition(O_x, 0);
		window.draw(axis);
		axis.setSize(sf::Vector2f(window.getSize().x, 3.0f));
		axis.setPosition(0, O_y);
		window.draw(axis);

		double current_x = (mouse_x - O_x) / (cell_size*koef_mas);
		double current_y = (-mouse_y + O_y) / (cell_size*koef_mas);

		//figures
		for (int i = 0; i < figures.size(); i++) {
			figures[i]->draw(window, cell_size*koef_mas, O_x, O_y);
		};
		
		//draw temp dots
		for (int i = 0; i < temp_figure.size(); i++) {
			dot.setPosition(temp_figure[i].first*cell_size*koef_mas + O_x - dot.getRadius(), O_y - temp_figure[i].second*cell_size*koef_mas - dot.getRadius());
			window.draw(dot);
		};

		
		//status
		window.draw(stat);
		//mouse axis
		axis.setSize(sf::Vector2f(1.0f, window.getSize().y));
		axis.setFillColor(sf::Color::Yellow);
		axis.setPosition(mouse_x, 0);
		window.draw(axis);
		axis.setSize(sf::Vector2f(window.getSize().x, 1.0f));
		axis.setPosition(0, mouse_y);
		window.draw(axis);
		text.setString(" ("+std::to_string(current_x)+", "+ std::to_string(current_y)+")");
		text.setPosition(sf::Vector2f(mouse_x+ 5.0f, mouse_y + 1.0f));
		window.draw(text);
		window.display();
	}

	return  0;
}
