#ifndef PROCESS_H
#define PROCESS_H

#include <string>
#include <iostream>

#include "eda/StatisticsIn.h"
#include "random/Math.h"


using namespace std;
class Process
{
	private:
		//Attributes
            //Date
            int id;
            double clock;
            //Statistics
            double timeProcessor;    //Time that needs this process for finish
            double timeProcessing;   //Time that this process is in the CPU
            double quantum;           //Time quantum in algorithm RR

    public:
        //Constructor
            Process();
            Process(int id, double quantum, double clock, StatisticsIn stdIn, Math dist);
            //GETTERS
            int getId();
            double getClock();
            double getTimeProcessor();
            double getTimeProcessing();
            double getQuantum();
            //SETTERS
            void setId(int id);
            void setClock(double clock);
            void setTimeProcessor(double timeProcessor);
            void setTimeProcessing(double timeProcessing);
            void setQuantum(double quantum);

        //Methods
            double calculateProcessor(StatisticsIn stdIn, Math dist);
            void printProcess();
};

#endif // PROCESS_H

