#include <vector/VectorEvent.h>

VectorEvent::VectorEvent() {}

void VectorEvent::insertEvent(Event process) {
    listEvent.push_back(elProceso);
}

Event VectorEvent::extractEvent() {
    Event extractEvent = listEvent[0];
    listaEvent.erase( listaEvent.begin() );

    return extractEvent;
}


void VectorEvent::printAllList() {

    for (unsigned int i = 0; i < listEvent.size(); i++)
        cout << "[" << i << "]: ID: " << listEvent[i].ID << " Tipo: " << listEvent[i].tipo << " TpoPro: " << listEvent[i].tiempoProcesador << " TpoIO: " << listEvent[i].tiempoIO << "\n";
    cout << "\n";
}
