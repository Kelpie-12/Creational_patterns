#pragma once
#include "Shape.h"


namespace MyGeometry 
{
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
		Triangle(Vector2 v1, Vector2 v2, Vector2 v3,int line_width,Color color);

		double get_area()const override;
		double get_perimeter()const override;
		void info()const override;
		void draw_figura()const override;


	private:
		MyGeometry::Vector2 vertex1;
		MyGeometry::Vector2 vertex2;
		MyGeometry::Vector2 vertex3;
	};

}