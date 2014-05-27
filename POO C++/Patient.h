#include “Virus.h”
#define MAX_VIRUS_POP 1000
class Patient {
Virus* virusPop[MAX_VIRUS_POP];

int numVirusCells;

float immunity;
// degree of immunity, in %

public:
Patient(float initImmunity, int initNumViruses);////CONSTRUCTOR
~Patient();/////DESTRUCTOR
void takeDrug();
bool simulateStep();
};
/////////// LLAMANDO AL CONSTRUCTOR///////////////
int main() {
float initImmunity = 0.1;
int initNumVirusCells = 5;
Patient p(0.1, 5);
p.takeDrug();
}