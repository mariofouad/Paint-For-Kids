#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include "StartRecording.h"
#include <string>
#include "PickByType.h"


//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200, MaxRecordingOps = 20 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	int ActionCount;
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	Action* RecordingList[MaxRecordingOps];
	CFigure* SelectedFig; //Pointer to the selected figure
	Action* lastaction; // Stores last action clicked by user
	bool IsRecording;  //Checks if we are recording or not
	Action* UndoRedoList[5]; //List of undoable actions
	int UndoneCount = 0;
	CFigure* FiguresUndone[5]; //array of the figures that has been undone
	bool IsPlayingRecord;
	bool AreWeChangingColor;
	bool IsColorChanged;

	int multiselect;
	Point p1;
	Point p2;
	//Pointers to Input and Output classes
	Input* pIn;
	Output* pOut;

public:
	ApplicationManager();
	~ApplicationManager();

	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType); //Creates an action and executes it
	void AddAction(Action* pAct); // Adds action to the RecordList
	void SetRecording(bool rec); //Sets RecordingState
	bool GetRecording(); //Gets RecordingState
	Action* GetAction(); //Gets Action
	CFigure* GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	CFigure* GetSelectedFig() const;
	bool ISFILLED();
	CFigure* Generate() const;
	void HouseKeeping();
	int GetFigCount();
	void PiCKFig();
	bool CheckForPlace(); //Check if we can record more actions
	int GetActionCount(); //Gets number of current actions
	void ApplicationManager::SaveAll(ofstream& file); //Saves all data
	void DeleteSelectedFigures();
	void ClearAllFigures();
	void MoveFigures();
	void RemoveFigure(); //Removes the last added figure from the FigList
	CFigure* GetlastUndoneFigure(); //gets last figure added in the undo array
	void AddinUndoneArray(CFigure* cptr);
	void ExecuteRecordedAction(int i); //Gets action from recording list
	bool GetPlayingRecordState();
	void SetPlayingRecordState(bool state);
	bool GetIsColorChanged();
	void SetIsColorChanged(bool color);
	//void AddInUndoList(Action* action); //takes a pointer to the action and adds the action in the UndoRedoList array 
	//int getUndoListCount(); //gets the count of the elements in the Undo/Redo array
	//void DecrementUndoCount();
	//void IncremenetUndoCount();
	//void AddInUndoList(Action* action); //takes a pointer to the action and adds the action in the UndoRedoList array 

	void LoadAll(ifstream& fileLoad);

	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	//CFigure* GetFigure(int x, int y) const; //Search for a figure given a point inside the figure

	// -- Interface Management Functions
	Input* GetInput() const; //Return pointer to the input
	Output* GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	
};

#endif