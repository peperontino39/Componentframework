#pragma once
#include "cinder/gl/gl.h"
#include "../ComponentBase/ComponentBase.h" 

class c_MeshFIlterBase : public c_ComponentBase
{
public:
	virtual void draw() = 0;

};

namespace Mesh {
	class c_Sphere : public c_MeshFIlterBase
	{
	public:
		c_Sphere(int _segments) : segments(_segments) {};
		void draw() { ci::gl::drawSphere(ci::Vec3f::zero(), 1, segments); };
		int segments;
	};
	class c_Rect : public c_MeshFIlterBase
	{
	public:
		void draw() { ci::gl::drawSolidRect(ci::Rectf(-0.5f, -0.5f, 0.5f, 0.5f)); };
	}; 
	class c_Cube : public c_MeshFIlterBase
	{
	public:
		void draw() { 
			ci::gl::drawCube(ci::Vec3f::zero(), ci::Vec3f::one()); 
		};
	};

}