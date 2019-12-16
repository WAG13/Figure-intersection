/**
*	@file Demonstration.h
*
*	@brief Demonstration for Lab#1 Sparse list & matrix and Figures (circle & line)
*
*	@author Bondarets Daryna K-29
*
*	@version 1.6 18/11/19
*/

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <stdio.h>
#include <stdlib.h>
#include "../Figure/Figure.h"
#include "../Figure/Circle.h"
#include "../Figure/Line.h"
#include "../Figure/Segment.h"
#include "../Figure/Polygon.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

/**
* @brief Demonstration
* @details Demonstration to show how Sparse list & matrix and Figures (circle & line) classes work
*/
class Demonstration
{
private:
	int type;
public:
	Demonstration() {};
	~Demonstration() {};

	void start();

protected:

	void testFigureClass();

	void testCircleClass();
	void functionsWithCircle(Circle O);

	void testLineClass();
	void functionsWithLine(Line L);

	/*RANDOMS*/
	Circle getCircle();
	Circle getRandomCircle();
	Line getLine();
	Line getRandomLine();
	Figure* getRandomFigure();
	
	int getRandomInt(int max);
	double getRandomDouble(int max);
};

