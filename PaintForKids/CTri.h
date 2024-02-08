#include"Figures/CFigure.h"
#include<iostream>
#include <string>
using namespace std;


class CTri: public CFigure {
private:
	Point vertex1, vertex2, vertex3;
public:
	CTri();
	CTri(Point vertex1, Point vertex2, Point vertex3, GfxInfo FigureGFXInfo);
	virtual void Draw(Output* pOut) const;
	virtual void Load(ifstream& fileLoad, Output* pOut);
	virtual void Save(ofstream& file, Output* pOut);
	virtual bool CheckIn(int x, int y); //check if the point inside 
	virtual void PrintInfo(Output* pOut);
	float TriArea(int x1, int y1, int x2, int y2, int x3, int y3); //Calc area
};