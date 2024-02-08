#pragma once
#include "Actions/Action.h"
#include <string>
class StopRecording : public Action
{
public:
	StopRecording(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
};
