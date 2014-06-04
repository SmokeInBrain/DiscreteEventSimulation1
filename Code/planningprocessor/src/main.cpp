#include <iostream>
#include "filereading/File.h"
#include "processing/Processing.h"

using namespace std;

int main(int argc, char * argv[])
{
    File file = File();
    file.getOptions(argc, argv);
    //file.setInput_name("input/inputExample.txt");
    file.readInput();
    file.openLog();
    //En el log debe entrar el evento como parámetro.
    //file.Log();
    

    Processing processing = Processing(file.getStdIn());

    if(processing.planificationProcess(file)){
        cout<<"True";
    }else{
        cout<<"False";
    }
    file.closeLog();
    return 0;
}
