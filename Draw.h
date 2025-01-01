#pragma once
#include "GameBoard.h"
#include "Utils.h"
#include "Snake.h"
#include <vector>
#include "Collectables.h"
#include "Score.h"

void renderGame(GameBoard& inGameBoard, Snake& inSnake, std::vector<Collectables<int>*> inCollectablesArray, Score* inScore)
{
	system("cls");
	//Draw border - top
	int borderWidth = inGameBoard.mWidth + 1;
	int borderHeight = inGameBoard.mHeight + 1;
	bool hasTailOrCollectableRendered = false;

	for (int iteratorAxisY = 0; iteratorAxisY <= borderHeight; iteratorAxisY++)
	{
		
		for (int iteratorAxisX = 0; iteratorAxisX <= borderWidth; iteratorAxisX++)
		{
			hasTailOrCollectableRendered = false;
			if (iteratorAxisY == 0 || iteratorAxisY == borderHeight)												//top and bottom border
			{
				LOG("#");
				if (iteratorAxisX == borderWidth)
				{
					std::cout << std::endl;
				}
				if (iteratorAxisY == borderHeight && iteratorAxisX == borderWidth)									//print score below the border
				{
					std::cout << std::endl;
					LOG("Score: " << inScore->GetScore());
				}
				continue;
			}

			for (int collectableIterator = 0; collectableIterator < inCollectablesArray.size(); collectableIterator++) //Draw collecables
			{
				if (	inCollectablesArray[collectableIterator]->GetPositionX() == iteratorAxisX 
					&&	inCollectablesArray[collectableIterator]->GetPositionY() == iteratorAxisY
					&& inCollectablesArray[collectableIterator]->GetHasBeenCollected() == false)
				{
					hasTailOrCollectableRendered = true;
					LOG("1");
					if (inCollectablesArray[collectableIterator]->GetPositionX() == inSnake.mHeadPositionX && inCollectablesArray[collectableIterator]->GetPositionY() == inSnake.mHeadPositionY)		//add to score if snake head is at postion of collectable
					{
						inScore->AddToScore();
						inCollectablesArray[collectableIterator]->SetHasBeenCollected();
						inSnake.AddToTail();
					}
					continue;
				}
			}

			if (inSnake.mHeadPositionX == iteratorAxisX && inSnake.mHeadPositionY == iteratorAxisY)					// Draw the snake's head
			{
				LOG("S");
				hasTailOrCollectableRendered = true;
				continue;
			}

			for (int tailIterator = 0; tailIterator < inSnake.mTailPositionX.size(); tailIterator++)
			{
				if (inSnake.mTailPositionX[tailIterator] == iteratorAxisX && inSnake.mTailPositionY[tailIterator] == iteratorAxisY)
				{
					LOG("o");
					hasTailOrCollectableRendered = true;
					continue;
				}
			}

			

			if (iteratorAxisX == 0 || iteratorAxisX == borderWidth)													//draw left and right border
			{
				LOG("#");
				if (iteratorAxisX == borderWidth)
				{
					std::cout << std::endl;
				}
				continue;
			}
			
			if (!hasTailOrCollectableRendered)
			{
				LOG(" ");
			}
			
		}
	}
	
}
