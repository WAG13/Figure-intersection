/**
*	@file Figure.h
*
*	@brief Lab#1 Figure class
*
*	@author Bondarets Daryna Ê-29
*
*	@version 1.6 10/11/19
*/

#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include "SFML/Graphics.hpp"

using std::vector;
using std::pair;
/**
* @brief A figure Point
* @details An implementation of the point in a standart form: x and y coordinates
*/
class Figure
{
public:
	Figure();
	Figure(double x,double y);
	Figure(pair<double, double> a);
	Figure(vector< pair<double, double> >);

	void setPoint(Figure p);
	void addPoint(pair<double, double> p0);
	void setX(double x);
	void setY(double y);

	vector<pair<double, double>> getPoints();
	pair<double, double> getPoint(int index);
	double getX();
	double getX(int index);
	double getY();
	double getY(int index);

	virtual void draw(sf::RenderWindow &win,double koef,double x,double y) {
		sf::CircleShape dot(2.0f);
		dot.setFillColor(sf::Color::Magenta);
		dot.setPosition(getX()*koef + x - dot.getRadius(), y - getY()*koef - dot.getRadius());
		win.draw(dot);
	};

	/**
	*	@brief Print 1st Point
	*/
	virtual void showType() {
		std::cout << "Point: ";
		for (int i = 0; i < points.size(); i++)
			 std::cout<< "(" << points[i].first << ", " << points[i].second << ") " << std::endl;
	};

	void displace(double x_, double y_);

	double destinationPoints(Figure p);

protected:
	vector<pair<double, double>> points;
};
