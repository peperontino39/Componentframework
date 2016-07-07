#include "Title.h"

using namespace ci;
using namespace ci::app;
using namespace std;

c_Title::c_Title()
{
	camera = ci::CameraPersp(WINDOW_WIDTH, WINDOW_HEIGHT,
		60.0f,
		1.0f, 1000.0f);

	camera.setEyePoint(ci::Vec3f::zero());
	camera.setViewDirection(ci::Vec3f::zAxis());

	
}

c_Title::~c_Title()
{
}

void c_Title::setup()
{

}

void c_Title::update()
{
	



}

void c_Title::draw()
{
	gl::setMatrices(camera);
	gl::drawColorCube(Vec3f(0, 0, 10), Vec3f(2, 2, 2));

	
	Textures.set("sky", "skydome/ñ¢ímÇÃòfêØ.bmp");
	//skydome.addComponent(c_Texture("sky"));
	skydome.addComponent(c_Color(Color(1, 1, 1)));
	skydome.addComponent(Mesh::c_Sphere(20));
	skydome.addComponent(c_Skydome());
	skydome.scale = Vec3f::one() * 500.f;


	skydome.draw();

}

void c_Title::shift()
{
	if (Key.isPush(KeyEvent::KEY_c)) {
		SceneManager.createScene(c_Title());
	}
}
