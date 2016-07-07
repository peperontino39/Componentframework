#pragma once
#include "../SceneBase.h"
#include "../../GameObject/GameObject.h"
#include "../../Component/Texture/Texture.h"
#include "../../Component/MeshFIlter/MeshFIlter.h"
#include "../../Component/Camera/Camera.h"
#include "../../Prefab/Prefab.h"
#include "../../Manager/TextureManager/TextureManager.h"
#include "cinder/Ray.h" 
#include "../../Component/Color/Color.h"
#include "../../Component/Skydome/Skydome.h"
#include "../../Manager/EventManager/EventManager.h"
#include "../../Manager/SceneManager/SceneManager.h"


class c_Title : public c_SceneBase
{
public:
	c_Title();
	~c_Title();

	inline void setup() override;

	inline void update() override;
	inline void draw() override;
	inline void shift() override;

private:
	c_GameObject MainCamera;
	c_GameObject skydome;
	c_GameObject floor;
	c_GameObject cube;
	ci::CameraPersp camera;
};

