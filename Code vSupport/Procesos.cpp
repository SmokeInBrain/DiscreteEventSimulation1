#include "Procesos.h"

Procesos::Procesos(int tipo, int identificador, Estadistica datos)
{
    //Datos
    this->identificador = identificador;
    //Inicializacion de estadisticas
    timeProcesado=0;

    if(tipo==1){
        timeProcesador = calcularTiempoIngreso(datos.tiempoPromedioProcesosP1, datos.desviacionEstandarTiempoProcesosP1);
        timeIO = calcularTiempoIngreso(datos.tiempoMedioIOP1, datos.desviacionEstandarTiempoIOP1);
    }
    if(tipo==2){
        timeProcesador = calcularTiempoIngreso(datos.tiempoPromedioProcesosP2, datos.desviacionEstandarTiempoProcesosP2);
        timeIO = calcularTiempoIngreso(datos.tiempoMedioIOP2, datos.desviacionEstandarTiempoIOP2);
    }

    //Inicializacion de tipo
    this->tipo = tipo;
}

