#include <vector/VectorEvent.h>

VectorEvent::VectorEvent()
{
    numEventArrival = 0;
}

void VectorEvent::insertEvent(Event event)
{
    int pos = 0;
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
        cout << "[" << i << "]: ID: " << FEL[i].ID << " Tipo: " << FEL[i].tipo << " TpoPro: " << FEL[i].tiempoProcesador << " TpoIO: " << FEL[i].tiempoIO << "\n";
    cout << "\n";
}
