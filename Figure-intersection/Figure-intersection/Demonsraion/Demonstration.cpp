/**
*	@file Demonstration.cpp
*
*	@brief Demonstration for Lab#3 Figures
*
*	@author Bondarets Daryna K-29
*
*	@version 2.0 15/12/19
*/

#include "Demonstration.h"

/**
* @brief starts demonstration mode
*/
void Demonstration::start() {
	system("CLS");
	cout << "******************MENU******************" << endl;
	cout << "You are in demonstration mode. Make your choise:" << endl;
	cout << "1 - Test Figure class" << endl;
	cout << "2 - Test Sparse List class" << endl;
	cout << "3 - Test Sparse Matrix class" << endl;
	cout << "4 - Exit" << endl;

	int ind = 0;
	cin >> ind;
	switch (ind)
	{
	case 1:
		testFigureClass();
		break;
	case 2:
		testSparseListClass();
		break;
	case 3:
		testSparseMatrixClass();
		break;
	default:
		break;
	}
	return;
};

void Demonstration:: testFigureClass() {
	system("CLS");
	cout << "You are in Test Figure Class mode. Make your choise:" << endl;
	cout << "1 - Create Circle" << endl;
	cout << "2 - Create Line" << endl;
	cout << "3 - Return to menu" << endl;
	cout << "4 - Exit" << endl;
	int ind = 0;
	cin >> ind;
	switch (ind)
	{
	case 1:
		testCircleClass();
		break;
	case 2:
		testLineClass();
		break;
	case 3:
		start();
		break;
	default:
		break;
	}
	return;
};

void Demonstration::testCircleClass() {
	system("CLS");
	cout << "You are in Test Circle Class mode. Make your choise:" << endl;
	cout << "1 - Input Circle" << endl;
	cout << "2 - Create random Circle" << endl;
	cout << "3 - Return to menu" << endl;
	cout << "4 - Exit" << endl;
	int ind = 0;
	cin >> ind;
	system("CLS");
	switch (ind)
	{
	case 1: 
	{
		Circle O = getCircle();
		functionsWithCircle(O);
	}
		break;
	case 2:
	{
		Circle O = getRandomCircle();
		functionsWithCircle(O);
	}
		break;
	case 3:
		start();
		break;
	default:
		break;
	}
	
	return;
};

void Demonstration::functionsWithCircle(Circle O) {
	
	cout << endl;
	O.showType();
	cout << "You are in functions With Circle mode. Make your choise:" << endl;
	cout << "1 - Print" << endl;

	cout << "2 - Intersection with Line" << endl;
	cout << "3 - Intersection with Circle" << endl;

	cout << "4 - Invertion with Line" << endl;
	cout << "5 - Invertion with Circle" << endl;

	cout << "6 - Angle with Line" << endl;
	cout << "7 - Angle with Circle" << endl;

	cout << "8 - Return to menu" << endl;
	cout << "9 - Exit" << endl;

	int ind = 0;
	cin >> ind;
	system("CLS");
	switch (ind)
	{
	case 1:
	{
		O.showType();
		functionsWithCircle(O);
	}
		break;

	case 2:
	{
		Line L = getLine();
		
		vector<Figure> points = O.intersect(L);
		for (auto point : points) {
			point.showType();
		}
		functionsWithCircle(O);
	}
		break;

	case 3:
	{
		Circle O1 = getCircle();
		
		vector<Figure> points = O.intersect(O1);
		for (auto point : points) {
			point.showType();
		}
		functionsWithCircle(O);
	}
		break;

	case 4:
	{
		Line L = getLine();
		O.inversion(L)->showType();
		functionsWithCircle(O);
	}
		break;

	case 5: 
	{
		Circle O1 = getCircle();
		O.inversion(O1)->showType();
		functionsWithCircle(O);
	}
		break;

	case 6: 
	{
		Line L = getLine();
		cout << "angle = " << O.angle(L) << endl;
		functionsWithCircle(O);
	}
		break;

	case 7: 
	{
		Circle O1 = getCircle();
		cout << "angle = " << O.angle(O1) << endl;
		functionsWithCircle(O);
	}
		break;
	
	case 8:
		start();
		break;
	default:
		break;
	}
	return;
};

void Demonstration::testLineClass() {
	system("CLS");
	cout << "You are in Test Line Class mode. Make your choise:" << endl;
	cout << "1 - Input Line" << endl;
	cout << "2 - Create random Line" << endl;
	cout << "3 - Return to menu" << endl;
	cout << "4 - Exit" << endl;
	int ind = 0;
	cin >> ind;
	system("CLS");
	switch (ind)
	{
	case 1: 
	{
		Line L = getLine();
		functionsWithLine(L);
	}
		break;
	case 2:
	{
		Line L = getRandomLine();
		functionsWithLine(L);
	}
		break;
	case 3:
		start();
		break;
	default:
		break;
	}
	
	return;
};

void Demonstration::functionsWithLine(Line L) {
	
	cout << endl;
	L.showType();
	cout << "You are in functions With Line mode. Make your choise:" << endl;
	cout << "1 - Print" << endl;

	cout << "2 - Intersection with Line" << endl;
	cout << "3 - Intersection with Circle" << endl;

	cout << "4 - Symmetry with Line" << endl;
	cout << "5 - Symmetry with Circle" << endl;

	cout << "6 - Angle with Line" << endl;
	cout << "7 - Angle with Circle" << endl;

	cout << "8 - Return to menu" << endl;
	cout << "9 - Exit" << endl;

	int ind = 0;
	cin >> ind;
	system("CLS");
	switch (ind)
	{
	case 1:
	{
		L.showType();
		functionsWithLine(L);
	}
		break;

	case 2:
	{
		Line L1 = getLine();
		
		vector<Figure> points = L1.intersect(L);
		for (auto point : points) {
			point.showType();
		}
		functionsWithLine(L);
	}
		break;

	case 3:
	{
		Circle O = getCircle();
		
		vector<Figure> points = L.intersect(O);
		for (auto point : points) {
			point.showType();
		}
		functionsWithLine(L);
	}
		break;

	case 4:
	{
		Line L1 = getLine();
		L.symmetry(L1).showType();
		functionsWithLine(L);
	}
		break;

	case 5: 
	{
		Circle O = getCircle();
		L.symmetry(O).showType();
		functionsWithLine(L);
	}
		break;

	case 6: 
	{
		Line L1 = getLine();
		cout << "angle = " << L.angle(L1) << endl;
		functionsWithLine(L);
	}
		break;

	case 7: 
	{
		Circle O = getCircle();
		cout << "angle = " << L.angle(O) << endl;
		functionsWithLine(L);
	}
		break;
	
	case 8:
		start();
		break;
	default:
		break;
	}
	return;
};

Circle Demonstration::getCircle() {
	cout << "Input (x, y) of centre of Circle and it`s radius:" << endl;
	double x, y, radius;
	cout << "x = ";
	cin >> x;
	cout << "y = ";
	cin >> y;
	cout << "radius = ";
	cin >> radius;
	Circle O(x, y, radius);
	return O;
};

Circle Demonstration::getRandomCircle() {
	double x, y, radius;
	x = getRandomInt(10);
	y = getRandomInt(10);
	radius = getRandomInt(10)+1;
	Circle O(x, y, radius);
	return O;
};

Line Demonstration::getLine() {
	cout << "Input a, b, c of Line ( a*x + b*y + c = 0 )" << endl;
	double a, b, c;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "c = ";
	cin >> c;
	Line L(a, b, c);
	return L;
};

Line Demonstration::getRandomLine() {
	double a, b, c;
	a = getRandomInt(10);
	b = getRandomInt(10);
	c = getRandomInt(10);
	Line L(a, b, c);
	return L;
};

Figure* Demonstration::getRandomFigure() {
	int ind;
	ind = getRandomInt(2);
	switch (ind)
	{
	case 0:
	{
		Figure* F = new Circle(getRandomCircle());
		return F;
		
	}
		break;

	case 1:
	{
		Figure* F = new Line(getRandomLine());
		return F;
	}
		break;

	default:
	{
		Figure* F = new Figure();
		return F;
	}
		break;
	}
	
};

int Demonstration::getRandomInt(int max) {
	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, max);
	return dis(gen);
};

double Demonstration::getRandomDouble(int max) {
	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(0, max);
	return dis(gen);
};
