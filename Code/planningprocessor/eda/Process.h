#ifndef PROCESS_H
#define PROCESS_H

class Process
{
    public:
        //Constructor
            Process(int id);

        //Attributes
            //Date
            int id;
            //Stadistic
            float timeProcessor;    //Time that need this process for finish
            float timeQueue;        //Time that this process is in the queue
            float timeProcessing;   //Time that this process is in the CPU
            float timeIO;           //Time that this process is in the IO

        //Methods

};

#endif // PROCESOS_H

