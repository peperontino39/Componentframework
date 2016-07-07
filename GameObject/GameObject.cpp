#include "GameObject.h"

c_GameObject::c_GameObject()
{
	for (auto& it : monobehaviours) {
		it.second->start();
	}
	position = ci::Vec3f::zero();
	rotation = ci::Vec3f::zero();
	scale = ci::Vec3f::one();
	pushmodelview = [&](ci::Vec3f _p, ci::Vec3f _r, ci::Vec3f _s) {
		ci::gl::translate(_p);
		ci::gl::rotate(_r);
		ci::gl::scale(_s);
	};
}

c_GameObject::~c_GameObject()
{
}

void c_GameObject::update()
{
	for (auto& it : monobehaviours) { it.second->update(); }
	for (auto& it : components) { it.second->update(); }
}

void c_GameObject::draw()
{
	drawBegin();
	ci::gl::pushModelView();
	pushmodelview(position,rotation,scale);
	for (auto& it : components) { it.second->draw(); }
	ci::gl::popModelView();
	drawEnd();
	
}

void c_GameObject::drawBegin()
{
	for (auto& it : components) { it.second->drawBegin(); }

}

void c_GameObject::drawEnd()
{
	for (auto& it : components) { it.second->drawEnd(); }
}

void c_GameObject::console()
{
	ci::app::console() << "position	" << position << std::endl;
	ci::app::console() << "rotation	" << rotation << std::endl;
	ci::app::console() << "scale	" << scale << std::endl;
	for (auto& it : components) {
		ci::app::console() << it.first << scale << std::endl;
	}
}

