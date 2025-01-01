#pragma once

//class CollectableSpawner;								//forward declare friend class

template<typename T>
class Collectables
{
	friend class CollectableSpawner;						//declare friend class										gives CollectableSpawner permission to create Collectable object

	//CONSTRUCTORS  - private 
	Collectables() = delete;							//constructor - default - deleted

	//MEMBER VARIABLES
	int mID;
	T mDisplayName;
	int mCollectablePositionX;
	int mCollectablePositionY;
	bool mHasBeenCollected;

protected:
	Collectables(int inID, T inDisplayName, int inPosX, int inPosY);			//constructor - param

public:
	int GetID() const;									//Getter func for private vars
	T	GetDisplayName() const;
	int GetPositionX();
	int GetPositionY();
	bool GetHasBeenCollected();
	void SetHasBeenCollected();

};

//TEMPLATE FUNCTION DEFINITION
template<typename T>
inline Collectables<T>::Collectables(int inID, T inDisplayName, int inPosX, int inPosY)
{
	mID = inID;
	mDisplayName = inDisplayName;
	mCollectablePositionX = inPosX;
	mCollectablePositionY = inPosY;
	mHasBeenCollected = false;
}


template<typename T>
inline int Collectables<T>::GetID() const
{
	return mID;
}

template<typename T>
inline T Collectables<T>::GetDisplayName() const
{
	return mDisplayName;
}

template<typename T>
inline int Collectables<T>::GetPositionX()
{
	return mCollectablePositionX;
}

template<typename T>
inline int Collectables<T>::GetPositionY()
{
	return mCollectablePositionY;
}

template<typename T>
inline bool Collectables<T>::GetHasBeenCollected()
{
	return mHasBeenCollected;
}

template<typename T>
inline void Collectables<T>::SetHasBeenCollected()
{
	mHasBeenCollected = true;
}

