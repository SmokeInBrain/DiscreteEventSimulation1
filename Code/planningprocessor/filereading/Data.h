#include <string>
using namespace std;
class Data
{
private:
	//VARIABLES PRIVADAS
	int numproc;
	double quantum;
	string algorithm;
	string interarrive;
	double interarriveInter[2];
	string service;
	double serviceInter[2];
	string RP;
	double RPInter[2]; 
	string RIO;
	double RIOInter[2];
	////VARIABLES PRIVADAS///////


	///////////METODOS PUBLICOS/////////////////////////////////
	//////////CONSTRUCTORES, ACCESORES Y MUTADORES//////////////
public:
	//AQUÍ VA LA DECLARACIÓN DE MÉTODOS////
    //CONSTRUCTORES
    Datos(int numproc, double quantum, string algoritmo, string interarrivo, string servicio, string RP, string RIO, double interarrivoInter1, double interarrivoInter2, double servicioInter1, double servicioInter2, double RPInter1, double RPInter2, double RIOInter1, double RIOInter2);
    Datos();
    //GETTERS
	int getNumProc();
	double getQuantum();
	string getAlgorithm();
	string getInterarrive();
	double* getInterarriveInter();
	string getService();
	double* getServiceInter();
	string getRP();
	double* getRPInter();
	string getRIO();
	double* getRIOInter();
	//SETTERS
	void setNumProc(int numproc);
	void setQuantum(double quantum);
	void setAlgorithm(string algoritmo);
	void setInterarrive(string interarrivo);
	void setInterarriveInter(double interarrivo1, double interarrivo2);
	void setService(string servicio);
	void setServiceInter(double servicio1, double servicio2);
	void setRP(string RP);
	void setRPInter(double RP1, double RP2);
	void setRIO(string RIO);
	void setRIOInter(double RIOInter1, double RIOInter2);
};

