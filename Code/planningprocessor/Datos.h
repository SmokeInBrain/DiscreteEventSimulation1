#include <string>
using namespace std;
class Datos
{
private:
	//VARIABLES PRIVADAS
	int numproc;
	double quantum;
	string algoritmo;
	string interarrivo;
	double interarrivoInter[2];
	string servicio;
	double servicioInter[2];
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
	string getAlgoritmo();
	string getInterarrivo();
	double* getInterarrivoInter();
	string getServicio();
	double* getServicioInter();
	string getRP();
	double* getRPInter();
	string getRIO();
	double* getRIOInter();
	//SETTERS
	void setNumProc(int numproc);
	void setQuantum(double quantum);
	void setAlgoritmo(string algoritmo);
	void setInterarrivo(string interarrivo);
	void setInterarrivoInter(double interarrivo1, double interarrivo2);
	void setServicio(string servicio);
	void setServicioInter(double servicio1, double servicio2);
	void setRP(string RP);
	void setRPInter(double RP1, double RP2);
	void setRIO(string RIO);
	void setRIOInter(double RIOInter1, double RIOInter2);
	void setNombreArchivo(string nombreArchivo);
};

