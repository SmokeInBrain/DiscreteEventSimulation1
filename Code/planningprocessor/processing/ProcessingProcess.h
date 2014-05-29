#ifndef PROCESSINGPROCESS_H
#define PROCESSINGPROCESS_H

class ProcessingProcess{
    public:
        //Constructor
            ProcessingProcess();

        //Attributes

        //Methods
            void processingCPU(pthread_mutex_t mutex);

};

#endif // PROCESSINGPROCESS_H
