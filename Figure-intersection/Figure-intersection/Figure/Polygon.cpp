/**
*	@file Polygon.cpp
*
*	@brief Lab#3 Polygon class
*
*	@author Bondarets Daryna K-29
*
*	@version 2.0 06/12/19
*/

#include "Polygon.h"

Polygon::Polygon():Figure(){};

Polygon::Polygon(vector<pair<double, double>> points):Figure(points) {
	for (int i = 0; i < points.size()-1; i++) {
		Segment l(points[i], points[i + 1]);
		addEdge(l);
	}
	Segment l(points[points.size() - 1], points[0]);
	addEdge(l);
	type = 4;
};

Polygon::Polygon(vector<Line> edg){
	for (int i = 0; i < edg.size() - 1; i++) {
		if (edg[i].isParall(edg[i + 1])) { return; }
		else {
			addPoint(edg[i].intersectPoint(edg[i+1]));
		}
	}
	if (edg[edg.size()-1].isParall(edg[0])) { return; }
	else {
		addPoint(edg[edg.size() - 1].intersectPoint(edg[0]));
	}
	Polygon(getPoints());
};

void Polygon::showType(){
	std::cout << "POLYGON: {" << std::endl;
	Figure::showType();
	std::cout << "}" << std::endl;
}

void Polygon::addPoint(Figure p) {
	Figure::addPoint(p.getPoints()[0]);
	vector<pair<double, double>> points = getPoints();
	Segment l1(points[points.size() - 2], points[points.size() - 1]);
	edges[edges.size() - 1] = l1;
	Segment l(points[points.size() - 1], points[0]);
	addEdge(l);
};

void Polygon::addPoint(pair<double, double> p) {
	Figure::addPoint(p);
	vector<pair<double, double>> points = getPoints();
	Segment l1(points[points.size() - 2], points[points.size() - 1]);
	edges[edges.size() - 1] = l1;
	Segment l(points[points.size() - 1], points[0]);
	addEdge(l);
};

void Polygon::addEdge(Segment l) {
	edges.push_back(l);
};

void Polygon::draw(sf::RenderWindow &win, double koef, double x, double y) {
	for (auto e : edges) {
		e.draw(win, koef, x, y);
	}
};

vector<Figure> Polygon::intersect(Figure p)
{
	vector<Figure> res;
	for (auto a : edges)
		if (a.checkPoint(p)) res.push_back(p);
	return res;
}

vector<Figure> Polygon::intersect(class Line l) 
{
	vector<Figure> res;
	for (auto a : edges) {
		vector<Figure> temp = a.intersect(l);
		res.insert(res.end(), temp.begin(), temp.end());
	}
	return res;
}

vector<Figure> Polygon::intersect(class Circle O)
{
	vector<Figure> res;
	for (auto a : edges) {
		vector<Figure> temp = a.intersect(O);
		res.insert(res.end(), temp.begin(), temp.end()); 
	}
	return res;
}

vector<Figure> Polygon::intersect(class Segment s)
{
	vector<Figure> res;
	for (auto a : edges) {
		vector<Figure> temp = a.intersect(s);
		res.insert(res.end(), temp.begin(), temp.end());
	}
	return res;
}

vector<Figure> Polygon::intersect(Polygon s)
{
	vector<Figure> res;
	for (auto a : edges) {
		for (auto b : s.getEdges()) {
			vector<Figure> temp = a.intersect(b);
			res.insert(res.end(), temp.begin(), temp.end());
		}
	}

	return res;
}
