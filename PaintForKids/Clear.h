#pragma once
#include"Actions/Action.h"
#include <string>
class Clear :public Action
{
public:
	Clear(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
};
