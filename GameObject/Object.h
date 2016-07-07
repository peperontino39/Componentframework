#pragma once
#include <unordered_map>
#include <memory>
#include "../Component/ComponentBase/ComponentBase.h"


class c_Object
{
public:
	template<typename T>
	void addComponent(T&);
	template<typename T>
	T& getComponent();
	template<typename T>
	void addScript(T&);
	template<typename T>
	T& getScript();
protected:
	template<typename T>
	std::string getClassName();
	
	std::unordered_map<std::string, std::shared_ptr<c_MonoBehaviour>> monobehaviours;
	std::unordered_map<std::string, std::shared_ptr<c_ComponentBase>> components;

private:
};

template<typename T>
void c_Object::addComponent(T & _component)
{
	components[getClassName<T>()]
		= std::make_shared<T>(_component);
}

template<typename T>
T& c_Object::getComponent()
{

	return static_cast<T&>(*components[getClassName<T>()]);
}

template<typename T>
inline void c_Object::addScript(T &)
{
	monobehaviours[getClassName<T>()] =
		std::make_shared<T>(_component);
}

template<typename T>
inline T & c_Object::getScript()
{
	return *monobehaviours[getClassName<T>()]
}

template<typename T>
std::string c_Object::getClassName()
{
	std::string str = typeid(T).name();
	str.erase(str.begin(), str.begin() + 6);
	return str;
}