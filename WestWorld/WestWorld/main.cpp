#include "Locations.h"
#include "Miner.h"
//#include <Windows.h>
#include "EntityNames.h"
int main()
{
	char c='\0';
	Miner miner(Miner_Bob);
	while(c!='q')
	{
		miner.Update();
		c=getchar();
	}
	return 0;
}