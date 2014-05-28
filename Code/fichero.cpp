#include "fichero.h"

Estadistica obtenerEstadistica(string ficheroEntrada)
{

    // Retorna verdadero si leyó correctamente.

    Estadistica datos;
    string s;
    ifstream fichero;

    fichero.open(ficheroEntrada.c_str());

    if ( fichero.is_open() )
    {

        fichero >> s >> datos.q1;
        fichero >> s >> datos.q2;
        fichero >> s >> datos.tamColaDeProcesos;
        fichero >> s >> datos.tamColaIO;
        fichero >> s >> datos.algoritmoDePlanificacion;
        fichero >> s >> datos.cantidadProcesos;
        fichero >> s >> datos.tiempoPromedioIngresoNuevoProceso;
        fichero >> s >> datos.desviacionEstandarIngresoNuevoProceso;
        fichero >> s >> datos.porcentajeProcesosTipo1 >> s;

        fichero >> s;
        fichero >> s >> datos.tiempoPromedioProcesosP1;
        fichero >> s >> datos.desviacionEstandarTiempoProcesosP1;
        fichero >> s >> datos.tiempoMedioIOP1;
        fichero >> s >> datos.desviacionEstandarTiempoIOP1;

        fichero >> s;
        fichero >> s >> datos.tiempoPromedioProcesosP2;
        fichero >> s >> datos.desviacionEstandarTiempoProcesosP2;
        fichero >> s >> datos.tiempoMedioIOP2;
        fichero >> s >> datos.desviacionEstandarTiempoIOP2;

        fichero.close();

        datos.porcentajeProcesosTipo2 = 100 - datos.porcentajeProcesosTipo1;

        datos.cantidadProcesosTipo1 = (datos.cantidadProcesos*datos.porcentajeProcesosTipo1) / 100 ;
        datos.cantidadProcesosTipo2 = (datos.cantidadProcesos*datos.porcentajeProcesosTipo2) / 100 ;
    }

    return datos;
}

int validarFichero(char *fichero)
{
    FILE *Fichero;
    Fichero = fopen(fichero,"r");
    if(Fichero==NULL)
    {
        return 0;
    }
    else
    {
        fclose(Fichero);
        return 1;
    }
}

void escribirErrorBanderas()
{
    FILE *Fichero;
    Fichero=fopen("error.out","w+");

    fprintf(Fichero,"Error banderas");

    fclose(Fichero);
}

void escribirErrorParametro()
{
    FILE *Fichero;
    Fichero=fopen("error.out","w+");

    fprintf(Fichero,"Error de parametros de entradas");

    fclose(Fichero);
}

void escribirErrorFichero()
{
    FILE *Fichero;
    Fichero=fopen("error.out","w+");

    fprintf(Fichero,"Error de archivo de entrada");

    fclose(Fichero);
}
