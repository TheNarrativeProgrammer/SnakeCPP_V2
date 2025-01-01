#include "Score.h"

Score::Score()
{
	mScore = 1;
}

Score::~Score()
{
}

void Score::AddToScore()
{
	mScore++;
}

int Score::GetScore()
{
	return mScore;
}
