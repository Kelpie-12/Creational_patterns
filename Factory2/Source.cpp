#include <iostream>
#include "Shape_Factory.h"
#include "Buider_Shape.h"

using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));
	Shape_Factory a(100, 200, 8, MyGeometry::Color::YELLOW);
	Shape_Factory d((MyGeometry::Circle(10, 150, 250, 9, MyGeometry::Color::YELLOW)));
	Buider_Shape e;
	//e.build_rectangle();	
	//Shape_Factory c(e.build_rectangle(55,55,300,300,7,MyGeometry::Color::BLUE));
	//e.build_square();
	Shape_Factory t(e.build_circle(/*300.0, 300, 300, 8, MyGeometry::Color::GREEN)*/));
	
	//c.info();
	t.info();
	//a.info();

}