#include "Triangle.h"

double MyGeometry::Triangle::get_area() const
{
	double p = 0.5 * this->get_perimeter();

	return sqrt(p * (p - this->get_side_a()) * (p - this->get_side_b()) * p - this->get_side_c());
}

double MyGeometry::Triangle::get_perimeter() const
{
	return this->get_side_a()+ this->get_side_b() + this->get_side_c();
}

void MyGeometry::Triangle::info() const
{
	std::cout << typeid(*this).name() << std::endl;
	std::cout << "Катет А " << this->get_side_a() << std::endl;
	std::cout << "Катет В " << this->get_side_b() << std::endl;
	std::cout << "Катет С " << this->get_side_c() << std::endl;
	MyGeometry::Shape::info();
}

void MyGeometry::Triangle::draw_figura() const
{
	POINT vertices[] = { {this->vertex1.x,this->vertex1.y}, {this->vertex2.x,this->vertex2.y}, {this->vertex3.x,this->vertex3.y} };
	Polygon(hdc, vertices, sizeof(vertices) / sizeof(vertices[0]));
}

double MyGeometry::Triangle::get_side_a() const
{
	int AB = this->vertex1.x - this->vertex2.x;
	int BC = this->vertex1.y - this->vertex2.y;
	return sqrt((AB * AB) + (BC * BC));	
}

double MyGeometry::Triangle::get_side_b() const
{
	int AB = this->vertex1.x - this->vertex3.x;
	int BC = this->vertex1.y - this->vertex3.y;
	return sqrt((AB * AB) + (BC * BC));
}

double MyGeometry::Triangle::get_side_c() const
{
	int AB = this->vertex2.x - this->vertex3.x;
	int BC = this->vertex2.y - this->vertex3.y;
	return sqrt((AB * AB) + (BC * BC));
}

void MyGeometry::Triangle::set_vertex_1(int x, int y)
{
	this->vertex1.x= set_size(x);
	this->vertex1.y = set_size(y);
}
void MyGeometry::Triangle::set_vertex_2(int x, int y)
{
	this->vertex2.x = set_size(x);
	this->vertex2.y = set_size(y);
}
void MyGeometry::Triangle::set_vertex_3(int x, int y)
{
	this->vertex3.x = set_size(x);
	this->vertex3.y = set_size(y);
}

MyGeometry::Triangle::Triangle()
{
	
	this->vertex1.x = 50 + rand() % (200 - 50 + 1);
	this->vertex1.y = 150 + rand() % (300 - 150 + 1);

	this->vertex2.x = 200 + rand() % (350 - 200 + 1);
	this->vertex2.y = 300 + rand() % (450 - 300 + 1);

	this->vertex3.x = 200 + rand() % (350 - 200 + 1);
	this->vertex3.y = 300 + rand() % (450 - 300 + 1);
}

MyGeometry::Triangle::Triangle(Vector2 v1, Vector2 v2, Vector2 v3, int line_width, Colors color) :Shape(v1.x, v1.y, line_width, color)
{
	this->vertex1 = v1;
	this->vertex2 = v2;
	this->vertex3 = v3;
}
