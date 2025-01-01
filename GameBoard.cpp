#include "GameBoard.h"
#include <random>

GameBoard::GameBoard(int inWidth, int inHeight)
{
	mWidth = inWidth;
	mHeight = inHeight;
}

int GameBoard::GenerateRandPosition(int inWidthOrHeight)
{
    int max = inWidthOrHeight;
    int min = 0;


    std::random_device seedNumber;
    std::mt19937 GenerateRandomNum(seedNumber());
    std::uniform_int_distribution<> randomRangeX(min, max);

    int randXYcord = randomRangeX(GenerateRandomNum);

    return randXYcord;

}
