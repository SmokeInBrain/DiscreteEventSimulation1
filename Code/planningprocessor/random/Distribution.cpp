#include <stdlib.h>
#include "Distribution.h"

Distribution::Distribution(double lambda){
	this->lambda=lambda;
}

Distribution::Distribution(double a, double b){
	this->a=a;
	this->b=b;
}

Distribution::Distribution(){
	this->lambda=0.0;
	this->a=0.0;
	this->b=0.0;
}

double Distribution::getLambda(){
	return this->lambda;
}
void Distribution::setLambda(double lambda){
	this->lambda=lambda;
}

double Distribution::getA(){
	return this->a;
}
double Distribution::getB(){
	return this->b;
}
void Distribution::setA(double a){
	this->a=a;
}
void Distribution::setB(double b){
	this->b=b;
}
double Distribution::uniform(double a, double b){
	Random rand = Random();
 	double u  = rand.calcRandom();
	double result = a+((b-a)*u);
	return result;
}
double Distribution::normal(double mu, double desv){
	const double p0 = 0.322232431088;     const double q0 = 0.099348462606;
  	const double p1 = 1.0;                const double q1 = 0.588581570495;
  	const double p2 = 0.342242088547;     const double q2 = 0.531103462366;
  	const double p3 = 0.204231210245e-1;  const double q3 = 0.103537752850;
  	const double p4 = 0.453642210148e-4;  const double q4 = 0.385607006340e-2;
  	double u, t, p, q, z;
  	Random rand = Random();
 	u = rand.calcRandom();
  	if (u < 0.5)
    	t = sqrt(-2.0 * log(u));
  	else
    	t = sqrt(-2.0 * log(1.0 - u));
  	p   = p0 + t * (p1 + t * (p2 + t * (p3 + t * p4)));
  	q   = q0 + t * (q1 + t * (q2 + t * (q3 + t * q4)));
  	if (u < 0.5)
    	z = (p / q) - t;
  	else
    	z = t - (p / q);
  	return (mu + desv * z);
}



double Distribution::exponential(double lambda){
	Random rand = Random();
 	double u = rand.calcRandom();
	double result = -lambda*log(1.0-u);
	return result; 
}