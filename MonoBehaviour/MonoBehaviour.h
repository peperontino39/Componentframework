#pragma once

class c_GameObject;

class c_MonoBehaviour
{
public:
	c_MonoBehaviour(c_GameObject*);
	~c_MonoBehaviour();

	virtual void start();
	virtual void update();

protected:

	c_GameObject* my;

private:

};

