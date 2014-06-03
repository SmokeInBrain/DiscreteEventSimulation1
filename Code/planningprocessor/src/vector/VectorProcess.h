#ifndef VECTORPROCESS_H
#define VECTORPROCESS_H

#include <iostream>
#include <string>
#include <vector>

#include "eda/Process.h"

using namespace std;

class VectorProcess {

    public:
        //Constructor
            VectorProcess();
            VectorProcess(int largeMax, string typePriority);

        // Attributes.
            int largeMax;
            vector <Process> listProcess;
            string typePriority;

        // Methods.
            void insertProcess(Process process);
            Process extractProcess();
            Process extractProcessIO(int id);
            void printAllList();
};

#endif // VECTORPROCESOS_H
