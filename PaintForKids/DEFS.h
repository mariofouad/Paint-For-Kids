#ifndef DEFS_H
#define DEFS_H
#include <string>
#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_RECT,		//Draw Rectangle
	DRAW_SQUARE,
	DRAW_TRIANGLE,
	DRAW_HEXAGON,
	DRAW_CIRCLE,
	EXIT,			//Exit
	SWITCHTODRAW,		//Switch interface to Draw mode
	SWITCHTOPLAY,	   	//Switch interface to Play mode
	EMPTY,			    //A click on empty place in the toolbar
	DRAWING_AREA,	   //A click on the drawing area
	SELECT_COLOR_RED,
	SELECT_COLOR_BLUE,
	SELECT_COLOR_GREEN,
	SELECT_COLOR_BLACK,
	SELECT_COLOR_ORANGE,
	SELECT_COLOR_YELLOW,
	SELECT_COLOR_FILLILNG,
	SELECT_DRAWING,
	SELECT_FILING,
	DELETE_FIGURE,
	MOVE_FIGURE,
	CLEAR,
	START_RECORDING,
	STOP_RECORDING,
	PLAY_RECORDING,
	SELECT_FIGURE,
	UNDO,
	REDO,
	SAVE_GRAPH,
	LOAD_GRAPH,  //draw 
	TO_PLAY,
	PICK_AND_HIDE,
	FIGURE_TYPE_MODE,
	FIGURE_FILLCOLOR_MODE,
	FIGURE_TYPEANDFILLCOLOR_MODE,
	PICKANDHIDE_MENU,
	STATUS			//A click on the status bar


	///TODO: Add the other action types of the two modes
};

struct Point	//To be used for figures points
{ int x,y; };

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif