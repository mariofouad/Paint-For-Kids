#include "CFigure.h"
#include <string>


CFigure::CFigure()
{
}

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}
string CFigure::GetFigName()
{
	return FigName;
}
void CFigure::SetID(int id)
{
	ID = id;
}

string CFigure::GetFigColor(Output* pOut)
{
	return (pOut->ColorToNames(FigGfxInfo.FillClr));
}

bool CFigure::GetIsFilled()
{
	return (FigGfxInfo.isFilled);
}
