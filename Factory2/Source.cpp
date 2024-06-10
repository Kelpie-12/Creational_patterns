#include <iostream>
#include "Shape_Factory.h"
#include "Buider_Shape.h"

using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));
	Buider_Shape e;	
	Shape_Factory t(e.build_circle(/*300,300.0, 300, 300, 8, MyGeometry::Color::GREEN*/));
	t.info();
}