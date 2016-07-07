#include "Color.h"

c_Color::c_Color(ci::ColorA _color)
{
	color = _color;
}

c_Color::c_Color(ci::Color _color)
{
	color = _color;
}

void c_Color::drawBegin()
{
	ci::gl::color(color);
}

void c_Color::drawEnd()
{
	ci::gl::color(1,1,1,1);
}
