/**
*	@file Circle.cpp
*
*	@brief Lab#1 circle class
*
*	@author Bondarets Daryna Ê-29
*
*	@version 1.6 8/10/19
*/

#include "Circle.h"
#include "Line.h"

/**
*	@brief Constructor
*	@details Create an object from the given parametes
*	@param x_ The x coordinate of the center of new Circle.
*	@param y_ The y coordinate of the center of new Circle.
*	@param radius The radius of new Circle
*/
Circle::Circle(double x_, double y_, double radius) : Figure(x_, y_) {
	this->radius = radius;
	type = 1;
};

/**
*	@brief Constructor
*	@details Create an object from the given parametes
*	@param p0 The point with coordinates of the center of new Circle.
*	@param radius The radius of new Circle
*/
Circle::Circle(Figure p0, double radius) : Figure(p0.getX(), p0.getY()) {
	this->radius = radius;
	type = 1;
};

/**
*	@brief Constructor
*	@details Create an object from the given parametes
*	@param p0 The point with coordinates of the center of new Circle.
*	@param radius The radius of new Circle
*/
Circle::Circle(pair<double, double> p0, pair<double, double> p1) : Figure(p0) {
	Figure P0(p0);
	Figure P1(p1);
	this->radius = P0.destinationPoints(P1);
	type = 1;
};

/*SETTERS/GETTERS*/

/**
*	@brief Sets new radius
*	@param radius The radius of the Circle
*/
void Circle::setRadius(double radius) {
	this->radius = radius;
};

/**
*	@brief Returnes radius of the Circle
*	@return The radius of the Circle
*/
double Circle::getRadius() { return radius; };

/**
*	@brief Checks if point lays on the Circle
*	@return True if point lays on the Circle, otherwise return false
*/
bool Circle::chekPoint(Figure P) {
	return (P.destinationPoints(*this) == radius);
}

/**
*	@brief Print the Circle (its center point and radius)
*/
void Circle::showType() {
	cout << "Circle: center in (" << getX() << ", " << getY() << ") and radius = " << radius << endl;
}

/**
*	@brief Create tangent line to the circle
*	@details Tangent line to a circle that touches the circle at p point
*
*	@param P Point that lays on the circle and a tangent line 
*	@return Tangent line to the circle
*/
Line Circle::tangent(Figure P) {
	Line line1(getX(),getY(), P.getX(), P.getY());
	Line result = line1.perpendicularLine(P);
	return result;
};

/**
*	@brief Calculates angle between Circle and Line
*	@details Calculates angle between Line and tangent line to a circle that touches their intersect point
*	if they don`t intersect returns 90
*	@param l Line
*	@return Angle between Circle and Line in degrees
*/
double Circle::angle(Line l) {
	vector<Figure> points = intersect(l);
	if (points.empty()) {
		return 90;
	}
	else {
		Figure P = points[0];
		Line l1 = tangent(P);
		return l1.angle(l);
	}
};

/**
*	@brief Calculates angle between 2 Circles
*	@details Calculates angle between 2 tangent lines to circles that touche their intersect point
*	if they don`t intersect returns 0
*	@param O Circle
*	@return Angle between Circles in degrees
*/
double Circle::angle(Circle O) {
	vector<Figure> points = intersect(O);
	if (points.empty()) {
		return 0;
	}
	else {
		Figure P = points[0];
		Line l1 = tangent(P);
		Line l2 = O.tangent(P);
		return l1.angle(l2);
	}
};

/**
*	@brief Calculates intersect points between Circle and Line
*	@param l Line
*	@return vector of intersect points
*/
vector<Figure> Circle::intersect(Line l) {
	vector<Figure> points;
	points = l.intersect(*this);
	return points;
}

/**
*	@brief Calculates intersect points between 2 Circles
*	@param O Circle
*	@return vector of intersect points
*/
vector<Figure> Circle::intersect(Circle O) {
	vector<Figure> points;

	double d = destinationPoints(O);
	if (d > (radius + O.getRadius())) {
		return points;
	} 
	else if (d < abs(radius - O.getRadius())) {
		return points;
	}
	else if (d == 0) {
		if (radius == O.getRadius()) 
			//cout << "There are an infinite number of solutions" << endl;
		return points;
	}
	else {
		double a1;
		a1 = (pow(radius, 2) - pow(O.getRadius(), 2) + pow(d, 2)) / (2 * d);
		
		Figure P(0, 0);
		P.setX(getX() + a1 * (O.getX() - getX()) / d);
		P.setY(getY() + a1 * (O.getY() - getY()) / d);

		if (d == (radius + O.getRadius())) {
			points.push_back(P);
			return points;
		}
		else {
			double h;
			h = sqrt(pow(radius, 2) - pow(a1, 2));
			Figure P1(0, 0);
			P1.setX((P.getX() + (h * (O.getY() - getY())) / d));
			P1.setY((P.getY() - (h * (O.getX() - getX())) / d));
			points.push_back(P1);
			
			Figure P2(0, 0);
			P2.setX((P.getX() - (h * (O.getY() - getY())) / d));
			P2.setY((P.getY() + (h * (O.getX() - getX())) / d));
			points.push_back(P2);

			return points;
		}
	}

}

/**
*	@brief Circle inversion of a point
*	@details the inverse of a point P with respect to a reference circle with center O and radius r is a point P', 
*	lying on the ray from O through P such that OP*OP`=r^2
*	@param P Point
*	@return inverse of a point
*/
Figure* Circle::inversion(Figure P) {
	double x1, y1, d;
	x1 = getX();
	y1 = getY();
	d = pow(P.getX() - getX(), 2) + pow(P.getY() - getY(), 2);
	if (d != 0) {
		x1 += (pow(radius, 2)*(P.getX() - getX())) / d;
		y1 += (pow(radius, 2)*(P.getY() - getY())) / d;
	}
	Figure* result = new Figure(x1,y1);
	return result;
}

/**
*	@brief Circle inversion of a Line
*	@details Inversion of a line is a circle containing the center of inversion; 
*	or it is the line itself if it contains the center
*	@param l Line
*	@return inverse of a line
*/
Figure* Circle::inversion(Line l) {
	
	Figure temp_point = l.getPointbyX(getX());
	
	if (chekPoint(temp_point)) {
		Figure* result = new Line(l);
		return result;
	}
	else {
		Line perpend = l.perpendicularLine(*this);
		Figure P1  = perpend.intersectPoint(l);
		Figure* P2 = inversion(P1);

		double dest;
		dest = P2->destinationPoints(*this);

		Figure O((getX()+P2->getX())/2, (getY()+P2->getY())/2);
		Figure* result = new Circle(O, dest / 2);
		return result;
	}
}

/**
*	@brief Circle inversion of a Cirlce
*	@details Inversion of a circle is another circle; 
*	or it is a line if the original circle contains the center
*	@param O Circle
*	@return inverse of a circle
*/
Figure* Circle::inversion(Circle O) {

	double dest;
	dest = destinationPoints(O);

	if (dest == O.getRadius()) {
		
		Figure P1(O.getX() + (getY() - O.getY())*(O.getRadius() / dest), O.getY() + (getX() - O.getX())*(O.getRadius() / dest));
		Figure P2(O.getX() - (getY() - O.getY())*(O.getRadius() / dest), O.getY() - (getX() - O.getX())*(O.getRadius() / dest));
		
		Figure* P3 = inversion(P1);
		Figure* P4 = inversion(P2);

		Figure* result = new Line(P3->getX(), P3->getY(), P4->getX(), P4->getY());
		return result;
	}
	else {
		double s;
		s = pow(getRadius(),2) / ( pow(O.getX() - getX(), 2) + pow(O.getY() - getY(), 2) - pow(O.getRadius(), 2) );
		double rad;
		rad = abs(s)*O.getRadius();
		Figure O( getX() + s*(O.getX()- getX()), getY() + s*(O.getY()- getY()));
		Figure* result = new Circle(O, rad);
		return result;
	}
};