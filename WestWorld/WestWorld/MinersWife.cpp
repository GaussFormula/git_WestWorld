#include "Miner's_Wife.h"
bool MinersWife::HandleMessage(const Telegram&msg)
{
	return m_pStateMachine->HandleMessage(msg);
}

void MinersWife::Update()
{
	m_pStateMachine->Update();
}