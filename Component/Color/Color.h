#pragma once
#include "../ComponentBase/ComponentBase.h"
#include "cinder/gl/gl.h"

class c_Color: public c_ComponentBase
{
public:
	c_Color(ci::ColorA);
	c_Color(ci::Color);
	void drawBegin()override;
	void drawEnd()override;

	ci::ColorA color;
private:
};
