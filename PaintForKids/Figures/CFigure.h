#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"
#include<fstream>
#include <string>
//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	/// Add more parameters if needed.
	string FigName;
public:
	CFigure();
	CFigure(GfxInfo FigureGfxInfo);

	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected

	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	virtual bool CheckIn(int x, int y) = 0; // knowing which selected

	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	
	string GetFigName();
	void SetID(int id);
	string GetFigColor(Output* pOut);
	bool GetIsFilled();
	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	

	//virtual string PickByTypeInfo() = 0;

	virtual void Save(ofstream &OutFile, Output* pOut) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream &Infile, Output* pOut) = 0;	//Load the figure parameters to the file

	virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
};

#endif