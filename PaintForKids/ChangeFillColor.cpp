#include "ChangeFillColor.h"
#include "ApplicationManager.h"
#include "Figures/CFigure.h"

ChangeFillColor::ChangeFillColor(ApplicationManager* pApp) :Action(pApp) 
{
	SelectedFigure = NULL;
}


void ChangeFillColor::ReadActionParameters()
{
	SelectedFigure = pManager->GetSelectedFig();
}

void ChangeFillColor::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("You Will Change Fill Color.");
	//if (!pManager->GetPlayingRecordState())
		ReadActionParameters();
	if (!pManager->GetPlayingRecordState())
	Act = pIn->GetUserAction();
	if (SelectedFigure != NULL)
	{
		switch (Act)
		{
		case SELECT_COLOR_RED:
			pOut->PrintMessage("You Chose Red.");
			SelectedFigure->ChngFillClr(RED);
			newcolor = RED;
			break;

		case SELECT_COLOR_BLACK:
			pOut->PrintMessage("You Chose Black.");
			SelectedFigure->ChngFillClr(BLACK);
			newcolor = BLACK;
			break;

		case SELECT_COLOR_BLUE:
			pOut->PrintMessage("You Chose Blue.");
			SelectedFigure->ChngFillClr(BLUE);
			newcolor = BLUE;
			break;

		case SELECT_COLOR_GREEN:
			pOut->PrintMessage("You Chose Green.");
			SelectedFigure->ChngFillClr(GREEN);
			newcolor = GREEN;
			break;

		case SELECT_COLOR_ORANGE:
			pOut->PrintMessage("You Chose Orange.");
			SelectedFigure->ChngFillClr(ORANGE);
			newcolor = ORANGE;
			break;

		case SELECT_COLOR_YELLOW:
			pOut->PrintMessage("You Chose Yellow.");
			SelectedFigure->ChngFillClr(YELLOW);
			newcolor = YELLOW;
			break;
		}
			SelectedFigure->SetSelected(false);
			pManager->SetIsColorChanged(true);
			UI.FillColor = newcolor;
			pOut->SetCrntFillColor(newcolor);
	}
	if (pManager->GetRecording() && pManager->CheckForPlace())
	{
		Action* action = pManager->GetAction();
		pManager->AddAction(action);
	}
	else if (!pManager->CheckForPlace())
		pManager->SetRecording(false);
}

void ChangeFillColor::Undo() {

}