#pragma once
#include "Actions/Action.h"
#include <fstream>
#include <string>
class SwitchToPlayMode : public Action
{
private:
	string FileName;
	ofstream file;
public:
	SwitchToPlayMode(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
};

