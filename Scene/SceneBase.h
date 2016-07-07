#pragma once


class c_SceneBase
{
public:
	virtual void setup() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;
	virtual void shift() = 0;

};

