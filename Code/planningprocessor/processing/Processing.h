#ifndef PROCESSING_H
#define PROCESSING_H

#include <pthread.h>

class Processing{
    public:
        //Constructor
            Processing(StadisticsIn stdIn);

        //Attributes
            //Date global
            StadisticsIn stdIn;
            StadisticsOut stdout;

            Process processListCPU;
            VectorProcess processListIO;
            VectorProcess processFinishList;

            VectorEvent eventList;

        //Methods
            void functionCreateProcess();
            void functionProcessingProcess();
            void functionProcessingIO();
            bool planificationProcess(StadisticsIn stdIn);

};

#endif // PROCESSING_H
