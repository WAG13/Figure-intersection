#include "Segment.h"

/**
*	@brief Constructor
*	@details An implementation of the Segment by 2 points
*	@param x1 x coordinate of first point
*	@param y1 y coordinate of first point
*	@param x2 x coordinate of second point
*	@param y2 y coordinate of second point
*/
Segment::Segment(double x1, double y1, double x2, double y2) : Figure(x1, y1), line(x1, y1, x2, y2) {
	addPoint(std::make_pair(x2, y2));
};

/**
*	@brief Constructor
*	@details An implementation of the Segment by 2 points
*	@param p1 first point
*	@param p2 second point
*/
Segment::Segment(Figure p1, Figure p2) : Segment(p1.getX(), p1.getY(), p2.getX(), p2.getY()) {};

/**
*	@brief Constructor
*	@details An implementation of the Segment by 2 points
*	@param p1 first point
*	@param p2 second point
*/
Segment::Segment(pair<double, double> p0, pair<double, double> p1) :Segment(p0.first, p0.second, p1.first, p1.second) {};

bool Segment::checkPoint(Figure p)
{
	double dest1 = abs(p.getX() - points[0].first) + abs(p.getX() - points[1].first);
	double dest2 = abs(points[0].first - points[1].first);
	if (dest1 != dest2) return false;
	dest1 = abs(p.getY() - points[0].second) + abs(p.getY() - points[1].second);
	dest2 = abs(points[0].second - points[1].second);
	if (dest1 != dest2) return false;
	return line.chekPoint(p);
}

void Segment::showType() {
	cout << "Segment: " << endl;
	Figure:showType();
};

void Segment::draw(sf::RenderWindow &win, double koef, double x, double y) {
	vector<pair<double, double>> temp = getPoints();
	sf::Vertex line[] =
	{
		sf::Vertex(sf::Vector2f((temp[0].first*koef + x), -temp[0].second*koef + y), sf::Color::Yellow),
		sf::Vertex(sf::Vector2f((temp[1].first*koef + x), -temp[1].second*koef + y), sf::Color::Yellow)
	};
	win.draw(line, 2, sf::Lines);
};

double Segment::angle(class Line l)
{
	return line.angle(l);
};

double Segment::angle(class Circle O)
{
	return line.angle(O);
}

vector<Figure> Segment::intersect(class Line l)
{
	vector<Figure> result;
	for (auto p : line.intersect(l)) {
		if (checkPoint(p)) result.push_back(p);
	}
	return result;
}

vector<Figure> Segment::intersect(class Circle O)
{
	vector<Figure> result;
	for (auto p : line.intersect(O)) {
		if (checkPoint(p)) result.push_back(p);
	}
	return result;
}