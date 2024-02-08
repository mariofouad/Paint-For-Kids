#include "SwitchToDraw.h"
#include "ApplicationManager.h"
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


SwitchToDraw::SwitchToDraw(ApplicationManager* pApp) :Action(pApp)
{
}

void SwitchToDraw::ReadActionParameters()
{

}

void SwitchToDraw::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->ClearDrawArea();
	pOut->CreateDrawToolBar();
	//string drawcolor;
	//string fillcolor;

	//string figuretype;
	//int figcount;

	//ifstream loadedfile;
	//loadedfile.open("SwitchToPlay.txt");
	//loadedfile >> drawcolor >> fillcolor >> figcount;
	//for (int i = 0; i < figcount; i++)
	//{
	//	loadedfile >> figuretype;
	//	CFigure* fig;
	//	if (figuretype == "Triangle") fig = new CTri;
	//	else if (figuretype == "Circle") fig = new CCirc;
	//	else if (figuretype == "Square") fig = new CSquare;
	//	else if (figuretype == "Hexagon") fig = new CHex;




	//	fig->Load(loadedfile, pOut);
	//	pManager->AddFigure(fig);
		//pManager->UpdateInterface();
	//}
	pOut->CreateDrawToolBar();
}

void SwitchToDraw::Undo() {

}