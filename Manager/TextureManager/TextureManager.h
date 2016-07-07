#pragma once
#include "cinder/gl/Texture.h"
#include "cinder/imageIo.h"
#include "cinder/app/AppNative.h"
#include <unordered_map>
#include "cinder/gl/gl.h"


class TextureManager
{
public:
	static TextureManager& single() {
		static TextureManager tm;
		return tm;
	}

	void set(std::string, std::string );
	void set(std::string, ci::gl::Texture);

	ci::gl::TextureRef& get(std::string);

private:
	std::unordered_map<std::string, ci::gl::TextureRef> textures;

};

#define Textures TextureManager::single()
