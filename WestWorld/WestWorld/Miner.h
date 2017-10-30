#pragma once
#include "GameEntity.h"
#include "State.h"
#include "Locations.h"

class State;
const int MaxNuggets = 3;
const int ComfortLevel = 5;
class Miner:public BaseGameEntity
{
private:
	State* p_CurrentState;
	location_type m_Location;
	int i_GoldCarried;
	int i_MoneyInBank;
	int i_Thirst;//口渴值
	int i_Fatigue;//疲劳值
public:
	Miner(int ID);
	~Miner();
	void Update();
	void ChangeState(State* p_NewState);
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
};