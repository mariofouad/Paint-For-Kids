#include "StartRecording.h"
#include"ApplicationManager.h"
#include <string>
StartRecording::StartRecording(ApplicationManager* pApp) :Action(pApp)
{}

//Reads no. of figures
//
void StartRecording::ReadActionParameters()
{
	int figurecount = pManager->GetFigCount();
	numoffigures = figurecount;
}

// turn on recording state if conditions are satisfied 
void StartRecording::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (numoffigures == 0)
	{
		pManager->SetRecording(true);
		pOut->PrintMessage("Recording Started Let Us See UR Beautiful Drawings.");
	}
	else
	{
		pOut->ClearStatusBar();
		pOut->PrintMessage("Error, recording starts only after clear all or the start of the program");
	}
}
void StartRecording::Undo() {
}