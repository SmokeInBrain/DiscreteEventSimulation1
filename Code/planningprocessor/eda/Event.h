#ifndef EVENT_H
#define EVENT_H

#include <StatisticsIn.h>
#include <string>

using namespace std;

class Event
{
    public:
        //Constructor
            Event(string typeEvent, int idProcess, StatisticsIn stdIn, int clock);

        //Attributes
            string typeEvent;
            int time;
            int idProcess;

        //Methods
            //bool finishEvent();
};

#endif // EVENT_H

