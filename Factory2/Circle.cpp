#include "Circle.h"

MyGeometry::Circle::Circle()
{
	this->radius = 50 + rand() % (150 - 50 + 1);
	this->x = 50 + rand() % (150 - 50 + 1);
	this->y = 50 + rand() % (150 - 50 + 1);
	this->p2.x = this->x + this->radius * 2;
	this->p2.y = this->y + this->radius * 2;
}

MyGeometry::Circle::Circle(double radius, unsigned int x, unsigned int y, unsigned int live_width, Color color) :Shape(x, y, live_width, color)
{
	set_radius(radius);
	set_position(x, y);
}

void MyGeometry::Circle::set_position(unsigned int x, unsigned int y)
{
	set_x(x);
	set_y(y);

	this->p2.x = this->x + this->radius * 2;
	this->p2.y = this->y + this->radius * 2;
}

void MyGeometry::Circle::set_radius(double radius)
{
	this->radius = set_size(radius);
}

double MyGeometry::Circle::get_radius()const
{
	return this->radius;
}

double MyGeometry::Circle::get_area() const
{
	return 3.14 * this->radius * this->radius;
}

double MyGeometry::Circle::get_perimeter() const
{
	return 2 * 3.14 * this->radius;
}

void MyGeometry::Circle::draw() const
{
	HWND hwnd = GetConsoleWindow();
	HDC hdc = GetDC(hwnd);
	HBRUSH hBrush = CreateSolidBrush(this->color);
	SelectObject(hdc, hBrush);
	Ellipse(hdc, this->x, this->y, this->p2.x, this->p2.y);
	//удаляем 
	DeleteObject(hBrush);
	ReleaseDC(hwnd, hdc);
}

void MyGeometry::Circle::info() const
{
	std::cout << typeid(*this).name() << std::endl;
	std::cout << "Радиус круга: " << get_radius() << std::endl;
	Shape::info();
}
