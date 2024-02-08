#include"UndoAction.h"
#include "ApplicationManager.h"
#include"GUI/Output.h"
#include"GUI/Input.h"
#include "DEFS.h"

UndoAction::UndoAction(ApplicationManager* pApp) :Action(pApp) {}

void UndoAction::ReadActionParameters() {}
void UndoAction::Undo() {}
//undo the addfigure action 
void UndoAction::Execute()
{
	//pManager->AddinUndoneArray(); //this should add the action that is going to be undone in the Undone list in order to use it to redo the addfigure action.
	pManager->RemoveFigure();
	pManager->UpdateInterface();
	if (pManager->GetRecording() && pManager->CheckForPlace())
	{
		Action* action = pManager->GetAction();
		pManager->AddAction(action);
	}
	else if (!pManager->CheckForPlace())
		pManager->SetRecording(false);
}
