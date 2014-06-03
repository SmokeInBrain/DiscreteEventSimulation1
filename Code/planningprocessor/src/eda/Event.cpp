#include "eda/Event.h"

Event::Event(string typeEvent, int idProcess, StatisticsIn stdIn, int clock)
{
    this->typeEvent = typeEvent;
    this->idProcess = idProcess;

    if(typeEvent == "Arrival"){
        time = 0;
        //time = clock + distArrival;
    }
    else if(typeEvent == "RP"){
        time = 0;
        //time = clock + distRP;
    }
    else if(typeEvent == "RIO"){
        time = 0;
        //time = clock + distRIO;
    }
    else if(typeEvent == "Final")
    {
        this->time = clock;
    }
}
