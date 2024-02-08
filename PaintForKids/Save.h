#pragma once
#include<fstream>
#include<iostream>
#include <string>
#include"Actions/Action.h"
class Save :public Action
{
	string FileName;
	ofstream file;

public:
	Save(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
};

