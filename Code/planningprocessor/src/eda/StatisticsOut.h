#ifndef STATISTICSOUT_H_INCLUDED
#define STATISTICSOUT_H_INCLUDED

class StatisticsOut
{
    public:
        //Constructor
            StatisticsOut();

        //Atribute
            //Date general
            float timeTotalSimulation;
            float timeUtilizationProcessor;
            float timeIdleProcessor;

            //Date process
            float timeQueue;
            float timeProcess;
            float timeIO;

            //Date queue
            int maxLenghtQueue;
            float avgLenghtQueue;

        //Methods

};

#endif // StatisticsOut_H_INCLUDED
