#pragma once
//-------------------------------------------------------
//
//	Name: StateMachine.h
//
//	Desc: State machine class. Inherit from this class and create
//		  some state to give your agents FSM functionality
#include <string>

#include "State.h"
#include "Telegram.h"

template <class entity_type>
class StateMachine
{
public:
	StateMachine(entity_type* owner):m_pOwner(owner),
									 m_pCurrentState(NULL),
									 m_pPreviousState(NULL),
									 m_pGlobalState(NULL)
	{}
	virtual ~StateMachine() {}

	//use these method to initialize the FSM 
	void SetCurrentState(State<entity_type>* s) { m_pCurrentState = s; }
	void SetPreviousState(State<entity_type>* s) { m_pPreviousState = s; }
	void SetGlobalState(State<entity_type>* s) { m_pGlobalState = s; }

private:
	//a pointer to the agent that owns this instance
	entity_type * m_pOwner;

	State<entity_type>* m_pCurrentState;

	//a record of the last state the agent was in
	State<entity_type>* m_pPreviousState;

	//this is called every time the FSM is updated
	State<entity_type>* m_pGlobalState;
};
