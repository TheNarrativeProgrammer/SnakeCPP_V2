#pragma once
#include "InputState.h"
#include "Snake.h"

class InputManager
{
public:
	void Update();
	bool IsButtonPressed(char inWASD);
	void changeButtonPressed();
	const InputState& GetInputState();
	void MoveSnake(Snake& inSnake);

private:
	InputState mInputState;
	char mLastKeyPressed;
};

