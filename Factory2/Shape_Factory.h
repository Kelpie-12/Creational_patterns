#pragma once
#include <Windows.h>
#include "Rectangle.h"
#include "Shape.h"
#include "Triangle.h"
#include "Cube.h"
#include "Circle.h"
#include <math.h>

class Shape_Factory
{
public:
	Shape_Factory();
	Shape_Factory(MyGeometry::Shape* a);
	Shape_Factory(MyGeometry::Circle c);
	Shape_Factory(MyGeometry::Square c);
	Shape_Factory(MyGeometry::Rectangle c);
	Shape_Factory(MyGeometry::Triangle c);
	Shape_Factory(unsigned int x, unsigned int y, unsigned int live_width = 5, MyGeometry::Color color = MyGeometry::Color::GREY);
	~Shape_Factory();
	void info()const;
private:	
	MyGeometry::Shape* shape = nullptr;	
};

