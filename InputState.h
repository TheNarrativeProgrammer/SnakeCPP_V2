#pragma once


enum class DirectionKeys : unsigned int
{
	DEFAULT		= 1,
	UP			= (DEFAULT << 0),
	DOWN		= (DEFAULT << 1),
	LEFT		= (DEFAULT << 2),
	RIGHT		= (DEFAULT << 3),
};

class InputState
{
	friend class InputManager;
public:
	InputState();
	~InputState();

protected:
	unsigned int mUp		: 1;
	unsigned int mDown		: 1;
	unsigned int mLeft		: 1;
	unsigned int mRight		: 1;

	bool isUp();
	bool isDown();
	bool isLeft();
	bool isRight();
};

