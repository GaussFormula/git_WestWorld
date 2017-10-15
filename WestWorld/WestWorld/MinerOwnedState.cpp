#include "MinerOwnedState.h"
#include "State.h"
#include "Miner.h"
#include "Locations.h"
#include "EntityNames.h"
#include <iostream>
using std::cout;
EnterMineAndDigForNugget * EnterMineAndDigForNugget::Instance()
{
	static EnterMineAndDigForNugget instance;
	return &instance;
}
void EnterMineAndDigForNugget::Enter(Miner*pMiner)
{
	if (pMiner->Location() != goldmine)
	{
		cout<<"\n"<<GetNameOfEntity(pMiner->getID())<<": "<< "Walkin' to the goldmine";
	}
	pMiner->ChangeLocation(goldmine);
}
void EnterMineAndDigForNugget::Execute(Miner*pMiner)
{
	pMiner->AddToGoldCarried(1);
	pMiner->IncreaseFatigue();

	cout<<"\n"<<GetNameOfEntity(pMiner->getID())<<": "<< "Pickin' up a nugget";
	if (pMiner->PocketIsFull())
	{
		pMiner->ChangeState(VisitBankAndDepositGold::Instance());
	}
	if (pMiner->Thirsty())
	{
		pMiner->ChangeState(QuenchThirst::Instance());
	}
}
