#include "Clear.h"
#include"ApplicationManager.h"
#include"GUI/Output.h"
#include"GUI/Input.h"
#include <string>

Clear::Clear(ApplicationManager* pApp):Action(pApp)
{

}

void Clear::ReadActionParameters() {

	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Clearing All figures");
}
void Clear::Execute()
{
	if (!pManager->GetPlayingRecordState())
		ReadActionParameters();
	pManager->UpdateInterface();
	pManager->ClearAllFigures();
	if (pManager->GetRecording() && pManager->CheckForPlace())
	{
		Action* action = pManager->GetAction();
		pManager->AddAction(action);
	}
	else if (!pManager->CheckForPlace())
		pManager->SetRecording(false);
}


void Clear::Undo() {
}
