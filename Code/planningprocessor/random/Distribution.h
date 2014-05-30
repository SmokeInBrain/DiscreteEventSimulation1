#include "Random.h"
#include <math.h>

class Distribution{
private:
	Random random;
public:
	Distribution(Random random);
	Distribution();
	Random getRandom();
	void setRandom(Random random);
	double uniform(double a, double b);
	double normal(double mu, double desv);
	double exponential(double lambda);
};


