#include "Triangle.h"

double MyTriangle::Triangle::get_area() const
{
	double p = 0.5 * this->get_perimeter();

	return sqrt(p * (p - this->get_side_a()) * (p - this->get_side_b()) * p - this->get_side_c());
}

double MyTriangle::Triangle::get_perimeter() const
{
	return this->get_side_a()+ this->get_side_b() + this->get_side_c();
}

void MyTriangle::Triangle::draw() const
{
	HWND hwnd = GetConsoleWindow();
	HDC hdc = GetDC(hwnd);

	HBRUSH hBrush = CreateSolidBrush(this->color);
	HBRUSH hOldBrush = SelectBrush(hdc, hBrush);

	POINT vertices[] = { {this->vertex1.x,this->vertex1.y}, {this->vertex2.x,this->vertex2.y}, {this->vertex3.x,this->vertex3.y} };
	Polygon(hdc, vertices, sizeof(vertices) / sizeof(vertices[0]));

	SelectBrush(hdc, hOldBrush);
	DeleteObject(hBrush);

}

void MyTriangle::Triangle::info() const
{
	std::cout << typeid(*this).name() << std::endl;
	std::cout << "Катет А " << this->get_side_a() << std::endl;
	std::cout << "Катет В " << this->get_side_b() << std::endl;
	std::cout << "Катет С " << this->get_side_c() << std::endl;
	MyGeometry::Shape::info();
}

double MyTriangle::Triangle::get_side_a() const
{
	int AB = this->vertex1.x - this->vertex2.x;
	int BC = this->vertex1.y - this->vertex2.y;
	return sqrt((AB * AB) + (BC * BC));	
}

double MyTriangle::Triangle::get_side_b() const
{
	int AB = this->vertex1.x - this->vertex3.x;
	int BC = this->vertex1.y - this->vertex3.y;
	return sqrt((AB * AB) + (BC * BC));
}

double MyTriangle::Triangle::get_side_c() const
{
	int AB = this->vertex2.x - this->vertex3.x;
	int BC = this->vertex2.y - this->vertex3.y;
	return sqrt((AB * AB) + (BC * BC));
}

void MyTriangle::Triangle::set_vertex_1(int x, int y)
{
	this->vertex1.x= set_size(x);
	this->vertex1.y = set_size(y);
}
void MyTriangle::Triangle::set_vertex_2(int x, int y)
{
	this->vertex2.x = set_size(x);
	this->vertex2.y = set_size(y);
}
void MyTriangle::Triangle::set_vertex_3(int x, int y)
{
	this->vertex3.x = set_size(x);
	this->vertex3.y = set_size(y);
}

MyTriangle::Triangle::Triangle()
{
	
	this->vertex1.x = 50 + rand() % (200 - 50 + 1);
	this->vertex1.y = 150 + rand() % (300 - 150 + 1);

	this->vertex2.x = 200 + rand() % (350 - 200 + 1);
	this->vertex2.y = 300 + rand() % (450 - 300 + 1);

	this->vertex3.x = 200 + rand() % (350 - 200 + 1);
	this->vertex3.y = 300 + rand() % (450 - 300 + 1);
}

MyTriangle::Triangle::Triangle(MyGeometry::Vector2 v1, MyGeometry::Vector2 v2, MyGeometry::Vector2 v3, int line_width, MyGeometry::Color color) :MyGeometry::Shape(v1.x, v1.y, line_width, color)
{
	this->vertex1 = v1;
	this->vertex2 = v2;
	this->vertex3 = v3;
}
