#pragma once
#include "Shape.h"
#include <wingdi.h>

namespace MyGeometry {
	class Circle :
		public MyGeometry::Shape
	{
	public:
		Circle();
		Circle(double radius, unsigned int x, unsigned int y, unsigned int live_width, Color color);

		void set_position(unsigned int x, unsigned int y);
		void set_radius(double radius);
		double get_radius()const;

		double get_area()const override;
		double get_perimeter()const override;
		void draw()const override;
		void info()const override;

	private:
		double radius;		
		Vector2 p2;
	};

}