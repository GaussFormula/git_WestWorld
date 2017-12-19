#pragma once
//----------------------------------------------------
//
//	Name: EntityManager.h
//
//  Desc: Singleton class to handle the management of Entities
//
//----------------------------------------------------
#include <map>
#include <string>

class BaseGameEntity;

class EntityManager
{
public:
	EntityManager();
	~EntityManager();

	static EntityManager* Instace();

	//this method stores a pointer to the entity in the std::vector
	//m_Entities at the index position indicated(ָ��������) by the entity's ID
	//(makes for faster access)
	void RegisterEntity(BaseGameEntity* NewEntity);

	//returns a pointer to the entity with the ID given as a parameter
	BaseGameEntity* GetEntityFromID(int id)const;

	//this method removes the entity from the list
	void RemoveEntiry(BaseGameEntity* pEntity);


private:

	//to facilitate(�ٽ�) quick lookup the entities are stored in a std::map,
	//in which pointers to entities are cross referenced by their identifying number
	std::map<int, BaseGameEntity*> EntityMap;

	//���ƹ��캯��
	EntityManager(const EntityManager&);
	EntityManager& operator=(const EntityManager&);
};

EntityManager::EntityManager()
{
}

EntityManager::~EntityManager()
{
}