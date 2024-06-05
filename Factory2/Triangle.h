#pragma once
#include "Shape.h"
#include <Windows.h>
#include <windowsx.h>
#include <iostream>

namespace MyTriangle {
	struct Vector2 
	{
		int x;
		int y;
	};
	class Triangle :
		public MyGeometry::Shape
	{
	public:
		double get_side_a()const;
		double get_side_b()const;
		double get_side_c()const;

		void set_vertex_1(int x, int y);
		void set_vertex_2(int x, int y);
		void set_vertex_3(int x, int y);

		Triangle();
		Triangle(MyGeometry::Vector2 v1, MyGeometry::Vector2 v2, MyGeometry::Vector2 v3,int line_width,MyGeometry::Color color);

		double get_area()const override;
		double get_perimeter()const override;
		void draw()const override;
		void info()const override;


	private:
		MyGeometry::Vector2 vertex1;
		MyGeometry::Vector2 vertex2;
		MyGeometry::Vector2 vertex3;
	};

}