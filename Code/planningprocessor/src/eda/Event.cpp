#include "eda/Event.h"


Event::Event(string typeEvent, int idProcess, StatisticsIn stdIn, int clock)
{
	string interarrivo = stdIn.getInterrarrive();
	double[2] interarrivoInter = stdIn.getInterrarriveInter();
	string RP = stdIn.getRP();
	double[2] RPInter = stdIn.getRPInter();
	string RIO = stdIn.getRIO();
	double[2] RIOInter = stdIn.getRIOInter();
    this->typeEvent = typeEvent;
    this->idProcess = idProcess;
    Random random = Random();
    Distribution dist = Distribution(random);


    if(typeEvent == "Arrival"){
    	double distArrival = dist.determineDistribution(interarrivo,interarrivoInter[0],interarrivoInter[1]);
    	time = clock + distArrival;
    }
    else if(typeEvent == "RP"){
        double distRP = dist.determineDistribution(RP,RPInter[0],RPInter[1]);
    	time = clock + distRP;
    }
    else if(typeEvent == "RIO"){
        double distRIO = dist.determineDistribution(RIO,RIOInter[0],RIOInter[1]);
        time = clock + distRIO;
    }
    else if(typeEvent == "Final")
    {
        this->time = clock;
    }
}
