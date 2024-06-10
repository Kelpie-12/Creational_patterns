#pragma once
#include "Rectangle.h"


double MyGeometry::Rectangle::get_width() const
{
	return this->width;
}

double MyGeometry::Rectangle::get_heigth() const
{
	return this->heigth;
}

void MyGeometry::Rectangle::set_width(double width)
{
	this->width = set_size(width);
}

void MyGeometry::Rectangle::set_heigth(double heigth)
{
	this->heigth = set_size(heigth);
}

MyGeometry::Rectangle::Rectangle(double width, double height, unsigned int x, unsigned int y, unsigned int live_width, Colors color)
	:Shape(x,y,live_width,color)
{
	set_heigth(height);
	set_width(width);
}

MyGeometry::Rectangle::Rectangle()
{
	this->heigth = 1 + rand() % 50;
	this->width = rand() % 50;
}

double MyGeometry::Rectangle::get_area() const
{
	return this->width * this->heigth;
}

double MyGeometry::Rectangle::get_perimeter() const
{
	return (this->width + this->heigth) * 2;
}

void MyGeometry::Rectangle::info() const
{
	std::cout << typeid(*this).name() << std::endl;
	std::cout << "Ширина прямоугольника: " << get_width() << std::endl;
	std::cout << "Высота прямоугольника: " << get_heigth() << std::endl;
	Shape::info();
}

void MyGeometry::Rectangle::draw_figura() const
{
	::Rectangle(hdc, x, y, x + width, y + heigth);
}

