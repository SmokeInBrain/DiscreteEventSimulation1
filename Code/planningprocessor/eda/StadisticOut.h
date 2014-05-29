#ifndef STADISTICSOUT_H_INCLUDED
#define STADISTICSOUT_H_INCLUDED

class StadisticsOut
{
    public:
        //Constructor
            StadisticsOut();

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

#endif // STADISTICSOUT_H_INCLUDED
