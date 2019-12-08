#include <iostream>

#include "Figure/Figure.h"
#include "Figure/Circle.h"
#include "Figure/Line.h"
//#include "Figure/Polygon.h"


int main(){
	Figure p(0,1);
	Figure p2(1,0);
	p.showType();
	p2.showType();
	std::cout << p2.destinationPoints(p);

	Line l(p,p2);
	l.showType();
	
	return  0;
}
