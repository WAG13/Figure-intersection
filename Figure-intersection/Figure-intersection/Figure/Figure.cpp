/**
*	@file Figure.cpp
*
*	@brief Lab#1 Figure class
*
*	@author Bondarets Daryna Ê-29
*
*	@version 1.6 10/11/19
*/

#include "Figure.h"

/**
*	@brief Constructor
*	@details Create a point with (0,0) coordinates
*/
Figure::Figure() {
	points.clear();
	pair<double, double> point = std::make_pair(0, 0);
	points.push_back(point);

};

/**
*	@brief Constructor
*	@details Create an object from the given parametes
*	@param x The x coordinate
*	@param y The y coordinate
*/
Figure::Figure(double x, double y) {
	points.clear();
	pair<double, double> point = std::make_pair(x, y);
	points.push_back(point);
};

/**
*	@brief Constructor
*	@details Create an object from the given parametes
*	@param point
*/
Figure::Figure(pair<double, double> point) {
	points.clear();
	points.push_back(point);
};

/**
*	@brief Constructor
*	@details Create an object from the given parametes
*	@param vector of points
*/
Figure::Figure(vector<pair<double, double>> point) {
	points.clear();
	points = point;
};

/**
*	@brief Copy function
*	@details Copy all properties from the given object
*	@param p point to copy from
*/
void Figure::setPoint(Figure p) {
	points.clear();
	pair<double, double> point = std::make_pair(p.getX(), p.getY());
	points.push_back(point);
};

/**
*	@brief Copy function
*	@details Copy all properties from the given object
*	@param p point to copy from
*/
void Figure::addPoint(pair<double, double> point) {
	points.push_back(point);
};

/**
*	@brief Sets x coordinate of the point
*	@param x coordinate of the point
*/
void Figure::setX(double x) { points[0].first = x; };

/**
*	@brief Sets y coordinate of the point
*	@param y coordinate of the point
*/
void Figure::setY(double y) { points[0].second = y; };

/**
*	@brief Returnes x coordinate of the point
*	@return x coordinate of the point
*/
vector<pair<double, double>> Figure::getPoints() { return points; };
pair<double, double> Figure::getPoint(int index) { return points[index]; };

/**
*	@brief Returnes x coordinate of the point
*	@return x coordinate of the point
*/
double Figure::getX() { return (points[0].first); };
double Figure::getX(int index) { return (points[index].first); };

/**
*	@brief Returnes y coordinate of the point
*	@return y coordinate of the point
*/
double Figure::getY() { return (points[0].second); };
double Figure::getY(int index) { return (points[index].second); };

/**
*	@brief Sets new coordinates of the point
*	@param x_ amount that we displace x coordinate of the point
*	@param y_ amount that we displace y coordinate of the point
*/
void Figure::displace(double x_, double y_) {
	for (int i = 0; i < points.size(); i++) {
		points[i].first += x_;
		points[i].second += y_;
	}
};

/**
*	@brief Destination between 2 Points
*	@details the distance between any two points as a line. The length of this line can be found using the distance formula
*	@param p point
*	@return destination between points
*/
double Figure::destinationPoints(Figure p) {
	double d;
	d = sqrt(pow(p.getX() - getX(), 2) + pow(p.getY() - getY(), 2));
	return d;
};
