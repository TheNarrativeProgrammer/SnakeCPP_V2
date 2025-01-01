#pragma once
class Score
{
public:

	Score();
	~Score();

	void AddToScore();
	int GetScore();

private:
	int mScore;
};

