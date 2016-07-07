#include "Prefab.h"

void Prefab::update()
{
	
}

void Prefab::draw()
{
	for (auto& it : gameobjects)
	{
		/*it.drawBegin();
		ci::gl::pushModelView();
		it.pushmodelview(it.position, it.rotation, it.scale);
		*/it.draw();
		/*ci::gl::popModelView();
		it.drawEnd();*/
	}

}

c_GameObject & Prefab::getBase()
{
	return base;
}


c_GameObject * instantiate(Prefab & _prefab)
{
	_prefab.gameobjects.push_back(_prefab.getBase());
	return &_prefab.gameobjects.back();
}
