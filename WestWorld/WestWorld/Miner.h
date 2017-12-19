#pragma once
#include <string>
#include <iostream>

#include "GameEntity.h"
#include "State.h"
#include "Locations.h"
#include "StateMachine.h"

template <class entity_type> class State;
class Telegram;
const int MaxNuggets = 3;
const int ComfortLevel = 5;
const int TirednessThreshold = 5;
const int TirstLevel = 5;
class Miner:public BaseGameEntity
{
private:
	//an instace of the state machine class
	StateMachine<Miner>* m_pStateMachine;

	location_type m_Location;
	int i_GoldCarried;
	int i_MoneyInBank;
	int i_Thirst;//口渴值
	int i_Fatigue;//疲劳值
public:
	Miner(int ID);
	~Miner() { delete m_pStateMachine; };
	void Update();
	//void ChangeState(State<Miner>* p_NewState);
	location_type Location()const { return m_Location; }
	void ChangeLocation(const location_type loc) { m_Location = loc; }
	int GoldCarried()const { return i_GoldCarried; }
	void SetGoldCarried(const int val) { i_GoldCarried = val; }
	void AddToGoldCarried(const int val);
	bool PocketIsFull()const { return i_GoldCarried >= MaxNuggets; }
	bool Fatigued()const;
	void DecreaseFatigue() { i_Fatigue -= 1; }
	void IncreaseFatigue() { i_Fatigue += 1; }
	int GetWealth()const { return i_MoneyInBank; }
	void SetWealth(const int val) { i_MoneyInBank = val; }
	void AddToWealth(const int val);
	bool Thirsty()const;
	void BuyAndDrinkWhiskey() { i_Thirst = 0; i_MoneyInBank -= 2; }
	virtual bool HandleMessage(const Telegram&msg);
	StateMachine<Miner>* GetFSM()const { return m_pStateMachine; }

};