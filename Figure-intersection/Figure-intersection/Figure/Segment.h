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
	bool checkPoint(Figure p);
	
	double angle(class Line l);
	double angle(class Circle O);

	vector<Figure> intersect(class Line l);
	vector<Figure> intersect(class Circle O);
	vector<Figure> intersect(Segment p);
	
	void draw(sf::RenderWindow &win, double koef, double x, double y);

private:
	Line line;
};

