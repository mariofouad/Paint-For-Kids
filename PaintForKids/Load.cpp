#include "Load.h"
#include"ApplicationManager.h"
#include"GUI/Output.h"
#include"GUI/Input.h"
#include <vector>
#include<fstream>
#include "CCirc.h"
#include "CTri.h"
#include "CHex.h"
#include "CSquare.h"
#include "Figures/CRectangle.h"





Load::Load(ApplicationManager* pApp):Action(pApp)
{
	
}

void Load::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	

}

void Load::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ReadActionParameters();
	pOut->PrintMessage("Enter the name of the file you want to load");
	string fileLoad = pIn->GetSrting(pOut);
	string drawcolor;
	string fillcolor;
	
	string figuretype;
	int figcount;
	
	ifstream loadedfile;
	loadedfile.open(fileLoad + ".txt");
	loadedfile >> drawcolor >> fillcolor >> figcount;
	for (int i = 0;i < figcount;i++)
	{
		loadedfile >> figuretype;
		CFigure* fig;
		if (figuretype == "Triangle") fig = new CTri;
		else if (figuretype == "Circle") fig = new CCirc;
		else if (figuretype == "Square") fig = new CSquare;
		else if (figuretype == "Hexagon") fig = new CHex;
		else if (figuretype == "RECT") fig = new CRectangle;




		fig->Load(loadedfile,pOut);
		pManager->AddFigure(fig);
		//pManager->UpdateInterface();
	}
	//pManager->LoadAll(loadedfile,figcount);
	
	pOut->PrintMessage("file loaded successfully");
	//pManager->UpdateInterface();
}

void Load::Undo() {

}

