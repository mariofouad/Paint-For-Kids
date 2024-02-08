#pragma once
#include<fstream>
#include<iostream>
#include <string>
#include"Actions/Action.h"
class Load :public Action
{

public:
     Load(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
};