#include "Random.h"
#include <math.h>
class Distribution{
private:
	Random randomNumber;
	double mu;
	double a;
	double b;
public:
	Distribution(Random randomNumber, double mu);
	Distribution(Random randomNumber, double a, double b);
	Distribution();
	Random getRandomNumber();
	void setRandomNumber(Random randomNumber);
	double getMu();
	void setMu(double mu);
	double getA();
	double getB();
	void setA(double a);
	void setB(double b);
	double uniform(double a, double b);
	double normal();
	double exponential(double mu);
};