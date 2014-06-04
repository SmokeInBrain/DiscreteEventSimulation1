#ifndef PROCESS_H
#define PROCESS_H

class Process
{
	private:
		//Attributes
            //Date
            int id;
            int clock;
            //Statistics
            float timeProcessor;    //Time that needs this process for finish
            float timeProcessing;   //Time that this process is in the CPU
            double quantum;           //Time quantum in algorithm RR
    public:
        //Constructor
            Process();
            Process(int id, double quantum, int clock);
            //GETTERS
            int getId();
            int getClock();
            float getTimeProcessor();
            float getTimeProcessing();
            double getQuantum();
            //SETTERS
            void setId(int id);
            void setClock(int clock);
            void setTimeProcessor(int timeProcessor);
            void setTimeProcessing(int timeProcessing);
            double setQuantum(int quantum);

        

        //Methods
            float calculateProcessor();
};

#endif // PROCESS_H

