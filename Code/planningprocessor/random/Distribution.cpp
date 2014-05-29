#include <stdlib.h>
#include "Distribution.h"

Distribution::Distribution(Random randomNumber, double mu){
	this->randomNumber=randomNumber;
	this->mu=mu;
}

Distribution::Distribution(Random randomNumber, double a, double b){
	this->randomNumber=randomNumber;
	this->a=a;
	this->b=b;
}

Distribution::Distribution(){
	Random *p = &this->randomNumber;
	p=NULL;
	this->mu=0.0;
	this->a=0.0;
	this->b=0.0;
}

Random Distribution::getRandomNumber(){
	return this->randomNumber;
}

void Distribution::setRandomNumber(Random randomNumber){
	this->randomNumber=randomNumber;
}

double Distribution::getMu(){
	return this->mu;
}

void Distribution::setMu(double mu){
	this->mu=mu;
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
double uniform(double a, double b){
	double u = this->randomNumber;
	double result = a+((b-a)*u);
	return result;
}
double normal(){

}
double exponential(double mu){
	double u= this->randomNumber;
	double result = -mu*log(1-u); 
}