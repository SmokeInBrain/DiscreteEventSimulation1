#ifndef HEBRAS_H_INCLUDED
#define HEBRAS_H_INCLUDED

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <vector>
#include <math.h>

#include "calculos.h"
#include "Procesos.h"
#include "estadistica.h"

using namespace std;

void *crearProcesos(void *arg);
void *procesarProcesos(void *arg);
void *procesarIO1(void *arg);
void *procesarIO2(void *arg);
void hebras(char *ficheroSalida, Estadistica datos);
float mediaProceso(vector<Procesos> datos, int tipo);
float desviacionProcesos(vector<Procesos> datos, int tipo);
void imprimirEstadisticas(string fichero);

#endif // HEBRAS_H_INCLUDED
