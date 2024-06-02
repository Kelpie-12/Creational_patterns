#include <iostream>
#include <vector>

#include <raylib.h>
using namespace std;
/*В проекте 'Factory' реализовать иерархию геометрических фигур :
Квадрат, Прямоугольник, Крут, треугольник.......
для каждой фигуры нужно вывести ее первичные свойства, например,
длина сторон, радиус ........и вторичные свойства : диагональ,
площадь, периметр....
Так же каждую фигуру нужно нарисовать.

Необходимо сгенерировать все эти фигуры в случайном порядке со случайными свойствами.
*/

class Figura
{
public:
	virtual void Draw() = 0;
	virtual void set_position(Vector2 position) = 0;
	Figura()
	{
		int r = (rand() % 255);
		int g = (rand() % 255);
		int b = (rand() % 255);
		this->color = { (unsigned char)r,(unsigned char)g,(unsigned char)b,255 };
		this->position = { (float)GetScreenWidth() / 2 ,(float)GetScreenHeight() / 2 };
	}
	virtual void info() = 0;
protected:
	Vector2 position;
	Color color;
	virtual double get_square() = 0;
};

class Rectangle1 :public Figura
{
public:
	void Draw()
	{
		DrawRectangle(this->position.x, this->position.y, this->widgh, this->height, this->color);
	}
	void set_high(float height)
	{
		this->height = height;
	}
	void set_weigh(float widgh)
	{
		this->widgh = widgh;
	}
	void set_position(Vector2 position) override
	{
		this->position = position;
	}
	Rectangle1(float widgh, float height, Vector2 position, Color color)
	{
		this->color = color;
		this->height = height;
		this->widgh = widgh;
		this->position = position;
	}
	Rectangle1()
	{
		this->height = (1 + rand() % 250);
		this->widgh = (1 + rand() % 250);
	}
	void info()
	{
		cout << "Square Rectangle " << get_square() << endl;
	}
	
protected:
	float widgh;
	float height;
	double get_square() override
	{
		return (position.x - position.x + widgh) * (position.y + height - position.y);
	}
};

class Cube1 : public Rectangle1
{
public:
	Cube1()
	{
		this->height = this->widgh = rand() % 100;
	}
	Cube1(float widgh, float height, Vector2 position, Color color)
	{
		this->color = color;
		this->height = height;
		this->widgh = widgh;
		this->position = position;
	}
	void set_position(Vector2 position) override
	{
		this->position = position;
	}
	void Draw()
	{
		DrawRectangle(this->position.x, this->position.y, this->height, this->widgh, this->color);
	}
	void info()
	{
		cout << "Square cube " << get_square() << endl;
	}

private:
	double get_square() override
	{
		return  (position.x - position.x + widgh) * (position.y + height - position.y);
	}
};

class Circle1 : public Figura
{
public:
	void Draw()
	{
		DrawCircle(this->position.x, this->position.y, this->radius, this->color);
	}
	Circle1()
	{
		this->radius = 1 + rand() % 200;
	}
	void set_position(Vector2 position) override
	{
		this->position = position;
	}
	void info()
	{
		cout << "Square circle " << get_square() << endl;
	}
private:
	float radius;
	double get_square() override
	{
		return 3.14* radius* radius;
	}
};

class Treuglnic :public Figura
{
public:
	void Draw()
	{
		DrawTriangle(this->position, this->v1, this->v2, this->color);
	}
	void info()
	{
		cout << "Square triangle " << get_square() * (-1) << endl;
	}
	Treuglnic()
	{
		this->v1 = { (float)GetScreenWidth() / 2 - 300 ,(float)GetScreenHeight() / 2 + 300 };
		this->v2 = { (float)GetScreenWidth() / 2 + 300 ,(float)GetScreenHeight() / 2 + 300 };
	}
	Treuglnic(Vector2 v1, Vector2 v2, Vector2 v3, Color color)
	{
		this->v1 = v1;
		this->v2 = v2;
		this->position = v3;
		this->color = color;
	}
	void set_position(Vector2 position) override
	{
		this->position = position;
	}
private:
	Vector2 v1;
	Vector2 v2;
	double get_square() override
	{
		return 0.5 * ((v2.x - v1.x) * (position.y - v1.y) - (position.x - v1.x) * (v2.y - v1.y));
	}
};
void hand_imput(vector <Figura*>& figur);

void main()
{
	srand(time_t());
	const int widgh = 800;
	const int height = 800;
	setlocale(LC_ALL, "");
	InitWindow(widgh, height, "HomeWork");
	SetTargetFPS(60);	
	vector<Figura*> figur{ new Rectangle1,new Circle1,new Cube1 };
	while (!WindowShouldClose())
	{
		BeginDrawing();

		figur[0]->Draw();
		hand_imput(figur);	
		ClearBackground(BLACK);
		EndDrawing();
	}
	CloseWindow();
}

void hand_imput(vector <Figura*>& figur)
{
	if (IsKeyPressed(KEY_SPACE))
	{
		int random = rand() % 4;
		figur.clear();
		if (random == 0)
		{
			figur.push_back(new Rectangle1);
			figur[0]->info();
		}
		else if (random == 1)
		{
			figur.push_back(new Circle1);
			figur[0]->info();
		}
		else if (random == 2)
		{
			figur.push_back(new Cube1);
			figur[0]->info();
		}
		else if (random == 3)
		{
			figur.push_back(new Treuglnic);
			figur[0]->info();
		}

	}
}