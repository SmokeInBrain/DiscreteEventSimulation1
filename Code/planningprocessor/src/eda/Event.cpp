#include "eda/Event.h"


Event::Event(string typeEvent, int idProcess, StatisticsIn stdIn, int clock)
{
    this->typeEvent = typeEvent;
    this->idProcess = idProcess;
    
    Random random = Random();
    Distribution dist = Distribution(random);

    string interarrivo = stdIn.getInterarrive();
    double *interarrivoInter = stdIn.getInterarriveInter();
    string RP = stdIn.getRP();
    double *RPInter = stdIn.getRPInter();
    string RIO = stdIn.getRIO();
    double *RIOInter = stdIn.getRIOInter();


    if(typeEvent == "Arrival"){
    	double distArrival = dist.determineDistribution(interarrivo, interarrivoInter[0], interarrivoInter[1]);
    	time = clock + distArrival;
    }
    else if(typeEvent == "RP"){
        double distRP = dist.determineDistribution(RP, RPInter[0], RPInter[1]);
    	time = clock + distRP;
    }
    else if(typeEvent == "RIO"){
        double distRIO = dist.determineDistribution(RIO, RIOInter[0], RIOInter[1]);
        time = clock + distRIO;
    }
    else if(typeEvent == "Final")
    {
        this->time = clock;
    }
}
