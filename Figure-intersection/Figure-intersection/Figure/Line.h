/**
*	@file Line.h
*
*	@brief Lab#1 line class
*
*	@author Bondarets Daryna K-29
*
*	@version 1.6 8/10/19
*/

#pragma once

#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <vector>
#include "Figure.h"
#include "Circle.h"

using std::vector;
using std::string;
using std::pair;
using std::cout;
using std::endl;

/**
* @brief A figure Line (subclass of Figure class)
* @details An implementation of the line in a standart form: a * x + b * y + c = 0 && y = k * x + d
*/
class Line : public Figure
{
public:
	Line(double a1, double b1, double c1);
	Line(double x1, double y1, double x2, double y2);
	Line(Figure p1, Figure p2);
	Line(pair<double, double> p0, pair<double, double> p1);
	~Line() {};

	void setK();
	double getK();
	double getA();
	double getB();
	double getC();
	double getD();

	Figure getPointbyX(double x);
	Figure getPointbyY(double y);

	void showType();

	bool chekPoint(Figure p);

	double destination(Figure p);
	
	double angle(Line l);
	double angle(class Circle O);

	Line perpendicularLine(Figure p);

	Figure intersectPoint(Line l);
	vector<Figure> intersect(Line l);
	vector<Figure> intersect(class Circle O);
	

	Figure symmetry(Figure p);
	Line symmetry (Line p);
	class Circle symmetry (class Circle O);
	
	bool isParall(Line l);
	
	void draw(sf::RenderWindow &win, double koef, double x, double y) {
		Figure p1 = getPointbyX((- x)/ koef);
		Figure p2 = getPointbyX((win.getSize().x - x)/ koef);
		
		sf::Vertex line[] =
		{
			sf::Vertex(sf::Vector2f((p1.getX()*koef + x), - p1.getY()*koef + y)),
			sf::Vertex(sf::Vector2f((p2.getX()*koef + x), - p2.getY()*koef + y))
		};
		//line.setColor(sf::Color::Yellow);
		win.draw(line, 2, sf::Lines);
	};
protected:
	bool isParall(double a1, double b1, double a2, double b2);

private:
	double a, b, c, d, k;
};
