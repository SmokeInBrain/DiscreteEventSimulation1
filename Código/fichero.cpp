#include "DatosEntrada.h"

Estadistica obtenerEstadistica(char *ficheroEntrada)
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
        fichero >> s >> datos.tamanoColaDeProcesos;
        fichero >> s >> datps.tamanoColaIO;
        fichero >> s >> datps.algoritmoDePlanificacion;
        fichero >> s >> datos.cantidadProcesos;
        fichero >> s >> tiempoPromedioIngresoNuevoProceso;
        fichero >> s >> desviacionEstandarIngresoNuevoProceso;
        fichero >> s >> porcentajeProcesosTipo1 >S> s;

        fichero >> s;
        fichero >> s >> datosTipo1.tiempoPromedioProcesosP1;
        fichero >> s >> datosTipo1.desviacionEstandarTiempoProcesosP1;
        fichero >> s >> datosTipo1.tiempoMedioIOP1;
        fichero >> s >> datosTipo1.desviacionEstandarTiempoIOP1;

        fichero >> s;
        fichero >> s >> datosTipo2.tiempoPromedioProcesosP2;
        fichero >> s >> datosTipo2.desviacionEstandarTiempoProcesosP2;
        fichero >> s >> datosTipo2.tiempoMedioIOP2;
        fichero >> s >> datosTipo2.desviacionEstandarTiempoIOP2;

        fichero.close();

        datos.porcentajeProcesosTipo2 = 100 - datos.porcentajeProcesosTipo1;

        return datos;

    }
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
    Fichero=fopen("comunication.out","w+");

    fprintf(Fichero,"Error banderas");

    fclose(Fichero);
}

void escribirErrorParametro()
{
    FILE *Fichero;
    Fichero=fopen("comunication.out","w+");

    fprintf(Fichero,"Error de parametros de entradas");

    fclose(Fichero);
}

void escribirErrorFichero()
{
    FILE *Fichero;
    Fichero=fopen("comunication.out","w+");

    fprintf(Fichero,"Error de archivo de entrada");

    fclose(Fichero);
}
