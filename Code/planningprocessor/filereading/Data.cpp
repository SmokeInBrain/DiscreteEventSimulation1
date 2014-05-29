#include <stdlib.h>
#include <string>
#include "Data.h"
using namespace std;

//CONSTRUCTORES

Data::Data() {
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

Data::Data(int numproc, double quantum, string algorithm, string interarrive, string service, string RP, string RIO, double interarriveInter1, double interarriveInter2, double serviceInter1, double serviceInter2, double RPInter1, double RPInter2, double RIOInter1, double RIOInter2){
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
int Data::getNumProc(){
	return this->numproc;
}

string Data::getAlgorithm(){
	return this->algorithm;
}

double Data::getQuantum(){
	return this->quantum;
}

string Data::getInterarrive(){
	return this->interarrive;
}

double* Data::getInterarriveInter(){
	return this->interarriveInter;
}

string Data::getService(){
	return this->service;
}

double* Data::getServiceInter(){
	return this->serviceInter;
}

string Data::getRP(){
	return this->RP;
}

double* Data::getRPInter(){
	return this->RPInter;
}

string Data::getRIO(){
	return this->RIO;
}

double* Data::getRIOInter(){
	return this->RIOInter;
}


//SETTERS

void Data::setNumProc(int numproc){
	this->numproc=numproc;
}

void Data::setAlgorithm(string algorithm){
	this->algorithm=algorithm;
}

void Data::setQuantum(double quantum){
	this->quantum=quantum;
}

void Data::setInterarrive(string interarrive){
	this->interarrive=interarrive;
}

void Data::setInterarriveInter(double interarrive1, double interarrive2){
	this->interarriveInter[0]=interarrive1;
	this->interarriveInter[1]=interarrive2;
}

void Data::setService(string service){
	this->service=service;
}

void Data::setServiceInter(double service1,double service2){
	this->serviceInter[0]=service1;
	this->serviceInter[1]=service2;
}

void Data::setRP(string RP){
	this->RP=RP;
}

void Data::setRPInter(double RP1, double RP2){
	this->RPInter[0]=RP1;
	this->RPInter[1]=RP2;
}

void Data::setRIO(string RIO){
	this->RIO=RIO;
}

void Data::setRIOInter(double RIO1, double RIO2){
	this->RIOInter[0]=RIO1;
	this->RIOInter[1]=RIO2;
}

