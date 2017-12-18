#pragma once
class Telegram;
template <class entity_type>
class State
{
public:
	//State();
	virtual ~State() {};
	//当状态被进入时执行这个
	virtual void Enter(entity_type*)=0;
	//当状态更新时执行这个
	virtual void Execute(entity_type*) = 0;
	//当状态退出时执行这个
	virtual void Exit(entity_type*) = 0;
	//消息处理函数
	//this executes if the agent receives a message from the
	//message dispatcher
	virtual bool OnMessage(entity_type*, const Telegram&) = 0;
};