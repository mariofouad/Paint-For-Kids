#include "StopRecording.h"
#include "ApplicationManager.h"
#include <string>
StopRecording::StopRecording(ApplicationManager* pApp) : Action(pApp)
{}

void StopRecording::ReadActionParameters()
{

}

void StopRecording::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pManager->SetRecording(false);
	pOut->PrintMessage("Recording Stopped.");
}
void StopRecording::Undo() {
}