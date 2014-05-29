#ifndef STADISTICOUT_H_INCLUDED
#define STADISTICOUT_H_INCLUDED

class StadisticOut
{
    public:
        //Constructor
            StadisticOut();

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
};

#endif // STADISTICOUT_H_INCLUDED
