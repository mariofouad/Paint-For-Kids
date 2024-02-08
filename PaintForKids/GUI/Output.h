#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"
#include <string>
class Output	//The application manager should have a pointer to this class
{
private:	
	window* pWind;	//Pointer to the Graphics Window
public:
	Output();		

	window* CreateWind(int, int, int , int) const; //creates the application window
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar

	Input* CreateInput() const; //creates a pointer to the Input object	
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area
	
	// -- Figures Drawing functions

	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected=false) const;  //Draw a rectangle

	void DrawTri(Point p1, Point p2, Point p3, GfxInfo TriGfxInfo, bool selected = false)const; // Draw a triangle

	void DrawSq(Point p1, GfxInfo SQGfxInfo, bool selected = false) const; // Draw square 

	void DrawCirc(Point p1, GfxInfo CircGfxInfo, bool selected = false)const;// Draw Circle

	void DrawHexagon(Point p1, GfxInfo HexGfxInfo, bool selected = false)const;// Draw Hexagon
	///TODO:Make similar functions for drawing all other figure types. (done)
	
	void PrintMessage(string msg) const;	//Print a message on Status bar

	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width
	string ColorToNames(color z);
	bool matched(color x, color y);
	void ClearToolBar() const;
	void SetCrntFillColor(color ncolor);
	color NameToColor(string clr);
	
	~Output();
};

#endif