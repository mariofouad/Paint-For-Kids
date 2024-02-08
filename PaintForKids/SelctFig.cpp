#include "SelctFig.h"
#include "ApplicationManager.h"
#include"GUI/Output.h"
#include"GUI/Input.h"
#include "DEFS.h"
#include <string>
SelctFig::SelctFig(ApplicationManager* pApp) :Action(pApp) {}

void SelctFig::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Select Figure from drawn area");

	pIn->GetPointClicked(P1.x, P1.y);

	pOut->ClearStatusBar();
}

//Execute the action
void SelctFig::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	if (!pManager->GetPlayingRecordState())
		ReadActionParameters();

	CFigure* ClFig = pManager->GetFigure(P1.x, P1.y);
	
	CFigure* slctd = pManager->GetSelectedFig();
	if (ClFig != NULL && ClFig->IsSelected()==false)
	{
		ClFig->SetSelected(true);
		ClFig->PrintInfo(pOut);
		if (slctd != NULL)
			slctd->SetSelected(false);
	}
	else if (ClFig != NULL && ClFig->IsSelected()==true)
	{
		ClFig->SetSelected(false);
	}
	else
		pOut->PrintMessage("No figure is selected");
	if (pManager->GetRecording() && pManager->CheckForPlace())
	{
		Action* action = pManager->GetAction();
		pManager->AddAction(action);
	}
	else if (!pManager->CheckForPlace())
		pManager->SetRecording(false);
}
void SelctFig::Undo() {
}