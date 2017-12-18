#pragma once
//Name: GameEntity.h
//Desc: Base class for a game object
#include <string>
#include "Telegram.h"
//------------------------------------------------------------
//	Name: GameEntity.h
//
//	Desc: Base class for a game object
//------------------------------------------------------------
class BaseGameEntity
{
private:
	int ID;
	static int NextID;
	void setID(int val); //{ ID = val; NextID = ID + 1; }
public:
	BaseGameEntity(int id)
	{
		setID(id);
	}
	virtual ~BaseGameEntity() {}
	virtual void Update() = 0;//¸üÐÂº¯Êý
	//all entities can communicate using messages. They are sent
	//using the MessageDispatcher singleton class
	virtual bool HandleMessage(const Telegram& msg) = 0;
	int getID()const
	{
		return this->ID;
	}
};