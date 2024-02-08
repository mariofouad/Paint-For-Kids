#include "PlayRecording.h"
#include "ApplicationManager.h"
#include <chrono>
#include <thread>
#include <string>

PlayRecording::PlayRecording(ApplicationManager* pApp) : Action(pApp)
{}

void PlayRecording::ReadActionParameters()
{

}

void PlayRecording::SetNumOfCurrentActions(int currentacions)
{
    NumOfCurrentActions = pManager->GetActionCount();
}

void PlayRecording::Wait()
{
    using namespace std::this_thread;     // sleep_for, sleep_until
    using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
    using std::chrono::system_clock;
    sleep_for(10ns);
    sleep_until(system_clock::now() + 1s);
}

void PlayRecording::Execute()
{
    pManager->SetPlayingRecordState(true);
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();

    Wait();

    pOut->ClearDrawArea();
    pOut->PrintMessage("Playing Record.");
    Wait();

    SetNumOfCurrentActions(pManager->GetActionCount());

    pManager->ClearAllFigures();
    for (int i = 0; i < NumOfCurrentActions; i++)
    {
        pManager->ExecuteRecordedAction(i);
        pManager->UpdateInterface();
        Wait();
    }
    pManager->SetPlayingRecordState(false);
    pOut->PrintMessage("Recording Finished.");
}
void PlayRecording::Undo() {
}