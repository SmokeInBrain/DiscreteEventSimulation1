#include "eda/StatisticsOut.h"

StatisticsOut::StatisticsOut()
{
    //Date
    timeTotalSimulation = 0;

    timeUtilizationProcessor = 0;
    timeIdleProcessor = 0;

    timeQueue = 0;
    timeProcess = 0;
    timeIO = 0;

    maxLenghtQueue = 0;
    avgLenghtQueue = 0;
}
