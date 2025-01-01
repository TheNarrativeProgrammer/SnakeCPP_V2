#pragma once
#include "Collectables.h"
#include "Utils.h"
#include "unordered_map"
#include <random>
#include "GameBoard.h"


class GameBoard;

class CollectableSpawner
{
//CONSTRUCTORS, DESTUCTOR & ASSIGNMENT OP - private
private:
	CollectableSpawner();															//constructor - default										private, therefore, only Singleton can instantiate Singleton
	~CollectableSpawner();															//destructor

	CollectableSpawner(const CollectableSpawner& inRef) = delete;					//constructor - copy assign - delete						prevent copy being made
	CollectableSpawner& operator=(const CollectableSpawner& inRef) = delete;		//copy assignmnet op		- delete

	//MEMBER VARIABLE 
	static CollectableSpawner* sInstance;											//singleton (static) instance var							SINGLETONE ELEMENT 1	- holds single instance of singleton
	std::vector<Collectables<int>*> mCollectablesArray;
	int mCollectablePrintID;

	int mUniqueIDIterator;
	std::unordered_map<int, Collectables<int>*> mCollectableMapInt;					//Factory (non-static)										ID ITERATOR				- assigns ID to each Collectable object created
	std::unordered_map<int, Collectables<char>*> mCollectableMapChar;																		//	UNORDER MAP				- holds key and value		key = int		value = Collecatable*

	
public:
	//SINGLETON FUNCTIONS
	static CollectableSpawner& GetInstance();										//Singleton (static) create or return instance				SINGLETON ELEMENT 2		- if no instance exist -> create instance			- if instance exist -> return instance

	static void DestroyInstance();													//Singleton (static) delete instance						deletes sInstance, then calls Destructor ~CollectableSpawner

	std::vector<Collectables<int>*> SpawnNewCollectable(GameBoard& inGameBoard);

	//FACTORY FUNCTIONS
	template<class CollectableToSpawn>
	CollectableToSpawn* GenerateCollecableInt(int inName, GameBoard& inGameBoard)
	{
		int posX = inGameBoard.GenerateRandPosition(inGameBoard.mWidth);
		int posY = inGameBoard.GenerateRandPosition(inGameBoard.mHeight);
		
		CollectableToSpawn* newCollectable = new CollectableToSpawn(mUniqueIDIterator, inName, posX, posY);									//siganture of Collecatble class ->		Collectables<T>::Collectables(int inID, T inDisplayName, int inPosX, int inPosY)
		
		if (newCollectable)
		{
			mCollectableMapInt.emplace(mUniqueIDIterator++, newCollectable);
		}

		return newCollectable;
	}

	template<class CollectableToSpawn>
	CollectableToSpawn* GenerateCollecableChar(char inName, GameBoard& inGameBoard)
	{
		int posX = inGameBoard.GenerateRandPosition(inGameBoard.mWidth);
		int posY = inGameBoard.GenerateRandPosition(inGameBoard.mHeight);

		CollectableToSpawn* newCollectable = new CollectableToSpawn(mUniqueIDIterator, inName, posX, posY);									//siganture of Collecatble class ->		Collectables<T>::Collectables(int inID, T inDisplayName, int inPosX, int inPosY)

		if (newCollectable)
		{
			mCollectableMapChar.emplace(mUniqueIDIterator++, newCollectable);
		}
		return newCollectable;
	}

};

