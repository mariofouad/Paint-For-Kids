#include "Actions/Action.h"

class RedoAction : public Action {

public:
	RedoAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();
	virtual void Undo();
	virtual void Execute();
};
