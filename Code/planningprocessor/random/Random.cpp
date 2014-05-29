#include "Random.h"

long Random::seed[STREAMS]={DEFAULT};
int Random::initialized =0;
int Random::stream = 0;

 
Random::Random(){
	
}

double Random::calcRandom(void){
	const long Q = MODULUS / MULTIPLIER;
  	const long R = MODULUS % MULTIPLIER;
    long t;

  	t = MULTIPLIER * (seed[stream] % Q) - R * (seed[stream] / Q);
  	if (t > 0) 
    	seed[stream] = t;
  	else 
    	seed[stream] = t + MODULUS;
  	return ((double) seed[stream] / MODULUS);
}


