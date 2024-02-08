#pragma once
#include "Actions/Action.h"
#include <string>
class PlayRecording : public Action
{
private:
	Action* pAct;
	int NumOfCurrentActions;
public:
	PlayRecording(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	void SetNumOfCurrentActions(int currentacions);
	void Wait();
	virtual void Undo();
};

