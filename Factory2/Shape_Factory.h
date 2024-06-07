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
	~Shape_Factory();
	void info()const;
private:	
	MyGeometry::Shape* shape = nullptr;	
};

