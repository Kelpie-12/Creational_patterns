#include "Cube.h"

MyCube::Square::Square()
{
	this->side = rand() % 300;
}

double MyCube::Square::get_side() const
{
	return this->side;
}

void MyCube::Square::set_side(double side)
{
	this->side = set_size(side);
}

MyCube::Square::Square(double side, unsigned int x, unsigned int y, unsigned int live_width, MyGeometry::Color color):MyRectangle::Rectangle(side,side,x,y,live_width,color)
{
	this->set_side(side);
}

double MyCube::Square::get_area() const
{
	return this->side*this->side;
}

double MyCube::Square::get_perimeter() const
{
	return this->side*4;
}

void MyCube::Square::draw() const
{
	HWND hwnd = GetConsoleWindow();
	HDC hdc = GetDC(hwnd);
	HPEN hPen = CreatePen(PS_SOLID, this->line_width, this->color);
	HBRUSH hBrush = CreateSolidBrush(this->color);
	SelectObject(hdc, hPen);
	SelectObject(hdc, hBrush);

	::Rectangle(hdc, x, y, x + side, y + side);

	//удаляем 
	DeleteObject(hPen);
	DeleteObject(hBrush);
	ReleaseDC(hwnd, hdc);
}

void MyCube::Square::info() const
{
	std::cout << typeid(*this).name() << std::endl;
	std::cout << "Сторона квадрата " << get_side() << std::endl;	
	MyGeometry::Shape::info();
}



