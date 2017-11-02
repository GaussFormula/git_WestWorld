#include "Miner.h"
#include "MinerOwnedState.h"
Miner::Miner(int ID):BaseGameEntity(ID),
					 m_Location(shack),
					 i_GoldCarried(0),
					 i_MoneyInBank(0),
					 i_Thirst(0),
					 i_Fatigue(0),
					 p_CurrentState(GoHomeAndSleepTilRested::Instance())
{}
void Miner::Update()
{
	i_Thirst += 1;
	if (p_CurrentState)
	{
		p_CurrentState->Execute(this);
	}
}
void Miner::ChangeState(State*pNewState)
{
	if (p_CurrentState&&pNewState)
	{
		p_CurrentState->Exit(this);
		p_CurrentState = pNewState;
		p_CurrentState->Enter(this);
	}
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

