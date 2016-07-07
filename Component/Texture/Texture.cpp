#include "Texture.h"


c_Texture::c_Texture()
{
}

c_Texture::c_Texture(ci::gl::TextureRef _texture)
{
	texture = _texture;
}

c_Texture::c_Texture(std::string _key)
{
	texture = Textures.get(_key);
}

void c_Texture::drawBegin()
{
	texture->enableAndBind();
}

void c_Texture::drawEnd()
{
	texture->disable();
}


