#pragma once
#include "State.h"
class Miner;
class EnterMineAndDigForNugget:public State
{
private:
	EnterMineAndDigForNugget() {}
	EnterMineAndDigForNugget(const EnterMineAndDigForNugget&);
	EnterMineAndDigForNugget& operator= (const EnterMineAndDigForNugget&);
public:
	static EnterMineAndDigForNugget* Instance();
	virtual void Enter(Miner* miner);
	virtual void Execute(Miner*miner);
	virtual void Exit(Miner*miner);
};

class VisitBankAndDepositGold :public State
{
private:
	VisitBankAndDepositGold(){}
	VisitBankAndDepositGold(const VisitBankAndDepositGold&);
	VisitBankAndDepositGold& operator=(const VisitBankAndDepositGold&);
public:
	static VisitBankAndDepositGold* Instance();
	virtual void Enter(Miner* miner);
	virtual void Execute(Miner*miner);
	virtual void Exit(Miner*miner);
};

class GoHomeAndSleepTilRested :public State
{
private:
	GoHomeAndSleepTilRested(){}
	GoHomeAndSleepTilRested(const GoHomeAndSleepTilRested&);
	GoHomeAndSleepTilRested& operator=(const GoHomeAndSleepTilRested&);
public:
	static GoHomeAndSleepTilRested* Instance();

	virtual void Enter(Miner* miner);

	virtual void Execute(Miner* miner);

	virtual void Exit(Miner* miner);
};

class QuenchThirst : public State
{
private:

	QuenchThirst() {}

	//copy ctor and assignment should be private
	QuenchThirst(const QuenchThirst&);
	QuenchThirst& operator=(const QuenchThirst&);

public:

	//this is a singleton
	static QuenchThirst* Instance();

	virtual void Enter(Miner* miner);

	virtual void Execute(Miner* miner);

	virtual void Exit(Miner* miner);
};