#pragma once
#include"Actions/Action.h"
#include <string>
class Move :public Action
{
private:
	int x;
	int y;

public:
	Move(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
};

