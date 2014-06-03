#include <iostream>
#include "filereading/File.h"

using namespace std;

int main(int argc, char * argv[])
{
    File file = File();
    file.getOptions(argc, argv);
    file.readInput();

    cout << "Numero de procesos: " << file.getStdIn().getNumProc();

    /*
    Processing processing();
    if(processing.planificationProcess()){
        cout<<"True";
    }else{
        cout<<"False";
    }
    */

    return 0;
}
