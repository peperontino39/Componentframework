#include "Skydome.h"


c_Skydome::c_Skydome()
{
}

c_Skydome::~c_Skydome()
{
}

void c_Skydome::drawBegin()
{
	glCullFace(GL_FRONT);
}

void c_Skydome::drawEnd()
{
	glCullFace(GL_BACK);

}
