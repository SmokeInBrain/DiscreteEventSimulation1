#ifndef VECTORPROCESS_H
#define VECTORPROCESS_H

#include <string>
#include <vector>

#include "eda/Process.h"

using namespace std;

class VectorProcess {
    private:
        // Attributes.
            int largeMax;
            vector <Process> listProcess;
            string typePriority;


    public:
        //Constructor
            VectorProcess();
            VectorProcess(int largeMax, string typePriority);
        //Getters
            int getLargeMax();
            vector <Process> getListProcess();
            string getTypePriority();
        //Setters
            void setLargeMax(int largeMax);
            void setListProcess(vector <Process> listProcess);
            void setTypePriority(string typePriority);
        // Methods.
            void insertProcess(Process process);
            Process extractProcess();
            Process extractProcessIO(int id);
            void printAllList();
};

#endif // VECTORPROCESOS_H
