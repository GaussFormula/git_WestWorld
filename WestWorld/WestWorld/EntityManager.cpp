#include "EntityManager.h"
#include "GameEntity.h"
//using std::cout;
//-----------------------------
//
//	this class is a singleton
//-----------------------------
EntityManager*EntityManager::Instace()
{
	static EntityManager instance;
	return &instance;
}

BaseGameEntity* EntityManager::GetEntityFromID(int id)const
{
	//find the entity
	std::map<int, BaseGameEntity*>::const_iterator ent = EntityMap.find(id);
	if (ent != EntityMap.end())
	{
		return ent->second;
	}
	else
	{
		std::cout << "<EntityManager::GetEntityFromID>: invalid ID";
		abort();
		return NULL;
	}
}

void EntityManager::RemoveEntiry(BaseGameEntity*p)
{
	EntityMap.erase(EntityMap.find(p->getID()));
}

void EntityManager::RegisterEntity(BaseGameEntity*NewEntity)
{
	EntityMap.insert(std::make_pair(NewEntity->getID(), NewEntity));
}

EntityManager::EntityManager()
{
}

EntityManager::~EntityManager()
{
}