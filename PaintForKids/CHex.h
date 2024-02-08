#include "Figures/CFigure.h"
#include <string>

class CHex : public CFigure {

private:
	Point HexCenter;

public:
	CHex(Point hexcent, GfxInfo FigGfxInfo);
	CHex();
	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream& file, int ID, Output* pOut);
	virtual bool CheckIn(int x, int y);
	virtual void Load(ifstream& fileLoad, Output* pOut);
	float MiniHexTriArea(int x1, int y1, int arrX[], int arry[]);

	virtual void PrintInfo(Output* pOut);

};