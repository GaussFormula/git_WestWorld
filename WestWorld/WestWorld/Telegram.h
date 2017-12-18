#pragma once
#include <iostream>
#include <math.h>
class Telegram
{
public:
	Telegram();
	~Telegram();

private:
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