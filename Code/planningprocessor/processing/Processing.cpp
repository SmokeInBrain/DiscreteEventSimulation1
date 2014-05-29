#include <processing/Processing.h>

Processing::Processing(StadisticIn stdIn){
    mutex = PTHREAD_MUTEX_INITIALIZER;
    this->stdIn = stdIn;
    stdOut();
}

void Processing::*functionCreateProcess(void * arg)
{
    CreateProcess createProcess();
    createProcess.creatingProcess();
    //procesador.procesar(mutex, colaProcesos, colaIO, colaTerminados, procesosTerminados, estadisticas);
    pthread_exit(NULL);
}

void Processing::*functionProcessingProcess(void * arg)
{
    ProcessingProcess
}

void Processing::*functionProcessingIO(void * arg)
{

}

bool Processing::planificationProcess()
{

    float timeInitial = getTime();

    pthread_t createProcessThread, processingProcessThread, processingIOThread;                          //Declaration thread

    pthread_create(&createProcessThread, NULL, functionCreateProcess, NULL);                             //Create thread that create process
    pthread_create(&processingProcessThread, NULL, functionProcessingProcess, NULL);                     //Create thread that processing process
    pthread_create(&processingIOThread, NULL, functionProcessingIOThread, NULL);                         //Create thread that processing IO

    pthread_join(createProcessThread, NULL);
    pthread_join(processingProcessThread, NULL);
    pthread_join(processingIOThread, NULL);

    float timeFinal = getTime();

    estadisticas.tiempoTotal = timeF - timeI;

    imprimirEstadisticas(ficheroSalida);
}
