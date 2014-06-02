#include <stdlib.h>
#include <string>
#include <eda/StadisticsIn.h>
using namespace std;

//CONSTRUCTORES

StadisticsIn::StadisticsIn() {
	this->numproc=0;
	this->quantum=0.0;h
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

StadisticsIn::StadisticsIn(int numproc, double quantum, string algorithm, string interarrive, string service, string RP, string RIO, double interarriveInter1, double interarriveInter2, double serviceInter1, double serviceInter2, double RPInter1, double RPInter2, double RIOInter1, double RIOInter2){
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
int StadisticsIn::getNumProc(){
	return this->numproc;
}

string StadisticsIn::getAlgorithm(){
	return this->algorithm;
}

double StadisticsIn::getQuantum(){
	return this->quantum;
}

string StadisticsIn::getInterarrive(){
	return this->interarrive;
}

double* StadisticsIn::getInterarriveInter(){
	return this->interarriveInter;
}

string StadisticsIn::getService(){
	return this->service;
}

double* StadisticsIn::getServiceInter(){
	return this->serviceInter;
}

string StadisticsIn::getRP(){
	return this->RP;
}

double* StadisticsIn::getRPInter(){
	return this->RPInter;
}

string StadisticsIn::getRIO(){
	return this->RIO;
}

double* StadisticsIn::getRIOInter(){
	return this->RIOInter;
}


//SETTERS

void StadisticsIn::setNumProc(int numproc){
	this->numproc=numproc;
}

void StadisticsIn::setAlgorithm(string algorithm){
	this->algorithm=algorithm;
}

void StadisticsIn::setQuantum(double quantum){
	this->quantum=quantum;
}

void StadisticsIn::setInterarrive(string interarrive){
	this->interarrive=interarrive;
}

void StadisticsIn::setInterarriveInter(double interarrive1, double interarrive2){
	this->interarriveInter[0]=interarrive1;
	this->interarriveInter[1]=interarrive2;
}

void StadisticsIn::setService(string service){
	this->service=service;
}

void StadisticsIn::setServiceInter(double service1,double service2){
	this->serviceInter[0]=service1;
	this->serviceInter[1]=service2;
}

void StadisticsIn::setRP(string RP){
	this->RP=RP;
}

void StadisticsIn::setRPInter(double RP1, double RP2){
	this->RPInter[0]=RP1;
	this->RPInter[1]=RP2;
}

void StadisticsIn::setRIO(string RIO){
	this->RIO=RIO;
}

void StadisticsIn::setRIOInter(double RIO1, double RIO2){
	this->RIOInter[0]=RIO1;
	this->RIOInter[1]=RIO2;
}

