#include"CCirc.h"
#include <string>

CCirc::CCirc(Point cent, GfxInfo FigGfxInfo) :CFigure(FigGfxInfo) {

	center = cent;
	FigName = "CIRCLE";
}
CCirc::CCirc()
{
}


void CCirc :: Draw (Output *pOut) const{

	pOut->DrawCirc(center, FigGfxInfo, Selected);

}
bool CCirc::CheckIn(int x, int y)
{
	float dist = sqrt(((x - center.x) * (x - center.x)) + ((y - center.y) * (y - center.y)));
	if (dist <= 100)
		return true;
	return false;
}

void CCirc::PrintInfo(Output* pOut)
{
	float A = 3.14 * 100 * 100;
	if (FigGfxInfo.isFilled)
		pOut->PrintMessage("CIRCLE "" ID: " + to_string(ID) + " Drawn Color: " + pOut->ColorToNames(FigGfxInfo.DrawClr) + " Filled with Color: " + pOut->ColorToNames(FigGfxInfo.FillClr) + " X: " + to_string(center.x) + " Y: " + to_string(center.y) + " Raduis: 100" + " Area: " + to_string(A));
	pOut->PrintMessage("CIRCLE "" ID: " + to_string(ID) + " Drawn Color: " + pOut->ColorToNames(FigGfxInfo.DrawClr) + " Not_Filled"" X: " + to_string(center.x) + " Y: " + to_string(center.y) + " Raduis: 100" + " Area: " + to_string(A));
}

void CCirc::Save(ofstream& file, Output* pOut)
{
	file << "Circle" << " " << to_string(ID) << " " << center.x << " " << center.y << " " << pOut->ColorToNames(FigGfxInfo.DrawClr) << " ";
	if (FigGfxInfo.isFilled == true)
	{
		file << pOut->ColorToNames(FigGfxInfo.FillClr) << endl;
	}
	else
		file << "NO_FILL" << endl;
}

void CCirc::Load(ifstream& fileLoad, Output* pOut)
{
	string DrawColor;
	string FillColor;

	fileLoad >> ID >> center.x >> center.y >> DrawColor >> FillColor;
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

	//fileLoad >>ID>> center.x >> center.y >> DrawColor >> FillColor;
}
