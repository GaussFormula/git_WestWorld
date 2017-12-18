#pragma once
class Telegram;
template <class entity_type>
class State
{
public:
	//State();
	virtual ~State() {};
	//��״̬������ʱִ�����
	virtual void Enter(entity_type*)=0;
	//��״̬����ʱִ�����
	virtual void Execute(entity_type*) = 0;
	//��״̬�˳�ʱִ�����
	virtual void Exit(entity_type*) = 0;
	//��Ϣ������
	//this executes if the agent receives a message from the
	//message dispatcher
	virtual bool OnMessage(entity_type*, const Telegram&) = 0;
};