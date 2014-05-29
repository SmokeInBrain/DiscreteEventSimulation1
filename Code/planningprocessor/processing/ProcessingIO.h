#ifndef PROCESSINGIO_H
#define PROCESSINGIO_H

class ProcessingIO{
    public:
        //Constructor
            ProcessingIO();

        //Attributes

        //Methods
            void executeIO(pthread_mutex_t mutex);

};

#endif // PROCESSINGIO_H
