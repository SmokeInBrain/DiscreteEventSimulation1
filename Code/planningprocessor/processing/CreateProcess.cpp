#include <processing/CreateProcess.h>

//Funcion para crear procesos y luego que sean procesados por el procesador
void CreateProcess::creatingProcess()
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
			if(estadisticas.algoritmoDePlanificacion=="FCFS"){
				listaProcesos.push_back(proceso);
			}
			if(estadisticas.algoritmoDePlanificacion=="SPN"){
				ordenarSPN(proceso);
			}
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
