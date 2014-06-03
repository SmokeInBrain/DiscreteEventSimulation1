#include "vector/VectorEvent.h"

#include <iostream>

VectorEvent::VectorEvent()
{
    numEventArrival = 0;
}

void VectorEvent::insertEvent(Event event)
{
    int position = 0;
    for (unsigned int i = 0; i < FEL.size(); i++)
    {
        if (FEL[i].time < event.time)
            position++;
    }

    FEL.insert( FEL.begin() + position, event);
}

Event VectorEvent::extractEvent()
{
    Event extractEvent = FEL[0];
    FEL.erase( FEL.begin() );

    return extractEvent;
}


void VectorEvent::printAllList()
{

    for (unsigned int i = 0; i < FEL.size(); i++)
        cout << "[" << i << "]: TypeEvent: " << FEL[i].typeEvent << " Time: " << FEL[i].time << " idProcess: " << FEL[i].idProcess << "\n";
    cout << "\n";
}
