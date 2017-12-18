#pragma once
#include <string>
enum MessageTypes
{
	Msg_HiHoneyImHome,
	Msg_StewReady
};
inline std::string MsgToStr(int MessageTypes)
{
	switch (MessageTypes)
	{
	case Msg_HiHoneyImHome:
		return "HiHoneyImHome";
	case Msg_StewReady:
		return "Msg_StewReady";
	default:
		return "No recognized";
	}
}