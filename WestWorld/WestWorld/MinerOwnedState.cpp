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
VisitBankAndDepositGold*VisitBankAndDepositGold::Instance()
{
	static VisitBankAndDepositGold instance;
	return &instance;
}
void VisitBankAndDepositGold::Enter(Miner*pMiner)
{
	if (pMiner->Location() != bank)
	{
		cout << "\n" << GetNameOfEntity(pMiner->getID()) << ": " << "Goin' to the bank. Yes siree";
		pMiner->ChangeLocation(bank);
	}
}
void VisitBankAndDepositGold::Execute(Miner*pMiner)
{
	//deposit gold
	pMiner->AddToWealth(pMiner->GoldCarried());
	pMiner->SetGoldCarried(0);
	cout << "\n" << GetNameOfEntity(pMiner->getID()) << ": "
		<< "Depositing gold. Total savings now: " << pMiner->GetWealth();
	if (pMiner->GetWealth() >= ComfortLevel)
	{
		cout<<"\n"<<GetNameOfEntity(pMiner->getID())<<": " << "WooHoo! Rich enough for now. Back home to mah li'lle lady";

		pMiner->ChangeState(GoHomeAndSleepTilRested::Instance());
	}
	else
	{
		pMiner->ChangeState(EnterMineAndDigForNugget::Instance());
	}
}
void VisitBankAndDepositGold::Exit(Miner*pMiner)
{
	cout<<"\n"<<GetNameOfEntity(pMiner->getID())<<": "<< "Leavin' the bank";
}
