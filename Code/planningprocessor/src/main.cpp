#include <iostream>
#include "filereading/File.h"
#include "processing/Processing.h"

using namespace std;

int main(int argc, char * argv[])
{
    File file = File();
    file.getOptions(argc, argv);
    file.readInput();
<<<<<<< HEAD
    
    Processing processing = Processing(file.getStdIn());
=======

    cout << "Numero de procesos: " << file.getStdIn().getNumProc();

    /*
    Processing processing();
>>>>>>> c3e609cd5418e2958a0d345181af2507f6959d7f
    if(processing.planificationProcess()){
        cout<<"True";
    }else{
        cout<<"False";
    }
    

    return 0;
}
