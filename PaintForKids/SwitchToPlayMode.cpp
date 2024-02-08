#include "SwitchToPlayMode.h"
#include "ApplicationManager.h"
#include <string>
SwitchToPlayMode::SwitchToPlayMode(ApplicationManager* pApp) : Action(pApp)
{}

void SwitchToPlayMode::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
}

void SwitchToPlayMode::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ReadActionParameters();
	file.open("SwitchToPlay.txt", ios::out);
	pManager->SaveAll(file);
	file.close();
	pOut->CreatePlayToolBar();
}
void SwitchToPlayMode::Undo() {
}