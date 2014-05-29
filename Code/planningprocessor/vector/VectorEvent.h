#ifndef VECTOREVENT_H
#define VECTOREVENT_H

#include <vector>
#include <eda/Event.h>

using namespace std;

class VectorEvent {

    public:
        //Constructor
            VectorEvent();

        // Attributes.
            vector <Event> FEL;

        // Methods.
            void insertEvent(Event event);
            Event extractEvent();
            void printAllList();
};

#endif // VECTORPROCESOS_H
