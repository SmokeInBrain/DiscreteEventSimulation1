#include <string>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <getopt.h>

#include <eda/StadisticIn.h>

using namespace std;
class File
{
private:
	StadisticIn stadisticIn;
	string input_name;
	string output_name;
	string log_name;
public:
	File(StadisticIn stadisticIn, string input_name, string output_name, string log_name);
	File();
	//GETTERS
	StadisticIn getStadisticIn();
	string getInput_name();
	string getOutput_name();
	string getLog_name();
	//SETTERS
	void setStadisticIn(StadisticIn stadisticIn);
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

