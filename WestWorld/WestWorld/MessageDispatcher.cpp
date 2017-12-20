#include "MessageDispatcher.h"
#include "GameEntity.h"
#include "EntityManager.h"
#include "Locations.h"
#include "MessageTypes.h"
#include "EntityNames.h"

#include <iostream>
#include <ctime>
using std::cout;

using std::set;

MessageDispatcher* MessageDispatcher::Instance()
{
	static MessageDispatcher instance;
	return &instance;
}

void MessageDispatcher::DispatchMessage(double delay, int sender, int receiver, int msg, void * ExtraInfo)
{
	//get pointers to the sender and receiver
	BaseGameEntity*pReceiver = EntityManager::Instace()->GetEntityFromID(receiver);
	BaseGameEntity*pSender = EntityManager::Instace()->GetEntityFromID(sender);

	//make sure that receiver is valid
	if (pReceiver == NULL)
	{
		cout << "\nWarning! No receiver with ID of " << receiver << " found";
		return;
	}

	//create the telegram
	Telegram telegram(0, sender, receiver, msg, ExtraInfo);

	//if there is no delay, route telegram immediately
	if (delay <= 0.0f)
	{
		cout << "\nInstant telegram dispatched at time: " << system("time")
			<< " by " << GetNameOfEntity(sender) << " for " << GetNameOfEntity(receiver)
			<< ". Msg is " << MsgToStr(msg);

		//send the telegram to the recipient
		Discharge(pReceiver, telegram);
	}

	//else calculate the time when the telegran should be dispatched
	else
	{
		time_t now_time;
		now_time = time(NULL);
		double CurrentTime = now_time;
		telegram.DispatchTime = CurrentTime + delay;

		//and put it in the queue
		PriorityQ.insert(telegram);

		cout << "\nDelayed telegram from " << GetNameOfEntity(pSender->getID()) << " recorded at time "
			<< system("time") << " for " << GetNameOfEntity(pReceiver->getID())
			<< ". Msg is " << MsgToStr(msg);
	}
}

void MessageDispatcher::Discharge(BaseGameEntity*pReceiver, const Telegram&msg)
{
	if (!pReceiver->HandleMessage(msg))
	{
		//telegram could not be handled
		cout << "Message not handled";
	}
}


//----------------------------------------------------------------
//
//	This function dispatches any telegrams with a timestamp that has 
//	expired. And dispatched telegrams are removed from the queue.
//----------------------------------------------------------------

void MessageDispatcher::DispatchDelayedMessage()
{
	//get current time
	time_t now_time;
	now_time = time(NULL);
	double CurrentTime = now_time;

	//now peek at the queue to see if any telegrams need dispatching.
	//remove all telegrams from the front of the queue that have gone
	//past their sell by date
	while (!PriorityQ.empty() &&
		(PriorityQ.begin()->DispatchTime < CurrentTime) &&
		(PriorityQ.begin()->DispatchTime > 0))
	{
		//read the telegram from the front of the queue
		const Telegram& telegram = *PriorityQ.begin();

		//find the recipient
		BaseGameEntity* pReceiver = EntityManager::Instace()->GetEntityFromID(telegram.receiver);

		cout << "\nQueued telegram ready for dispatch: Sent to "
			<< GetNameOfEntity(pReceiver->getID()) << ". Msg is " << MsgToStr(telegram.msg);


		//send the telegram to the recipient
		Discharge(pReceiver, telegram);

		//remove it from the queue
		PriorityQ.erase(PriorityQ.begin());
	}
}

MessageDispatcher::MessageDispatcher()
{
}

MessageDispatcher::~MessageDispatcher()
{
}