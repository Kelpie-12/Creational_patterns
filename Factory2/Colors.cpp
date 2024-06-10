#include "Colors.h"

Colors::Colors()
{
	this->red = rand() % 256;
	this->green = rand() % 256;
	this->blue = rand() % 256;
	this->alpha = rand() % 256;
}

Colors::Colors(int red, int green, int blue, int alpha)
{
	this->red = red;
	this->green = green;
	this->blue = blue;
	this->alpha = alpha;
}

Colors::~Colors()
{
}

void Colors::set_colors(int red, int green, int blue, int alpha)
{
	this->red = red;
	this->green = green;
	this->blue = blue;
	this->alpha = alpha;
}

int Colors::get_colors() const
{
	return this->blue * this->green * this->red*this->alpha;
}
