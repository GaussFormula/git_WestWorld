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

	bool operator==(const Telegram&t1)const;
	bool operator<(const Telegram&t)const;
	
};