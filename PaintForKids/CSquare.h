
#ifndef CSQUARE_H
#define CSQUARE_H

#include "Figures/CFigure.h"
#include <string>

class CSquare : public CFigure
{
private:
	Point TopLeftCorner;

public:
	CSquare();
	CSquare(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream& file, Output* pOut);
	virtual bool CheckIn(int x, int y);
	virtual void PrintInfo(Output* pOut);
	virtual void Load(ifstream& fileLoad, Output* pOut);
};

#endif