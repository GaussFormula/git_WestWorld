#pragma once
//-----------------------------------
//
//	Name: Miner's_Wife.h
//
//	Desc: class to implement Miner Bob's wife.
//
//-----------------------------------

#include <string>

#include "State.h"
#include "GameEntity.h"
#include "Locations.h"
#include "Miner'sWifeOwnedState.h"
#include "Miner.h"
#include "StateMachine.h"

class MinersWife :public BaseGameEntity
{
private:
	//an instance of the state machine class
	StateMachine<MinersWife>*m_pStateMachine;

	location_type m_Loaction;

	//is she presently cooking?
	bool m_bCooking;

public:

	MinersWife(int ID):m_Loaction(shack),
						m_bCooking(false),
						BaseGameEntity(ID)
	{
		//set up the state machine
		m_pStateMachine = new StateMachine<MinersWife>(this);

		m_pStateMachine->SetCurrentState(DoHouseWork::Instance());

		m_pStateMachine->SetGlobalState(WifeGlobalState::Instance());

	}

	~MinersWife()
	{
		delete m_pStateMachine;
	}

	//this must be implemented
	void Update();

	//and this
	virtual bool HandleMessage(const Telegram&msg);

	StateMachine<MinersWife>* GetFSM()const { return m_pStateMachine; }


	location_type Location()const { return m_Loaction; }
	void ChangeLocation(location_type Loc) { m_Loaction = Loc; }

	bool Cooking()const { return m_bCooking; }
	void SetCooking(bool val) { m_bCooking = val; }
};