#pragma once
class BaseGameEntity
{
private:
	int ID;
	static int NextID;
	void setID(int val);
public:
	BaseGameEntity(int id)
	{
		setID(id);
	}
	virtual ~BaseGameEntity() {}
	virtual void Update() = 0;//¸üÐÂº¯Êý
	int getID()const
	{
		return this->ID;
	}
};