#pragma once
#include <iostream>
#include <list>
#include "../GameObject/GameObject.h"
#include "../GameObject/Object.h"

class Prefab
{
public: 
	void update();
	void draw();

	template<typename T>
	void addComponent(T&);
	template<typename T>
	void addScript(T&);
	
	std::list<c_GameObject> gameobjects;
	c_GameObject& getBase();

private:
	c_GameObject base;
};


template<typename T>
void Prefab::addComponent(T & _com)
{
	base.addComponent<T>(_com);
}

template<typename T>
void Prefab::addScript(T & _scr)
{
	base.addScript<T><_scr>;
}


c_GameObject* instantiate(Prefab& _prefab);
