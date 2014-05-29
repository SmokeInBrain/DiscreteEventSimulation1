#ifndef VECTORPROCESS_H
#define VECTORPROCESS_H

#include <vector>
#include <eda/Process.h>

using namespace std;

class VectorProcess {

    public:
        //Constructor
            VectorProcess(int largeMax, string typePriority);

        // Attributes.
            int largeMax;
            vector <Process> listProcess;
            string typePriority;

        // Methods.
            void insertProcess(Process process);
            Process extractProcess();
            void printAllList();
};

#endif // VECTORPROCESOS_H
