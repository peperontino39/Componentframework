#include "EventManager.h"



bool c_Key::isPush(int _key)
{
	return status.push.find(_key) != status.push.cend();
}

bool c_Key::isPress(int _key)
{
	return  status.press.find(_key) != status.press.cend();
}

bool c_Key::isPull(int _key)
{
	return status.pull.find(_key) != status.pull.cend();
}

void c_Key::registerPush(ci::app::KeyEvent & _event)
{
	if (status.press.find(_event.getCode()) == status.press.cend()) {
		status.push.insert(_event.getCode());
	}
	status.press.insert(_event.getCode());
}

void c_Key::registerPull(ci::app::KeyEvent & _event)
{
	status.press.erase(_event.getCode());
	status.pull.insert(_event.getCode());

}

void c_Key::registerLast()
{
	status.push.clear();
	status.pull.clear();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


bool c_Mouse::isPush(int _mouse_button)
{
	return status.push.find(_mouse_button) != status.push.cend();
}

bool c_Mouse::isPress(int _mouse_button)
{
	return status.press.find(_mouse_button) != status.push.cend();
}

bool c_Mouse::isPull(int _mouse_button)
{
	return status.pull.find(_mouse_button) != status.push.cend();
}

ci::Vec2i c_Mouse::getPos()
{
	return position;
}

float c_Mouse::getWheel()
{
	return wheel;
}

void c_Mouse::registerPush(ci::app::MouseEvent & _event)
{
	if (_event.isLeft()) {
		status.push.insert(ci::app::MouseEvent::LEFT_DOWN);
		status.press.insert(ci::app::MouseEvent::LEFT_DOWN);
	}
	if (_event.isRight()) {
		status.push.insert(ci::app::MouseEvent::RIGHT_DOWN);
		status.press.insert(ci::app::MouseEvent::RIGHT_DOWN);
	}
	if (_event.isMiddle()) {
		status.push.insert(ci::app::MouseEvent::MIDDLE_DOWN);
		status.press.insert(ci::app::MouseEvent::MIDDLE_DOWN);
	}
}

void c_Mouse::registerPull(ci::app::MouseEvent & _event)
{
	if (_event.isLeft()) {
		status.pull.insert(ci::app::MouseEvent::LEFT_DOWN);
		status.press.erase(ci::app::MouseEvent::LEFT_DOWN);
	}
	if (_event.isRight()) {
		status.pull.insert(ci::app::MouseEvent::RIGHT_DOWN);
		status.press.erase(ci::app::MouseEvent::RIGHT_DOWN);
	}
	if (_event.isMiddle()) {
		status.pull.insert(ci::app::MouseEvent::MIDDLE_DOWN);
		status.press.erase(ci::app::MouseEvent::MIDDLE_DOWN);
	}
}

void c_Mouse::registerLast()
{
	status.pull.clear();
	status.push.clear();
}

void c_Mouse::registerPos(ci::app::MouseEvent & _event)
{
	position = _event.getPos();
}

void c_Mouse::registerWheel(ci::app::MouseEvent & _event)
{
	wheel = _event.getWheelIncrement();
}

////////////////////////////////////////////////////////////////////////////////////
void c_Touch::registerBegan(ci::app::TouchEvent & _event)
{
		for (auto& it: _event.getTouches())
		{
			//status[it.getId()] = 
			
		}

}

void c_Touch::registerMoved(ci::app::TouchEvent & _event)
{
}

void c_Touch::registerEnded(ci::app::TouchEvent & _event)
{
}
