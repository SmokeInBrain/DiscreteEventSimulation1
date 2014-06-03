#ifndef PROCESS_H
#define PROCESS_H

class Process
{
    public:
        //Constructor
            Process();
            Process(int id, double quantum, int clock);

        //Attributes
            //Date
            int id;
            int clock;
            //Statistics
            float timeProcessor;    //Time that need this process for finish
            float timeProcessing;   //Time that this process is in the CPU
            double quantum;           //Time quantum in algorithm RR

        //Methods
            float calculateProcessor();
};

#endif // PROCESS_H

