#include "Snake.h"

Snake::Snake(int inPosX, int inPosY, const GameBoard& inGameBoard)
{
	if (inPosX <=0 || inPosX <= inGameBoard.mWidth)						//check if x Position of Snake head is within bounds of game - X axis. 
	{
		inPosX = inGameBoard.mWidth / 2;
	}
	if (inPosY <= 0 || inPosY <= (inGameBoard.mHeight) - 2)				//check if x Position of Snake head is within bounds of game - Y axis					Because tail starts at length of 2 and its position is Posy - 2, the bounds of the head are the height - 2
	{
		inPosY = inGameBoard.mHeight / 2;
	}


	mHeadPositionX = inPosX;											//Set position - Snake head
	mHeadPositionY = inPosY;

	mTailPositionX.emplace_back(mHeadPositionX);
	mTailPositionX.emplace_back(mHeadPositionX);
	mTailPositionX.emplace_back(mHeadPositionX);

	mTailPositionY.emplace_back(mHeadPositionY - 1);
	mTailPositionY.emplace_back(mHeadPositionY - 2);
	mTailPositionY.emplace_back(mHeadPositionY - 3);

}

void Snake::AddToTail()
{
	mTailPositionX.emplace_back(mHeadPositionX);
	mTailPositionY.emplace_back(mHeadPositionY);


}
