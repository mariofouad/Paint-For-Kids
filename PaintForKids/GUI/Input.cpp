#include "Input.h"
#include "Output.h"


Input::Input(window* pW) 
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output *pO) const 
{
	string Label;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if(Key == 13 )	//ENTER key is pressed
			return Label;
		if((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() -1 );			
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RECT: return DRAW_RECT;
			case ITM_SQUARE: return DRAW_SQUARE;
			case ITM_TRIANGLE:return DRAW_TRIANGLE;
			case ITM_HEXAGON: return DRAW_HEXAGON;
			case ITM_CIRCLE: return DRAW_CIRCLE;
			case ITM_SELECT: return SELECT_FIGURE;
			case ITM_DRAWINGCOLOR:return SELECT_DRAWING;
			case ITM_FILLINGCOLOR: return SELECT_FILING;
			case ITM_BLACK: return SELECT_COLOR_BLACK;
			case ITM_YELLOW: return SELECT_COLOR_YELLOW;
			case ITM_ORANGE:return SELECT_COLOR_ORANGE;
			case ITM_RED: return SELECT_COLOR_RED;
			case ITM_GREEN: return SELECT_COLOR_GREEN;
			case ITM_BLUE: return SELECT_COLOR_BLUE;
			case ITM_DELETE:return DELETE_FIGURE;
			case ITM_MOVE: return MOVE_FIGURE;
			case ITM_UNDO:return UNDO;
			case ITM_REDO:return REDO;
			case ITM_CLEAR: return CLEAR;
			case ITM_STARTREC: return START_RECORDING;
			case ITM_STOPREC: return STOP_RECORDING;
			case ITM_PLAYREC:return PLAY_RECORDING;
			case ITM_SAVE: return SAVE_GRAPH;
			case ITM_LOAD:return LOAD_GRAPH;
			case ITM_SWITCHTOPLAY: return SWITCHTOPLAY;
			case ITM_EXIT: return EXIT;
			
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;	
		}
		
		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{
		///TODO: DONE
		//perform checks similar to Draw mode checks above
		//and return the correspoding action
		
			//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_PCIKBYTYPE: return FIGURE_TYPE_MODE;
			case ITM_PICKBYBYFILLCOLOR: return FIGURE_FILLCOLOR_MODE;
			case ITM_PICKBYBOTH: return FIGURE_TYPEANDFILLCOLOR_MODE;
			case ITM_SWITCHTODRAW: return SWITCHTODRAW;
				//case PLAY_ITM_COUNT: return ""; //should we return an action?

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}	

}
/////////////////////////////////
	
Input::~Input()
{
}
