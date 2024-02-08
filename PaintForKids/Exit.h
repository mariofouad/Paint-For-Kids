#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"
#include <string>
class Exit : public Action
{
private:

public:
	Exit(ApplicationManager* pApp);
	
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
};

