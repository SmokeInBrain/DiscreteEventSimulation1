#include <iostream>
#include "filereading/File.h"
#include "processing/Processing.h"

using namespace std;

int main(int argc, char * argv[])
{
    File file = File();
    //file.getOptions(argc, argv);
    file.setInput_name("input/inputExample.txt");
    file.readInput();

    Processing processing = Processing(file.getStdIn());

    if(processing.planificationProcess()){
        cout<<"True";
    }else{
        cout<<"False";
    }

    return 0;
}
