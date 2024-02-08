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
	
	pManager->ClearAllFigures();
	
	pOut->PrintMessage("Enter the name of the file you want to load");
	
	inputfilename = pIn->GetSrting(pOut);
}

void Load::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
	ReadActionParameters();
	

	file.open(inputfilename + ".txt");
	if (file.is_open())
	{
		string line;
		
		string FigureType;
		int ID;
		Point pt1;
		Point pt2;
		Point pt3;
		string FigureColor;
		string Filled;
		string FillColor;
		CFigure* fig;
		color FigureColor;

		GfxInfo FigInfo;
		while (!file.eof())
		{
			getline(file, line);
			stringstream NewLine(line);
			NewLine >> FigureType >> ID;
			
			if (FigureType == "Triangle")
			{
				NewLine >> pt1.x >> pt1.y >> pt2.x >> pt2.y >> pt3.x >> pt3.y >> FigureColor >> Filled;
				FigInfo.DrawClr = pOut->NameToColor(FigureColor);
				
				if (Filled != "NO_FILL")
				{
					NewLine >> FillColor;
					FigInfo.isFilled = true;
					FigInfo.FillClr =pOut->NameToColor(FillColor);
				}
				else
				{
					FigInfo.isFilled = false;
				}
				fig = new CTri(pt1, pt2, pt3, FigInfo);
			}
			else if(FigureType == "Circle")
			{
				NewLine >> pt1.x >> pt1.y >> FigureColor >> Filled;
				FigInfo.DrawClr = pOut->NameToColor(FigureColor);

				if (Filled != "NO_FILL")
				{
					NewLine >> FillColor;
					FigInfo.isFilled = true;
					FigInfo.FillClr = pOut->NameToColor(FillColor);
				}
				else
				{
					FigInfo.isFilled = false;
				}
				fig = new CCirc(pt1, FigInfo);
			}
			else if (FigureType == "Hexagon")
			{
				NewLine >> pt1.x >> pt1.y >> FigureColor >> Filled;
				FigInfo.DrawClr = pOut->NameToColor(FigureColor);

				if (Filled != "NO_FILL")
				{
					NewLine >> FillColor;
					FigInfo.isFilled = true;
					FigInfo.FillClr = pOut->NameToColor(FillColor);
				}
				else
				{
					FigInfo.isFilled = false;
				}
				fig = new CHex(pt1, FigInfo);
			}
			else if (FigureType == "Rect")
			{
				NewLine >> pt1.x >> pt1.y >> pt2.x >> pt2.y >> FigureColor >> Filled;
				FigInfo.DrawClr = pOut->NameToColor(FigureColor);

				if (Filled != "NO_FILL")
				{
					NewLine >> FillColor;
					FigInfo.isFilled = true;
					FigInfo.FillClr = pOut->NameToColor(FillColor);
				}
				else
				{
					FigInfo.isFilled = false;
				}
				fig = new CRectangle(pt1, pt2, FigInfo);
			}
			else if (FigureType == "Square")
			{
				NewLine >> pt1.x >> pt1.y >> FigureColor >> Filled;
				FigInfo.DrawClr = pOut->NameToColor(FigureColor);

				if (Filled != "NO_FILL")
				{
					NewLine >> FillColor;
					FigInfo.isFilled = true;
					FigInfo.FillClr = pOut->NameToColor(FillColor);
				}
				else
				{
					FigInfo.isFilled = false;
				}
				fig = new CSquare(pt1, FigInfo);
			}
			pManager->AddFigure(fig);
		}
		pOut->PrintMessage("file loaded successfully");
		file.close();

	}
	else
	{
		pOut->PrintMessage("File name entered is not found, please try again!");
	}

	//string drawcolor;
	//string fillcolor;
	//
	//string figuretype;
	//int figcount;
	//
	//ifstream loadedfile;
	////loadedfile.open(fileLoad + ".txt");
	//loadedfile >> drawcolor >> fillcolor >> figcount;
	//for (int i = 0;i < figcount;i++)
	//{
	//	loadedfile >> figuretype;
	//	CFigure* fig;
	//	if (figuretype == "Triangle") fig = new CTri;
	//	else if (figuretype == "Circle") fig = new CCirc;
	//	else if (figuretype == "Square") fig = new CSquare;
	//	else if (figuretype == "Hexagon") fig = new CHex;
	//	else if (figuretype == "RECT") fig = new CRectangle;




	//	fig->Load(loadedfile,pOut);
	//	pManager->AddFigure(fig);
	//	//pManager->UpdateInterface();
	//}
	////pManager->LoadAll(loadedfile,figcount);
	//
	//pOut->PrintMessage("file loaded successfully");
	////pManager->UpdateInterface();
}

void Load::Undo() {

}

