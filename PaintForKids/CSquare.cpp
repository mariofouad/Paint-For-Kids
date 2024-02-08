#include "CSquare.h"
#include <string>

CSquare::CSquare()
{

}
CSquare::CSquare(Point CTL, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	TopLeftCorner = CTL;
	FigName = "SQUARE";
}


void CSquare::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawSq(TopLeftCorner, FigGfxInfo, Selected); 
}

void CSquare::Save(ofstream& file, Output* pOut)
{
	file << "Square" << " " << to_string(ID) << " " << TopLeftCorner.x << " " << TopLeftCorner.y << " " << pOut->ColorToNames(FigGfxInfo.DrawClr) << " ";
	if (FigGfxInfo.isFilled == true)
	{
		file << pOut->ColorToNames(FigGfxInfo.FillClr) << endl;
	}
	else
		file << "NO_FILL" << endl;
}
bool CSquare::CheckIn(int x, int y)
{
	if (x >= TopLeftCorner.x && x <= TopLeftCorner.x + 100 && y >= TopLeftCorner.y && y <= TopLeftCorner.y + 100)
		return true;
	else
		return false;
}
void CSquare::PrintInfo(Output* pOut)
{
	float A = 100 * 100;
	if (FigGfxInfo.isFilled)
		pOut->PrintMessage("SQUARE "" ID: " + to_string(ID) + " Drawn Color: " + pOut->ColorToNames(FigGfxInfo.DrawClr) + " Filled with Color: " + pOut->ColorToNames(FigGfxInfo.FillClr) + " X: " + to_string(TopLeftCorner.x) + " Y: " + to_string(TopLeftCorner.y) + "Side Length: 100" + " Area: " + to_string(A));
	pOut->PrintMessage("SQUARE "" ID: " + to_string(ID) + " Drawn Color: " + pOut->ColorToNames(FigGfxInfo.DrawClr) + " Not_Filled" + " X: " + to_string(TopLeftCorner.x) + " Y: " + to_string(TopLeftCorner.y) + "Side Length: 100" + " Area: " + to_string(A));
}

void CSquare::Load(ifstream& fileLoad, Output* pOut)
{
	string DrawColor;
	string FillColor;
	fileLoad >> ID >> TopLeftCorner.x >> TopLeftCorner.y >> DrawColor >> FillColor;
	FigGfxInfo.DrawClr = pOut->NameToColor(DrawColor);
	if (FillColor == "NO_FILL")
	{
		FigGfxInfo.isFilled = false;
	}
	else
	{

		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = pOut->NameToColor(FillColor);
	}


}
