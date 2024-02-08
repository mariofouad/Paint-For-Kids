#include "CRectangle.h"
#include <string>
CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	FigName = "RECTANGLE";
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

void CRectangle::Save(ofstream& file, int ID, Output* pOut)
{
	file << "RECT" << " " << ID << " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " " << pOut->ColorToNames(FigGfxInfo.DrawClr) << " ";
	if (FigGfxInfo.isFilled == true)
	{
		file << pOut->ColorToNames(FigGfxInfo.FillClr) << endl;
	}
	else
		file << " NO_FILL" << endl;


}
bool CRectangle::CheckIn(int x, int y)
{
	if (x >= Corner1.x && x <= Corner2.x && y >= Corner1.y && y <= Corner2.y)
		return true;
	else if (x <= Corner1.x && x >= Corner2.x && y <= Corner1.y && y >= Corner2.y)
		return true;
	else if (x >= Corner1.x && x <= Corner2.x && y <= Corner1.y && y >= Corner2.y)
		return true;
	else if (x <= Corner1.x && x >= Corner2.x && y >= Corner1.y && y <= Corner2.y)
		return true;
	else
		return false;
}

void CRectangle::PrintInfo(Output* pOut)
{
	float A = (abs(Corner2.x - Corner1.x)) * (abs(Corner1.y - Corner2.y));
	if (FigGfxInfo.isFilled)
		pOut->PrintMessage("REGTANGLE "" ID: " + to_string(ID) + " Drawn Color: " + pOut->ColorToNames(FigGfxInfo.DrawClr) + " Filled with Color: " + pOut->ColorToNames(FigGfxInfo.FillClr) + " Width: " + to_string(abs(Corner2.x - Corner1.x)) + " Height: " + to_string(abs(Corner1.y - Corner2.y)) + " Area: " + to_string(A));
	pOut->PrintMessage("REGTANGLE "" ID: " + to_string(ID) + " Drawn Color: " + pOut->ColorToNames(FigGfxInfo.DrawClr) + " Not_Filled" + " Width: " + to_string(abs(Corner2.x - Corner1.x)) + " Height: " + to_string(abs(Corner1.y - Corner2.y)) + " Area: " + to_string(A));
}

void CRectangle::Load(ifstream& fileLoad, Output* pOut)
{
	string DrawColor;
	string FillColor;
	fileLoad >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> DrawColor >> FillColor;

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

CRectangle::CRectangle()
{

}
