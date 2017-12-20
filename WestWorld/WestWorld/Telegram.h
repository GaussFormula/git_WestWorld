#pragma once
#include <iostream>
#include <math.h>
class Telegram
{
public:
	Telegram();
	~Telegram();

	//the entity that sent this telegram
	int sender;
	//the entity that receive this telegram
	int receiver;
	//the message itself These are all enumerated in the file
	//"MessageTypes.h"
	int msg;
	//messages can be dispatched immediately or delayed for a specified amount
	//of time. If a delay is necessary this field is stamped with the time 
	//the message should be dispatched.
	double DispatchTime;
	//any additional information that may accompany this message
	void* ExtraInfo;

	Telegram(double time, int sender, int receiver, int msg, void* info = NULL)
	{}

	//these telegram will be stored in a priority queue.Therefore the > 
	//operator needs to be overloaded so that the PQ can sort the telegrams
	//by time priotity. Note how the times must be smaller than 
	//SmallestDelay apart before two telegrams are considered unique.
	const double SmallestDelay = 0.25;

	bool operator==(const Telegram&t1);
	bool operator<(const Telegram&t);
	
};

Telegram::Telegram():
			sender(-1),
			receiver(-1),
			msg(-1),
			DispatchTime(-1)
{
}



Telegram::~Telegram()
{
}

std::ostream& operator<<(std::ostream& os,const Telegram&t)
{
	os << "time: " << t.DispatchTime << " Sender: " << t.sender <<
		" Receiver: " << t.receiver << "  Msg: " << t.msg;
	return os;
}


//handy helper function for dereferencing the ExtraInfo field of the Telegram
//to the require type.
template <class T>
T DereferenceToType(void* p)
{
	return *(T*)(p);
}


bool Telegram::operator==(const Telegram&t1)
{
	return(fabs(DispatchTime - t1.DispatchTime)<SmallestDelay) &&
		(sender == t1.sender) &&
		(receiver == t1.receiver) &&
		(msg == t1.msg);
}

bool Telegram::operator<(const Telegram&t)
{
	if (*this == t)
	{
		return false;
	}
	else
	{
		return (DispatchTime < t.DispatchTime);
	}
}