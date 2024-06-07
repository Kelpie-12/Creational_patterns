#include "Shape_Factory.h"

Shape_Factory::Shape_Factory()
{	
	int r = rand() % 4;
	if (r==0)
	{
		this->shape = new MyGeometry::Rectangle;
	}
	else if (r==1)
	{
		this->shape = new MyGeometry::Circle;
	}
	else if (r==2)
	{
		this->shape = new MyGeometry::Square;
	}
	else if (r==3)
	{
		this->shape = new MyGeometry::Triangle;
	}
}

Shape_Factory::Shape_Factory(unsigned int x, unsigned int y, unsigned int live_width, MyGeometry::Color color)
{	
	int r = rand() % 4;
	if (r == 0)
	{
		this->shape = new MyGeometry::Rectangle;
	}
	else if (r == 1)
	{
		this->shape = new MyGeometry::Circle;
	}
	else if (r == 2)
	{
		this->shape = new MyGeometry::Square;
	}
	else if (r == 3)
	{
		this->shape = new MyGeometry::Triangle;
	}
	this->shape->set_x(x);
	this->shape->set_y(y);
	this->shape->set_line_width(live_width);
	this->shape->set_color(color);
}

Shape_Factory::~Shape_Factory()
{
	delete this->shape;
	std::cout << "Delete shape" << std::endl;
}

void Shape_Factory::info() const
{
	this->shape->info();	
}




