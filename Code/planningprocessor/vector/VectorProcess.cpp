#include <vector/VectorProcess.h>

VectorProcess::VectorProcess(int largeMax, string typePriority) {

    this->typePriority = typePriority;
    this->largeMax = largeMax;

}

void VectorProcess::insertProcess(Process process) {

    if (tipoPrioridad == "FCFS")
        listProcess.push_back(elProceso);

    else if (tipoPrioridad == "SPN") {

        int pos = 0;
        for (unsigned int i = 0; i < listProcess.size(); i++) {
            if (listProcess[i].timeProcess < elProceso.timeProcessing)
                posicion++;
        }

        listProcess.insert( listProcess.begin() + posicion, elProceso);
    }

}

Process VectorProcess::extractProcess() {
    Process extractProcess = listProcess[0];
    listaProcess.erase( listaProcess.begin() );

    return extractProcess;
}


void VectorProcess::printAllList() {

    for (unsigned int i = 0; i < listProcess.size(); i++)
        cout << "[" << i << "]: ID: " << listProcess[i].ID << " Tipo: " << listProcess[i].tipo << " TpoPro: " << listProcess[i].tiempoProcesador << " TpoIO: " << listProcess[i].tiempoIO << "\n";
    cout << "\n";
}
