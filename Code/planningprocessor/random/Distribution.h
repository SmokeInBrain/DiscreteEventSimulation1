#include "Random.h"
#include <math.h>
class Distribution{
private:
	double mu;
	double lambda;
	double var;
	double a;
	double b;
public:
	Distribution(double lambda);
	Distribution(double a, double b);
	Distribution();
	double getMu();
	double getVar();
	void setVar(double var);
	void setMu(double mu);
	double getLambda();
	void setLambda(double lambda);
	double getA();
	double getB();
	void setA(double a);
	void setB(double b);
	double uniform(double a, double b);
	double normal(double mu, double var);
	double exponential(double mu);
};
