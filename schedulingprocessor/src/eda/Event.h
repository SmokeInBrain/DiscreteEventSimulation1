#ifndef EVENT_H_INCLUDED
#define EVENT_H_INCLUDED

#include "eda/Process.h"
#include "eda/StatisticsIn.h"
#include "random/Random.h"
#include "random/Math.h"
#include <string>

using namespace std;

class Event
{
	private:
		//Attributes
       	string typeEvent;
        double time;
        int idProcess;

    public:
        //Constructor
            Event(string typeEvent, int idProcess, StatisticsIn stdIn, double clock);
            //GETTERS
            string getTypeEvent();
            double getTime();
            int getIdProcess();
            //SETTERS
            void setTypeEvent(string typeEvent);
            void setTime(double time);
            void setIdProcess(int idProcess);

        //Methods
            void validateRP(Process processCPU, double clock);
            //bool finishEvent();
};

#endif // EVENT_H

