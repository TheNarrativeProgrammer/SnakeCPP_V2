#include "InputManager.h"
#include <conio.h>
#include "Utils.h"
#include <chrono>
#include <thread>

void InputManager::Update()
{
    changeButtonPressed();
    mInputState.mUp = IsButtonPressed('w');
    mInputState.mDown = IsButtonPressed('s');
    mInputState.mLeft = IsButtonPressed('a');
    mInputState.mRight = IsButtonPressed('d');
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
}

bool InputManager::IsButtonPressed(char inWASD)
{
    static bool isKeyUp = true;

    if (mLastKeyPressed == inWASD)
    {
        if (isKeyUp)
        {
            isKeyUp = false;
            return true;
        }
    }
    else
    {
        isKeyUp = true;
    }
    return false;
}

void InputManager::changeButtonPressed()
{
    static bool isKeyUp = true;

    if (_kbhit())
    {
        switch (_getch())
        {
        case 'w':
            mLastKeyPressed = 'w';
            break;
        case 's':
            mLastKeyPressed = 's';
            break;
        case 'a':
            mLastKeyPressed = 'a';
            break;
        case 'd':
            mLastKeyPressed = 'd';
            break;
        default:
            break;
        }
    }
}

const InputState& InputManager::GetInputState()
{
    return mInputState;
}

void InputManager::MoveSnake(Snake& inSnake)
{
    if (mInputState.isUp())
    {
        inSnake.mHeadPositionY--;
    }
     else if (mInputState.isDown())
    {
        inSnake.mHeadPositionY++;
    }
    else if (mInputState.isLeft())
    {
        inSnake.mHeadPositionX--;
    }
    else  if (mInputState.isRight())
    {
        inSnake.mHeadPositionX++;
    }
    else
    {
        inSnake.mHeadPositionY++;
    }

     int prevPosX1 = inSnake.mHeadPositionX;                            // Store the previous positions of the head and tail segments
     int prevPosY1 = inSnake.mHeadPositionY;
     int prevPosX2;
     int prevPosY2;

     for (int i = 0; i < inSnake.mTailPositionX.size(); i++)
     {
         prevPosX2 = inSnake.mTailPositionX[i];                         // Store the current tail segment position
         prevPosY2 = inSnake.mTailPositionY[i];

         inSnake.mTailPositionX[i] = prevPosX1;                         // Update the tail segment to the previous position     tail[0] moves to SnakeHead. tail[1] moves to tail[0]
         inSnake.mTailPositionY[i] = prevPosY1;

         prevPosX1 = prevPosX2;                                         // Update previous positions for the next segment
         prevPosY1 = prevPosY2;
     }

}
