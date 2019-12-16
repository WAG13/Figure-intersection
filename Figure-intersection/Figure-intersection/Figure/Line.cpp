/**
*	@file Line.cpp
*
*	@brief Lab#1 line class
*
*	@author Bondarets Daryna K-29
*
*	@version 1.6 8/10/19
*/

#include "Line.h"

/**
*	@brief Constructor
*	@details An implementation of the line in a standart form: a * x + b * y + c = 0
*	@param a1 coefficient a of a line
*	@param b1 coefficient b of a line
*	@param c1 coefficient c of a line
*/
Line::Line(double a1, double b1, double c1) : Figure(0, 0) {
	this->a = a1;
	this->b = b1;
	this->c = c1;
	if (b1==0) {
		setY(0);
		setX(-c1 / a1);
		addPoint(std::make_pair(-c1 / a1, 1));
	}
	else {
		setY(-c1 / b1);
		setX(0);
		addPoint(std::make_pair(1, (-c1 - 1) / b1));
	}
	
};

/**
*	@brief Constructor
*	@details An implementation of the line by 2 points
*	@param x1 x coordinate of first point
*	@param y1 y coordinate of first point
*	@param x2 x coordinate of second point
*	@param y2 y coordinate of second point
*/
Line::Line(double x1, double y1, double x2, double y2) : Figure(x1, y1) {
	if (x1 == x2 && y1 == y2) return;
	this->a = y1 - y2;
	this->b = - x1 + x2;
	this->c = +x1 * (y2 - y1) - y1 * (x2 - x1);
	addPoint(std::make_pair(x2,y2));
};

/**
*	@brief Constructor
*	@details An implementation of the line by 2 points
*	@param p1 first point
*	@param p2 second point
*/
Line::Line(Figure p1, Figure p2) : Line(p1.getX(), p1.getY(), p2.getX(), p2.getY()){};

/**
*	@brief Constructor
*	@details An implementation of the line by 2 points
*	@param p1 first point
*	@param p2 second point
*/
Line::Line(pair<double, double> p0, pair<double, double> p1):Line(p0.first, p0.second, p1.first, p1.second){};

/*SETTERS/GETTERS*/

/**
*	@brief Sets slope of the line
*/
void Line::setK() {
	if (b != 0) {
		this->k = -a / b;
		this->d = -c / b;
		setY(d);
	}
	else {
		this->k = INFINITY;
		this->d = 0;
		setY(d);
	}
};

double Line::getK() { setK(); return k; };
double Line::getA() { return a; };
double Line::getB() { return b; };
double Line::getC() { return c; };
double Line::getD() { setK(); return d; };

/**
*	@brief point on the line
*	@details finds y coordinate of the point of the line by x coordinate
*	if there is none return point (-c/a, 1)
*	@param x coordinate
*	@return point on the line
*/
Figure Line::getPointbyX(double x) { 
	Figure P(0,0);
	if (b == 0) {
		P.setY(x);
		P.setX(-c / a);
	}
	else {
		P.setY((-c - a * x) / b);
		P.setX(x);
	}
	return P;
};

/**
*	@brief point on the line
*	@details finds x coordinate of the point of the line by y coordinate
*	if there is none return point (1, -c/b)
*	@param y coordinate
*	@return point on the line
*/
Figure Line::getPointbyY(double y) { 
	Figure P(0,0);
	if (a == 0) {
		P.setX(y);
		P.setY(-c / b);
	}
	else {
		P.setX((-c - b * y) / a);
		P.setY(y);
	}
	return P;
};

/**
*	@brief check if point is on the line
*	@param P point
*	@return true if point is laying on the line
*/
bool Line::chekPoint(Figure P) {
	
	if (a == 0) {
		return (P.getY() == -c / b);
	}
	else if (b == 0) {
		return (P.getX() == -c / a);
	}
	else {
		return (P.getX() == (-c - b * P.getY()) / a);
	}
}

void Line::showType() {
	cout << "Line: " << a << "*x + (" << b << ")*y + (" << c << ") = 0" << endl;
	Figure:showType();
};


/**
*	@brief check if line is parallel to other line
*	@param a1 coefficient a of the first line
*	@param b1 coefficient b of the first line
*	@param a2 coefficient a of the second line
*	@param b2 coefficient b of the second line
*	@return true if lines are parallel
*/
bool Line::isParall(double a1, double b1, double a2, double b2) {
	if (a1 == 0 && a2 == 0) return true;
	if (b1 == 0 && b2 == 0) return true;
	return ((a1 / a2) == (b1 / b2));
}

/**
*	@brief check if line is parallel to other line
*	@param l  line 
*	@return true if lines are parallel
*/
bool Line::isParall(Line l) {
	return isParall(a, b, l.getA(), l.getB());
}


Figure Line::intersectPoint(Line l) {
	Figure p(0, 0);
	double a2 = l.getA();
	double b2 = l.getB();
	double c2 = l.getC();
	double det = a * b2 - a2 * b;
	p.setX((b * c2 - b2 * c) / det);
	p.setY((a2 * c - a * c2) / det);
	return p;
}

double Line::destination(Figure p) {
	double dest;
	dest = abs((a * p.getX() + b * p.getY() + c) / (sqrt(pow(a, 2) + pow(b, 2))));
	return dest;
};

/**
*	@brief Calculates angle between 2 Lines
*	@details Calculates angle between 2 lines
*	if they don`t intersect returns 0
*	@param l Line
*	@return Angle between Lines in degrees
*/
double Line::angle(Line l) {
	double cos_a;
	cos_a = abs((a * l.getA()) + (b * l.getB())) / ((sqrt(pow(a, 2) + pow(b, 2)))*(sqrt(pow(l.getA(), 2) + pow(l.getB(), 2))));
	double angle;
	angle = acos(cos_a);
	if (angle > M_PI_2) angle = M_PI - angle; 
	return angle * (180 / M_PI);
};

/**
*	@brief Calculates angle between Circle and Line
*	@details Calculates angle between Line and tangent line to a circle that touches their intersect point
*	if they don`t intersect returns 90
*	@param O Circle
*	@return Angle between Circle and Line in degrees
*/
double Line::angle(Circle O) {
	return O.angle(*this);
};

/**
*	@brief Perpendicular Line
*	@details returns perpendicular Line
*	@param p point
*	@return perpendicular Line
*/
Line Line::perpendicularLine(Figure p) {
	Line l(b, -a, -b * p.getX() + a * p.getY());
	return l;
};

/**
*	@brief Calculates intersect points between 2 Lines
*	@param l Line
*	@return vector of intersect points
*/
vector<Figure> Line::intersect(Line l) {
	vector<Figure> p;
	if (this->isParall(l)) {
		cout << "Lines are parallel" << endl;
		if (c == l.getC()) {
			cout << "There are an infinite number of solutions" << endl;
		}
		return p;
	};
	p.push_back(intersectPoint(l));
	return p;
}

/**
*	@brief Calculates intersect points between Circle and Line
*	@param O Circle
*	@return vector of intersect points
*/
vector<Figure> Line::intersect(Circle O) {
	vector<Figure> p;

	double d = destination(O);
	
	if (d > O.getRadius()) return p;
	else if (d == O.getRadius()) { 
		Line perpend = perpendicularLine(O);
		
		p.push_back(intersectPoint(perpend));
		return p; 
	}
	else {
		Figure temp = O;
		if (d != 0) {
			Line perpend = perpendicularLine(O);
			temp = intersectPoint(perpend);
		}
		
		double dest;
		dest = sqrt(pow(O.getRadius(), 2) - pow(temp.destinationPoints(O), 2)) / sqrt(pow(a, 2) + pow(b, 2));
		
		Figure p1 = temp;
		p1.displace(b*dest, -a*dest);
		p.push_back(p1);
		p1 = temp;
		p1.displace(-b*dest, a*dest);
		p.push_back(p1);
		
		return p; 
	}
}

/**
*	@brief line symmerty of a point
*	@param p point
*	@return new point
*/
Figure Line::symmetry(Figure p) {
	Line l = perpendicularLine(p);
	Figure P0 = intersectPoint(l);
	Figure P((2*P0.getX()-p.getX()), (2 * P0.getY() - p.getY()));
	return P;
}

/**
*	@brief line symmerty of a Line
*	@param l Line
*	@return new line
*/
Line Line::symmetry(Line l) {
	if (angle(l) == 0) {
		Line l1(a, b, 2 * c + l.getC());
		return l1;
	}
	if (angle(l)==90) {
		return l;
	}
	else {
		Figure p1 = symmetry(Figure(l.getX(), l.getY()));
		p1.showType();
		Figure p2 = symmetry(l.getPointbyX(1));
		p2.showType();
		Line l1(p1, p2);
		return l1;
	}
}

/**
*	@brief line symmerty of a Circle
*	@param O Circle
*	@return new Circle
*/
Circle Line::symmetry(Circle O) {
	Figure P0(O.getX(), O.getY());
	Figure P1 = symmetry(P0);
	Circle O1(P1, O.getRadius());
	return O1;
}

