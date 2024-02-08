#include "ChangeDrawingColor.h"
#include "ApplicationManager.h"
#include "DEFS.h"
#include "CMUgraphicsLib\CMUgraphics.h"
#include "Figures/CFigure.h"
#include <string>

ChangeDrawingColor::ChangeDrawingColor(ApplicationManager* pApp) :Action(pApp)
{
	SelectedFigure = NULL;
}


void ChangeDrawingColor::ReadActionParameters()
{
	SelectedFigure = pManager->GetSelectedFig();
}

void ChangeDrawingColor::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("You Will Change Drawing Color.");
	//if (!pManager->GetPlayingRecordState())
		ReadActionParameters();
	if (SelectedFigure != NULL)
	{
		if (!pManager->GetPlayingRecordState())
		Act =pIn->GetUserAction();
		switch (Act)
		{
		case SELECT_COLOR_RED:
			pOut->PrintMessage("You Chose Red.");
			SelectedFigure->ChngDrawClr(RED);
			newcolor = RED;
			break;

		case SELECT_COLOR_BLACK:
			pOut->PrintMessage("You Chose Black.");
			SelectedFigure->ChngDrawClr(BLACK);
			newcolor = BLACK;
			break;
			
		case SELECT_COLOR_BLUE:
			pOut->PrintMessage("You Chose Blue.");
			SelectedFigure->ChngDrawClr(BLUE);
			newcolor = BLUE;
			break;

		case SELECT_COLOR_GREEN:
			pOut->PrintMessage("You Chose Green.");
			SelectedFigure->ChngDrawClr(GREEN);
			newcolor = GREEN;
			break;

		case SELECT_COLOR_ORANGE:
			pOut->PrintMessage("You Chose Orange.");
			SelectedFigure->ChngDrawClr(ORANGE);
			newcolor = ORANGE;
			break;

		case SELECT_COLOR_YELLOW:
			pOut->PrintMessage("You Chose Yellow.");
			SelectedFigure->ChngDrawClr(YELLOW);
			newcolor = YELLOW;
			break;
		}
		SelectedFigure->SetSelected(false);
		UI.DrawColor = newcolor;
	}
	if (pManager->GetRecording() && pManager->CheckForPlace())
	{
		Action* action = pManager->GetAction();
		pManager->AddAction(action);
	}
	else if (!pManager->CheckForPlace())
		pManager->SetRecording(false);
}

void ChangeDrawingColor::Undo() {

}