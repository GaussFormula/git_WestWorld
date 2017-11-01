#include "GameEntity.h"
int BaseGameEntity::NextID = 0;
void BaseGameEntity::setID(int val)
{
	ID = val;
	NextID = ID + 1;
}
