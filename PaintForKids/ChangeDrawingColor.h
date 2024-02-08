#pragma once
#include "Actions/Action.h"
#include "Figures/CFigure.h"

class ChangeDrawingColor : public Action
{
private:
	CFigure* SelectedFigure;
	ActionType Act;
	color newcolor;
public:
	ChangeDrawingColor(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
};

