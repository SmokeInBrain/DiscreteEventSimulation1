#<stdlib.h>
#include “Patient.h”

Patient::Patient(float initImmunity, int initNumVirusCells) {
	float resistance;
	immunity = initImmunity;
	for (int i = 0; i < initNumVirusCells; i++) {
	//randomly generate resistance, between 0.0 and 1.0
	resistance = (float) rand()/RAND_MAX;
	virusPop[i] = new Virus(resistance);
	}
	numVirusCells = initNumVirusCells;
}

bool Patient::simulateStep() {
	Virus* virus;
	bool survived = false;
	for (int i = 0; i < numVirusCells; i++){
		virus = virusPop[i];
		survived = virus->survive(immunity);
		int a=0;///CUALQUIER COSA
		if (survived) {
			a=1;
		} else {
			a=-1;
		}
	}
}

Patient::~Patient(){
	for (int i = 0; i < numVirusCells; i++){
	delete virusPop[i];
	}
}