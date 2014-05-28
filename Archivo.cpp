#include "Archivo.h"
//CONSTRUCTORES
Archivo::Archivo(Datos dato, string nombre){
	this->dato=dato;
	this->nombre=nombre;
}

Archivo::Archivo() {
	this->dato=NULL;
	this->nombre="";
}
//GETTERS
Datos getDato(){
	return this->dato;
}

string getNombre(){
	return this->nombre;
}


//SETTERS

void setDato(Datos dato){
	this->dato=dato;
}

void setNombre(string nombre){
	this->nombre=nombre;
}

//METODOS
void lectura(){
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
	double RIOInter1="";
	double RIOInter2="";
	string l;
	string basura;
	ficheroEntrada.open(nombreArchivo, ios::in);
	if(ficheroEntrada.is_open()){
		ficheroEntrada << l << basura;
		ficheroEntrada << l << numproc;
		ficheroEntrada << l << basura;
		ficheroEntrada << l << algoritmo;
		if(algoritmo=="RR"){
			ficheroEntrada << l << quantum;
		}
		ficheroEntrada << l << basura;
		ficheroEntrada << l << interarrivo;
		//VER TEMA DE SI ES INTERVALO O NO!
		ficheroEntrada << l << interarrivoInter1;
		if(interarrivo=="uniforme"){
			ficheroEntrada << l << interarrivoInter2;
		}
		ficheroEntrada << l << basura;
		ficheroEntrada << l << servicio;
		ficheroEntrada << l << servicioInter1;
		if(servicio="uniforme"){
			ficheroEntrada << l << servicioInter2;
		}
		ficheroEntrada << l << basura;
		ficheroEntrada << l << RP;
		ficheroEntrada << l << RPInter1;
		if(RP=="uniforme" || RP=="normal"){
			ficheroEntrada << l << RPInter2;
		}
		ficheroEntrada << l << basura;
		ficheroEntrada << l << RIO;
		ficheroEntrada << l << RIOInter1;
		if(RIO=="uniforme"){
			ficheroEntrada << l << RIOInter2;
		}
		ficheroEntrada.close();
	}else{
		cout <<"Error, el fichero no existe o no hay permisos para abrirlo"<<endl;
	}

	Datos datosEntrada=new Datos(numproc, quantum, algoritmo, interarrivo, servicio, RP, RIO, interarrivoInter1, interarrivoInter2, servicioInter1, servicioInter2, RPInter1, RPInter2, RIOInter1, RIOInter2);
	this->dato=datosEntrada;

}

void escrituraSalida(){

}

void escrituraLog(){

}
