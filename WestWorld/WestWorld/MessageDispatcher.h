#pragma once
#include <set>
#include "Telegram.h"
class BaseGameEntity;
//to make code easier to read
const double Send_Message_Immediately = 0.0f;
const int No_Additonal_Info = 0;
class MessageDispatcher
{
public:
	MessageDispatcher();
	~MessageDispatcher();
	
	//this class is a singleton
	static MessageDispatcher* Instance();

	//send a message to another agent. Receiving agent is reference by ID
	void DispatchMessage(double delay,
		int sender,
		int receiver,
		int msg,
		void* ExtraInfo);

	//send out any delayed messages. This method is called each time through
	//the main game loop
	void DispatchDelayedMessage();

private:
	//a std::set is used as the container for the delayed messages
	//because of the benefit of automatic sorting and avoidance
	//of duplicates.Messages are sorted by their dispatch time.
	std::set<Telegram>PriorityQ;
	
	//this method is utilized by DispatchMessage or DispatchDelayedMessages.
	//This method calls the message handling member function of the receiving
	//entity, pReceiver, with the newly created Telegram
	void Discharge(BaseGameEntity* pReceiver, const Telegram& msg);

	//copy ctor and assignment should be private
	MessageDispatcher(const MessageDispatcher&) {}
	MessageDispatcher& operator=(const MessageDispatcher&);
};