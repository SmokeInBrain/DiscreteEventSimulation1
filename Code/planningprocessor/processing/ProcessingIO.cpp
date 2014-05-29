#include <processing/ProcessingIO.h>

ProcessingProcess::ProcessingProcess(){}

//Funcion para poder procesar los procesos en el IO de tipo 2
void executeIO()
{
    float timeIT, timeFT, timeI, timeF, timeIO;

    while (true)
    {

        pthread_mutex_lock(&mutex);

		timeIT = tiempoProceso();

        if (cantidadProcesosIO2 > 0)
        {
            timeI = tiempoProceso();

            //Procesos proceso = procesosIO.back();
            //procesosIO.pop_back();
			Procesos proceso = procesosIO[0];
            procesosIO.erase(procesosIO.begin());
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

            if(estadisticas.algoritmoDePlanificacion=="FCFS"){
				listaProcesos.push_back(proceso);
			}
			if(estadisticas.algoritmoDePlanificacion=="SPN"){
				ordenarSPN(proceso);
			}
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

