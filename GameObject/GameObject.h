#pragma once
#include "../Component/ComponentBase/ComponentBase.h"
#include "../MonoBehaviour/MonoBehaviour.h"
#include "../Component/MeshFIlter/MeshFIlter.h"
#include "../Component/Camera/Camera.h"
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <memory>


class c_GameObject
{
public:
	c_GameObject();
	~c_GameObject();

	void update();
	void draw();

	void drawBegin();
	void drawEnd();

	void console();


	template<typename T>
	void addComponent(T&);
	template<typename T>
	T& getComponent();
	template<typename T>
	void addScript(T&);
	template<typename T>
	T& getScript();

	ci::Vec3f position;
	ci::Vec3f rotation;
	ci::Vec3f scale;

	std::function<void(ci::Vec3f,ci::Vec3f, ci::Vec3f)> pushmodelview;
private:
	std::unordered_map<std::string, std::shared_ptr<c_MonoBehaviour>> monobehaviours;
	std::unordered_map<std::string, std::shared_ptr<c_ComponentBase>> components;

	template<typename T>
	std::string getClassName();

};

template<typename T>
void c_GameObject::addComponent(T & _component)
{
	components[getClassName<T>()]
		= std::make_shared<T>(_component);

}

template<typename T>
T& c_GameObject::getComponent()
{
	
	return static_cast<T&>(*components[getClassName<T>()]);
}

template<typename T>
void c_GameObject::addScript(T & _component)
{
	monobehaviours[getClassName<T>()] = 
		std::make_shared<T>(_component);
}

template<typename T>
T & c_GameObject::getScript()
{
	return *monobehaviours[getClassName<T>()]
}

template<typename T>
std::string c_GameObject::getClassName()
{
	std::string str = typeid(T).name();
	str.erase(str.begin(), str.begin() + 6);
	return str;
}

