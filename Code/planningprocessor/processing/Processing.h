#ifndef PROCESSING_H
#define PROCESSING_H

#include <eda/StadisticsIn.h>
#include <vector/VectorProcess.h>
#include <vector/VectorEvent.h>

class Processing{
    public:
        //Constructor
            Processing(StadisticsIn stdIn);

        //Attributes
            //Date global
            StadisticsIn stdIn;

            int clock;

            //System state
            int largeQueue;
            bool condProcessCPU;
            //int largeIO;

            VectorProcess processQueue;     //List of process in the system
            Process processCPU;             //Process in CPU
            VectorProcess processIO;        //List of process in IO

            VectorEvent eventList;          //Future Event List

            //Cumulative Statistics Time
            int timeAccumulatedQueue;
            int timeAccumulatedCPU;
            int timeAccumulatedIO;

            //Cumulative Statistics Queue
            int largeAccumulatedQueue;
            int maxLargeQueue;

            int processFinish;

        //Methods
            int activityArrivalProcess();
            int activityProcessCPU();
            int activityProcessIO();
            bool planificationProcess(StadisticsIn stdIn);

};

#endif // PROCESSING_H
