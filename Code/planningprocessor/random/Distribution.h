#include "Random.h"
#include <math.h>

class Distribution{
private:
	Random random;
public:
	Distribution(Random random);
	Distribution();;
	double getLambda();
	void setLambda(double lambda);
	double getA();
	double getB();
	void setA(double a);
	void setB(double b);
	double uniform(double a, double b);
	double normal(double mu, double desv);
	double exponential(double lambda);
};


