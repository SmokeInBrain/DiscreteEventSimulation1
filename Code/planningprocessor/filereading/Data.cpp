#include <stdlib.h>
#include <string>
#include "Data.h"
using namespace std;

//CONSTRUCTORES

Datos::Datos() {
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

Datos::Datos(int numproc, double quantum, string algorithm, string interarrive, string service, string RP, string RIO, double interarriveInter1, double interarriveInter2, double serviceInter1, double serviceInter2, double RPInter1, double RPInter2, double RIOInter1, double RIOInter2){
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
int Datos::getNumProc(){
	return this->numproc;
}

string Datos::getalgorithm(){
	return this->algorithm;
}

double Datos::getQuantum(){
	return this->quantum;
}

string Datos::getinterarrive(){
	return this->interarrive;
}

double* Datos::getinterarriveInter(){
	return this->interarriveInter;
}

string Datos::getservice(){
	return this->service;
}

double* Datos::getserviceInter(){
	return this->serviceInter;
}

string Datos::getRP(){
	return this->RP;
}

double* Datos::getRPInter(){
	return this->RPInter;
}

string Datos::getRIO(){
	return this->RIO;
}

double* Datos::getRIOInter(){
	return this->RIOInter;
}


//SETTERS

void Datos::setNumProc(int numproc){
	this->numproc=numproc;
}

void Datos::setalgorithm(string algorithm){
	this->algorithm=algorithm;
}

void Datos::setQuantum(double quantum){
	this->quantum=quantum;
}

void Datos::setinterarrive(string interarrive){
	this->interarrive=interarrive;
}

void Datos::setinterarriveInter(double interarrive1, double interarrive2){
	this->interarriveInter[0]=interarrive1;
	this->interarriveInter[1]=interarrive2;
}

void Datos::setservice(string service){
	this->service=service;
}

void Datos::setserviceInter(double service1,double service2){
	this->serviceInter[0]=service1;
	this->serviceInter[1]=service2;
}

void Datos::setRP(string RP){
	this->RP=RP;
}

void Datos::setRPInter(double RP1, double RP2){
	this->RPInter[0]=RP1;
	this->RPInter[1]=RP2;
}

void Datos::setRIO(string RIO){
	this->RIO=RIO;
}

void Datos::setRIOInter(double RIO1, double RIO2){
	this->RIOInter[0]=RIO1;
	this->RIOInter[1]=RIO2;
}

