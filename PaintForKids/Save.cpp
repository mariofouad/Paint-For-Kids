#include "Save.h"
#include"ApplicationManager.h"
#include"GUI/Output.h"
#include"GUI/Input.h"
#include <vector>
#include<fstream>
#include <string>

vector <string> fileNames;

Save::Save(ApplicationManager* pApp):Action(pApp)
{

}

void Save::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Enter the name of the file you want to save");
	FileName = pIn->GetSrting(pOut);
}

void Save::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
	ReadActionParameters();
	
	file.open(FileName + ".txt", ios::out);
    pManager->SaveAll(file);
	
	file.close();
	pOut->PrintMessage("File saved successfully");
	
}

void Save::Undo() {
}