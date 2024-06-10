#include "Buider_Shape.h"

Buider_Shape::Buider_Shape()
{

}

Buider_Shape::~Buider_Shape()
{
	//delete this->shape;
}

MyGeometry::Shape* Buider_Shape::build_rectangle()
{
	return new MyGeometry::Rectangle();
}

MyGeometry::Shape* Buider_Shape::build_rectangle(double width, double height, unsigned int x, unsigned int y, unsigned int live_width, MyGeometry::Color color)
{
	return new MyGeometry::Rectangle(width, height,x,y,live_width,color);
}

MyGeometry::Shape* Buider_Shape::build_triangle()
{
	return new MyGeometry::Triangle();
}

MyGeometry::Shape* Buider_Shape::build_triangle(MyGeometry::Vector2 v1, MyGeometry::Vector2 v2, MyGeometry::Vector2 v3, int line_width, MyGeometry::Color color)
{
	return new MyGeometry::Triangle(v1,v2,v3,line_width,color);
}

MyGeometry::Shape* Buider_Shape::build_circle()
{
	return new MyGeometry::Circle();
}

MyGeometry::Shape* Buider_Shape::build_circle(double radius, unsigned int x, unsigned int y, unsigned int live_width, MyGeometry::Color color)
{
	return new MyGeometry::Circle(radius,x,y,live_width,color);
}

MyGeometry::Shape* Buider_Shape::build_square()
{
	return new MyGeometry::Square();
}

MyGeometry::Shape* Buider_Shape::build_square(double side, unsigned int x, unsigned int y, unsigned int live_width, MyGeometry::Color color)
{
	return new MyGeometry::Square(side,x,y,live_width,color);
}
