#include "Actions/Action.h"
#include <string>
class AddHexAction : public Action {

private:
	Point HC;
	GfxInfo HexGfxInfo;

public:
	
	AddHexAction(ApplicationManager* pApp);

	//reads parameters from user
	virtual void ReadActionParameters();

	//adds the hexagon to figure list
	virtual void Execute();
	virtual void Undo();
};