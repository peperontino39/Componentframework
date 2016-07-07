#pragma once
#include <set>
#include "cinder/app/KeyEvent.h"
#include "cinder/app/MouseEvent.h"
#include "cinder/app/TouchEvent.h"
#include <unordered_map>

#define Key c_Key::single()
#define Mouse c_Mouse::single()


struct Status
{
	std::set<int> push;
	std::set<int> press;
	std::set<int> pull;
};

class c_Key
{
public:
	static c_Key& single() {
		static c_Key _key;
		return _key;
	}

	bool isPush(int);
	bool isPress(int);
	bool isPull(int);

	void registerPush(ci::app::KeyEvent &);
	void registerPull(ci::app::KeyEvent &);
	void registerLast();

private:
	Status status;
};


class c_Mouse
{
public:
	static c_Mouse& single() {
		static c_Mouse _mouse;
		return _mouse;
	}

	bool isPush(int);
	bool isPress(int);
	bool isPull(int);
	ci::Vec2i getPos();
	float getWheel();

	void registerPush(ci::app::MouseEvent &);
	void registerPull(ci::app::MouseEvent &);
	void registerLast();
	void registerPos(ci::app::MouseEvent &);
	void registerWheel(ci::app::MouseEvent &);

private:
	Status status;
	ci::Vec2i position;
	float wheel;
};

class c_Touch {
public:
	void registerBegan(ci::app::TouchEvent &);
	void registerMoved(ci::app::TouchEvent &);
	void registerEnded(ci::app::TouchEvent &);
	
private:
	std::unordered_map<int, ci::app::TouchEvent::Touch> status;

};

