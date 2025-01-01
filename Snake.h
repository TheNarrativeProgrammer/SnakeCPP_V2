#pragma once
#include "Utils.h"
#include "GameBoard.h"

class Snake
{
public:

	Snake(int inPosX, int inPosY, const GameBoard& inGameBoard);


	int	mHeadPositionX;
	int	mHeadPositionY;
	std::vector<int> mTailPositionX;
	std::vector<int> mTailPositionY;

	void AddToTail();

};