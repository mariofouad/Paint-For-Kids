#pragma once
#include<fstream>
#include<iostream>
#include<sstream>
#include <string>
#include"Actions/Action.h"
class Load :public Action
{
	string inputfilename;
	ifstream file;

public:
     Load(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
};