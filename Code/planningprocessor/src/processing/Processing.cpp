#include "processing/Processing.h"

Processing::Processing(StatisticsIn stdIn)
{
    //Initialize Statistics
    this->stdIn = stdIn;

    //Initialize clock of the system
    clock = 0;

    //Initialize condition of the system
    largeQueue = 0;
    condProcessCPU = true;

    //Initialize list in the system

    processQueue = VectorProcess(stdIn.getNumProc(), stdIn.getAlgorithm());

    Process firstProcess = Process(1, stdIn.getQuantum(), clock);
    processCPU = firstProcess;

    processIO = VectorProcess(stdIn.getNumProc(), "FCFS");

    //Initialize FEL
    eventList = VectorEvent();

    //Initialize first RP
    Event firstEventRP = Event("RP", 1, stdIn, clock);
    eventList.insertEvent(firstEventRP);

    //Initialize second Arrival
    Event secondEventArrival = Event("Arrival", 2, stdIn, clock);
    eventList.numEventArrival = 2;

    //Initialize statistics
    timeAccumulatedQueue = 0;
    timeAccumulatedCPU = 0;
    timeAccumulatedIO = 0;

    largeAccumulatedQueue = 0;
    maxLargeQueue = 0;

    processFinish = 0;

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
        Event nextRP = Event("RP", eventCurrent.idProcess, stdIn, eventCurrent.time);      //Create next RP in the system
        eventList.insertEvent(nextRP);                                         //Insert event RP in FEL
    }

    //Generate next arrival
    if(eventList.numEventArrival < stdIn.getNumProc())                        //Condition: The system can't generate more arrival for maximum case of process arrival
    {
        Event nextArrival = Event("Arrival", eventList.numEventArrival, stdIn, clock);   //Create next arrival
        eventList.insertEvent(nextArrival);     //And insert in the FEL
    }

    //Statistics
    if(maxLargeQueue < largeQueue)
        maxLargeQueue = largeQueue;

    //Return clock
    return eventCurrent.time;
}

int Processing::activityProcessCPU(Event eventCurrent)
{
    int timeProcessCPU;
    int timeRP = eventCurrent.time - clock;

    Process processAnalyzed = processCPU;

    if(largeQueue != 0)
    {
        //Reduce queue
        largeQueue--;

        //Generate RP for the first process in the queue
        Process processFirstQueue = processQueue.extractProcess();
        processCPU = processFirstQueue;
        processCPU.clock = eventCurrent.time;
        Event nextRP = Event("RP", processFirstQueue.id, stdIn, eventCurrent.time);

        //Statistics
        timeAccumulatedQueue = processCPU.clock - processFirstQueue.clock;
    }
    else
    {
        //Empty CPU
        condProcessCPU = false;
        processCPU = Process();
    }

    //Increment processing time of the analyzed process
    processAnalyzed.timeProcessing += (eventCurrent.time - clock);

    if(processAnalyzed.timeProcessor <= processAnalyzed.timeProcessing)     //If this process has not more time of processing, it finish
    {
        timeProcessCPU = timeRP - (processAnalyzed.timeProcessing - processAnalyzed.timeProcessor);
        processFinish++;                                                    //Increment number of process finish

        if(processFinish == stdIn.getNumProc())
        {
            Event eventFinal = Event("Final", 0, stdIn, eventCurrent.time);
            eventList.insertEvent(eventFinal);
        }
    }
    else if(processQueue.typePriority ==  "RR")                             //If the queue is Round-Robin, then it is necessary analyzed its quantum
    {
        if( processAnalyzed.quantum < timeRP)                              //If the quantum is minor to the time processing in CPU
        {
            processAnalyzed.clock = eventCurrent.time;                      //Switch clock of process
            processQueue.insertProcess(processAnalyzed);                    //Insert process in queue

            largeQueue++;                                                   //Increment queue
            if(maxLargeQueue < largeQueue)                                  //Statistics queue
                maxLargeQueue = largeQueue;

            timeProcessCPU = processAnalyzed.quantum;
        }
        else
        {
            processIO.insertProcess(processAnalyzed);                       //Else, this process insert list IO
            Event eventRIO = Event("RIO", processAnalyzed.id, stdIn, eventCurrent.time);
            eventList.insertEvent(eventRIO);

            timeProcessCPU = timeRP;
        }
    }
    else
    {
        processIO.insertProcess(processAnalyzed);                           //Else, this process insert list IO
        Event eventRIO = Event("RIO", processAnalyzed.id, stdIn, eventCurrent.time);
        eventList.insertEvent(eventRIO);

        timeProcessCPU = timeRP;
    }

    //Statistics
    timeAccumulatedCPU += timeProcessCPU;

    return eventCurrent.time;
}

int Processing::activityProcessIO(Event eventCurrent)
{
    Process processCurrentIO = processIO.extractProcessIO(eventCurrent.idProcess);  //Determinate process IO to extract
    processCurrentIO.clock = eventCurrent.time;                                     //Switch clock of process
    processQueue.insertProcess(processCurrentIO);                                   //Insert process IO in the queue

    //Statistics
    timeAccumulatedIO += (eventCurrent.time - clock);

    largeQueue++;
    if(maxLargeQueue < largeQueue)
        maxLargeQueue = largeQueue;

    //Return time
    return eventCurrent.time;
}

bool Processing::planificationProcess()
{

    while(true)
    {

        Event eventCurrent = eventList.extractEvent();

        if(eventCurrent.typeEvent == "Arrival")
        {
            Process arrivalProcess(eventList.numEventArrival, stdIn.getQuantum(), eventCurrent.time); //Create process arrival
            eventList.numEventArrival++;                                                //Increment number of arrival in the system
            clock = activityArrivalProcess(eventCurrent, arrivalProcess);
        }
        else if(eventCurrent.typeEvent == "RP")
        {
            clock = activityProcessCPU(eventCurrent);
        }
        else if(eventCurrent.typeEvent == "RIO")
        {
            clock = activityProcessIO(eventCurrent);
        }
        else if(eventCurrent.typeEvent == "Final")
        {
            return true;
        }

    }

    return false;
}
