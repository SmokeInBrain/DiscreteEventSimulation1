#include <eda/Process.h>

Process::Process(int id)
{
    //Datos
    this->id = id;

    timeProcessor = calculateProcessor();
    timeQueue = 0;
    timeProcessing = 0;
    timeIO = 0;
}


