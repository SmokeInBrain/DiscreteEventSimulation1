#ifndef ESTADISTICA_H_INCLUDED
#define ESTADISTICA_H_INCLUDED

typedef struct str_Estadistica{
    //Tipo por proceso
    float q1;
    float q2;

    //Tama~no procesos
    int tamColaDeProcesos;
    int tamColaIO;
    int cantidadProcesos;

    //Tipo de algoritmo
    bool algoritmoDePlanificacion;

    //Tipo promedio por cada proceso
    float tiempoPromedioIngresoNuevoProceso;
    float desviacionEstandarIngresoNuevoProceso;

    //Tipo de proceso
    int porcentajeProcesosTipo1;
    int porcentajeProcesosTipo2;

    //Proceso 1
    float tiempoPromedioProcesosP1;
    float desviacionEstandarTiempoProcesosP1;
    float tiempoMedioIOP1;
    float desviacionEstandarTiempoIOP1;

    //Proceso 2
    float tiempoPromedioProcesosP2;
    float desviacionEstandarTiempoProcesosP2;
    float tiempoMedioIOP2;
    float desviacionEstandarTiempoIOP2;

}Estadistica;

#endif // ESTADISTICA_H_INCLUDED
