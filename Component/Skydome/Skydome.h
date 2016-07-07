#pragma once
#include "../ComponentBase/ComponentBase.h"
#include "cinder/gl/gl.h"

class c_Skydome : public c_ComponentBase
{
public:
	c_Skydome();
	~c_Skydome();
	void drawBegin() override;
	void drawEnd() override;

private:

};

