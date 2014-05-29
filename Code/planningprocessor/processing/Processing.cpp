#include <processing/Processing.h>

Processing::Processing(StadisticsIn stdIn){
    //Initialize Statistics
    this->stdIn = stdIn;
    stdOut();

    //Initialize list of process in each activity
    processListCPU();
    processListIO();
    processFinishList();

    //Initialize list
}

void Processing::functionCreateProcess()
{
    CreateProcess createProcess();
    createProcess.creatingProcess();
}

void Processing::functionProcessingProcess()
{
    ProcessingProcess processingProcess();
    processingProcess.ProcesprocessingCPU();
}

void Processing::functionProcessingIO()
{
    ProcessingIO procesingIO();
    procesingIO.executeIO();
}

bool Processing::planificationProcess(StadisticsIn stdIn)
{

}
