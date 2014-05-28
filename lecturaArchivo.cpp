#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include “lecturaArchivo.h”
using namespace std;

//CONSTRUCTOR

lecturaArchivo::lecturaArchivo(string nombreArchivo) {
	this->nombreArchivo=nombreArchivo;
	string nomAr = this->nombreArchivo;
	fstream ficheroEntrada;
	string lectura;
	ficheroEntrada.open(nomAr, ios::in);
	if(ficheroEntrada.is_open()){
		while(! ficheroEntrada.eof()){
			getline(ficheroEntrada,lectura);
			cout << "Leido: "<<frase<<endl;
		}
		ficheroEntrada.close();
	}else{
		cout <<"Error, el fichero no existe o no hay permisos para abrirlo"<<endl;
	}

}

