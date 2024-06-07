#include <iostream>
#include "Shape_Factory.h"

using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));	
	Shape_Factory a;
	a.info();
	/*MyGeometry::Triangle rect;
	rect.draw();*/

	/*MyGeometry::Triangle a;
	MyGeometry::Square square(50,150,200,9,MyGeometry::GREEN);
	MyGeometry::Circle c(25, 150, 200, 9, MyGeometry::YELLOW);
	rect.draw();
	Sleep(500);
	a.draw();
	Sleep(500);
	square.draw();
	Sleep(500);
	c.draw();*/
}