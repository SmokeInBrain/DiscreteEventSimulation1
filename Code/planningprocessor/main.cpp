#include <iostream>

using namespace std;

void main()
{
    //GetOpt
    Processing processing = new Processing();
    if(processing.planificationProcess()){
        cout<<"True";
    }else{
        cout<<"False";
    }
}
