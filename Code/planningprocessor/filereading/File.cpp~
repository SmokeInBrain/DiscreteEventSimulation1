#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "File.h"

//CONSTRUCTORES
File::File(Data data, string name){
	this->data= Data();
	this->data = data;
	this->name=name;
}

File::File() {
	Data *p = &this->data;
	p=NULL;
	this->name="";
}
//GETTERS
Data File::getData(){
	return this->data;
}

string File::getName(){
	return this->name;
}


//SETTERS

void File::setData(Data data){
	this->data=data;
}

void File::setName(string name){
	this->name=name;
}

//METODOS
void File::read(){
	string fileName= this->name;
	int numproc=0;
	double quantum=0.0;
	string algorithm="";
	string interarrive="";
	double interarriveInter1=0.0;
	double interarriveInter2=0.0;
	string service="";
	double serviceInter1=0.0;
	double serviceInter2=0.0;
	string RP="";
	double RPInter1=0.0;
	double RPInter2=0.0; 
	string RIO="";
	double RIOInter1=0.0;
	double RIOInter2=0.0;
	string s;
	string garbage="";
	ifstream inputFile;
	inputFile.open(fileName.c_str());
	if(inputFile.is_open()){
		
		inputFile >> s >> garbage;
		inputFile >> s >> numproc;
		inputFile >> s >> garbage;
		inputFile >> s >> algorithm;
		if(algorithm=="RR"){
			inputFile >> s >> quantum;
		}
		inputFile >> s >> garbage;
		inputFile >> s >> interarrive;
		//VER TEMA DE SI ES INTERVALO O NO!
		inputFile >> s >> interarriveInter1;
		if(interarrive=="uniforme"){
			inputFile >> s >> interarriveInter2;
		}
		inputFile >> s >> garbage;
		inputFile >> s >> service;
		inputFile >> s >> serviceInter1;
		if(service=="uniforme"){
			inputFile >> s >> serviceInter2;
		}
		inputFile >> s >> garbage;
		inputFile >> s >> RP;
		inputFile >> s >> RPInter1;
		if(RP=="uniforme" || RP=="normal"){
			inputFile >> s >> RPInter2;
		}
		inputFile >> s >> garbage;
		inputFile >> s >> RIO;
		inputFile >> s >> RIOInter1;
		if(RIO=="uniforme"){
			inputFile >> s >> RIOInter2;
		}
		
		inputFile.close();
	}else{
		cout <<"Error, el fichero no existe o no hay permisos para abrirlo"<<endl;
	}

	Data inputData=Data(numproc, quantum, algorithm, interarrive, service, RP, RIO, interarriveInter1, interarriveInter2, serviceInter1, serviceInter2, RPInter1, RPInter2, RIOInter1, RIOInter2);
	this->data=inputData;

}

void writeOutput(){

}

void writeLog(){

}
