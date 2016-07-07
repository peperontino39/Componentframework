#include "Camera.h"

c_Camera::c_Camera()
{
	camera = ci::CameraPersp(WINDOW_WIDTH, WINDOW_HEIGHT,
		60.0f,
		1.0f, 1000.0f);
	angle = ci::Vec2f::zero();

	camera.setEyePoint(ci::Vec3f::zero());
	camera.setCenterOfInterestPoint(camera.getEyePoint() + ci::Vec3f::zAxis());
	
	
}


void c_Camera::drawEnd()
{

	ci::gl::setMatrices(camera);
}

void c_Camera::rotate(ci::Vec2f _angle)
{
	angle += _angle;
	angle.x = std::min(std::max(angle.x,
		-float(M_PI / 2) + 0.01f),
		float(M_PI / 2) - 0.01f);
	angle.y = std::fmod(angle.y, M_PI * 2.f);

	camera.setCenterOfInterestPoint(camera.getEyePoint() +
		ci::Matrix44f::createRotation(ci::Vec3f(-angle.x,-angle.y,0)) *
		ci::Vec3f::zAxis());

}

void c_Camera::transrate(ci::Vec3f _add)
{
	camera.setEyePoint(camera.getEyePoint() + ci::Matrix44f::createRotation(ci::Vec3f(-angle.x, -angle.y, 0)) * _add);
}
