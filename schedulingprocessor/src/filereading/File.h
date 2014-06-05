#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

#include "eda/StatisticsIn.h"
#include "eda/StatisticsOut.h"
#include "eda/Event.h"

#include <string>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <getopt.h>

using namespace std;

class File
{
private:
	StatisticsIn stdIn;
	string input_name;
	string output_name;
	string log_name;
	ofstream *ofs;
public:
	File(StatisticsIn stdIn, string input_name, string output_name, string log_name, ofstream *ofs);
	File();
	//GETTERS
	StatisticsIn getStdIn();
	string getInput_name();
	string getOutput_name();
	string getLog_name();
	//SETTERS
	void setStdIn(StatisticsIn stdIn);
	void setInput_name(string input_name);
	void setOutput_name(string output_name);
	void setLog_name(string log_name);
	//Methods
	void help_printing();
	void getOptions(int argc, char **argv);
	void readInput();
	void writeOutput(StatisticsOut stdOut);
	void openLog();
	void Log(Event currentEvent);
	void closeLog();

};

#endif // FILE_H_INCLUDED
