#pragma once
#include "Rectangle.h"
namespace MyGeometry {
	class Square :
		public MyGeometry::Rectangle
	{
	private:
		double side;
	public:
		Square();
		double get_side()const;
		void set_side(double side);	
		Square(double side, unsigned int x, unsigned int y, unsigned int live_width, Color color);

		double get_area()const override;
		double get_perimeter()const override;		
		void info()const override;
		void draw_figura()const override;
	};
}

