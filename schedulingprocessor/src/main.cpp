#include <iostream>
#include "eda/StatisticsOut.h"
#include "filereading/File.h"
#include "processing/Processing.h"

using namespace std;

int main(int argc, char * argv[])
{
    File file = File();
    //file.getOptions(argc, argv);
    file.setInput_name("input/inputExample.txt");
    file.setOutput_name("output/outputExample.txt");
    file.setLog_name("log/logExample.txt");

    file.readInput();

    file.openLog();
    //En el log debe entrar el evento como parámetro.

    Processing processing = Processing(file.getStdIn());

    if(processing.planificationProcess(file)){
        StatisticsOut stdOut = StatisticsOut(processing.getClock(), processing.getTimeAccumulatedQueue(), processing.getTimeAccumulatedCPU(), processing.getTimeAccumulatedIO(), processing.getProcessFinish(), processing.getMaxLargeQueue(), processing.getLargeAccumulatedQueue());
        file.writeOutput(stdOut);
        cout<<"True";
    }else{
        cout<<"False";
    }
    file.closeLog();
    return 0;
}
