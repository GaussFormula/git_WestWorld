#pragma once
#include "State.h"
class Miner;
class Telegram;

class EnterMineAndDigForNugget:public State<Miner>
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
	virtual bool OnMessage(Miner*agent, const Telegram& msg);
};

class VisitBankAndDepositGold :public State<Miner>
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
	
	virtual bool OnMessage(Miner*agent, const Telegram&msg);
};

class GoHomeAndSleepTilRested :public State<Miner>
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

	virtual bool OnMessage(Miner*agent, const Telegram& msg);
};

class QuenchThirst : public State<Miner>
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

	virtual bool OnMessage(Miner*agent, const Telegram&msg);
};

class EatStew :public State<Miner>
{
private:
	EatStew(){}

	//copy ctor and assignment should be private
	EatStew(const EatStew&);
	EatStew& operator=(const EatStew&);

public:

	//this is a singleton
	static EatStew* Instance();

	virtual void Enter(Miner*miner);

	virtual void Execute(Miner*Miner);

	virtual void Exit(Miner*miner);

	virtual bool OnMessage(Miner*agent, const Telegram&msg);


};