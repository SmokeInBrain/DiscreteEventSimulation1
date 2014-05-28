#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int calcularTiempoIngreso(int tiempo, int desviacion)
{
    int tiempo;
    srand(time(NULL));
    return tiempo = (desviacion-tiempo) + (rand()%(2*desviacion));
}

bool tipoProceso(int porcentajeTipo1)
{
    int numero;
    srand(time(NULL));
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

bool binario()
{
    int tipo;
    srand(time(NULL));
    tipo = rand()%2;
    if(tipo==0)
    {
        return false;
    }
    else
    {
        return true;
    }
}
