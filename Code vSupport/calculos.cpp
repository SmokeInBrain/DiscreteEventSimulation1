#include <stdio.h>
#include <stdlib.h>

#include <iostream>
using namespace std;

float calcularTiempoIngreso(float tiempo, float desviacion)
{
    //cout<<"Tiempo: "<<tiempo<<"Desviacion: "<<desviacion<<"\n";
    float minimo = tiempo-desviacion;
    float maximo = tiempo+desviacion;

    float random = ((float) rand()) / (float) RAND_MAX;
    float rango = maximo - minimo;
    float variable = random * rango;

    return minimo + variable;
}

bool tipoProceso(int porcentajeTipo1)
{
    int numero;
    numero = rand()%100;
    if(numero<=porcentajeTipo1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void esperarProceso(float tiempo)
{

    int seg = tiempo;
    float dec = tiempo - seg;

    struct timespec tiempo1, tiempo2;
    tiempo1.tv_sec = seg;
    tiempo1.tv_nsec = dec * 1000 * 1000 * 1000;

    while (true)
    {
        if ( nanosleep(&tiempo1, &tiempo2) >= 0 )
            break;
    }

}

float tiempoProceso()
{
    clock_t tclock = clock();
    float time = tclock / (float)CLOCKS_PER_SEC;
    return time;
}
