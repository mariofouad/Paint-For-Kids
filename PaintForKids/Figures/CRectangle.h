#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"
#include <string>

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CRectangle();
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream& file, int ID, Output* pOut);
	virtual bool CheckIn(int x, int y);
	virtual void PrintInfo(Output* pOut);
	virtual void Load(ifstream& fileLoad, Output* pOut);
};

#endif