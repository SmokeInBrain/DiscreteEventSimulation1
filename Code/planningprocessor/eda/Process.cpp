#include <eda/Process.h>

Process::Process()
{
    id = 0;
    clock = 0;
    timeProcessor = 0;
    timeProcessing = 0;
    quantum = 0;
}

Process::Process(int id, double quantum, int clock)
{
    //Datos
    this->id = id;
    this->clock = clock;
    timeProcessor = calculateProcessor();
    timeProcessing = 0;
    this->quantum = quantum;
}

float Process::calculateProcessor(){

}
