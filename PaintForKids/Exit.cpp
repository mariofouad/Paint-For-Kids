#include "Exit.h"
#include <chrono>
#include <thread>
#include <string>
Exit::Exit(ApplicationManager* pApp):Action(pApp)
{
}
void Exit::ReadActionParameters() {}

void Exit::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	
    
    pOut->ClearStatusBar();

    using namespace std::this_thread;     // sleep_for, sleep_until
    using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
    using std::chrono::system_clock;
   
    pOut->ClearDrawArea();

    pOut->PrintMessage("GoodBye!!");
    pManager->HouseKeeping();

    sleep_for(10ns);
    sleep_until(system_clock::now() + 1s);
}
void Exit::Undo() {
}
