#include <eda/Event.h>

Event::Event(string typeEvent, int idProcess, StatisticsIn stdIn, int clock)
{
    this->typeEvent = typeEvent;
    this->idProcess = idProcess;

    if(typeEvent.compare("Arrival")){
        //
        time = clock + distArrival;
    }
    else if(typeEvent.compare("RP")){
        //
        time = clock + distRP;
    }
    else if(typeEvent.compare("RIO")){
        //
        time = clock + distRIO;
    }
}
