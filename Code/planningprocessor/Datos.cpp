#include <stdlib.h>
#include <string>
#include "Datos.h"
using namespace std;

//CONSTRUCTORES

Datos::Datos() {
	this->numproc=0;
	this->quantum=0.0;
	this->algoritmo = "";
	this->interarrivo="";
	this->interarrivoInter[0]=0.0;
	this->interarrivoInter[1]=0.0;
	this->servicio = "";
	this->servicioInter[0]=0.0;
	this->servicioInter[1]=0.0;
	this->RP="";
	this->RPInter[0]=0.0;
	this->RPInter[0]=0.0;
	this->RIO="";
	this->RIOInter[0]=0.0;
	this->RIOInter[1]=0.0;
}

Datos::Datos(int numproc, double quantum, string algoritmo, string interarrivo, string servicio, string RP, string RIO, double interarrivoInter1, double interarrivoInter2, double servicioInter1, double servicioInter2, double RPInter1, double RPInter2, double RIOInter1, double RIOInter2){
	this->numproc=numproc;
	this->quantum=quantum;
	this->algoritmo = algoritmo;
	this->interarrivo=interarrivo;
	this->interarrivoInter[0]=interarrivoInter1;
	this->interarrivoInter[1]=interarrivoInter2;
	this->servicio = servicio;
	this->servicioInter[0]=servicioInter1;
	this->servicioInter[1]=servicioInter2;
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

string Datos::getAlgoritmo(){
	return this->algoritmo;
}

double Datos::getQuantum(){
	return this->quantum;
}

string Datos::getInterarrivo(){
	return this->interarrivo;
}

double* Datos::getInterarrivoInter(){
	return this->interarrivoInter;
}

string Datos::getServicio(){
	return this->servicio;
}

double* Datos::getServicioInter(){
	return this->servicioInter;
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

void Datos::setAlgoritmo(string algoritmo){
	this->algoritmo=algoritmo;
}

void Datos::setQuantum(double quantum){
	this->quantum=quantum;
}

void Datos::setInterarrivo(string interarrivo){
	this->interarrivo=interarrivo;
}

void Datos::setInterarrivoInter(double interarrivo1, double interarrivo2){
	this->interarrivoInter[0]=interarrivo1;
	this->interarrivoInter[1]=interarrivo2;
}

void Datos::setServicio(string servicio){
	this->servicio=servicio;
}

void Datos::setServicioInter(double servicio1,double servicio2){
	this->servicioInter[0]=servicio1;
	this->servicioInter[1]=servicio2;
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

