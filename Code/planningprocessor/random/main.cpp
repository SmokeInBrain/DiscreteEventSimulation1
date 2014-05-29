#include <iostream>
#include "Distribution.h"

using namespace std;

int main(){
	Distribution dist = Distribution();
	for(int i=0; i<100;i++){
		double num = dist.normal(100,10);
		cout << "ALEATORIO "<< num << endl;
	}
	
	return 0;
}