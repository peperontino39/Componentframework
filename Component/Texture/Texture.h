#pragma once
#include "cinder/gl/Texture.h" 
#include "cinder/imageIo.h"  
#include "../ComponentBase/ComponentBase.h"
#include "../../Manager/TextureManager/TextureManager.h"

class c_Texture : public c_ComponentBase
{
public:
	c_Texture();
	c_Texture(ci::gl::TextureRef);
	c_Texture(std::string);

	void drawBegin()override;
	void drawEnd()override;
private:
	ci::gl::TextureRef texture;
};

