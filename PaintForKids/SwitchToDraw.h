#pragma once
#include "Actions/Action.h"
class SwitchToDraw : public Action
{
public:
	SwitchToDraw(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
};

