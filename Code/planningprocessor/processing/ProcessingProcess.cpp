#include <processing/ProcessingProcess.h>

ProcessingProcess::ProcessingProcess(){}

//Funcion para poder procesar los procesos en el procesador
void ProcessingProcess::ProcesprocessingCPU()
{
    float timeIT, timeFT, timeI, timeF, timeP;

			timeIT = tiempoProceso();

    while (true)
    {

        pthread_mutex_lock(&mutex);

        if (listaProcesos.size() > 0)
        {
            timeI = tiempoProceso();

			//Procesos proceso = listaProcesos.back();
            //listaProcesos.pop_back();
			Procesos proceso = listaProcesos[0];
            listaProcesos.erase(listaProcesos.begin());
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
                if(estadisticas.algoritmoDePlanificacion=="FCFS"){
					listaProcesos.push_back(proceso);
				}
				if(estadisticas.algoritmoDePlanificacion=="SPN"){
					ordenarSPN(proceso);
				}
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
