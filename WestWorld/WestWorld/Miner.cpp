#include "Miner.h"
#include "MinerOwnedState.h"
#include "StateMachine.h"
Miner::Miner(int ID):BaseGameEntity(ID),
					 m_Location(shack),
					 i_GoldCarried(0),
					 i_MoneyInBank(0),
					 i_Thirst(0),
					 i_Fatigue(0)	 
{
	//set up state machine
	m_pStateMachine = new StateMachine<Miner>(this);

	m_pStateMachine->SetCurrentState(GoHomeAndSleepTilRested::Instance());
	//note: a global state has not been implemented for the miner
}
void Miner::Update()
{
	i_Thirst += 1;
	m_pStateMachine->Update();
}

void Miner::AddToGoldCarried(const int val)
{
	if (i_GoldCarried >= 0)
	{
		i_GoldCarried += val;
	}
}
void Miner::AddToWealth(const int val)
{
	i_MoneyInBank += i_GoldCarried;
}
bool Miner::Fatigued() const
{
	if (i_Fatigue > TirednessThreshold)
	{
		return true;
	}
	return false;
}

bool Miner::Thirsty()const
{
	if (i_Thirst >= TirstLevel)
	{
		return true;
	}
	return false;
}

bool Miner::HandleMessage(const Telegram&msg)
{
	return m_pStateMachine->HandleMessage(msg);
}

