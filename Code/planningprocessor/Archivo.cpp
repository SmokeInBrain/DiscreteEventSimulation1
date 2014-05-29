#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "Archivo.h"

//CONSTRUCTORES
Archivo::Archivo(Datos dato, string nombre){
	this->dato= Datos();
	this->dato = dato;
	this->nombre=nombre;
}

Archivo::Archivo() {
	Datos *p = &this->dato;
	p=NULL;
	this->nombre="";
}
//GETTERS
Datos Archivo::getDato(){
	return this->dato;
}

string Archivo::getNombre(){
	return this->nombre;
}


//SETTERS

void Archivo::setDato(Datos dato){
	this->dato=dato;
}

void Archivo::setNombre(string nombre){
	this->nombre=nombre;
}

//METODOS
void Archivo::lectura(){
	string nombreArchivo = this->nombre;
	int numproc=0;
	double quantum=0.0;
	string algoritmo="";
	string interarrivo="";
	double interarrivoInter1=0.0;
	double interarrivoInter2=0.0;
	string servicio="";
	double servicioInter1=0.0;
	double servicioInter2=0.0;
	string RP="";
	double RPInter1=0.0;
	double RPInter2=0.0; 
	string RIO="";
	double RIOInter1=0.0;
	double RIOInter2=0.0;
	string s;
	string basura="";
	ifstream ficheroEntrada;
	ficheroEntrada.open(nombreArchivo.c_str());
	if(ficheroEntrada.is_open()){
		
		ficheroEntrada >> s >> basura;
		ficheroEntrada >> s >> numproc;
		ficheroEntrada >> s >> basura;
		ficheroEntrada >> s >> algoritmo;
		if(algoritmo=="RR"){
			ficheroEntrada >> s >> quantum;
		}
		ficheroEntrada >> s >> basura;
		ficheroEntrada >> s >> interarrivo;
		//VER TEMA DE SI ES INTERVALO O NO!
		ficheroEntrada >> s >> interarrivoInter1;
		if(interarrivo=="uniforme"){
			ficheroEntrada >> s >> interarrivoInter2;
		}
		ficheroEntrada >> s >> basura;
		ficheroEntrada >> s >> servicio;
		ficheroEntrada >> s >> servicioInter1;
		if(servicio=="uniforme"){
			ficheroEntrada >> s >> servicioInter2;
		}
		ficheroEntrada >> s >> basura;
		ficheroEntrada >> s >> RP;
		ficheroEntrada >> s >> RPInter1;
		if(RP=="uniforme" || RP=="normal"){
			ficheroEntrada >> s >> RPInter2;
		}
		ficheroEntrada >> s >> basura;
		ficheroEntrada >> s >> RIO;
		ficheroEntrada >> s >> RIOInter1;
		if(RIO=="uniforme"){
			ficheroEntrada >> s >> RIOInter2;
		}
		
		ficheroEntrada.close();
	}else{
		cout <<"Error, el fichero no existe o no hay permisos para abrirlo"<<endl;
	}

	Datos datosEntrada=Datos(numproc, quantum, algoritmo, interarrivo, servicio, RP, RIO, interarrivoInter1, interarrivoInter2, servicioInter1, servicioInter2, RPInter1, RPInter2, RIOInter1, RIOInter2);
	this->dato=datosEntrada;

}

void escrituraSalida(){

}

void escrituraLog(){

}
