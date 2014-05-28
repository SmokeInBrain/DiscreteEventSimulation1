#include <pthread.h>
#include "hebras.h"

//Variables globales
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int cantidadProcesoAgregados = 0;
int cantidadProcesosProcesados = 0;
int cantidadProcesosFinalizados = 0;
int cantidadProcesosIO1 = 0;
int cantidadProcesosIO2 = 0;
Estadistica estadisticas;

vector<Procesos> listaProcesos;
vector<Procesos> procesosIO;
vector<Procesos> procesosFinalizados;

using namespace std;

//Funcion para crear procesos y luego que sean procesados por el procesador
void *crearProcesos(void *arg)
{
    float timeI, timeF, time;

	timeI = tiempoProceso();

    while (true)
    {

	    

        time = calcularTiempoIngreso(estadisticas.tiempoPromedioIngresoNuevoProceso,estadisticas.desviacionEstandarIngresoNuevoProceso);
        esperarProceso(time);

        pthread_mutex_lock(&mutex);

        if ( (int) listaProcesos.size() < ( estadisticas.tamColaDeProcesos/2) )
        {

            int tipoProceso;


            if ((estadisticas.cantidadProcesosTipo1 > 0) && (estadisticas.cantidadProcesosTipo2 > 0))
            {
                tipoProceso = rand()%2 + 1;
                if(tipoProceso==1){
                    estadisticas.cantidadProcesosTipo1--;
                }
                if(tipoProceso==2){
                    estadisticas.cantidadProcesosTipo2--;
                }
            }
            else if (estadisticas.cantidadProcesosTipo1 > 0)
            {
                tipoProceso = 1;
            }
            else if (estadisticas.cantidadProcesosTipo2 > 0)
            {
                tipoProceso = 2;
            }

            Procesos proceso(tipoProceso,cantidadProcesoAgregados,estadisticas);
            proceso.timeProcesado = proceso.timeIO + proceso.timeProcesador + time;
            listaProcesos.push_back(proceso);
            cantidadProcesoAgregados++;

            if (cantidadProcesoAgregados == estadisticas.cantidadProcesos)
            {
                timeF = tiempoProceso();
                //estadisticas.tiempoTotal = estadisticas.tiempoTotal + (timeF - timeI);

                pthread_mutex_unlock(&mutex);
                pthread_exit(NULL);
            }

        }

        pthread_mutex_unlock(&mutex);

    }


}

//Funcion para poder procesar los procesos en el procesador
void *procesarProcesos(void *arg)
{
    float timeIT, timeFT, timeI, timeF, timeP;

			timeIT = tiempoProceso();

    while (true)
    {

        pthread_mutex_lock(&mutex);

        if (listaProcesos.size() > 0)
        {
            timeI = tiempoProceso();
            
			Procesos proceso = listaProcesos.back();
            listaProcesos.pop_back();
            cantidadProcesosProcesados--;

            pthread_mutex_unlock(&mutex);

            if (proceso.timeProcesador > 0)
            {
                timeP = estadisticas.q1 * rand() / ((float) RAND_MAX);
                if (timeP > proceso.timeProcesador)
                {
                    timeP = proceso.timeProcesador;
                }

                esperarProceso(timeP);
                proceso.timeProcesador = proceso.timeProcesador - timeP;
            }

            pthread_mutex_lock(&mutex);
            if (proceso.timeIO > 0)
            {
                procesosIO.push_back(proceso);
                timeF = tiempoProceso();
                estadisticas.tiempoUtilizadoProcesador = estadisticas.tiempoUtilizadoProcesador + (timeF - timeI);
                if(proceso.tipo==1)
                {
                    cantidadProcesosIO1++;
                }
                if(proceso.tipo==2)
                {
                    cantidadProcesosIO2++;
                }
            }
            else if (proceso.timeProcesador > 0)
            {
                listaProcesos.push_back(proceso);
                cantidadProcesosProcesados++;
                timeF = tiempoProceso();
                estadisticas.tiempoUtilizadoProcesador = estadisticas.tiempoUtilizadoProcesador + (timeF - timeI);
            }
            else
            {
                procesosFinalizados.push_back(proceso);
                cantidadProcesosFinalizados++;
                timeF = tiempoProceso();
                estadisticas.tiempoUtilizadoProcesador = estadisticas.tiempoUtilizadoProcesador + (timeF - timeI);
                //cout<<"Cantidad Procesos Procesados: "<<cantidadProcesosProcesados<<"\n";
            }

        }

        else
        {
            if (cantidadProcesosFinalizados == estadisticas.cantidadProcesos)
            {
                timeFT = tiempoProceso();
                //estadisticas.tiempoTotal = estadisticas.tiempoTotal + (timeFT - timeIT);

                pthread_mutex_unlock(&mutex);
                pthread_exit(NULL);
            }
        }

        pthread_mutex_unlock(&mutex);
    }
}

//Funcion para poder procesar los procesos en el IO de tipo 1
void *procesarIO1(void *arg)
{
    float timeIT, timeFT, timeI, timeF, timeIO;

    while (true)
    {

        pthread_mutex_lock(&mutex);

		timeIT = tiempoProceso();

        if (cantidadProcesosIO1 > 0)
        {
            timeI = tiempoProceso();

            Procesos proceso = procesosIO.back();
            procesosIO.pop_back();
            cantidadProcesosIO1--;

            pthread_mutex_unlock(&mutex);

            if (proceso.timeIO > 0)
            {

                timeIO = estadisticas.q2 * rand() / ((float) RAND_MAX);
                if (timeIO > proceso.timeIO)
                {
                    timeIO = proceso.timeIO;
                }

                esperarProceso(timeIO);
                proceso.timeIO = proceso.timeIO - timeIO;
            }

            pthread_mutex_lock(&mutex);

            listaProcesos.push_back(proceso);
            cantidadProcesosProcesados++;

            timeF = tiempoProceso();
            estadisticas.tiempoUtilizadoIO1 = estadisticas.tiempoUtilizadoIO1 + (timeF - timeI);
        }

        else
        {
            if (cantidadProcesosFinalizados == estadisticas.cantidadProcesos)
            {
                timeFT = tiempoProceso();
                //estadisticas.tiempoTotal = estadisticas.tiempoTotal + (timeFT - timeIT);

                pthread_mutex_unlock(&mutex);
                pthread_exit(NULL);
            }
        }


        pthread_mutex_unlock(&mutex);
    }
}

//Funcion para poder procesar los procesos en el IO de tipo 2
void *procesarIO2(void *arg)
{
    float timeIT, timeFT, timeI, timeF, timeIO;    

    while (true)
    {

        pthread_mutex_lock(&mutex);

		timeIT = tiempoProceso();

        if (cantidadProcesosIO2 > 0)
        {
            timeI = tiempoProceso();

            Procesos proceso = procesosIO.back();
            procesosIO.pop_back();
            cantidadProcesosIO2--;

            pthread_mutex_unlock(&mutex);

            if (proceso.timeIO > 0)
            {

                timeIO = estadisticas.q2 * rand() / ((float) RAND_MAX);
                if (timeIO > proceso.timeIO)
                {
                    timeIO = proceso.timeIO;
                }

                esperarProceso(timeIO);
                proceso.timeIO = proceso.timeIO - timeIO;
            }

            pthread_mutex_lock(&mutex);

            listaProcesos.push_back(proceso);
            cantidadProcesosProcesados++;

            timeF = tiempoProceso();
            estadisticas.tiempoUtilizadoIO2 = estadisticas.tiempoUtilizadoIO2 + (timeF - timeI);
        }

        else
        {
            if (cantidadProcesosFinalizados == estadisticas.cantidadProcesos)
            {
                timeFT = tiempoProceso();
                //estadisticas.tiempoTotal = estadisticas.tiempoTotal + (timeFT - timeIT);

                pthread_mutex_unlock(&mutex);
                pthread_exit(NULL);
            }
        }

        pthread_mutex_unlock(&mutex);
    }
}

void hebras(char *ficheroSalida, Estadistica datos)
{
    estadisticas = datos;   //Guardar los datos en la variable global
	estadisticas.tiempoTotal = 0;
    estadisticas.tiempoUtilizadoProcesador = 0;
    estadisticas.tiempoUtilizadoIO1 = 0;
    estadisticas.tiempoUtilizadoIO2 = 0;	

	float timeI = 0;
	float timeF = 0;

	timeI = tiempoProceso();

    pthread_t generador, procesador, IO1, IO2;      //Declaracion de las hebras

    pthread_create(&generador, NULL, crearProcesos, NULL);      //Crear hebra para crear Procesos
    pthread_create(&procesador, NULL, procesarProcesos, NULL);  //Crear hebra para procesar procesos
    pthread_create(&IO1, NULL, procesarIO1, NULL);              //Crear hebra para procesar segun IO1
    pthread_create(&IO2, NULL, procesarIO2, NULL);              //Crear hebra para procesar segun IO2

    pthread_join(generador, NULL);
    pthread_join(procesador, NULL);
    pthread_join(IO1, NULL);
    pthread_join(IO2, NULL);

	timeF = tiempoProceso();

	estadisticas.tiempoTotal = timeF - timeI;

    imprimirEstadisticas(ficheroSalida);

    return;
}

float mediaProceso(vector<Procesos> datos, int tipo)
{
    float acumulador=0;
    int contador=0;
    for(unsigned int i=0; i<datos.size(); i++)
    {
        if(tipo==0)
        {
            acumulador=acumulador+datos[i].timeProcesado;
            contador++;
        }

        else if(tipo==datos[i].tipo && tipo!=0)
        {
            acumulador=acumulador+datos[i].timeProcesado;
            contador++;
        }
    }

    return acumulador/contador;
}

float desviacionProcesos(vector<Procesos> datos, int tipo)
{

    float var=0;
    float coef=0;
    int contador=0;
    for(unsigned int i=0; i<datos.size(); i++)
    {
        if(tipo==0)
        {
            coef = (datos[i].timeProcesado-mediaProceso(datos,tipo));
            var = var + coef*coef;
            contador++;
        }

        else if(tipo==datos[i].tipo)
        {
            coef = (datos[i].timeProcesado-mediaProceso(datos,tipo));
            var = var + coef*coef;
            contador++;
        }
    }

    float varianza = var/contador;

    return sqrt(varianza);
}

void imprimirEstadisticas(string nombreFicheroSalida)
{
    ofstream fichero;
    fichero.open(nombreFicheroSalida.c_str());

	float tiempoSegundos = estadisticas.tiempoTotal/estadisticas.cantidadProcesos;

    if ( fichero.is_open() )
    {

        fichero << "Tiempo promedio de término de un proceso tipo 1 desde que entra: " << mediaProceso(procesosFinalizados,1) << " s\n";
        fichero << "Tiempo promedio de término de un proceso tipo 2 desde que entra: " << mediaProceso(procesosFinalizados,2) << " s\n";
        fichero << "Tiempo promedio de término de un proceso desde que entra: " << mediaProceso(procesosFinalizados,0) << " s\n";
        fichero << "Desviación estándar de término de un proceso tipo 1 desde que entra: " << desviacionProcesos(procesosFinalizados, 1) << " s\n";
        fichero << "Desviación estándar de término de un proceso tipo 2 desde que entra: " << desviacionProcesos(procesosFinalizados, 2) << " s\n";
        fichero << "Desviación estándar de término de un proceso desde que entra: " << desviacionProcesos(procesosFinalizados, 0) << " s\n";
        fichero << "Tiempo promedio en sacar un proceso en un segundo: " << tiempoSegundos << " s\n";
        fichero << "Tiempo total: " << estadisticas.tiempoTotal << " s\n";
        fichero << "Tiempo de utilización del procesador: " << estadisticas.tiempoUtilizadoProcesador << " s\n";
        fichero << "Tiempo de utilización del manejador de I/O 1: " << estadisticas.tiempoUtilizadoIO1<< " s\n";
        fichero << "Tiempo de utilización del manejador de I/O 2: " << estadisticas.tiempoUtilizadoIO2 << " s\n";

        fichero.close();

    }

    return;
}
