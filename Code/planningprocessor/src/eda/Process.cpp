#include "eda/Process.h"

Process::Process()
{
    this->id = 0;
    this->clock = 0.0;
    this->timeProcessor = 0.0;
    this->timeProcessing = 0.0;
    this->quantum = 0.0;
}

Process::Process(int id, double quantum, double clock, StatisticsIn stdIn)
{
    //Datos
    this->id = id;
    this->clock = clock;
    this->timeProcessor = calculateProcessor(stdIn);
    this->timeProcessing = 0;
    this->quantum = quantum;
}
//GETTERS
int Process::getId(){
	return this->id;
}
double Process::getClock(){
	return this->clock;
}
double Process::getTimeProcessor(){
	return this->timeProcessor;
}
double Process::getTimeProcessing(){
	return this->timeProcessing;
}
double Process::getQuantum(){
	return this->quantum;
}
//SETTERS
void Process::setId(int id){
	this->id=id;
}
void Process::setClock(double clock){
	this->clock=clock;
}
void Process::setTimeProcessor(double timeProcessor){
	this->timeProcessor=timeProcessor;
}
void Process::setTimeProcessing(double timeProcessing){
	this->timeProcessing=timeProcessing;
}
double Process::setQuantum(int quantum){
	this->quantum=quantum;
}

double Process::calculateProcessor(StatisticsIn stdIn){
	string service = stdIn.getService();
	double *servInter = stdIn.getServiceInter();
	Random random = Random();
	Distribution dist = Distribution(random);
	double num = dist.determineDistribution(service, servInter[0], servInter[1]);
    return num;
}
