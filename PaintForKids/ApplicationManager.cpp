#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "AddSquareAction.h"
#include "AddTriAction.h"
#include "AddCircAction.h"
#include "AddHexAction.h"
#include "StartRecording.h"
#include "StopRecording.h"
#include "PlayRecording.h"
#include "SwitchToPlayMode.h"
#include "Save.h"
#include "Clear.h"
#include "Delete.h"
#include "Move.h"
#include <fstream>
#include <string>
#include"SelctFig.h"
#include"Exit.h"
#include <cstdlib>
#include <iostream>
#include "PickByType.h"
#include "PickByColor.h"
#include "PickByBoth.h"
#include "UndoAction.h"
#include "RedoAction.h"
#include "ChangeFillColor.h"
#include "ChangeDrawingColor.h"
#include "SwitchToDraw.h"
#include "Load.h"
using namespace std;


//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();

	FigCount = 0;
	ActionCount = 0;
	IsRecording = false;
	IsPlayingRecord = false;
	AreWeChangingColor = false;

	//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++)
		FigList[i] = NULL;

	//Create an array of action pointers and set them to NULL
	for (int i = 0; i < MaxRecordingOps; i++)
		RecordingList[i] = NULL;
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;

	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case DRAW_RECT:
		pAct = new AddRectAction(this);
		break;

	case DRAW_SQUARE:
		pAct = new AddSquareAction(this);
		break;

	case DRAW_TRIANGLE:
		pAct = new AddTriAction(this);
		break;

	case DRAW_CIRCLE:
		pAct = new AddCircAction(this);
		break;

	case DRAW_HEXAGON:
		pAct = new AddHexAction(this);
		break;

	case START_RECORDING:
		pAct = new StartRecording(this);
		break;

	case STOP_RECORDING:
		pAct = new StopRecording(this);
		break;

	case PLAY_RECORDING:
		pAct = new PlayRecording(this);
		break;

	case SWITCHTOPLAY:
		pAct = new SwitchToPlayMode(this);
		break;

	case DELETE_FIGURE:
		pAct = new Delete(this);
		break;

	case SAVE_GRAPH:
		pAct = new Save(this);
		break;

	case MOVE_FIGURE:
		pAct = new Move(this);
		break;
	case UNDO:
		pAct = new UndoAction(this);
		break;
	case REDO:
		pAct = new RedoAction(this);
		break;
	case SELECT_FIGURE:
		pAct = new SelctFig(this);
		break;
	case EXIT:
		pAct = new Exit(this);
		break;
	case STATUS:	//a click on the status bar ==> no action
		return;
	case CLEAR:
		pAct = new Clear(this);
		break;
	case FIGURE_TYPE_MODE:
		pAct = new PickByType(this);
		break;
	case FIGURE_FILLCOLOR_MODE:
		pAct = new PickByColor(this);
		break;
	case FIGURE_TYPEANDFILLCOLOR_MODE:
		pAct = new PickByBoth(this);
		break;
	case SELECT_FILING:
		pAct = new ChangeFillColor(this);
		break;

	case SELECT_DRAWING:
		pAct = new ChangeDrawingColor(this);
		break;

	case SWITCHTODRAW:
		pAct = new SwitchToDraw(this);
		break;
	case LOAD_GRAPH:
		pAct = new Load(this);
		break;
	}

	//Execute the created action
	if (pAct != NULL)
	{
		lastaction = pAct;
		pAct->Execute();//Execute
		//delete pAct;	//You may need to change this line depending to your implementation
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount)
		FigList[FigCount++] = pFig;
	pFig->SetID(FigCount);
}

//Add an action to the list of actions
void ApplicationManager::AddAction(Action* pAct)
{
	if (ActionCount < MaxRecordingOps)
		RecordingList[ActionCount++] = lastaction;
}

////////////////////////////////////////////////////////////////////////////////////

//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	pOut->ClearDrawArea();
	for (int i = 0; i < FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input* ApplicationManager::GetInput() const
{
	return pIn;
}
//Return a pointer to the output
Output* ApplicationManager::GetOutput() const
{
	return pOut;
}
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;

}

void ApplicationManager::SetRecording(bool rec)
{
	IsRecording = rec;
}

bool ApplicationManager::GetRecording()
{
	return IsRecording;
}

Action* ApplicationManager::GetAction()
{
	return lastaction;
}
bool ApplicationManager::CheckForPlace()
{
	if (ActionCount < 20)
		return true;
}

int ApplicationManager::GetActionCount()
{
	return ActionCount;
}
CFigure* ApplicationManager::GetFigure(int x, int y) const
{
	for (int i = FigCount - 1; i >= 0; i--)    //If a figure is found return a pointer to it.
	{
		if (FigList[i]->CheckIn(x, y))
		{
			return FigList[i];
		}
	}
	return NULL;     //if this point (x,y) does not belong to any figure return NULL
}
CFigure* ApplicationManager::GetSelectedFig() const
{
	for (int i = FigCount - 1; i >= 0; i--)   //If a figure is found return a pointer to it.
	{
		if (FigList[i]->IsSelected())
		{
			return FigList[i];
		}
	}
	return NULL;     //if this point (x,y) does not belong to any figure return NULL
}
bool ApplicationManager::ISFILLED()
{
	for (int i = 0; i < FigCount; i++)
	{
		if ((FigList[i]->GetIsFilled()))
		{
			return true;
		}
	}
	return false;
}

CFigure* ApplicationManager::Generate() const
{
	srand(time(NULL));
	for (int i = 0; i < FigCount; i++)
	{
		return FigList[rand()%FigCount];
	}
}
void ApplicationManager::HouseKeeping()
{
	for (int i = 0; i < FigCount; i++)
	{
		FigList[i]->ChngDrawClr(UI.BkGrndColor);
		FigList[i]->ChngFillClr(UI.BkGrndColor);
	}
}
int ApplicationManager::GetFigCount()
{
	return FigCount;
}
void ApplicationManager::PiCKFig()
{
	for (int i = 0; i < FigCount; i++)
	{
		FigList[i]->ChngDrawClr(BLUE);
		FigList[i]->Draw(pOut);
	}
}
void ApplicationManager::SaveAll(ofstream& file)
{
	file << FigCount << endl;
	int ID = 1;
	for (int i = 0; i < FigCount; i++)
	{
		FigList[i]->Save(file, ID, pOut);
		ID++;
	}
}
void ApplicationManager::DeleteSelectedFigures()
{
	int deletedfigures = 0;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected())
		{
			FigList[i] = NULL;
			for (int j = i; j < FigCount - 1; j++)
			{
				FigList[j] = FigList[j + 1];
			}
			FigCount--;

		}
	}
}
void ApplicationManager::ClearAllFigures()
{
	pOut->ClearDrawArea();
	for (int i = 0; i < FigCount; i++)
	{
		delete FigList[i];
	}
	FigCount = 0;
}
void ApplicationManager::MoveFigures()
{
	pOut->PrintMessage("select the figure you want to move");
	pIn->GetPointClicked(p2.x, p2.y); // points to select the figure the user wants to move
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected()) // check if the figure is selected
		{
			delete FigList[i];
		}
		pOut->PrintMessage("Select new position");
		pIn->GetPointClicked(p1.x, p1.y); // the point of the new position

		FigList[i]->Draw(pOut); // Drawing the figure in the new position
	}
}
//Removes a figure from the list of figures
void ApplicationManager::RemoveFigure() {

	if (FigCount > 0) {
		FigList[FigCount] = NULL;
		FigCount--;
	}

}

void ApplicationManager::ExecuteRecordedAction(int i)
{
	RecordingList[i]->Execute();
}

void ApplicationManager::AddinUndoneArray(CFigure* cptr) {
	FiguresUndone[UndoneCount] = cptr;
	UndoneCount++;
}

bool ApplicationManager::GetPlayingRecordState()
{
	return IsPlayingRecord;
}

void ApplicationManager::SetPlayingRecordState(bool state)
{
	IsPlayingRecord = state;
}

bool ApplicationManager::GetIsColorChanged()
{
	return IsColorChanged;
}

void ApplicationManager::SetIsColorChanged(bool color)
{
	IsColorChanged = color;
}


//void ApplicationManager::IncremenetUndoCount() {
//	ActionCount++;
//}

//decrement the count of the undo/redo list
//void ApplicationManager::DecrementUndoCount() {
//	ActionCount--;
//}
//
//void ApplicationManager::AddInUndoList(Action* action) {
//
//	if (ActionCount < 5) {
//		UndoRedoList[ActionCount] = action;
//		ActionCount++;
//	}
//	else if (ActionCount >= 5) {
//		delete UndoRedoList[0];
//		for (int i = 0; i < 3; i++) {
//			UndoRedoList[i] = UndoRedoList[i + 1];
//		}
//		UndoRedoList[4] = action;
//
//	}
//}

//void ApplicationManager::LoadAll(ifstream& fileLoad)
//{
//	for (int i = 0; i < FigCount; i++)
//	{
//		FigList[i]->Load(fileLoad, pOut);
//
//	}
//}
//loading all figures