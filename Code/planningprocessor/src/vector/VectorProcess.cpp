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

void VectorProcess::insertProcess(Process process)
{

    if (typePriority == "FCFS")
        listProcess.push_back(process);

    else if (typePriority == "STF")
    {

        int position = 0;
        for (unsigned int i = 0; i < listProcess.size(); i++)
        {
            if (listProcess[i].timeProcessor < process.timeProcessing)
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
    Process extractProcessIO = listProcess[id];
    listProcess.erase( listProcess.begin() + id );

    return extractProcessIO;
}


void VectorProcess::printAllList()
{

    for (unsigned int i = 0; i < listProcess.size(); i++)
        cout << "[" << i << "]: ID: " << listProcess[i].id << " Clock: " << listProcess[i].clock << " TimeProcessor: " << listProcess[i].timeProcessor << " TimeProcessing: " << listProcess[i].timeProcessing << " Quantum: " << listProcess[i].quantum << "\n";
    cout << "\n";
}
