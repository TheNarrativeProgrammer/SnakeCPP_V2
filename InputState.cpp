#include "InputState.h"

InputState::InputState()
{
    mUp     = ((unsigned int)   DirectionKeys::UP);
    mDown   = ((unsigned int)   DirectionKeys::DOWN);
    mLeft   = ((unsigned int)   DirectionKeys::LEFT);
    mRight  = ((unsigned int)   DirectionKeys::RIGHT);  
}

InputState::~InputState()
{
}

bool InputState::isUp()
{
    return mUp;
}

bool InputState::isDown()
{
    return mDown;
}

bool InputState::isLeft()
{
    return mLeft;
}

bool InputState::isRight()
{
    return mRight;
}
