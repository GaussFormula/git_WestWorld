#pragma once
class Miner;
class State
{
public:
	//State();
	virtual ~State() {};
	//当状态被进入时执行这个
	virtual void Enter(Miner*)=0;
	//当状态更新时执行这个
	virtual void Execute(Miner*) = 0;
	//当状态退出时执行这个
	virtual void Exit(Miner*) = 0;
};