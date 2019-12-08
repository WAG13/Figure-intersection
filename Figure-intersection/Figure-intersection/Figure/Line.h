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

protected:
	bool isParall(double a1, double b1, double a2, double b2);
	bool isParall(Line l);
	
private:
	double a, b, c, d, k;
};
