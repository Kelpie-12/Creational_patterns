#pragma once
#include "Rectangle.h"


double MyRectangle::Rectangle::get_width() const
{
	return this->width;
}

double MyRectangle::Rectangle::get_heigth() const
{
	return this->heigth;
}

void MyRectangle::Rectangle::set_width(double width)
{
	this->width = set_size(width);
}

void MyRectangle::Rectangle::set_heigth(double heigth)
{
	this->heigth = set_size(heigth);
}

MyRectangle::Rectangle::Rectangle(double width, double height, unsigned int x, unsigned int y, unsigned int live_width, MyGeometry::Color color)
	:MyGeometry::Shape(x,y,live_width,color)
{
	set_heigth(height);
	set_width(width);
}

MyRectangle::Rectangle::Rectangle()
{
	this->heigth = 1 + rand() % 50;
	this->width = rand() % 50;
}

double MyRectangle::Rectangle::get_area() const
{
	return this->width * this->heigth;
}

double MyRectangle::Rectangle::get_perimeter() const
{
	return (this->width + this->heigth) * 2;
}

void MyRectangle::Rectangle::draw() const
{
	HWND hwnd = GetConsoleWindow();
	HDC hdc = GetDC(hwnd);
	HPEN hPen = CreatePen(PS_SOLID, this->line_width, this->color);
	HBRUSH hBrush = CreateSolidBrush(this->color);
	SelectObject(hdc, hPen);
	SelectObject(hdc, hBrush);

	::Rectangle(hdc, x, y, x + width, y + heigth);

	//удаляем 
	DeleteObject(hPen);
	DeleteObject(hBrush);
	ReleaseDC(hwnd, hdc);

}

void MyRectangle::Rectangle::info() const
{
	std::cout << typeid(*this).name() << std::endl;
	std::cout << "Ширина прямоугольника: " << get_width() << std::endl;
	std::cout << "Высота прямоугольника: " << get_heigth() << std::endl;
	MyGeometry::Shape::info();
}

