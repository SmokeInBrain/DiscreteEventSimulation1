#include "Random.h"
#include <stdio.h>

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

void Random::plantSeeds(long x){
	const long Q = MODULUS / A256;
 	const long R = MODULUS % A256;
    int  j;
    int  s;
	initialized = 1;
  	s = stream;                            /* remember the current stream */
  	selectStream(0);                       /* change to stream 0          */
  	putSeed(x);                            /* set seed[0]                 */
  	stream = s;                            /* reset the current stream    */
  	for (j = 1; j < STREAMS; j++) {
    	x = A256 * (seed[j - 1] % Q) - R * (seed[j - 1] / Q);
    if (x > 0)
      seed[j] = x;
    else
      seed[j] = x + MODULUS;
   }
}

void Random::putSeed(long x){
	char ok = 0;
   	x = x % MODULUS;                       
  	seed[stream] = x;
}

void Random::getSeed(long *x){
  *x = seed[stream];
}

void Random::selectStream(int index){
  stream = ((unsigned int) index) % STREAMS;
  if ((initialized == 0) && (stream != 0))   
    plantSeeds(DEFAULT);                     
}


