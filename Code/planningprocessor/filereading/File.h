#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

#include <string>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <getopt.h>

#include <eda/StatisticsIn.h>

using namespace std;
class File
{
private:
	StatisticsIn StatisticsIn;
	string input_name;
	string output_name;
	string log_name;
public:
	File(StatisticsIn StatisticsIn, string input_name, string output_name, string log_name);
	File();
	//GETTERS
	StatisticsIn getStatisticsIn();
	string getInput_name();
	string getOutput_name();
	string getLog_name();
	//SETTERS
	void setStatisticsIn(StatisticsIn StatisticsIn);
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

#endif // FILE_H_INCLUDED
