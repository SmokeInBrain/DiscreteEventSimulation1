
#include <string>
#include "Datos.h"
using namespace std;
class Archivo
{
private:
	Datos dato;
	string nombre;
public:
	Archivo(Datos dato, string nombre);
	Archivo();
	~Archivo();
	//GETTERS
	Datos getDato();
	string getNombre();
	//SETTERS
	void setDato(Datos dato);
	void setNombre(string nombre);
	//METODOS
	void lectura();
	void escrituraSalida();
	void escrituraLog();

};

int main(){
	return 0;
}