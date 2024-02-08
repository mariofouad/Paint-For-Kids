#include"AddCircAction.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include "ApplicationManager.h"
#include "CCirc.h"
#include <string>
AddCircAction::AddCircAction(ApplicationManager *pApp):Action(pApp) {}

void AddCircAction::ReadActionParameters() {

	//get a pointer to the input and output classes

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: Click on the center");

	// gets the centter of the circle

	pIn->GetPointClicked(cent.x, cent.y);

	if (pManager->GetIsColorChanged())
	{
		CircGfxInfo.isFilled = true;
	}
	else
	{
		CircGfxInfo.isFilled = false; // not filled by default
	}
	CircGfxInfo.DrawClr = pOut->getCrntDrawColor(); // gets the drawing color
	CircGfxInfo.FillClr = pOut->getCrntFillColor(); // gets the filling color

	pOut->ClearStatusBar();
}

void AddCircAction::Execute() {

	if (!pManager->GetPlayingRecordState())
		ReadActionParameters();

	//create a circle with read parameters 
	CCirc* C = new CCirc(cent, CircGfxInfo); 

	//add circle to figure list 
	pManager->AddFigure(C);

	if (pManager->GetRecording() && pManager->CheckForPlace())
	{
		Action* action = pManager->GetAction();
		pManager->AddAction(action);
	}
	else if (!pManager->CheckForPlace())
		pManager->SetRecording(false);
}

void AddCircAction::Undo() {
	//pManager->AddinUndoneFigures();
	pManager->RemoveFigure();
	pManager->UpdateInterface();
}