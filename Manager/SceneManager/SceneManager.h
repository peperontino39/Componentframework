#pragma once
#include "../../Scene/SceneBase.h"
#include <memory>

#define GetScene c_SceneManager::single().now()
#define SceneManager c_SceneManager::single()

class c_SceneManager
{
public:
	static c_SceneManager& single() {
		static c_SceneManager _scene;
		return _scene;
	};
	template<class T>
	void createScene(T& _scene) {
		scene = std::make_shared<T>(_scene);
	};
	c_SceneBase& now() {
		return *scene;
	};

private:
	std::shared_ptr<c_SceneBase> scene;

};

