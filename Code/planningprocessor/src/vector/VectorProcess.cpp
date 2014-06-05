#include "vector/VectorProcess.h"

VectorProcess::VectorProcess()
{

    this->typePriority = "";
    this->largeMax = 0;

}

VectorProcess::VectorProcess(int largeMax, string typePriority)
{

    this->typePriority = typePriority;
    this->largeMax = largeMax;

}

//Getters
int VectorProcess::getLargeMax(){
    return this->largeMax;
}
vector <Process> VectorProcess::getListProcess(){
    return this->listProcess;
}
string VectorProcess::getTypePriority(){
    return this->typePriority;

}
//Setters
void VectorProcess::setLargeMax(int largeMax){
    this->largeMax=largeMax;
}
void VectorProcess::setListProcess(vector <Process> listProcess){
    this->listProcess=listProcess;
}
void VectorProcess::setTypePriority(string typePriority){
    this->typePriority=typePriority;
}

void VectorProcess::insertProcess(Process process)
{

    if (typePriority == "FCFS")
        listProcess.push_back(process);

    else if (typePriority == "STF")
    {

        int position = 0;
        for (unsigned int i = 0; i < listProcess.size(); i++)
        {
            if (listProcess[i].getTimeProcessor() < process.getTimeProcessing())
                position++;
        }

        listProcess.insert( listProcess.begin() + position, process);
    }

    else if (typePriority == "RR")
        listProcess.push_back(process);
}

Process VectorProcess::extractProcess()
{
    Process extractProcess = listProcess[0];
    listProcess.erase( listProcess.begin() );

    return extractProcess;
}

Process VectorProcess::extractProcessIO(int id)
{
    int i;

    for (i = 0; i < listProcess.size(); i++)
    {
        if (listProcess[i].getId() == id)
            break;
    }

    Process extractProcessIO = listProcess[i];
    listProcess.erase( listProcess.begin() + i );

    return extractProcessIO;
}


void VectorProcess::printAllList()
{

    for (unsigned int i = 0; i < listProcess.size(); i++)
        cout << "[" << i << "]: ID: " << listProcess[i].getId() << " Clock: " << listProcess[i].getClock() << " TimeProcessor: " << listProcess[i].getTimeProcessor() << " TimeProcessing: " << listProcess[i].getTimeProcessing() << " Quantum: " << listProcess[i].getQuantum() << "\n";
    cout << "\n";
}
