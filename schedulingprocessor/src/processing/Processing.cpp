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

    //Initialize Math
    math = Math();

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

double Processing::activityArrivalProcess(Event eventCurrent, Process processArrival)
{
    //Statistics initial
    largeAccumulatedQueue += largeQueue * (eventCurrent.getTime() - clock);

    //cout << "[Process Arrival] ";
    //processArrival.printProcess();

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
        nextRP.validateRP(processCPU, processCPU.getClock());
        eventList.insertEvent(nextRP);                                         //Insert event RP in FEL
    }

    //Generate next arrival
    if(eventList.getNumEventArrival() < stdIn.getNumProc())                        //Condition: The system can't generate more arrival for maximum case of process arrival
    {
        Event nextArrival = Event("Arrival", eventList.getNumEventArrival()+1, stdIn, clock);   //Create next arrival
        eventList.insertEvent(nextArrival);                                                     //And insert in the FEL
    }

    //Statistics final
    if(this->maxLargeQueue < this->largeQueue)
        this->maxLargeQueue = this->largeQueue;

    //Return clock
    return eventCurrent.getTime();
}

double Processing::activityProcessCPU(Event eventCurrent)
{
    Process processAnalyzed = processCPU;

    //double timeProcessCPU;
    double timeRP = eventCurrent.getTime() - processAnalyzed.getClock();

    //Statistics initial
    largeAccumulatedQueue += largeQueue * (eventCurrent.getTime() - clock);

    //cout << "[Process CPU] ";
    //processAnalyzed.printProcess();

    if(largeQueue != 0)
    {
        //Reduce queue
        largeQueue--;

        //Generate RP for the first process in the queue
        Process processFirstQueue = processQueue.extractProcess();
        processCPU = processFirstQueue;
        processCPU.setClock(eventCurrent.getTime());
        Event nextRP = Event("RP", processFirstQueue.getId(), stdIn, eventCurrent.getTime());
        nextRP.validateRP(processCPU, processCPU.getClock());
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
    //cout << "Time RP: " << timeRP ;
    processAnalyzed.setTimeProcessing(processAnalyzed.getTimeProcessing() + timeRP);
    //processAnalyzed.printProcess();

    if( math.roundZero(processAnalyzed.getTimeProcessor() - processAnalyzed.getTimeProcessing()) == 0 )     //If this process has not more time of processing, it finish
    {
        //timeProcessCPU = timeRP - (processAnalyzed.getTimeProcessing() - processAnalyzed.getTimeProcessor());
        processFinish++;                                                    //Increment number of process finish

        if(processFinish == stdIn.getNumProc())
        {
            Event eventFinal = Event("Final", 0, stdIn, eventCurrent.getTime());
            eventList.insertEvent(eventFinal);
        }
    }
    else if(processQueue.getTypePriority() ==  "RR")                             //If the queue is Round-Robin, then it is necessary analyzed its quantum
    {
        if( math.roundZero(processAnalyzed.getQuantum() - timeRP ) == 0 )                              //If the quantum is minor to the time processing in CPU
        {
            //Insert process CPU with quantum in the queue
            processAnalyzed.setClock(eventCurrent.getTime());                      //Switch clock of process
            processAnalyzed.setQuantum(stdIn.getQuantum());                         //Setting new quantum

            if(condProcessCPU)
            {
                largeQueue++;
                processQueue.insertProcess(processAnalyzed);                    //Insert process in queue
            }
            else
            {
                condProcessCPU = true;                                                 //Setting process CPU
                processCPU = processAnalyzed;
                Event nextRP = Event("RP", processAnalyzed.getId(), stdIn, processAnalyzed.getClock());      //Create next RP in the system
                nextRP.validateRP(processCPU, eventCurrent.getTime());
                eventList.insertEvent(nextRP);
            }

            //Statistics general
            if(maxLargeQueue < largeQueue)
                maxLargeQueue = largeQueue;

            //timeProcessCPU = processAnalyzed.getQuantum();
        }
        else                                                                        //Else, this process insert list IO
        {
            //Statistics
            processAnalyzed.setClock(eventCurrent.getTime());
            processAnalyzed.setQuantum( processAnalyzed.getQuantum() - timeRP );

            //Insert I/O
            processIO.insertProcess(processAnalyzed);
            Event eventRIO = Event("RIO", processAnalyzed.getId(), stdIn, eventCurrent.getTime());
            eventList.insertEvent(eventRIO);

            //timeProcessCPU = timeRP;
        }
    }
    else
    {
        //cout << "[Process Analyzed] ";
        //processAnalyzed.printProcess();
        processAnalyzed.setClock(eventCurrent.getTime());

        processIO.insertProcess(processAnalyzed);
        Event eventRIO = Event("RIO", processAnalyzed.getId(), stdIn, eventCurrent.getTime());
        eventList.insertEvent(eventRIO);

        //timeProcessCPU = timeRP;
    }

    //Statistics final
    timeAccumulatedCPU += timeRP;

    return eventCurrent.getTime();
}

double Processing::activityProcessIO(Event eventCurrent)
{
    //Statistics initial
    largeAccumulatedQueue += largeQueue * (eventCurrent.getTime() - clock);

    //cout << endl;
    //cout << "[List IO] ";
    //processIO.printAllList();                          //Else, this process insert list IO
    //cout << endl;

    Process processCurrentIO = processIO.extractProcessIO(eventCurrent.getIdProcess());  //Determinate process IO to extract
    //Statistics IO
    timeAccumulatedIO += eventCurrent.getTime() - processCurrentIO.getClock();

    //Setting clock process
    processCurrentIO.setClock(eventCurrent.getTime());                                     //Switch clock of process

    //cout << "[Process IO]: " << endl;
    //processCurrentIO.printProcess();

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
        nextRP.validateRP(processCPU, eventCurrent.getTime());
        eventList.insertEvent(nextRP);                                         //Insert event RP in FEL
    }

    //Statistics final
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

        //cout << "Queue" << endl;
        //processQueue.printAllList();
        //cout << "List IO" << endl;
        //processIO.printAllList();
        /*cout << "Process CPU ";
        processCPU.printProcess();*/

        Event eventCurrent = eventList.extractEvent();


        file.Log(eventCurrent);

        if(eventCurrent.getTypeEvent() == "Arrival")
        {
            eventList.setNumEventArrival(eventList.getNumEventArrival()+1);                                                              //Increment number of arrival in the system
            Process arrivalProcess = Process(eventList.getNumEventArrival(), stdIn.getQuantum(), eventCurrent.getTime(), this->stdIn); //Create process arrival

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
