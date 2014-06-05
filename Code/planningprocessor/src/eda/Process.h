#ifndef PROCESS_H
#define PROCESS_H

class Process
{
	private:
		//Attributes
            //Date
            int id;
            double clock;
            //Statistics
            float timeProcessor;    //Time that needs this process for finish
            float timeProcessing;   //Time that this process is in the CPU
            double quantum;           //Time quantum in algorithm RR
    public:
        //Constructor
            Process();
            Process(int id, double quantum, double clock);
            //GETTERS
            int getId();
            double getClock();
            float getTimeProcessor();
            float getTimeProcessing();
            double getQuantum();
            //SETTERS
            void setId(int id);
            void setClock(double clock);
            void setTimeProcessor(double timeProcessor);
            void setTimeProcessing(double timeProcessing);
            double setQuantum(int quantum);



        //Methods
            float calculateProcessor();
};

#endif // PROCESS_H

