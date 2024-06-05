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
	MyRectangle::Rectangle rect(100, 50, 150, 150, 8, MyGeometry::RED);
	MyTriangle::Triangle a;
	MyCube::Cube cube(50,150,200,9,MyGeometry::GREEN);
	MyCirle::Circle c(25, 150, 200, 9, MyGeometry::YELLOW);
	c.info();	
	
}