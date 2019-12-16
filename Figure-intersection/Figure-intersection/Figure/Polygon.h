/**
*	@file Polygon.h
*
*	@brief Lab#3 Polygon class
*
*	@author Bondarets Daryna K-29
*
*	@version 2.0 06/12/19
*/

#include <iostream>
#include "Figure.h"
#include "Circle.h"
#include "Line.h"
#include "Segment.h"


class Polygon : public Figure
{
public:
	Polygon();
	Polygon(vector<pair<double,double>> points);
	Polygon(vector<Line> edg);

	void showType();
	void addPoint(Figure);
	void addPoint(pair<double,double>);
	//void addEdge(class Line);
	void addEdge(class Segment);

	void draw(sf::RenderWindow &win, double koef, double x, double y);

private:
	vector<Segment> edges;
protected:
};