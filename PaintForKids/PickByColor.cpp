#include "PickByColor.h"
#include "Actions/Action.h"
#include "ApplicationManager.h"
#include"GUI/Output.h"
#include"GUI/Input.h"
#include "DEFS.h"
#include <string>
#include <chrono>
#include <thread>
#include <string>
using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using std::chrono::system_clock;
PickByColor::PickByColor(ApplicationManager* pApp) : Action(pApp) {}

void PickByColor::ReadActionParameters()
{
    //Get a Pointer to the Input / Output Interfaces
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();
    pIn->GetPointClicked(P1.x, P1.y);

    pOut->ClearStatusBar();
}

void PickByColor::Execute()
{
    pManager->PiCKFig();
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();

    CFigure* Fig = pManager->Generate();
    string PlayedColor = Fig->GetFigColor(pOut);
    pOut->PrintMessage("Your game started choose: " + PlayedColor);
    int CountTrue = 0;
    int CountFalse = 0;
    for (int i = 0; i < pManager->GetFigCount(); i++)
    {
        ReadActionParameters();
        CFigure* ClFig = pManager->GetFigure(P1.x, P1.y);

        if (ClFig != NULL)
        {
            if (ClFig->GetFigColor(pOut) == PlayedColor)
            {
                pOut->PrintMessage("True");
                CountTrue++;
            }
            else
            {
                pOut->PrintMessage("False");
                CountFalse++;
            }
            ClFig->ChngDrawClr(UI.BkGrndColor);
            ClFig->ChngFillClr(UI.BkGrndColor);
            pManager->UpdateInterface();
        }
        else
        {
            pOut->PrintMessage("You clicked on empty space, TRY AGAIN");
            i--;
        }
    }
    sleep_for(10ns);
    sleep_until(system_clock::now() + 1s);
    pOut->PrintMessage("Number of Figures you choose correct: " + to_string(CountTrue) + " ,Number of Figures you choose wrong: " + to_string(CountFalse));
}
void PickByColor::Undo() {
}