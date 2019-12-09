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


class Polygon : public Figure
{
public:
	Polygon();
	Polygon(vector<pair<double,double>> points);
	Polygon(vector<Line> edg);

	void showType();
	void addPoint(Figure);
	void addPoint(pair<double,double>);
	void addEdge(class Line);

	/*vector<Figure> intersect(class Line l);
	vector<Figure> intersect(class Circle O);
	vector<Figure> intersect(Polygon l);*/

private:
	vector<Line> edges;
protected:
};