#pragma once
#include <Windows.h>
class Colors
{
public:
	Colors();
	Colors(int red, int green, int blue, int alpha);
	~Colors();
	void set_colors(int red, int green, int blue, int alpha);
	int get_colors()const;
protected:
	int red;
	int green;
	int blue;
	int alpha;

};

