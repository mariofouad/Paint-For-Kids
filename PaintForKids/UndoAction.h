#include "Actions/Action.h"

class UndoAction : public Action {

public:
	UndoAction(ApplicationManager* pApp);
	virtual void Execute();
	virtual void ReadActionParameters();
	virtual void Undo();

};
