#ifndef EVENT_H
#define EVENT_H

#include <string>

using namespace std;

class Event
{
    public:
        //Constructor
            Event(string typeEvent);

        //Attributes
            //Date
            int id;
            int idProcess;
            //Stadistic
            float timeArrival;
            float timeDelay;

            bool actionEvent;
            bool stateEvent;

        //Methods
            bool finishEvent();
};

#endif // EVENT_H

