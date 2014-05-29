
#include <string>
#include "Data.h"
using namespace std;
class File
{
private:
	Data data;
	string name;
public:
	File(Data data, string name);
	File();
	//GETTERS
	Data getData();
	string getName();
	//SETTERS
	void setData(Data data);
	void setName(string name);
	//METODOS
	void read();
	void writeOutput();
	void writeLog();

};

int main(){
	return 0;
}