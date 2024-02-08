#include "CHex.h"
#include <string>

CHex::CHex(Point hexcent, GfxInfo FigGfxInfo) :CFigure(FigGfxInfo) {

	HexCenter = hexcent;
	FigName = "HEXAGON";
}

void CHex::Draw(Output *pOut) const {

	//Call Output::DrawHexagon to draw a hexagon on the screen
	pOut->DrawHexagon(HexCenter, FigGfxInfo, Selected);

}

void CHex::Save(ofstream& file, Output* pOut)
{
	file << "Hexagon" << " " << to_string(ID) << " " << HexCenter.x << " " << HexCenter.y << " " << pOut->ColorToNames(FigGfxInfo.DrawClr) << " ";
	if (FigGfxInfo.isFilled)
	{
		file << pOut->ColorToNames(FigGfxInfo.FillClr) << endl;
	}
	else
		file << "NO_FILL" << endl;
}
float CHex::MiniHexTriArea(int x1, int y1, int arrX[], int arrY[])
{
	float sum = 0;
	int j = 0;
	int k = 1;
	for (int i = 0; i <= 5; i++)
	{
		float area = abs((x1 * (arrY[j] - arrY[k]) + arrX[j] * (arrY[k] - y1) + arrX[k] * (y1 - arrY[j])) / 2.0);
		sum += area;
		j++;
		k++;
		if (k == 6)
			k = 0;
	}
	return sum;
}

bool CHex::CheckIn(int x, int y)
{
	int l = 70; //length
	int arrX[6] = { (HexCenter.x - (l / 2)),(HexCenter.x + l / 2),(HexCenter.x + l), (HexCenter.x + (l / 2)), (HexCenter.x - (l / 2)), (HexCenter.x - l) };

	int arrY[6] = { (HexCenter.y - (sqrt(3) / 2) * l), ((HexCenter.y - (sqrt(3) / 2) * l)), HexCenter.y, (HexCenter.y + (sqrt(3) / 2) * l), (HexCenter.y + (sqrt(3) / 2) * l),HexCenter.y };

	float Area = MiniHexTriArea(HexCenter.x, HexCenter.y, arrX, arrY);

	float MiniArea = MiniHexTriArea(x, y, arrX, arrY);

	if (Area == MiniArea)
		return true;
	return false;
}
void CHex::PrintInfo(Output* pOut)
{
	float A = ((3 / 2) * sqrt(3)) * 70 * 70;
	if (FigGfxInfo.isFilled)
		pOut->PrintMessage("HEXAGON "" ID: " + to_string(ID) + " Drawn Color: " + pOut->ColorToNames(FigGfxInfo.DrawClr) + " Filled with Color: " + pOut->ColorToNames(FigGfxInfo.FillClr) + " X: " + to_string(HexCenter.x) + " Y: " + to_string(HexCenter.y) + " Side length: 70" + " Area: " + to_string(A));
	pOut->PrintMessage("HEXAGON "" ID: " + to_string(ID) + " Drawn Color: " + pOut->ColorToNames(FigGfxInfo.DrawClr) + " Not_Filled"" X: " + to_string(HexCenter.x) + " Y: " + to_string(HexCenter.y) + " Side length: 70" + " Area: " + to_string(A));
}

void CHex::Load(ifstream& fileLoad, Output* pOut)
{
	string DrawColor;
	string FillColor;
	fileLoad >> ID >> HexCenter.x >> HexCenter.y >> DrawColor >> FillColor;

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
CHex::CHex()
{
}