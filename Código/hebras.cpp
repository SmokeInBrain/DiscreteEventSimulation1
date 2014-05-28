#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <vector>

#include "hebras.h"
#include "estadistica.h"

//Variables globales
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
vector<proceso> colaProcesos, colaIO, colaFinalizados;
int procesosTerminados = 0;
Estadistica estadisticas;

//Funcion para crear procesos y luego que sean procesados por el procesador
void crearProcesos(void *args){

}

//Funcion para poder procesar los procesos en el procesador
void procesarProcesos(void *args){

}

//Funcion para poder procesar los procesos en el IO de tipo 1
void procesarIO1(void *args){

}

//Funcion para poder procesar los procesos en el IO de tipo 2
void procesarIO2(void *args){

}

void hebras(char *ficheroSalida, Estadistica datos)
{
    estadisticas = datos;   //Guardar los datos en la variable global

    pthread_t generador, procesador, IO1, IO2;      //Declaracion de las hebras

    pthread_create(&generador, NULL, crearProcesos, NULL);      //Crear hebra para crear Procesos
    pthread_create(&procesador, NULL, procesarProcesos, NULL);  //Crear hebra para procesar procesos
    pthread_create(&IO1, NULL, procesarIO1, NULL);              //Crear hebra para procesar segun IO1
    pthread_create(&IO2, NULL, procesarIO2, NULL);              //Crear hebra para procesar segun IO2

    pthread_join(generador, NULL);
    pthread_join(procesador, NULL);
    pthread_join(IO1, NULL);
    pthread_join(IO2, NULL);
}
