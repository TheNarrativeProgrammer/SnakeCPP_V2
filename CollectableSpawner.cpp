#include "CollectableSpawner.h"

//STATIC VARIABLE - INITIALIZE  
CollectableSpawner* CollectableSpawner::sInstance = nullptr;

//CONSTRUCTORS, DESTUCTOR - private
CollectableSpawner::CollectableSpawner()
{
	mCollectablePrintID = 1;
	mUniqueIDIterator = 0;
}

CollectableSpawner::~CollectableSpawner()
{
	for (std::pair<int, Collectables<int>*> collectableIteratorInt : mCollectableMapInt)
	{
		if (collectableIteratorInt.second)
		{
			delete collectableIteratorInt.second;
		}
		collectableIteratorInt.second = nullptr;
	}
	mCollectableMapInt.clear();

	for (std::pair<int, Collectables<char>*> collectableIteratorChar : mCollectableMapChar)
	{
		if (collectableIteratorChar.second)
		{
			delete collectableIteratorChar.second;
		}
		collectableIteratorChar.second = nullptr;
	}
	mCollectableMapChar.clear();
}

CollectableSpawner& CollectableSpawner::GetInstance()
{
	if (!sInstance)
	{
		sInstance = new CollectableSpawner();
	}
	return *sInstance;
}

void CollectableSpawner::DestroyInstance()
{
	if (!sInstance)
	{
		return;
	}
	delete sInstance;
}

std::vector<Collectables<int>*> CollectableSpawner::SpawnNewCollectable(GameBoard& inGameBoard)
{
	Collectables<int>* collectableInt = CollectableSpawner::GetInstance().GenerateCollecableInt<Collectables<int>>(mCollectablePrintID, inGameBoard);
	mCollectablesArray.emplace_back(collectableInt);
	return mCollectablesArray;
}
