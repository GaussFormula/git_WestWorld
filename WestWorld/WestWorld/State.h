#pragma once
class Miner;
class State
{
public:
	//State();
	virtual ~State() {};
	//��״̬������ʱִ�����
	virtual void Enter(Miner*)=0;
	//��״̬����ʱִ�����
	virtual void Execute(Miner*) = 0;
	//��״̬�˳�ʱִ�����
	virtual void Exit(Miner*) = 0;
};