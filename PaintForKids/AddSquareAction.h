#ifndef ADD_SQUARE_ACTION_H
#define ADD_SQUARE_ACTION_H
#include "Actions/Action.h"
#include <string>
class AddSquareAction : public Action {

private:
	Point C;
	GfxInfo SquareGfxInfo;
public:
	AddSquareAction(ApplicationManager* pAPP);

	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();

};
#endif