#include "eda/Event.h"

Event::Event(string typeEvent, int idProcess, StatisticsIn stdIn, double clock)
{
    this->typeEvent = typeEvent;
    this->idProcess = idProcess;

    Math dist = Math();

    string interarrivo = stdIn.getInterarrive();
    double *interarrivoInter = stdIn.getInterarriveInter();
    string RP = stdIn.getRP();
    double *RPInter = stdIn.getRPInter();
    string RIO = stdIn.getRIO();
    double *RIOInter = stdIn.getRIOInter();


    if(typeEvent == "Arrival"){
    	double distArrival = dist.determineDistribution(interarrivo, interarrivoInter[0], interarrivoInter[1]);
    	this->time = clock + distArrival;
    }
    else if(typeEvent == "RP"){
        double distRP = dist.determineDistribution(RP, RPInter[0], RPInter[1]);
    	this->time = clock + distRP;
    }
    else if(typeEvent == "RIO"){
        double distRIO = dist.determineDistribution(RIO, RIOInter[0], RIOInter[1]);
        this->time = clock + distRIO;
    }
    else if(typeEvent == "Final")
    {
        this->time = clock;
    }
}
//GETTERS
string Event::getTypeEvent(){
	return this->typeEvent;
}
double Event::getTime(){
	return this->time;
}
int Event::getIdProcess(){
	return this->idProcess;
}
//SETTERS
void Event::setTypeEvent(string typeEvent){
	this->typeEvent=typeEvent;
}
void Event::setTime(double time){
	this->time=time;
}
void Event::setIdProcess(int idProcess){
	this->idProcess=idProcess;
}

//Methods
void Event::validateRP(Process processCPU, double clock)
{
    double timeRP = time - clock;
    double timeMissingProcessing = processCPU.getTimeProcessor() - processCPU.getTimeProcessing();

    if(processCPU.getQuantum() == 0)                //If process hasn't quantum
    {
        if( timeMissingProcessing < timeRP )
            time = timeMissingProcessing + clock;
    }
    else                                            //If process has quantum
    {
        if ( processCPU.getQuantum() < timeRP ){
            if ( timeMissingProcessing < processCPU.getQuantum() )
                time = timeMissingProcessing + clock;
            else
                time = processCPU.getQuantum() + clock;
        }
    }


}
