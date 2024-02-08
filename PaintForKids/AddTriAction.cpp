#include"AddTriAction.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include "ApplicationManager.h"
#include "CTri.h"
#include <string>

AddTriAction::AddTriAction(ApplicationManager *pApp) : Action(pApp) {}

void AddTriAction::ReadActionParameters() {

	// get a pointer to the input and output classes
	
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: Click at the first vertex");

	// gets the first vertex from the user click

	pIn->GetPointClicked(v1.x, v1.y);

	pOut->PrintMessage("Click at the second vertex");

	// gets the second vertex from the user click

	pIn->GetPointClicked(v2.x, v2.y);

	pOut->PrintMessage("Click at the third vertex");

	// gets the thirds vertex from the user click

	pIn->GetPointClicked(v3.x, v3.y);

	if (pManager->GetIsColorChanged())
	{
		TriGfxInfo.isFilled = true;
	}
	else
	{
		TriGfxInfo.isFilled = false; // not filled by default
	}
	TriGfxInfo.FillClr = pOut->getCrntFillColor(); // gets the filling color
	TriGfxInfo.DrawClr = pOut->getCrntDrawColor(); // gets the drawing color

	pOut->ClearStatusBar();

}

void AddTriAction::Execute() {

	if (!pManager->GetPlayingRecordState())
		ReadActionParameters(); //reads the parameters of the triangle

	CTri* T = new CTri(v1, v2, v3, TriGfxInfo); // creates a triangle with the read parameters

	pManager->AddFigure(T); // adds the triangle to the list of figures

	if (pManager->GetRecording() && pManager->CheckForPlace())
	{
		Action* action = pManager->GetAction();
		pManager->AddAction(action);
	}
	else if (!pManager->CheckForPlace())
		pManager->SetRecording(false);
}

void AddTriAction::Undo() {
	pManager->RemoveFigure();
	pManager->UpdateInterface();
}