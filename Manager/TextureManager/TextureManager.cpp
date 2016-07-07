#include "TextureManager.h"



void TextureManager::set(std::string _key, std::string _path)
{
	if (textures.find(_key) == textures.end()) {
		textures[_key] = std::make_shared<ci::gl::Texture>(ci::loadImage(ci::app::loadAsset(_path)));
	}
}

void TextureManager::set(std::string _key, ci::gl::Texture _tex)
{
	if (textures.find(_key) == textures.end()) {
		textures[_key] = std::make_shared<ci::gl::Texture>(_tex);
	}
}

ci::gl::TextureRef & TextureManager::get(std::string _key)
{
	return textures[_key];
}

