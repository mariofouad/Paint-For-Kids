#include"CTri.h"
#include<iostream>
#include <string>
using namespace std;

CTri::CTri()
{
}

CTri::CTri(Point vrtx1, Point vrtx2, Point vrtx3, GfxInfo TriGfxInfo) : CFigure(TriGfxInfo) {
	vertex1 = vrtx1;
	vertex2 = vrtx2;
	vertex3 = vrtx3;
	FigName = "TRIANGLE";
}

void CTri::Draw(Output *pOut) const{ 

	pOut->DrawTri(vertex1, vertex2, vertex3, FigGfxInfo, Selected);

}
float CTri::TriArea(int x1, int y1, int x2, int y2, int x3, int y3)  //calculate a triangle area 
{
	return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}

void CTri::Save(ofstream& file, Output* pOut)
{
	file << "Triangle" << " "<< to_string(ID) << " " << vertex1.x << " " << vertex1.y << " " << vertex2.x << " " << vertex2.y << " " << vertex3.x << " " << vertex3.y << " " << pOut->ColorToNames(FigGfxInfo.DrawClr);
	if (FigGfxInfo.isFilled == true)
	{
		file << pOut->ColorToNames(FigGfxInfo.FillClr) << endl;
	}
	else
		file << "NO_FILL" << endl;
}
bool CTri::CheckIn(int x, int y)
{
	float A = TriArea(vertex1.x, vertex1.y, vertex2.x, vertex2.y, vertex3.x, vertex3.y); //calculate drawn triangle area

	float A1 = TriArea(x, y, vertex2.x, vertex2.y, vertex3.x, vertex3.y);  //calculate area1 of the point with 2 points of drwn triangle

	float A2 = TriArea(vertex1.x, vertex1.y, x, y, vertex3.x, vertex3.y);  //calculate area2 of the point with 2 points of drwn triangle

	float A3 = TriArea(vertex1.x, vertex1.y, vertex2.x, vertex2.y, x, y);  //calculate area3 of the point with 2 points of drwn triangle

	return (A == A1 + A2 + A3);
}
void CTri::PrintInfo(Output* pOut)
{
	float side1 = abs(sqrt(((vertex1.x - vertex2.x) * (vertex1.x - vertex2.x)) + ((vertex1.y - vertex2.y) * (vertex1.y - vertex2.y))));
	float side2 = abs(sqrt(((vertex2.x - vertex3.x) * (vertex2.x - vertex3.x)) + ((vertex2.y - vertex3.y) * (vertex2.y - vertex3.y))));
	float side3 = abs(sqrt(((vertex3.x - vertex1.x) * (vertex3.x - vertex1.x)) + ((vertex3.y - vertex1.y) * (vertex3.y - vertex1.y))));
	float A = TriArea(vertex1.x, vertex1.y, vertex2.x, vertex2.y, vertex3.x, vertex3.y);

	if (FigGfxInfo.isFilled)
		pOut->PrintMessage("TRIANGLE "" ID: " + to_string(ID) + " Drawn Color: " + pOut->ColorToNames(FigGfxInfo.DrawClr) + " Filled with Color: " + pOut->ColorToNames(FigGfxInfo.FillClr) + " Side1 Length: " + to_string(side1) + " Side2 Length: " + to_string(side1) + " Side3 Length: " + to_string(side3) + " Area: " + to_string(A));
	pOut->PrintMessage("TRIANGLE "" ID: " + to_string(ID) + " Drawn Color: " + pOut->ColorToNames(FigGfxInfo.DrawClr) + " Not_Filled" + " Side1 Length: " + to_string(side1) + " Side2 Length: " + to_string(side1) + " Side3 Length: " + to_string(side3) + " Area: " + to_string(A));
}

void CTri::Load(ifstream& fileLoad, Output* pOut)
{
	string DrawColor;
	string FillColor;
	fileLoad >> ID >> vertex1.x >> vertex1.y >> vertex2.x >> vertex2.y >> vertex3.x >> vertex3.y >> DrawColor >> FillColor;

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