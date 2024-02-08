#include "Move.h"
#include"ApplicationManager.h"
#include"GUI/Output.h"
#include"GUI/Input.h"
#include <string>

Move::Move(ApplicationManager* pApp):Action(pApp)
{

}

void Move::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("select a figure to move");
	

}

void Move::Execute()
{
	if (!pManager->GetPlayingRecordState())
		ReadActionParameters();
	pManager->MoveFigures();
	if (pManager->GetRecording() && pManager->CheckForPlace())
	{
		Action* action = pManager->GetAction();
		pManager->AddAction(action);
	}
	else if (!pManager->CheckForPlace())
		pManager->SetRecording(false);
}


void Move::Undo() {
}
