#include "eda/StatisticsOut.h"

StatisticsOut::StatisticsOut()
{
    //General Data
    this->totalSimulationTime=0.0;
    this->throughputTime=0.0;
    this->idleTime=0.0;

    //Processor Data
    this->queueTime=0.0;
    this->processTime=0.0;
    this->IOTime=0.0;

    //Queue Data
   	this->queueMaxLength=0;
    this->queueAvgLength=0.0;
}

StatisticsOut::StatisticsOut(double totalSimulationTime, double throughputTime, double idleTime, double queueTime, double processTime, double IOTime, int queueMaxLength, double queueAvgLength){
	//General Data
    this->totalSimulationTime=totalSimulationTime;
    this->throughputTime=throughputTime;
    this->idleTime=idleTime;

    //Processor Data
    this->queueTime=queueTime;
    this->processTime=processTime;
    this->IOTime=IOTime;

    //Queue Data
   	this->queueMaxLength=queueMaxLength;
    this->queueAvgLength=queueAvgLength;
}
//GETTERS
double StatisticsOut::getTotalSimulationTime(){
	return this->totalSimulationTime;
}
double StatisticsOut::getThroughputTime(){
	return this->throughputTime;
}
double StatisticsOut::getIdleTime(){
	return this->idleTime;
}
double StatisticsOut::getQueueTime(){
	return this->queueTime;
}
double StatisticsOut::getProcessTime(){
	return this->processTime;
}
double StatisticsOut::getIOTime(){
	return this->IOTime;
}
int StatisticsOut::getQueueMaxLength(){
	return this->queueMaxLength;
}
double StatisticsOut::getQueueAvgLength(){
	return this->queueAvgLength;
}

//SETTERS
void StatisticsOut::setTotalSimulationTime(double totalSimulationTime){
	this->totalSimulationTime=totalSimulationTime;
}
void StatisticsOut::setThroughputTime(double throughputTime){
	this->throughputTime=throughputTime;
}
void StatisticsOut::setIdleTime(double idleTime){
	this->idleTime=idleTime;
}
void StatisticsOut::setQueueTime(double queueTime){
	this->queueTime=queueTime;
}
void StatisticsOut::setProcessTime(double processTime){
	this->processTime=processTime;
}
void StatisticsOut::setIOTime(double IOTime){
	this->IOTime=IOTime;
}
void StatisticsOut::setQueueMaxLength(int queueMaxLength){
	this->queueMaxLength=queueMaxLength;
}
void StatisticsOut::setQueueAvgLength(double queueAvgLength){
	this->queueAvgLength=queueAvgLength;
}