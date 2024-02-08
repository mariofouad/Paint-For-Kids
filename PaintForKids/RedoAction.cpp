#include"RedoAction.h"
#include "ApplicationManager.h"
#include"GUI/Output.h"
#include"GUI/Input.h"
#include "DEFS.h"

RedoAction::RedoAction(ApplicationManager* pApp) :Action(pApp) {}

void RedoAction::ReadActionParameters() {}
void RedoAction::Undo() {}

//redoes the undone addfigure actions
void RedoAction::Execute()
{
	//pManager->AddFigure(pManager->GetlastUndoneFigure()); //this should get the last undone figure and add it to the figlist 
	//pManager->UpdateInterface(); //updates the interface with the and adds the figure that has been redone.
}
