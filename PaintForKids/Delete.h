#pragma once
#include"Actions/Action.h"
#include <string>
#include "PickByType.h"
class Delete :public Action
{
public:
	Delete(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
};

