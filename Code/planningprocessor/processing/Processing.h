#ifndef PROCESSING_H
#define PROCESSING_H

#include <pthread.h>

class Processing{
    public:
        //Constructor
            Processing(StadisticIn stdIn);

        //Attributes
            //Date global
            pthread_mutex_t mutex;
            StadisticIn stdIn;
            StadisticOut stdout;

        //Methods
            void *functionCreateProcess(void * arg);
            void *functionProcessingProcess(void * arg);
            void *functionProcessingIO(void * arg);
            bool planificationProcess(StadisticIn stdIn);

};

#endif // PROCESSING_H
