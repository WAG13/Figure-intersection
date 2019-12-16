#pragma once
#include "Figure.h"
#include "Line.h"
#include "Circle.h"

class Segment : public Figure
{
public:
	Segment(double x1, double y1, double x2, double y2);
	Segment(Figure p1, Figure p2);
	Segment(pair<double, double> p0, pair<double, double> p1);
	~Segment() {};

	void showType();
	double angle(Line l);
	double angle(class Circle O);

	bool chekPoint(Figure p);

	void draw(sf::RenderWindow &win, double koef, double x, double y) {
		vector<pair<double, double>> temp = getPoints();
		sf::Vertex line[] =
		{
			sf::Vertex(sf::Vector2f((temp[0].first*koef + x), -temp[0].second*koef + y), sf::Color::Yellow),
			sf::Vertex(sf::Vector2f((temp[1].first*koef + x), -temp[1].second*koef + y), sf::Color::Yellow)
		};
		win.draw(line, 2, sf::Lines);
	};
private:
	Line line;
};

