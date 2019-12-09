#include <iostream>
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

	double cell_size = 100;
	double koef_mas = 1;
	double w_shift = 0;
	double h_shift = 0;
	double step_zoom = 0.1;
	double step_move = 5;

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
			koef_mas -= step_zoom;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
		{
			h_shift -= step_move;
		}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
		{
			h_shift += step_move;
		}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
		{
			w_shift -= step_move;
		}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
		{
			w_shift += step_move;
		}

		window.clear(); 
		
		sf::RectangleShape rect(sf::Vector2f(cell_size*koef_mas, cell_size*koef_mas));
		rect.setFillColor(sf::Color::Transparent);
		rect.setOutlineThickness(0.5f);
		rect.setOutlineColor(sf::Color::Blue);
		
		rect.setPosition(sf::Vector2f(O_x + w_shift, O_y + h_shift));
		for (int i = 0; i < (window.getSize().x / (cell_size * koef_mas)); i++) {
			rect.move(cell_size*koef_mas*i, 0.0f);
			for (int j = 0; j < (window.getSize().y / (cell_size * koef_mas)); j++) {
				window.draw(rect);
				rect.move(0.0f, cell_size*koef_mas);
			}
			rect.setPosition(sf::Vector2f(O_x + w_shift, O_y + h_shift));
		}
		circle_shape.setPosition(O_x, O_y);
		
		window.draw(circle_shape);
		window.display();
	}

	return  0;
}
