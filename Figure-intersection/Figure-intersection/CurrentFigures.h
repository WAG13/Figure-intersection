#pragma once
#include <vector>
#include "Figure/Figure.h"
#include "Figure/Circle.h"
#include "Figure/Line.h"
#include "Figure/Segment.h"
#include "Figure/Polygon.h"

using std::vector;

class CurrentFigures
{
public:
	CurrentFigures() {};
	~CurrentFigures() {};
	void addFigure(Figure p) {
		intersection_figures.push_back(p);
		figures.push_back(p);
	};
	void addCircle(Circle p) {
		addInter(p);
		circles.push_back(p);
	};
	void addLine(Line p) {
		addInter(p);
		lines.push_back(p);
	};
	void addSegment(Segment p) {
		addInter(p);
		segments.push_back(p);
	};
	void addPolygon(Polygon p) {
		addInter(p);
		polygons.push_back(p);
	};

	void addInter(Circle a) {
		vector<Figure> temp;
		for (auto f : circles) {
			temp = f.intersect(a);
			for (auto t : temp)
				add_new(t);
			temp.clear();
		};
		for (auto f : lines) {
			temp = f.intersect(a);
			for (auto t : temp)
				add_new(t);
			temp.clear();
		};
		for (auto f : segments) {
			temp = f.intersect(a);
			for (auto t : temp)
				add_new(t);
			temp.clear();
		};
		for (auto f : polygons) {
			temp = f.intersect(a);
			for (auto t : temp)
				add_new(t);
			temp.clear();
		};
	};

	void addInter(Line a) {
		vector<Figure> temp;
		for (auto f : circles) {
			temp = f.intersect(a);
			for (auto t : temp)
				add_new(t);
			temp.clear();
		};
		for (auto f : lines) {
			temp = f.intersect(a);
			for (auto t : temp)
				add_new(t);
			temp.clear();
		};
		for (auto f : segments) {
			temp = f.intersect(a);
			for (auto t : temp)
				add_new(t);
			temp.clear();
		};
		for (auto f : polygons) {
			temp = f.intersect(a);
			for (auto t : temp) {
				intersection_figures.push_back(t);
			}
			temp.clear();
		};
	};

	void addInter(Segment a) {
		vector<Figure> temp;
		for (auto f : circles) {
			temp = a.intersect(f);
			for (auto t : temp)
				add_new(t);
			temp.clear();
		};
		for (auto f : lines) {
			temp = a.intersect(f);
			for (auto t : temp)
				add_new(t);
			temp.clear();
		};
		for (auto f : segments) {
			temp = a.intersect(f);
			for (auto t : temp)
				add_new(t);
			temp.clear();
		};
		for (auto f : polygons) {
			temp = f.intersect(a);
			for (auto t : temp)
				add_new(t);
			temp.clear();
		};
	};

	void addInter(Polygon a) {
		vector<Figure> temp;
		for (auto f : circles) {
			temp = a.intersect(f);
			for (auto t : temp)
				add_new(t);
			temp.clear();
		};
		for (auto f : lines) {
			temp = a.intersect(f);
			for (auto t : temp)
				add_new(t);
			temp.clear();
		};
		for (auto f : segments) {
			temp = a.intersect(f);
			for (auto t : temp)
				add_new(t);
			temp.clear();
		};
		for (auto f : polygons) {
			temp = a.intersect(f);
			for (auto t : temp)
				add_new(t);
			temp.clear();
		};
	};

	vector<Figure> getInterFigures() {
		return intersection_figures;
	}

	vector<Figure> getFigures() {
		return figures;
	}
	vector<Circle> getCircles() {
		return circles;
	}
	vector<Line> getLines() {
		return lines;
	}
	vector<Segment> getSegments() {
		return segments;
	}
	vector<Polygon> getPolygons() {
		return polygons;
	}

private:
	std::vector<Figure> figures;
	std::vector<Circle> circles;
	std::vector<Line> lines;
	std::vector<Segment> segments;
	std::vector<Polygon> polygons;
	
	std::vector<Figure> intersection_figures;

	void add_new(Figure p) {
		for (auto a : intersection_figures) {
			if ((a.getX() == p.getX()) && (a.getY() == p.getY())) return;
		};
		p.showType();
		intersection_figures.push_back(p);
	}
};