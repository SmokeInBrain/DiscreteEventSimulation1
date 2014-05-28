#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <vector>

#include "hebras.h"
#include "fichero.h"
#include "estadistica.h"

int main(int argc, char **argv)
{
     // Obtener datos con "GetOpt".

    int banderaI = 0;
    int banderaO = 0;
    int banderaE = 0;

    char *archivoI = NULL;
    char *archivoO = NULL;

    opterr = 0;

    int valor;
    while ( (valor = getopt(argc, argv, "i:o:")) != -1  ) {

        switch (valor) {
            case 'i':
                banderaI = 1;
                archivoI = optarg;
                break;

            case 'o':
                banderaO = 1;
                archivoO = optarg;
                break;

            default:
                banderaE = 1;
                break;
        }

    }

    if ((!banderaI)||(banderaE)){
            escribirErrorBanderas();
            return 0;
    }

    if(banderaE){
        escribirErrorBanderas();
        return 0;
    }

    if (!banderaO){
        archivoO = "estadisticasHebras.out";
    }

    if(!validarEntrada(archivoI,archivoO,datoP)){
        escribirErrorParametro();
        return 0;
    }

    if(!validarFichero(archivoI)){
        escribirErrorFichero();
        return 0;
    }

    Estadistica datosEstadisticos = obtenerEstadistica(archivoI);

    hebras(archivoO, datosEstadisticos);

    return 0;
}
