#ifndef VECTOREVENT_H
#define VECTOREVENT_H

#include <vector>
#include "eda/Event.h"

using namespace std;

class VectorEvent {
    private:
        // Attributes.
            vector <Event> FEL;
            int numEventArrival;

    public:
        //Constructor
            VectorEvent();
            VectorEvent(vector <Event> FEL, int numEventArrival);

        //GETTERS
            vector <Event> getFEL();
            int getNumEventArrival();

        //SETTERS
            void setFEL(vector <Event> FEL);
            void setNumEventArrival(int numEventArrival);

        // Methods.
            void insertEvent(Event event);
            Event extractEvent();
            void printAllList();
};

#endif // VECTORPROCESOS_H
