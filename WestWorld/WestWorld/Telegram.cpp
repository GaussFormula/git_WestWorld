#include "Telegram.h"
Telegram::Telegram() :
	sender(-1),
	receiver(-1),
	msg(-1),
	DispatchTime(-1)
{
}



Telegram::~Telegram()
{
}

std::ostream& operator<<(std::ostream& os, const Telegram&t)
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


bool Telegram::operator==(const Telegram&t1)const
{
	return(fabs(DispatchTime - t1.DispatchTime)<SmallestDelay) &&
		(sender == t1.sender) &&
		(receiver == t1.receiver) &&
		(msg == t1.msg);
}

bool Telegram::operator<(const Telegram&t)const
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