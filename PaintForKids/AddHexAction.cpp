#include "AddHexAction.h"
#include"ApplicationManager.h"
#include"GUI/Output.h"
#include"GUI/Input.h"
#include "CHex.h"
#include <string>
AddHexAction:: AddHexAction(ApplicationManager *pApp): Action (pApp){}


void AddHexAction::ReadActionParameters() {

	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New hexagon: Click at center");

	//Read corner and store in point HC 
	pIn->GetPointClicked(HC.x, HC.y);


	if (pManager->GetIsColorChanged())
	{
		HexGfxInfo.isFilled = true;
	}
	else
	{
		HexGfxInfo.isFilled = false; // not filled by default
	}
	//get drawing, filling colors and pen width from the interface
	HexGfxInfo.DrawClr = pOut->getCrntDrawColor();
	HexGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

void AddHexAction::Execute() {

	//This action needs to read some parameters first
	if (!pManager->GetPlayingRecordState())
		ReadActionParameters();

	//Create a square with the parameters read from the user
	CHex* H = new CHex(HC, HexGfxInfo);

	//Add the square to the list of figures
	pManager->AddFigure(H);

	if (pManager->GetRecording() && pManager->CheckForPlace())
	{
		Action* action = pManager->GetAction();
		pManager->AddAction(action);
	}
	else if (!pManager->CheckForPlace())
		pManager->SetRecording(false);
}

void AddHexAction::Undo() {
	pManager->RemoveFigure();
	pManager->UpdateInterface();

}