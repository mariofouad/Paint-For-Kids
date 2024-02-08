#include"Figures/CFigure.h"
#include <string>
class CCirc : public CFigure {
private:
	Point center;
public:

	CCirc(Point cent, GfxInfo FigGfxInfo );
	CCirc();
	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream& file, Output* pOut);
	virtual bool CheckIn(int x, int y);
	virtual void Load(ifstream& fileLoad, Output* pOut);
	virtual void PrintInfo(Output* pOut);
};