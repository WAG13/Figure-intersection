/**
*	@file Circle.h
*
*	@brief Lab#1 circle class
*
*	@author Bondarets Daryna Ê-29
*
*	@version 1.6 8/10/19
*/

#pragma once

#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <vector>
#include "Figure.h"
#include "Line.h"

using std::vector;
using std::string;
using std::cout;
using std::endl;

/**
* @brief A figure Circle (subclass of Figure class)
* @details A+n implementation of the circle in a standart form: point of the center and its radius
*/
class Circle : public Figure
{
public:

	Circle(double x_, double y_, double radius);
	Circle(Figure p0, double radius);
	Circle(pair<double,double> p0, pair<double, double> p1);
	~Circle() {};

	void setRadius(double radius);
	double getRadius();

	void draw(sf::RenderWindow &win, double koef, double x, double y) {
		sf::CircleShape circle(getRadius()*koef);
		circle.setFillColor(sf::Color::Transparent);
		circle.setOutlineThickness(2.0f);
		circle.setOutlineColor(sf::Color::Green);
		circle.setPosition(getX()*koef + x - circle.getRadius(), y - getY()*koef - circle.getRadius());
		win.draw(circle);
		circle.setRadius(0.1f);
		circle.setPosition(x + getX()*koef, y - getY()*koef);
		win.draw(circle);
	};

	void showType();
	bool chekPoint(Figure P);

	class Line tangent(Figure P);
	double angle(class Line l);
	double angle(Circle l);

	vector<Figure> intersect(class Line l);
	vector<Figure> intersect(Circle O);
	
	Figure* inversion(Figure p);
	Figure* inversion(class Line p);
	Figure*  inversion(Circle O);

private:
	double radius;
};
