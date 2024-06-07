#include "Shape.h"

unsigned int MyGeometry::Shape::get_x() const
{
	return this->x;
}

unsigned int MyGeometry::Shape::get_y() const
{
	return this->y;
}

unsigned int MyGeometry::Shape::get_line_width() const
{
	return this->line_width;
}
unsigned int MyGeometry::Shape::set_size(unsigned int size)
{
	return size<MIN_SIZE ? MIN_SIZE : size>MAX_SIZE ? MAX_SIZE : size;
}

void MyGeometry::Shape::set_x(unsigned int x)
{
	this->x = x < MAX_HORICONTAL_RESOLUTION ? x : MAX_HORICONTAL_RESOLUTION;
}

void MyGeometry::Shape::set_y(unsigned int y)
{
	this->y = y < MAX_VERTICAL_RESOLUTION ? y : MAX_VERTICAL_RESOLUTION;
}

void MyGeometry::Shape::set_line_width(unsigned int line_width)
{
	if (line_width < MIN_LINE_WIDTH)
		this->line_width = MIN_LINE_WIDTH;
	if (line_width > MAX_LINE_WIDTH)
		this->line_width = MAX_LINE_WIDTH;
	this->line_width = line_width;
}

void MyGeometry::Shape::set_color(MyGeometry::Color color)
{
	this->color = color;
}

MyGeometry::Shape::Shape(unsigned int x, unsigned int y, unsigned int live_width, Color color) :color(color)
{
	set_x(x);
	set_y(y);
	set_line_width(live_width);

}

MyGeometry::Shape::Shape()
{
	this->color = static_cast<MyGeometry::Color>(/*MyGeometry::Color::BLUE+ */ (std::rand() % MyGeometry::Color::BLUE));
	this->x = 50 + rand() % (150 - 50 + 1);
	this->y = 50 + rand() % (150 - 50 + 1);
	this->line_width = rand() % MAX_LINE_WIDTH;
	this->hwnd = GetConsoleWindow();
	this->hdc = GetDC(hwnd);
	//this->hPen = CreatePen(PS_SOLID, this->line_width, this->color);
	this->hBrush = CreateSolidBrush(this->color);
}

void MyGeometry::Shape::info() const
{
	std::cout << "Площадь фигуры: " << get_area() << std::endl;
	std::cout << "Периметр фигуры: " << get_perimeter() << std::endl;
	/*Sleep(500);
	system("cls");*/
	draw();
}

void MyGeometry::Shape::draw() const
{
	//SelectObject(hdc, hPen);
	HBRUSH	hBrush = CreateSolidBrush(this->color);
	SelectObject(hdc, hBrush);
	draw_figura();
	//удаляем 
	DeleteObject(hBrush);
	ReleaseDC(hwnd, hdc);
}




