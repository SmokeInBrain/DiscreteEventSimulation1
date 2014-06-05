#ifndef STATISTICSOUT_H_INCLUDED
#define STATISTICSOUT_H_INCLUDED

using namespace std;
class StatisticsOut
{	private:
		//Attributes
            //General Data
            double totalSimulationTime;
            double throughputTime;
            double idleTime;

            //Processor Data
            double queueTime;
            double processTime;
            double IOTime;

            //Queue Data
            int queueMaxLength;
            double queueAvgLength;
    public:
        //Constructors
            StatisticsOut();
            StatisticsOut(double clock, double timeAccumulatedQueue, double timeAccumulatedCPU, double timeAccumulatedIO, int processFinish, int maxLargeQueue, double largeAccumulatedQueue);
        //Getters
            double getTotalSimulationTime();
            double getThroughputTime();
            double getIdleTime();
            double getQueueTime();
            double getProcessTime();
            double getIOTime();
            int getQueueMaxLength();
            double getQueueAvgLength();
        //Setters
            void setTotalSimulationTime(double totalSimulationTime);
            void setThroughputTime(double throughputTime);
            void setIdleTime(double idleTime);
            void setQueueTime(double queueTime);
            void setProcessTime(double processTime);
            void setIOTime(double IOTime);
            void setQueueMaxLength(int queueMaxLength);
            void setQueueAvgLength(double queueAvgLength);
};

#endif // StatisticsOut_H_INCLUDED
