#include "Actions/Action.h"
#include <string>
class SelctFig : public Action
{
private:
	Point P1;
public:
	SelctFig(ApplicationManager* pApp);
	
	//Reads parameters required for select action
	virtual void ReadActionParameters();

	//Execute select action
	virtual void Execute();
	virtual void Undo();
};