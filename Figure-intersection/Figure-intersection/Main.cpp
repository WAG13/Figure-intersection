#include <iostream>
#include <vector>
#include <string>

#include "SFML/Graphics.hpp"
//#include "SFML/System.hpp"

#include "Figure/Figure.h"
#include "Figure/Circle.h"
#include "Figure/Line.h"
//#include "Figure/Polygon.h"

enum DRAW_FIGURE
{ FIGURE, CIRCLE, LINE, SEGMENT, POLYGON };

int main(){
	/*Figure p(0,1);
	Figure p2(1,0);
	p.showType();
	p2.showType();
	std::cout << p2.destinationPoints(p);

	Line l(p,p2);
	l.showType();
	
	Circle o(0,0,1);
	Circle o2(0,1,1);
	o.showType();

	l.intersect(o)[0].showType();
	l.intersect(o)[1].showType();

	o2.intersect(o)[0].showType();*/

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(1600, 900), "Figure-intersection", sf::Style::Default, settings);
	
	double O_x = window.getSize().x / 2;
	double O_y = window.getSize().y / 2;

	double cell_size = 100.0f;
	double koef_mas = 1.0f;
	double w_shift = 0.0f;
	double h_shift = 0.0f;
	double step_zoom = 0.001f;
	double step_move = 1.0f;

	sf::CircleShape circle_shape(100.0f);
	circle_shape.setFillColor(sf::Color::Transparent);
	circle_shape.setOutlineThickness(1.0f);
	circle_shape.setOutlineColor(sf::Color::Green);

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
			case sf::Event::Resized:
			{
				std::cout << evnt.size.width << " " << evnt.size.height << std::endl;
				std::cout << window.getSize().x << " " << window.getSize().y << std::endl;
			}
			break;
			
			/*case sf::Event::TextEntered:
			{
				switch (evnt.text.unicode)
				{
				default:
					break;
				}
			}
			break;*/
			default:
				break;
			}
				
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Add))
		{
			koef_mas += step_zoom;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Subtract))
		{
			if (koef_mas > step_zoom)
				koef_mas -= step_zoom;
		}
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
		
		if (sf::Mouse::isButtonPressed(sf::Mouse::Right)){
				O_x = evnt.mouseButton.x;
				O_y = evnt.mouseButton.y;
		};

		window.clear(); 
		
		//grid
		sf::RectangleShape rect(sf::Vector2f(cell_size*koef_mas, cell_size*koef_mas));
		rect.setFillColor(sf::Color::Transparent);
		rect.setOutlineThickness(0.5f);
		rect.setOutlineColor(sf::Color::Cyan);
		
		sf::Text text;
		sf::Font font;
		font.loadFromFile("calibri.ttf");
		text.setFont(font);
		text.setCharacterSize(24);
		text.setFillColor(sf::Color::Red);
		
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

		//figres
		
		//circle_shape.setPosition(-5, -80);
		circle_shape.setPosition(O_x-circle_shape.getRadius(), O_y - circle_shape.getRadius());
		window.draw(circle_shape);
		window.display();
	}

	return  0;
}
