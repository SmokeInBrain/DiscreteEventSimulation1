#include <eda/StadisticsOut.h>

StadisticsOut::StadisticsOut()
{
    //Date
    timeTotalSimulation = 0;

    timeUtilizationProcessor = 0;
    timeIdleProcessor = 0;

    timeQueue = 0;
    timeProcess = 0;
    timeI0 = 0;

    maxLenghtQueue = 0;
    avgLenghtQueue = 0;
}
