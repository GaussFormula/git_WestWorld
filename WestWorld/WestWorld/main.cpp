#include "Locations.h"
#include "Miner.h"
#include <Windows.h>
#include "EntityNames.h"
int main()
{
	Miner miner(Miner_Bob);
	for (int i = 0; i < 20; ++i)
	{
		miner.Update();
		Sleep(800);
	}
	getchar();
	return 0;
}