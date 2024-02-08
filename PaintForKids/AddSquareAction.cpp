#include"AddSquareAction.h"
#include"ApplicationManager.h"
#include"GUI/Output.h"
#include"GUI/Input.h"
#include "CSquare.h"
#include <string>

AddSquareAction::AddSquareAction(ApplicationManager* appPtr):Action(appPtr) {}

void AddSquareAction::ReadActionParameters() {

	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Square: Click at corner");

	//Read corner and store in point C
	pIn->GetPointClicked(C.x, C.y);


	if (pManager->GetIsColorChanged())
	{
		SquareGfxInfo.isFilled = true;
	}
	else
	{
		SquareGfxInfo.isFilled = false; // not filled by default
	}
	//get drawing, filling colors and pen width from the interface
	SquareGfxInfo.DrawClr = pOut->getCrntDrawColor();
	SquareGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();


}

//Execute the action
void AddSquareAction::Execute()
{
	//This action needs to read some parameters first
	if (!pManager->GetPlayingRecordState())
		ReadActionParameters();

	//Create a square with the parameters read from the user
	CSquare* S = new CSquare(C, SquareGfxInfo);

	//Add the square to the list of figures
	pManager->AddFigure(S);

	if (pManager->GetRecording() && pManager->CheckForPlace())
	{
		Action* action = pManager->GetAction();
		pManager->AddAction(action);
	}
	else if (!pManager->CheckForPlace())
		pManager->SetRecording(false);
}
void AddSquareAction::Undo() {
	pManager->RemoveFigure();
	pManager->UpdateInterface();
}