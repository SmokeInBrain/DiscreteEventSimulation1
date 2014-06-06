#ifndef PROCESSING_H
#define PROCESSING_H

#include "eda/StatisticsIn.h"
#include "eda/Event.h"
#include "eda/Process.h"
#include "vector/VectorProcess.h"
#include "vector/VectorEvent.h"
#include "filereading/File.h"


class Processing{
    private:
        //Attributes
            //Date global
            StatisticsIn stdIn;

            double clock;

            //System state
            int largeQueue;
            bool condProcessCPU;
            //int largeIO;

            VectorProcess processQueue;     //List of process in the system
            Process processCPU;             //Process in CPU
            VectorProcess processIO;        //List of process in IO

            VectorEvent eventList;          //Future Event List

            //Cumulative Statistics Time
            double timeAccumulatedQueue;
            double timeAccumulatedCPU;
            double timeAccumulatedIO;

            //Cumulative Statistics Queue
            int largeAccumulatedQueue;
            int maxLargeQueue;

            int processFinish;

            //Math
            Math math;

    public:
        //Constructor
            Processing(StatisticsIn stdIn);
        //Getters
            StatisticsIn getStdIn();
            double getClock();
            int getLargeQueue();
            bool getCondProcessCPU();
            VectorProcess getProcessQueue();
            Process getProcessCPU();
            VectorProcess getProcessIO();
            VectorEvent getEventList();
            double getTimeAccumulatedQueue();
            double getTimeAccumulatedCPU();
            double getTimeAccumulatedIO();
            int getLargeAccumulatedQueue();
            int getMaxLargeQueue();
            int getProcessFinish();
        //Setters
            void setStdIn(StatisticsIn stdIn);
            void setClock(double clock);
            void setLargeQueue(int largeQueue);
            void setCondProcessCPU(bool condProcessCPU);
            void setProcessQueue(VectorProcess processQueue);
            void setProcessCPU(Process processCPU);
            void setProcessIO(VectorProcess processIO);
            void setEventList(VectorEvent eventList);
            void setTimeAccumulatedQueue(double timeAccumulatedQueue);
            void setTimeAccumulatedCPU(double timeAccumulatedCPU);
            void setTimeAccumulatedIO(double timeAccumulatedIO);
            void setLargeAccumulatedQueue(int largeAccumulatedQueue);
            void setMaxLargeQueue(int maxLargeQueue);
            void setProcessFinish(int processFinish);

        //Methods
            double activityArrivalProcess(Event eventCurrent, Process processArrival);
            double activityProcessCPU(Event eventCurrent);
            double activityProcessIO(Event eventCurrent);
            bool planificationProcess(File file);

};

#endif // PROCESSING_H
