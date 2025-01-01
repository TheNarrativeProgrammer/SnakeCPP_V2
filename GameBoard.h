#pragma once

class CollectableSpawner;

class GameBoard
{
	friend class CollectableSpawner;
public:
	GameBoard(int inWidth, int inHeight);

	int mWidth;
	int mHeight;

	int GenerateRandPosition(int inWidthOrHeight);

};

