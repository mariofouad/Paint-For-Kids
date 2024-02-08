#include"Actions/Action.h"
#include<iostream>
#include <string>
using namespace std;

class AddTriAction : public Action {

private:
	Point v1, v2, v3;
	GfxInfo TriGfxInfo;

public:
	
	AddTriAction(ApplicationManager* pApp);

	//reads the parameters of the triangle
	void ReadActionParameters();

	//Add triangle to the ApplicationManager
	void Execute();
	virtual void Undo();
};