#include "filereading/File.h"
#include <iomanip>

using namespace std;

//CONSTRUCTORES
File::File(StatisticsIn stdIn, string input_name, string output_name, string log_name, ofstream *ofs){
	this->stdIn = stdIn;
	this->input_name=input_name;
	this->output_name=output_name;
	this->log_name=log_name;
	this->ofs = ofs;
}

File::File() {
	StatisticsIn *p = &this->stdIn;
	p=NULL;
	this->input_name="";
	this->output_name="";
	this->log_name="";
	this->ofs = NULL;
}
//GETTERS
StatisticsIn File::getStdIn(){
	return this->stdIn;
}

string File::getInput_name(){
	return this->input_name;
}

string File::getOutput_name(){
	return this->output_name;
}

string File::getLog_name(){
	return this->log_name;
}




//SETTERS

void File::setStdIn(StatisticsIn stdIn){
	this->stdIn=stdIn;
}

void File::setInput_name(string input_name){
	this->input_name=input_name;
}

void File::setOutput_name(string output_name){
	this->output_name=output_name;
}

void File::setLog_name(string log_name){
	this->log_name=log_name;
}


//METODOS
void File::help_printing ()
{
    cout << "Example: executable_name options [ arguments ...]\n" << endl;
    cout << "    -h  --help                  Shows this help\n" << endl;
    cout << "    -i  --input file        	Reads the input file\n" << endl;
    cout << "    -o  --output file           Writes the output file\n" << endl;
    cout << "    -l  --log file              Writes the log file\n" << endl;
}

void File::getOptions(int argc, char **argv){
	int next_opt;
	const char* const short_op = "hi:o:l:" ;
	const struct option long_op[] =
  	{
  	  { "help", 0, NULL, 'h'},
      { "input",         1,  NULL,   'i'},
      { "output",      1,  NULL,   'o'},
      { "log",       1,  NULL,   'l'},
      { NULL,           0,  NULL,   0  }
 	 };
 	char* input_file;
  	char* output_file;
  	char* log_file;
  	if(argc==1){
  		cout <<"ERROR. THE PROGRAM HAS BEEN EXECUTED WITHOUT PARAMETERS OR OPTIONS"<<endl;
  		help_printing();
  		exit(EXIT_SUCCESS);
  	}

  	while(1){
  		next_opt = getopt_long(argc, argv, short_op, long_op, NULL);
  		if(next_opt==-1){
  			break;
  		}
  		switch(next_opt){
  			case 'h':
  				help_printing();
  				exit(EXIT_SUCCESS);
  			case 'i':
  				input_file = optarg;
  				break;
  			case 'o':
  				output_file = optarg;
  				break;
  			case 'l':
  				log_file = optarg;
  				break;
  			case '?':
  				help_printing();
  				exit(1);
  			case -1 :
  				break;
  			default:
  				abort();
  		}
  	}
  	string ifile(input_file);
  	string ofile(output_file);
  	string lfile(log_file);

  	this->input_name=ifile;
  	this->output_name=ofile;
  	this->log_name=lfile;
}
void File::readInput(){
	string fileName= this->input_name;
	int numproc=0;
	double quantum=0.0;
	string algorithm="";
	string interarrive="";
	double interarriveInter1=0;
	double interarriveInter2=0.0;
	string service="";
	double serviceInter1=0.0;
	double serviceInter2=0.0;
	string RP="";
	double RPInter1=0.0;
	double RPInter2=0.0;
	string RIO="";
	double RIOInter1=0.0;
	double RIOInter2=0.0;
	string name;
	ifstream inputFile;
	inputFile.open(fileName.c_str());
	if(inputFile.is_open()){
		inputFile >> name >> numproc;
		inputFile >> name >> algorithm;
 		if(algorithm=="RR"){
			inputFile >> quantum;
		}
		inputFile >> name >> interarrive >> interarriveInter1;
		if(interarrive=="uniform"){
			inputFile >> interarriveInter2;
		}
		inputFile >> name >> service >> serviceInter1;
		if(service=="uniform"){
			inputFile >> serviceInter2;
		}
		inputFile >> name >> RP >> RPInter1;
		if(RP=="uniform" || RP=="normal"){
			inputFile >> RPInter2;
		}
		inputFile >> name >> RIO >> RIOInter1;


		if(RIO=="uniform"){
			inputFile >> RIOInter2;

		}
		inputFile.close();
	}else{
		cout <<"ERROR. The file doesn't exists or there are no permission to open it"<<endl;
	}

	StatisticsIn inputStatisticsIn = StatisticsIn(numproc, quantum, algorithm, interarrive, service, RP, RIO, interarriveInter1, interarriveInter2, serviceInter1, serviceInter2, RPInter1, RPInter2, RIOInter1, RIOInter2);
	this->stdIn = inputStatisticsIn;

}

void File:: writeOutput(StatisticsOut stdOut){
    const char *nombre_output = this->output_name.c_str();
	cout <<nombre_output<< endl;
	ofs = new ofstream(nombre_output, ios::binary | ios::out);

	*ofs << "Total time of simulation: " << stdOut.getTotalSimulationTime() << endl;
	*ofs << "Processor utilization: " << stdOut.getThroughputTime() << endl;
	*ofs << "Total idle processor time: " << stdOut.getIdleTime() << endl;
	*ofs << "Average wait time in queue of ready: " << stdOut.getQueueTime() << endl;
	*ofs << "Average time of I/O: " << stdOut.getIOTime() << endl;
	*ofs << "Average residence time (TAT): " << stdOut.getProcessTime() << endl;
	*ofs << "Maximum length of the ready queue: " << stdOut.getQueueMaxLength() << endl;
	*ofs << "Average length of the ready queue: " << stdOut.getQueueAvgLength() << endl;

	ofs->close();
}

void File::openLog(){
	const char *nombre_log = this->log_name.c_str();
	cout <<nombre_log<< endl;
	ofs = new ofstream(nombre_log, ios::binary | ios::out);
	*ofs <<setw(10)<<left<<"|PID"<<setw(15)<<left<<"|Event Type"<<setw(10)<<left<<"|Time|"<<endl;
	*ofs <<"-------------------------------"<<endl;
	//&this->ofs = ofst;
}

void File::Log(Event currentEvent){
	*ofs <<setw(9)<<left<<"|"<<currentEvent.getIdProcess();
	if(currentEvent.getTypeEvent()=="Arrival"){
		*ofs<<setw(8)<<left<<"|"<<currentEvent.getTypeEvent();
	}else{
		if(currentEvent.getTypeEvent()=="RP"){
			*ofs<<setw(13)<<left<<"|"<<currentEvent.getTypeEvent();
		}else{
			if(currentEvent.getTypeEvent()=="RIO"){
				*ofs<<setw(12)<<left<<"|"<<currentEvent.getTypeEvent();
			}else{
				if(currentEvent.getTypeEvent()=="Final"){
					*ofs<<setw(10)<<left<<"|"<<currentEvent.getTypeEvent();
				}
			}
		}
	}
	*ofs<<setw(4)<<left<<"|"<<currentEvent.getTime()<<"|\n";
	*ofs <<"-------------------------------"<<endl;
}

void File::closeLog(){
	ofs->close();
}
