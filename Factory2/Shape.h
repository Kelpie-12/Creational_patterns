#pragma once
#include <Windows.h>
#include <iostream>


namespace MyGeometry
{
	enum Color
	{
		RED = 0x000000FF,
		GREEN = 0x0000FF00,
		BLUE = 0x00FF0000,
		GREY = 0x00AAAAAA,
		YELLOW = 0x0000FFFF
	};
	struct Vector2
	{
		int x;
		int y;
	};
	class Shape 
	{
	protected:
		static const int MIN_SIZE = 50;
		static const int MAX_SIZE = 400;
		static const int MIN_LINE_WIDTH = 1;
		static const int MAX_LINE_WIDTH = 25;
		static const int MAX_HORICONTAL_RESOLUTION = 800;
		static const int MAX_VERTICAL_RESOLUTION = 600;

		unsigned int x;
		unsigned int y;
		unsigned int line_width;
		MyGeometry::Color color;
		HWND hwnd;
		HDC hdc;
		//HPEN hPen;
		HBRUSH hBrush;
	public:
		unsigned int get_x()const;
		unsigned int get_y()const;
		unsigned int get_line_width()const;
		MyGeometry::Color get_color()const;

		unsigned int set_size(unsigned int size);

		void set_x(unsigned int x);
		void set_y(unsigned int y);
		void set_line_width(unsigned int line_width);
		void set_color(MyGeometry::Color color);
		//constructors
		Shape(unsigned int x, unsigned int y, unsigned int live_width = 5, Color color = Color::GREY);
		Shape();
		virtual ~Shape() { }

		//methods
		virtual void info()const;
		virtual double get_area()const = 0;
		virtual double get_perimeter()const = 0;
		void draw()const;
		virtual void draw_figura()const = 0;
	};

}

