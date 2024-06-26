#pragma once
#include "Shape.h"
#include <iostream>
#include <Windows.h>

namespace MyGeometry
{
	class Rectangle : public MyGeometry::Shape
	{
		double width;
		double heigth;
	public:
		double get_width()const;
		double get_heigth()const;
		void set_width(double width);
		void set_heigth(double heigth);
		Rectangle(double width, double height, unsigned int x, unsigned int y, unsigned int live_width, Color color) ;
		Rectangle();
		~Rectangle() { }

		//Methods
		double get_area()const override;
		double get_perimeter()const override;		
		void info()const override;
		void draw_figura()const override;
	};
}

