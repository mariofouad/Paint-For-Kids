#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	
	UI.width = 1550;
	UI.height = 650;
	UI.wx = 5;
	UI.wy =5;

	
	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 51;

	UI.ToolBarColor = SNOW;
	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = LIGHTGOLDENRODYELLOW;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames

	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");
	
	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearToolBar()const
{
	pWind->SetPen(UI.ToolBarColor, 1);
	pWind->SetBrush(UI.ToolBarColor);
	pWind->DrawRectangle(0, 0, UI.width, 50);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem 
	// DONE!!
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect.jpg";
	MenuItemImages[ITM_SQUARE] = "images\\MenuItems\\Menu_Square.jpg";
	MenuItemImages[ITM_TRIANGLE] = "images\\MenuItems\\Menu_Triangle.jpg";
	MenuItemImages[ITM_HEXAGON] = "images\\MenuItems\\Menu_Hexagon.jpg";
	MenuItemImages[ITM_CIRCLE] = "images\\MenuItems\\Menu_Circ.jpg";
	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\Menu_Select.jpg";
	MenuItemImages[ITM_DRAWINGCOLOR] = "images\\MenuItems\\Menu_DrawingColor.jpg";
	MenuItemImages[ITM_FILLINGCOLOR] = "images\\MenuItems\\Menu_FillColor.jpg";
	MenuItemImages[ITM_BLACK] = "images\\MenuItems\\Palette_black.jpg";
	MenuItemImages[ITM_YELLOW] = "images\\MenuItems\\Palette_yellow.jpg";
	MenuItemImages[ITM_ORANGE] = "images\\MenuItems\\Palette_orange.jpg";
	MenuItemImages[ITM_RED] = "images\\MenuItems\\Palette_red.jpg";
	MenuItemImages[ITM_GREEN] = "images\\MenuItems\\Palette_green.jpg";
	MenuItemImages[ITM_BLUE] = "images\\MenuItems\\Palette_blue.jpg";
	MenuItemImages[ITM_DELETE] = "images\\MenuItems\\Menu_Delete.jpg";
	MenuItemImages[ITM_MOVE] = "images\\MenuItems\\Menu_Move.jpg";
	MenuItemImages[ITM_UNDO] = "images\\MenuItems\\Menu_Undo.jpg";
	MenuItemImages[ITM_REDO] = "images\\MenuItems\\Menu_Redo.jpg";
	MenuItemImages[ITM_CLEAR] = "images\\MenuItems\\Menu_Clear.jpg";
	MenuItemImages[ITM_STARTREC] = "images\\MenuItems\\Menu_rec.jpg";
	MenuItemImages[ITM_STOPREC] = "images\\MenuItems\\Menu_StopRecording.jpg";
	MenuItemImages[ITM_PLAYREC] = "images\\MenuItems\\Menu_PlayRecording.jpg";
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\Menu_Save.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\Menu_Load.jpg";
	MenuItemImages[ITM_SWITCHTOPLAY] = "images\\MenuItems\\Menu_Switch.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";


	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	ClearToolBar();
	UI.InterfaceMode = MODE_PLAY;
	string MenuItemImages[PLAY_ITM_COUNT];
	///TODO: write code to create Play mode menu 
	//DONE!!!

	MenuItemImages[ITM_PCIKBYTYPE] = "images\\MenuItems\\Menu_PickByShape.jpg";
	MenuItemImages[ITM_PICKBYBYFILLCOLOR] = "images\\MenuItems\\Menu_PickByColor.jpg";
	MenuItemImages[ITM_PICKBYBOTH] = "images\\MenuItems\\Menu_PickByBoth.jpg";
	MenuItemImages[ITM_SWITCHTODRAW] = "images\\MenuItems\\Menu_SwitchToDraw.jpg";
	MenuItemImages[ITM_WHITE] = "images\\MenuItems\\MENU_WHITE.jpg";

	pWind->DrawImage(MenuItemImages[ITM_WHITE], UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);


	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
	
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{	return UI.DrawColor;	}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
//////////////////////////////////////////////////////////////////////////////////////////
	
int Output::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
	
}
void Output::DrawSq(Point p1, GfxInfo SQGfxInfo, bool selected) const
{
	Point p2;
	p2.x = p1.x + 100;
	p2.y = p1.y + 100;
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = SQGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (SQGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(SQGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawRectangle(p1.x, p1.y, p2.x, p2.y, style);

}

void Output::DrawTri(Point p1, Point p2, Point p3, GfxInfo TriGfxInfo, bool selected) const
{
	color Drawclr;
	if (selected)
		Drawclr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		Drawclr = TriGfxInfo.DrawClr;
	pWind->SetPen(Drawclr, 1);
	drawstyle style;
	if (TriGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TriGfxInfo.FillClr);
	}
	else
		style = FRAME;
	pWind->DrawTriangle(p1.x, p2.y, p2.x, p2.y, p3.x, p3.y, style);
}

void Output::DrawCirc(Point p1, GfxInfo CircGfxInfo, bool selected)const
{
	int radius;
	radius = 100;
	color Drawclr;
	if (selected)
		Drawclr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		Drawclr = CircGfxInfo.DrawClr;
	pWind->SetPen(Drawclr, 1);
	drawstyle style;
	if (CircGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CircGfxInfo.FillClr);
	}
	else
		style = FRAME;
	pWind->DrawCircle(p1.x, p1.y, radius, style);
}

void Output::DrawHexagon(Point p1, GfxInfo HexGfxInfo, bool selected) const
{
	int vertices = 6;
	int l = 70; //length

	int x = p1.x;
	int y = p1.y;

	int arrX[6] = { (x - (l / 2)),(x + l / 2),(x + l), (x + (l / 2)), (x - (l / 2)), (x - l) };
	//arrX = { 1,2,3,4,5,6 };
	//arrX = {(x - (l/2)),(x+l/2),(x + l), (x + (l / 2)), (x - (l / 2)), (x - l)};
	int arrY[6] = { (y - (sqrt(3) / 2) * l), ((y - (sqrt(3) / 2) * l)), y, (y + (sqrt(3) / 2) * l), (y + (sqrt(3) / 2) * l), y };




	color Drawclr;
	if (selected)
		Drawclr = UI.HighlightColor;// Figure should be drawn highlighted
	else
		Drawclr = HexGfxInfo.DrawClr;
	pWind->SetPen(Drawclr, 1);
	drawstyle style;
	if (HexGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(HexGfxInfo.FillClr);
	}
	else
		style = FRAME;
	pWind->DrawPolygon(arrX, arrY, vertices, style);
}

//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

//Converrting colors to string
string Output::ColorToNames(color n)
{
	if (matched(n, BLACK))
		return "BLACK";
	else if (matched(n, ORANGE))
		return "ORANGE";
	else if (matched(n, BLUE))
		return "BLUE";
	else if (matched(n, GREEN))
		return "GREEN";
	else if (matched(n, RED))
		return "RED";
	else if (matched(n, YELLOW))
		return "YELLOW";
	else if (matched(n, LIGHTGOLDENRODYELLOW))
		return "NO FILLED";
}

//check if the colors are matched
bool Output::matched(color x, color y)
{
	if (x.ucBlue == y.ucBlue && x.ucGreen == y.ucGreen && x.ucBlue == y.ucBlue)
		return true;
	else
		return false;
}

void Output::SetCrntFillColor(color ncolor)
{
	UI.FillColor = ncolor;
}

color Output::NameToColor(string clr)
{
	if (clr == "BLACK")
		return BLACK;
	else if (clr == "ORANGE")
		return ORANGE;
	else if (clr == "BLUE")
		return BLUE;
	else if (clr == "GREEN")
		return GREEN;
	else if (clr == "RED")
		return RED;
	else if (clr == "YELLOW")
		return YELLOW;

}
