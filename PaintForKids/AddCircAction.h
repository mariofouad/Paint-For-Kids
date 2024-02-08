#include"Actions/Action.h"
#include <string>
class AddCircAction : public Action {

private:
	Point cent;
	GfxInfo CircGfxInfo;
	
public:
	AddCircAction(ApplicationManager* pApp);

	//reads the parameters of the circle
	virtual void ReadActionParameters();

	//adds the circle to the figure list 
	virtual void Execute();
	virtual void Undo();
};