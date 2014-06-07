#include <cstdlib>
#include <string>
#include "eda/StatisticsIn.h"

using namespace std;

//CONSTRUCTORES

StatisticsIn::StatisticsIn() {
	this->numproc=0;
	this->quantum=0.0;
	this->algorithm = "";
	this->interarrive="";
	this->interarriveInter[0]=0.0;
	this->interarriveInter[1]=0.0;
	this->service = "";
	this->serviceInter[0]=0.0;
	this->serviceInter[1]=0.0;
	this->RP="";
	this->RPInter[0]=0.0;
	this->RPInter[0]=0.0;
	this->RIO="";
	this->RIOInter[0]=0.0;
	this->RIOInter[1]=0.0;
}

StatisticsIn::StatisticsIn(int numproc, double quantum, string algorithm, string interarrive, string service, string RP, string RIO, double interarriveInter1, double interarriveInter2, double serviceInter1, double serviceInter2, double RPInter1, double RPInter2, double RIOInter1, double RIOInter2){
	this->numproc=numproc;
	this->quantum=quantum;
	this->algorithm = algorithm;
	this->interarrive=interarrive;
	this->interarriveInter[0]=interarriveInter1;
	this->interarriveInter[1]=interarriveInter2;
	this->service = service;
	this->serviceInter[0]=serviceInter1;
	this->serviceInter[1]=serviceInter2;
	this->RP=RP;
	this->RPInter[0]=RPInter1;
	this->RPInter[1]=RPInter2;
	this->RIO=RIO;
	this->RIOInter[0]=RIOInter1;
	this->RIOInter[1]=RIOInter2;
}
//GETTERS
int StatisticsIn::getNumProc(){
	return this->numproc;
}

string StatisticsIn::getAlgorithm(){
	return this->algorithm;
}

double StatisticsIn::getQuantum(){
	return this->quantum;
}

string StatisticsIn::getInterarrive(){
	return this->interarrive;
}

double* StatisticsIn::getInterarriveInter(){
	return this->interarriveInter;
}

string StatisticsIn::getService(){
	return this->service;
}

double* StatisticsIn::getServiceInter(){
	return this->serviceInter;
}

string StatisticsIn::getRP(){
	return this->RP;
}

double* StatisticsIn::getRPInter(){
	return this->RPInter;
}

string StatisticsIn::getRIO(){
	return this->RIO;
}

double* StatisticsIn::getRIOInter(){
	return this->RIOInter;
}


//SETTERS

void StatisticsIn::setNumProc(int numproc){
	this->numproc=numproc;
}

void StatisticsIn::setAlgorithm(string algorithm){
	this->algorithm=algorithm;
}

void StatisticsIn::setQuantum(double quantum){
	this->quantum=quantum;
}

void StatisticsIn::setInterarrive(string interarrive){
	this->interarrive=interarrive;
}

void StatisticsIn::setInterarriveInter(double interarrive1, double interarrive2){
	this->interarriveInter[0]=interarrive1;
	this->interarriveInter[1]=interarrive2;
}

void StatisticsIn::setService(string service){
	this->service=service;
}

void StatisticsIn::setServiceInter(double service1,double service2){
	this->serviceInter[0]=service1;
	this->serviceInter[1]=service2;
}

void StatisticsIn::setRP(string RP){
	this->RP=RP;
}

void StatisticsIn::setRPInter(double RP1, double RP2){
	this->RPInter[0]=RP1;
	this->RPInter[1]=RP2;
}

void StatisticsIn::setRIO(string RIO){
	this->RIO=RIO;
}

void StatisticsIn::setRIOInter(double RIO1, double RIO2){
	this->RIOInter[0]=RIO1;
	this->RIOInter[1]=RIO2;
}

