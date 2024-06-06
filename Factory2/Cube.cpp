#include "Cube.h"

MyGeometry::Square::Square()
{
	this->side = rand() % 300;
}

double MyGeometry::Square::get_side() const
{
	return this->side;
}

void MyGeometry::Square::set_side(double side)
{
	this->side = set_size(side);
}

MyGeometry::Square::Square(double side, unsigned int x, unsigned int y, unsigned int live_width, Color color):Rectangle(side,side,x,y,live_width,color)
{
	this->set_side(side);
}

double MyGeometry::Square::get_area() const
{
	return this->side*this->side;
}

double MyGeometry::Square::get_perimeter() const
{
	return this->side*4;
}

void MyGeometry::Square::draw() const
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

void MyGeometry::Square::info() const
{
	std::cout << typeid(*this).name() << std::endl;
	std::cout << "Сторона квадрата " << get_side() << std::endl;	
	Shape::info();
}



