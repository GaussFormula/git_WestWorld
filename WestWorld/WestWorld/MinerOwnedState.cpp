#include "MinerOwnedState.h"
#include "State.h"
#include "Miner.h"
#include "Locations.h"
#include "EntityNames.h"
#include "Telegram.h"
#include "MessageDispatcher.h"
#include "MessageTypes.h"


#include <iostream>
#include <time.h>
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
		pMiner->ChangeLocation(goldmine);
	}
}
void EnterMineAndDigForNugget::Execute(Miner*pMiner)
{
	pMiner->AddToGoldCarried(1);
	pMiner->IncreaseFatigue();

	cout<<"\n"<<GetNameOfEntity(pMiner->getID())<<": "<< "Pickin' up a nugget";
	if (pMiner->PocketIsFull())
	{
		pMiner->GetFSM()->ChangeState(VisitBankAndDepositGold::Instance());
	}
	if (pMiner->Thirsty())
	{
		pMiner->GetFSM()->ChangeState(QuenchThirst::Instance());
	}
}
void EnterMineAndDigForNugget::Exit(Miner*pMiner)
{
	cout<<"\n"<<GetNameOfEntity(pMiner->getID())<<": "<<
		"Ah'm leavin' the goldmine with mah pockets full o' sweet gold";

}
bool EnterMineAndDigForNugget::OnMessage(Miner * agent, const Telegram & msg)
{
	//send msg to global message handler
	return false;
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

		//pMiner->ChangeState(GoHomeAndSleepTilRested::Instance());
		pMiner->GetFSM()->ChangeState(GoHomeAndSleepTilRested::Instance());
	}
	else
	{
		//pMiner->ChangeState(EnterMineAndDigForNugget::Instance());
		pMiner->GetFSM()->ChangeState(EnterMineAndDigForNugget::Instance());
	}
}
void VisitBankAndDepositGold::Exit(Miner*pMiner)
{
	cout<<"\n"<<GetNameOfEntity(pMiner->getID())<<": "<< "Leavin' the bank";
}
bool VisitBankAndDepositGold::OnMessage(Miner * agent, const Telegram & msg)
{
	//send msg to global message handler
	return false;
}
GoHomeAndSleepTilRested* GoHomeAndSleepTilRested::Instance()
{
	static GoHomeAndSleepTilRested instance;
	return &instance;
}

void GoHomeAndSleepTilRested::Enter(Miner*pMiner)
{
	if (pMiner->Location() != shack)
	{
		cout << "\n" << GetNameOfEntity(pMiner->getID()) << ": " << "Walkin' home";
		pMiner->ChangeLocation(shack);
		MessageDispatcher::Instance()->DispatchMessage(Send_Message_Immediately,
			pMiner->getID(), Elsa, Msg_HiHoneyImHome, No_Additonal_Info);
	}
}
void GoHomeAndSleepTilRested::Execute(Miner*pMiner)
{
	if (!pMiner->Fatigued())
	{
		cout<<"\n"<<GetNameOfEntity(pMiner->getID())<<": "<< "What a God darn fantastic nap! Time to find more gold";
		//pMiner->ChangeState(EnterMineAndDigForNugget::Instance());
		pMiner->GetFSM()->ChangeState(EnterMineAndDigForNugget::Instance());
	}
	else
	{
		pMiner->DecreaseFatigue();
		cout << "\n" << GetNameOfEntity(pMiner->getID()) << ": " << "Zzzzz...";
	}
}

void GoHomeAndSleepTilRested::Exit(Miner*pMiner)
{
	cout << "\n" << GetNameOfEntity(pMiner->getID()) << ": " << "Leaving the house";
}

bool GoHomeAndSleepTilRested::OnMessage(Miner * agent, const Telegram & msg)
{
	switch (msg.msg)
	{
	case Msg_StewReady:
		cout << "\nMessage handled by" << GetNameOfEntity(agent->getID())
			<< " at time: " << system("time");
		cout << "\n" << GetNameOfEntity(agent->getID())
			<< ": Okay Hun, ahm a comin'!";
		agent->GetFSM()->ChangeState(EatStew::Instance());
		return true;
	}
	return false;
}

QuenchThirst* QuenchThirst::Instance()
{
	static QuenchThirst instance;
	return &instance;
}
void QuenchThirst::Enter(Miner*pMiner)
{
	if (pMiner->Location() != saloon)
	{
		pMiner->ChangeLocation(saloon);
		cout<<"\n"<<GetNameOfEntity(pMiner->getID())<<": "<< "Boy, ah sure is thusty! Walking to the saloon";
	}
}

void QuenchThirst::Execute(Miner*pMiner)
{
	if (pMiner->Thirsty())
	{
		pMiner->BuyAndDrinkWhiskey();
		cout<<"\n"<<GetNameOfEntity(pMiner->getID())<<": "<< "That's mighty fine sippin liquer";
		//pMiner->ChangeState(EnterMineAndDigForNugget::Instance());
		pMiner->GetFSM()->ChangeState(EnterMineAndDigForNugget::Instance());
	}
	else
	{
		cout << "\nERROR!\nERROR!\nERROR!";
	}
}

void QuenchThirst::Exit(Miner*pMiner)
{
	cout<<"\n"<<GetNameOfEntity(pMiner->getID())<<": "<< "Leaving the saloon, feelin' good";
}

bool QuenchThirst::OnMessage(Miner * agent, const Telegram & msg)
{
	//send msg to global message handle function
	return false;
}

EatStew * EatStew::Instance()
{
	static EatStew instance;

	return &instance;
}

void EatStew::Enter(Miner*pMiner)
{
	cout << "\n" << GetNameOfEntity(pMiner->getID())
		<< ": " << "Smells Reaaal goood Elsa!";

}

void EatStew::Execute(Miner* pMiner)
{
	cout << "\n" << GetNameOfEntity(pMiner->getID())
		<< ": " << "Tastes real good too!";
	pMiner->GetFSM()->RevertToPreviousState();
}

void EatStew::Exit(Miner*pMiner)
{
	cout << "\n" << GetNameOfEntity(pMiner->getID())
		<< ": " << "Thankya li'lle lady. Ah better get back to whatever ah wuz doin'";
}

bool EatStew::OnMessage(Miner*pMiner,const Telegram&msg)
{
	//send msg to global message handler
	return false;
}