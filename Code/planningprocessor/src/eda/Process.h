#ifndef PROCESS_H
#define PROCESS_H
#include "eda/StatisticsIn.h"
#include "random/Distribution.h"
#include <string>
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
            Process(int id, double quantum, double clock, StatisticsIn stdIn);
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
            double setQuantum(int quantum);



        //Methods
            double calculateProcessor(StatisticsIn stdIn);
};

#endif // PROCESS_H

