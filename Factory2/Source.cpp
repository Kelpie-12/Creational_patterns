#include <iostream>
#include <Windows.h>

using namespace std;

//#define MIN_SIZE 50
//#define MAX_SIZE 800
//#define MIN_LINE_WIDTH  1
//#define MAX_LINE_WIDTH  25
//#define MAX_HORICONTAL_RESOLUTION 800
//#define MAX_VERTICAL_RESOLUTION 600
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
	class Shape
	{
	protected:
		static const int MIN_SIZE = 50;
		static const int MAX_SIZE = 800;
		static const int MIN_LINE_WIDTH = 1;
		static const int MAX_LINE_WIDTH = 25;
		static const int MAX_HORICONTAL_RESOLUTION = 800;
		static const int MAX_VERTICAL_RESOLUTION = 600;

		unsigned int x;
		unsigned int y;
		unsigned int line_width;
		Color color;
	public:
		virtual double get_area()const = 0;
		virtual double get_perimeter()const = 0;
		virtual void draw()const = 0;
		unsigned int get_x()const
		{
			return this->x;
		}
		unsigned int get_y()const
		{
			return this->y;
		}
		unsigned int get_line_width()const
		{
			return this->line_width;
		}
		unsigned int set_size(unsigned int size)
		{
			return size<MIN_SIZE ? MIN_SIZE : size>MAX_SIZE ? MAX_SIZE : size;

		}
		void set_x(unsigned int x)
		{

			this->x = x < MAX_HORICONTAL_RESOLUTION ? x : MAX_HORICONTAL_RESOLUTION;
		}
		void set_y(unsigned int y)
		{

			this->y = y < MAX_VERTICAL_RESOLUTION ? y : MAX_VERTICAL_RESOLUTION;
		}
		void set_line_width(unsigned int line_width)
		{
			if (line_width < MIN_LINE_WIDTH)
				this->line_width = MIN_LINE_WIDTH;
			if (line_width > MAX_LINE_WIDTH)
				this->line_width = MAX_LINE_WIDTH;
			this->line_width = line_width;
		}

		//constructors
		Shape(unsigned int x, unsigned int y, unsigned int live_width = 5, Color color = Color::GREY) :color(color)
		{
			set_x(x);
			set_y(y);
			set_line_width(live_width);
		}
		virtual ~Shape() { }

		//methods
		virtual void info()const
		{
			cout << "Площадь фигуры: " << get_area() << endl;
			cout << "Периметр фигуры: " << get_perimeter() << endl;
			draw();
		}
	};

	class Rectangle :public Shape
	{
		double width;
		double heigth;
	public:
		double get_width()const
		{
			return this->width;
		}
		double get_heigth()const
		{
			return this->heigth;
		}
		void set_width(double width)
		{
			this->width = set_size(width);
		}
		void set_heigth(double heigth)
		{
			this->heigth = set_size(heigth);
		}

		Rectangle(double width, double height, unsigned int x, unsigned int y, unsigned int live_width, Color color) :Shape(x, y, live_width, color)
		{
			set_heigth(height);
			set_width(width);
		}
		~Rectangle() { }

		//Methods
		double get_area()const override
		{
			return this->width * this->heigth;
		}
		double get_perimeter()const override
		{
			return (this->width + this->heigth)*2;
		}
		void draw()const override
		{
			/*for (size_t i = 0; i < this->heigth; i++)
			{
				for (size_t j = 0; j < this->width; j++)
				{
					cout << "*";
				}
				cout << endl;
			}*/

			HWND hwnd = GetConsoleWindow();

			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID,this->line_width,this->color);
			HBRUSH hBrush = CreateSolidBrush(this->color);
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			::Rectangle(hdc, x, y, x + width, y+heigth);

			//удаляем 
			DeleteObject(hPen);
			DeleteObject(hBrush);
			ReleaseDC(hwnd, hdc);

		}
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "Ширина прямоугольника: " << get_width() << endl;
			cout << "Высота прямоугольника: " << get_heigth() << endl;
			Shape::info();
		}
	};

}

void main()
{
	setlocale(LC_ALL, "");
	MyGeometry::Rectangle rect(100, 50, 150, 200, 8, MyGeometry::RED);
	/*cout << "Ширина прямоугольника: " << rect.get_width()<<endl;
	cout << "Высота прямоугольника: " << rect.get_heigth() << endl;
	cout << "Площадь прямоугольника: " << rect.get_area() << endl;
	cout << "Периметр прямоугольника: " << rect.get_perimeter() << endl;
	rect.draw();*/
	rect.info();
}