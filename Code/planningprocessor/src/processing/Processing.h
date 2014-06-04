#ifndef PROCESSING_H
#define PROCESSING_H

#include "eda/StatisticsIn.h"
#include "vector/VectorProcess.h"
#include "vector/VectorEvent.h"
#include "filereading/File.h"


class Processing{
    private:
        //Attributes
            //Date global
            StatisticsIn stdIn;

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

    public:
        //Constructor
            Processing(StatisticsIn stdIn);
        //Getters
            StatisticsIn getStdIn();
            int getClock();
            int getLargeQueue();
            bool getCondProcessCPU();
            VectorProcess getProcessQueue();
            Process getProcessCPU();
            VectorProcess getProcessIO();
            VectorEvent getEventList();
            int getTimeAccumulatedQueue();
            int getTimeAccumulatedCPU();
            int getTimeAccumulatedIO();
            int getLargeAccumulatedQueue();
            int getMaxLargeQueue();
            int getProcessFinish();
        //Setters
            void setStdIn(StatisticsIn stdIn);
            void setClock(int clock);
            void setLargeQueue(int largeQueue);
            void setCondProcessCPU(bool condProcessCPU);
            void setProcessQueue(VectorProcess processQueue);
            void setProcessCPU(Process processCPU);
            void setProcessIO(VectorProcess processIO);
            void setEventList(VectorEvent eventList);
            void setTimeAccumulatedQueue(int timeAccumulatedQueue);
            void setTimeAccumulatedCPU(int timeAccumulatedCPU);
            void setTimeAccumulatedIO(int timeAccumulatedIO);
            void setLargeAccumulatedQueue(int largeAccumulatedQueue);
            void setMaxLargeQueue(int maxLargeQueue);
            void setProcessFinish(int processFinish);

        //Methods
            int activityArrivalProcess(Event eventCurrent, Process processArrival);
            int activityProcessCPU(Event eventCurrent);
            int activityProcessIO(Event eventCurrent);
            bool planificationProcess(File file);

};

#endif // PROCESSING_H
