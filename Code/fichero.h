#ifndef FICHERO_H_INCLUDED
#define FICHERO_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>

#include "estadistica.h"

using namespace std;

Estadistica obtenerEstadistica(string ficheroEntrada);
int validarFichero(char *fichero);
void escribirErrorBanderas();
void escribirErrorParametro();
void escribirErrorFichero();

#endif // FICHERO_H_INCLUDED
