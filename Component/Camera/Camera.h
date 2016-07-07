#pragma once
#include "../ComponentBase/ComponentBase.h"
#include "cinder/Camera.h"
#include "cinder/gl/gl.h"
#include "cinder/app/AppNative.h"


enum {
	WINDOW_WIDTH = 960,
	WINDOW_HEIGHT = 540,
};

class c_Camera : public c_ComponentBase
{
public:
	c_Camera();
	void drawEnd() override;

	void rotate(ci::Vec2f);
	void transrate(ci::Vec3f);


	ci::CameraPersp camera;
private:
	ci::Vec2f angle;
};

