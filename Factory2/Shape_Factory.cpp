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

Shape_Factory::~Shape_Factory()
{
	delete this->shape;
	std::cout << "Delete shape" << std::endl;
}

void Shape_Factory::info() const
{
	this->shape->info();	
}




