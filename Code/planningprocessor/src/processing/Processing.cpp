#include "processing/Processing.h"

#include <iostream>

Processing::Processing(StatisticsIn stdIn)
{
    //Initialize Statistics
    this->stdIn = stdIn;

    //Initialize clock of the system
    clock = 0;

    //Initialize condition of the system
    largeQueue = 0;
    condProcessCPU = false;

    //Initialize list in the system

    processQueue = VectorProcess(stdIn.getNumProc(), stdIn.getAlgorithm());
    processCPU = Process();
    processIO = VectorProcess(stdIn.getNumProc(), "FCFS");

    eventList = VectorEvent();
    eventList.setNumEventArrival(0);

    /*Process firstProcess = Process(1, stdIn.getQuantum(), clock);
    processCPU = firstProcess;

    processIO = VectorProcess(stdIn.getNumProc(), "FCFS");

    //Initialize FEL
    eventList = VectorEvent();

    //Initialize first RP
    Event firstEventRP = Event("RP", 1, stdIn, clock);
    eventList.insertEvent(firstEventRP);

    eventList.setNumEventArrival(1);                      //Setting arrival for default

    //Initialize second Arrival
    Event secondEventArrival = Event("Arrival", 2, stdIn, clock);
    eventList.insertEvent(secondEventArrival);*/

    //Initialize statistics
    timeAccumulatedQueue = 0;
    timeAccumulatedCPU = 0;
    timeAccumulatedIO = 0;

    largeAccumulatedQueue = 0;
    maxLargeQueue = 0;

    processFinish = 0;

}
//Getters
StatisticsIn Processing::getStdIn(){
    return this->stdIn;
}
double Processing::getClock(){
    return this->clock;
}
int Processing::getLargeQueue(){
    return this->largeQueue;
}
bool Processing::getCondProcessCPU(){
    return this->condProcessCPU;
}
VectorProcess Processing::getProcessQueue(){
    return this->processQueue;
}
Process Processing::getProcessCPU(){
    return this->processCPU;
}
VectorProcess Processing::getProcessIO(){
    return this->processIO;
}
VectorEvent Processing::getEventList(){
    return this->eventList;
}
double Processing::getTimeAccumulatedQueue(){
    return this->timeAccumulatedQueue;
}
double Processing::getTimeAccumulatedCPU(){
    return this->timeAccumulatedCPU;
}
double Processing::getTimeAccumulatedIO(){
    return this->timeAccumulatedIO;
}
int Processing::getLargeAccumulatedQueue(){
    return this->largeAccumulatedQueue;
}
int Processing::getMaxLargeQueue(){
    return this->maxLargeQueue;
}
int Processing::getProcessFinish(){
    return this->processFinish;
}
//Setters
void Processing::setStdIn(StatisticsIn stdIn){
    this->stdIn=stdIn;
}
void Processing::setClock(double clock){
    this->clock=clock;
}
void Processing::setLargeQueue(int largeQueue){
    this->largeQueue=largeQueue;
}
void Processing::setCondProcessCPU(bool condProcessCPU){
    this->condProcessCPU=condProcessCPU;
}
void Processing::setProcessQueue(VectorProcess processQueue){
    this->processQueue=processQueue;
}
void Processing::setProcessCPU(Process processCPU){
    this->processCPU=this->processCPU;
}
void Processing::setProcessIO(VectorProcess processIO){
    this->processIO=processIO;
}
void Processing::setEventList(VectorEvent eventList){
    this->eventList=eventList;
}
void Processing::setTimeAccumulatedQueue(double timeAccumulatedQueue){
    this->timeAccumulatedQueue=timeAccumulatedQueue;
}
void Processing::setTimeAccumulatedCPU(double timeAccumulatedCPU){
    this->timeAccumulatedCPU=timeAccumulatedCPU;
}
void Processing::setTimeAccumulatedIO(double timeAccumulatedIO){
    this->timeAccumulatedIO=timeAccumulatedIO;
}
void Processing::setLargeAccumulatedQueue(int largeAccumulatedQueue){
    this->largeAccumulatedQueue=largeAccumulatedQueue;
}
void Processing::setMaxLargeQueue(int maxLargeQueue){
    this->maxLargeQueue=maxLargeQueue;
}
void Processing::setProcessFinish(int processFinish){
    this->processFinish=processFinish;
}

int Processing::activityArrivalProcess(Event eventCurrent, Process processArrival)
{
    if(condProcessCPU)
    {
        largeQueue++;                                                           //Increment queue
        processQueue.insertProcess(processArrival);                             //Insert process in queue
    }
    else
    {
        condProcessCPU = true;                                                 //Setting process CPU
        processCPU = processArrival;
        Event nextRP = Event("RP", eventCurrent.getIdProcess(), stdIn, eventCurrent.getTime());      //Create next RP in the system
        eventList.insertEvent(nextRP);                                         //Insert event RP in FEL
    }

    //Generate next arrival
    if(eventList.getNumEventArrival() < stdIn.getNumProc())                        //Condition: The system can't generate more arrival for maximum case of process arrival
    {
        Event nextArrival = Event("Arrival", eventList.getNumEventArrival()+1, stdIn, clock);   //Create next arrival
        eventList.insertEvent(nextArrival);                                                     //And insert in the FEL
    }

    //Statistics
    if(this->maxLargeQueue < this->largeQueue)
        this->maxLargeQueue = this->largeQueue;

    //Return clock
    return eventCurrent.getTime();
}

int Processing::activityProcessCPU(Event eventCurrent)
{
    double timeProcessCPU;
    double timeRP = eventCurrent.getTime() - clock;

    Process processAnalyzed = processCPU;

    if(largeQueue != 0)
    {
        //Reduce queue
        largeQueue--;

        //Generate RP for the first process in the queue
        Process processFirstQueue = processQueue.extractProcess();
        processCPU = processFirstQueue;
        processCPU.setClock(eventCurrent.getTime());
        Event nextRP = Event("RP", processFirstQueue.getId(), stdIn, eventCurrent.getTime());
        eventList.insertEvent(nextRP);                                              //And insert in the FEL

        //Statistics
        timeAccumulatedQueue = processCPU.getClock() - processFirstQueue.getClock();
    }
    else
    {
        //Empty CPU
        condProcessCPU = false;
        processCPU = Process();
    }

    //Increment processing time of the analyzed process
    processAnalyzed.setTimeProcessing(processAnalyzed.getTimeProcessing() + (eventCurrent.getTime() - clock));

    if(processAnalyzed.getTimeProcessor() <= processAnalyzed.getTimeProcessing())     //If this process has not more time of processing, it finish
    {
        timeProcessCPU = timeRP - (processAnalyzed.getTimeProcessing() - processAnalyzed.getTimeProcessor());
        processFinish++;                                                    //Increment number of process finish

        if(processFinish == stdIn.getNumProc())
        {
            Event eventFinal = Event("Final", 0, stdIn, eventCurrent.getTime());
            eventList.insertEvent(eventFinal);
        }
    }
    else if(processQueue.getTypePriority() ==  "RR")                             //If the queue is Round-Robin, then it is necessary analyzed its quantum
    {
        if( processAnalyzed.getQuantum() < timeRP)                              //If the quantum is minor to the time processing in CPU
        {
            processAnalyzed.setClock(eventCurrent.getTime());                      //Switch clock of process
            processQueue.insertProcess(processAnalyzed);                    //Insert process in queue

            largeQueue++;                                                   //Increment queue
            if(maxLargeQueue < largeQueue)                                  //Statistics queue
                maxLargeQueue = largeQueue;

            timeProcessCPU = processAnalyzed.getQuantum();
        }
        else
        {
            processIO.insertProcess(processAnalyzed);                       //Else, this process insert list IO
            Event eventRIO = Event("RIO", processAnalyzed.getId(), stdIn, eventCurrent.getTime());
            eventList.insertEvent(eventRIO);

            timeProcessCPU = timeRP;
        }
    }
    else
    {
        processIO.insertProcess(processAnalyzed);                           //Else, this process insert list IO
        Event eventRIO = Event("RIO", processAnalyzed.getId(), stdIn, eventCurrent.getTime());
        eventList.insertEvent(eventRIO);

        timeProcessCPU = timeRP;
    }

    //Statistics
    timeAccumulatedCPU += timeProcessCPU;

    return eventCurrent.getTime();
}

int Processing::activityProcessIO(Event eventCurrent)
{
    Process processCurrentIO = processIO.extractProcessIO(eventCurrent.getIdProcess());  //Determinate process IO to extract
    processCurrentIO.setClock(eventCurrent.getTime());                                     //Switch clock of process

    //Insert process IO in the queue
    if(condProcessCPU)
    {
        largeQueue++;                                                           //Increment queue
        processQueue.insertProcess(processCurrentIO);                             //Insert process in queue
    }
    else
    {
        condProcessCPU = true;                                                 //Setting process CPU
        processCPU = processCurrentIO;
        Event nextRP = Event("RP", eventCurrent.getIdProcess(), stdIn, eventCurrent.getTime());      //Create next RP in the system
        eventList.insertEvent(nextRP);                                         //Insert event RP in FEL
    }


    if(maxLargeQueue < largeQueue)
        maxLargeQueue = largeQueue;

    //Return time
    return eventCurrent.getTime();
}

bool Processing::planificationProcess(File file)
{
    //Initialize first event of arrival
    Event firstEventArrival = Event("Arrival", eventList.getNumEventArrival()+1, stdIn, clock);
    firstEventArrival.setTime(0);
    eventList.insertEvent(firstEventArrival);

    while(true)
    {

        Event eventCurrent = eventList.extractEvent();

        file.Log(eventCurrent);

        if(eventCurrent.getTypeEvent() == "Arrival")
        {
            eventList.setNumEventArrival(eventList.getNumEventArrival()+1);                                                              //Increment number of arrival in the system
            Process arrivalProcess = Process(eventList.getNumEventArrival()+1, stdIn.getQuantum(), eventCurrent.getTime(), this->stdIn); //Create process arrival

            clock = activityArrivalProcess(eventCurrent, arrivalProcess);
        }
        else if(eventCurrent.getTypeEvent() == "RP")
        {
            clock = activityProcessCPU(eventCurrent);
        }
        else if(eventCurrent.getTypeEvent() == "RIO")
        {
            clock = activityProcessIO(eventCurrent);
        }
        else if(eventCurrent.getTypeEvent() == "Final")
        {
            return true;
        }

    }
    return false;
}
