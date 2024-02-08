#include "Delete.h"
#include"ApplicationManager.h"
#include"GUI/Output.h"
#include"GUI/Input.h"
#include <string>
Delete::Delete(ApplicationManager* pApp):Action(pApp)
{
	

}

void Delete::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Select a figure to delete");
	if (pManager->GetFigCount() == 0)// checking if there is selected figure
	{
		pOut->PrintMessage("No figures are selected");

	}
	pOut->ClearDrawArea();
}

void Delete::Execute()
{
	if (!pManager->GetPlayingRecordState())
		ReadActionParameters();

	
	
	
	
		//deleting selected figures
		pManager->DeleteSelectedFigures();
		
		//pManager->UpdateInterface();
		pManager->UpdateInterface();
		if (pManager->GetRecording() && pManager->CheckForPlace())
		{
			Action* action = pManager->GetAction();
			pManager->AddAction(action);
		}
		else if (!pManager->CheckForPlace())
			pManager->SetRecording(false);
	
}
void Delete::Undo() {
}
