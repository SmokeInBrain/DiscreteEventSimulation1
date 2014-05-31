
#include <string>
#include "Data.h"
using namespace std;
class File
{
private:
	Data data;
	string input_name;
	string output_name;
	string log_name;
public:
	File(Data data, string input_name, string output_name, string log_name);
	File();
	//GETTERS
	Data getData();
	string getInput_name();
	string getOutput_name();
	string getLog_name();
	//SETTERS
	void setData(Data data);
	void setInput_name(string input_name);
	void setOutput_name(string output_name);
	void setLog_name(string log_name);
	//METODOS
	void help_printing();
	void getOptions(int argc, char **argv);
	void readInput();
	void writeOutput();
	void writeLog();

};

