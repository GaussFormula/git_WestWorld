#pragma once
//-----------------------------
//
//	Name:	Miner'sWifeOwnedState
//
//	Desc:	All the states that can be assigned to the MinersWife class
//
//-----------------------------
#include "State.h"

class MinersWife;


class WifeGlobalState : public State<MinersWife>
{
private:
	WifeGlobalState(){}

	//copy ctor and assigment should be private
	WifeGlobalState(const WifeGlobalState&);
	WifeGlobalState& operator=(const WifeGlobalState&);

public:
	//this is a singleton
	static WifeGlobalState* Instance();

	virtual void Enter(MinersWife*wife){}

	virtual void Execute(MinersWife*wife);

	virtual void Exit(MinersWife* wife){}

	virtual bool OnMessage(MinersWife* wife, const Telegram&msg);

};

class DoHouseWork :public State<MinersWife>
{
private:
	DoHouseWork(){}

	//copy ctor and assignment should be private
	DoHouseWork(const DoHouseWork&);
	DoHouseWork& operator=(const DoHouseWork&);

public:

	//this is a singleton
	static DoHouseWork* Instance();

	virtual void Enter(MinersWife*wife);

	virtual void Execute(MinersWife*wife);

	virtual void Exit(MinersWife*wife);

	virtual bool OnMessage(MinersWife*wife, const Telegram&msg);

};

class VisitBathroom :public State<MinersWife>
{
private:
	VisitBathroom(){}

	//copy ctor and assignment should be private
	VisitBathroom(const VisitBathroom&);
	VisitBathroom& operator=(const VisitBathroom&);

public:

	//this is a singleton
	static VisitBathroom* Instance();

	virtual void Enter(MinersWife*wife);

	virtual void Execute(MinersWife*wife);

	virtual void Exit(MinersWife*wife);

	virtual bool OnMessage(MinersWife* wife, const Telegram& msg);

};

class CookStew :public State<MinersWife>
{
private:
	CookStew(){}

	//copy ctor and assignment should be private
	CookStew(const CookStew&);
	CookStew& operator=(const CookStew&);

public:
	//this is a singleton
	static CookStew* Instance();

	virtual void Enter(MinersWife*wife);

	virtual void Execute(MinersWife*wife);

	virtual void Exit(MinersWife*wife);

	virtual bool OnMessage(MinersWife*wife, const Telegram&msg);

};