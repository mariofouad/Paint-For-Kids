#pragma once
#include "Actions/Action.h"
#include "Figures/CFigure.h"

class ChangeFillColor : public Action
{
private:
	CFigure* SelectedFigure;
	ActionType Act;
	color newcolor;
public:
	ChangeFillColor(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
};

