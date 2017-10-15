#include "Miner.h"

Miner::Miner(int ID):BaseGameEntity(ID),
					 m_Location(shack),
					 i_GoldCarried(0),
					 i_MoneyInBank(0),
					 i_Thirst(0),
					 i_Fatigue(0),
					 p_CurrentState(nullptr)
{}

