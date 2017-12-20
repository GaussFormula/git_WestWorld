#include "Locations.h"
#include "Miner.h"
#include "Miner's_Wife.h"
#include "EntityManager.h"
#include "MessageDispatcher.h"
//#include <Windows.h>
#include "EntityNames.h"
int main()
{
	char c = '\0';
	Miner*Bob = new Miner(Miner_Bob);

	MinersWife* WifeElsa = new MinersWife(Elsa);

	EntityManager::Instace()->RegisterEntity(Bob);
	EntityManager::Instace()->RegisterEntity(WifeElsa);
	while (c!='q')
	{
		Bob->Update();
		WifeElsa->Update();
		c = getchar();
	}

	delete Bob;
	delete WifeElsa;
	return 0;
}