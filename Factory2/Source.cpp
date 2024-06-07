#include <iostream>
#include "Shape_Factory.h"

using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));
	Shape_Factory a(100, 200, 8, MyGeometry::Color::YELLOW);
	Shape_Factory d((MyGeometry::Circle()));
	d.info();
	a.info();
	
}