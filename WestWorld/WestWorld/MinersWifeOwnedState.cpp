#include "Miner'sWifeOwnedState.h"
#include "MinerOwnedState.h"
#include "Miner's_Wife.h"
#include "Locations.h"
#include "MessageDispatcher.h"
#include "MessageTypes.h"
#include "EntityNames.h"

#include <iostream>
#include <ctime>

using std::cout;

WifeGlobalState* WifeGlobalState::Instance()
{
	static WifeGlobalState instance;
	return &instance;
}

void WifeGlobalState::Execute(MinersWife*wife)
{
	//1 in 10 chance of needing the bathroom (provided
	//she is not already in the bathroom.
	srand((unsigned)time(0));
	if ((rand() % 10) < 1 && !wife->GetFSM()->isInState(*VisitBathroom::Instance()))
	{
		wife->GetFSM()->ChangeState(VisitBathroom::Instance());
	}
	
}

bool WifeGlobalState::OnMessage(MinersWife*wife, const Telegram&msg)
{
	switch (msg.msg)
	{
	case Msg_HiHoneyImHome:
	{
		cout << "\nMessage handled by " << GetNameOfEntity(wife->getID()) <<
			" at time: " << system("time");
		cout << "\nMessage handled by " << GetNameOfEntity(wife->getID()) <<
			": Hi honey. Let me make you some of mah fine country stew";

		wife->GetFSM()->ChangeState(CookStew::Instance());
	}
	return true;
	}
	return false;
}

DoHouseWork* DoHouseWork::Instance()
{
	static DoHouseWork instance;
	return &instance;
}


void DoHouseWork::Enter(MinersWife*wife)
{
	cout << "\n" << GetNameOfEntity(wife->getID()) << ": Time to do some more housework!";
}

void DoHouseWork::Execute(MinersWife*wife)
{
	srand((unsigned)time(0));
	switch (rand()%3)
	{
	case 0:
		cout << "\n" << GetNameOfEntity(wife->getID()) << ": Moppin' the floor";
		break;
	case 1:

		cout << "\n" << GetNameOfEntity(wife->getID()) << ": Washin' the dishes";

		break;

	case 2:

		cout << "\n" << GetNameOfEntity(wife->getID()) << ": Makin' the bed";

		break;
	}
}

void DoHouseWork::Exit(MinersWife*wife)
{
	cout << "\n" << "Not doing housework!";
}

bool DoHouseWork::OnMessage(MinersWife*wife, const Telegram&msg)
{
	return false;
}

VisitBathroom* VisitBathroom::Instance()
{
	static VisitBathroom instance;

	return &instance;
}

void VisitBathroom::Enter(MinersWife*wife)
{
	cout << "\n" << GetNameOfEntity(wife->getID()) << ": Walkin' to the can. Need to powda mah pretty li'lle nose";
}

void VisitBathroom::Execute(MinersWife*wife)
{
	cout << "\n" << GetNameOfEntity(wife->getID()) << ": Ahhhhhh! Sweet relief!";

	wife->GetFSM()->RevertToPreviousState();
}
void VisitBathroom::Exit(MinersWife*wife)
{
	cout << "\n" << GetNameOfEntity(wife->getID()) << ": Leavin' the Jon";
}

bool VisitBathroom::OnMessage(MinersWife*wife, const Telegram&msg)
{
	return false;
}

CookStew* CookStew::Instance()
{
	static CookStew instance;

	return &instance;
}

void CookStew::Enter(MinersWife*wife)
{
	if (!wife->Cooking())
	{
		cout << "\n" << GetNameOfEntity(wife->getID()) << ": Putting the stew in the oven";

		//send a delayed message myself so that I know when to take the stew
		//out of the oven.
		MessageDispatcher::Instance()->DispatchMessage(1.5,
			wife->getID(),
			wife->getID(),
			Msg_StewReady,
			No_Additonal_Info);
		wife->SetCooking(true);
	}
}

void CookStew::Execute(MinersWife*wife)
{
	cout << "\n" << GetNameOfEntity(wife->getID()) << ": Fussin' over food";
}

void CookStew::Exit(MinersWife*wife)
{
	cout << "\n" << GetNameOfEntity(wife->getID()) << ": Puttin' the stew on the table";
}

bool CookStew::OnMessage(MinersWife*wife, const Telegram&msg)
{
	switch (msg.msg)
	{
	case Msg_StewReady:
	{
		cout << "\nMessage received by " << GetNameOfEntity(wife->getID())
			<< " at time: " << system("time");

		cout << "\n" << GetNameOfEntity(wife->getID()) << ": StewReady! Lets eat";

		//let hubby know the stew is ready
		MessageDispatcher::Instance()->DispatchMessage(
			Send_Message_Immediately,
			wife->getID(),
			Miner_Bob,
			Msg_StewReady,
			No_Additonal_Info);
		wife->SetCooking(false);
		wife->GetFSM()->ChangeState(DoHouseWork::Instance());

	}
	return true;
	}//end of switch
	return false;
}