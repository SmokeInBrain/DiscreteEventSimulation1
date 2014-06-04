#include "vector/VectorEvent.h"

#include <iostream>

VectorEvent::VectorEvent()
{
    numEventArrival = 0;
}
VectorEvent::VectorEvent(vector <Event> FEL, int numEventArrival){
    this->FEL=FEL;
    this->numEventArrival=numEventArrival;
}
//GETTERS
vector <Event> VectorEvent::getFEL(){
    return this->FEL;
}

int VectorEvent::getNumEventArrival(){
    return this->numEventArrival;
}

//SETTERS

void VectorEvent::setFEL(vector <Event> FEL){
    this->FEL=FEL;
}

void VectorEvent::setNumEventArrival(int numEventArrival){
    this->numEventArrival=numEventArrival;
}


void VectorEvent::insertEvent(Event event)
{
    int position = 0;
    for (unsigned int i = 0; i < FEL.size(); i++)
    {
        if (FEL[i].getTime() < event.getTime())
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
        cout << "[" << i << "]: TypeEvent: " << FEL[i].getTypeEvent() << " Time: " << FEL[i].getTime() << " idProcess: " << FEL[i].getIdProcess() << "\n";
    cout << "\n";
}
