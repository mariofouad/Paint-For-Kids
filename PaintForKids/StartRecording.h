#pragma once
#include "Actions/Action.h"
#include <string>


class StartRecording : public Action
{
private:
	int numoffigures;

public:
	StartRecording(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	bool CheckForPlace();
	virtual void Undo();
};
