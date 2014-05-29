#include <eda/Event.h>

Event::Event(string typeEvent, int i)
{
    if(typeEvent.compare("Arrival")){
        //
    }
    else if(typeEvent.compare("RP")){
        //
    }
    else if(typeEvent.compare("RIO")){
        //
    }
}

bool Event::finishEvent()
{
    this->stateEvent = false;
}
