#include <iostream>

using namespace std;

void main()
{
    //GetOpt
    Processing processing();
    if(processing.planificationProcess()){
        cout<<"True";
    }else{
        cout<<"False";
    }
}
