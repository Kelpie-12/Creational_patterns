#pragma once
#include "Shape_Factory.h"
class Buider_Shape
{
public:
	Buider_Shape();
	~Buider_Shape();
	MyGeometry::Shape* build_rectangle();
	MyGeometry::Shape* build_rectangle(double width, double height, unsigned int x, unsigned int y, unsigned int live_width, MyGeometry::Color color);
	MyGeometry::Shape* build_triangle();
	MyGeometry::Shape* build_triangle(MyGeometry::Vector2 v1, MyGeometry::Vector2 v2, MyGeometry::Vector2 v3, int line_width, MyGeometry::Color color);
	MyGeometry::Shape* build_circle();
	MyGeometry::Shape* build_circle(double radius, unsigned int x, unsigned int y, unsigned int live_width, MyGeometry::Color color);
	MyGeometry::Shape* build_square();
	MyGeometry::Shape* build_square(double side, unsigned int x, unsigned int y, unsigned int live_width, MyGeometry::Color color);
private:
	
};

