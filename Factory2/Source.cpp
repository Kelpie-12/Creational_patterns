#include <iostream>
#include <Windows.h>
#include "Rectangle.h"
#include "Shape.h"
#include "Triangle.h"
#include "Cube.h"
#include "Circle.h"
#include <math.h>

using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));	
	MyGeometry::Rectangle rect/*(100, 50, 150, 150, 8, MyGeometry::RED)*/;
	MyGeometry::Triangle a;
	MyGeometry::Square square(50,150,200,9,MyGeometry::GREEN);
	MyGeometry::Circle c(25, 150, 200, 9, MyGeometry::YELLOW);
	rect.draw();
	Sleep(500);
	a.draw();
	Sleep(500);
	square.draw();
	Sleep(500);
	c.draw();
}