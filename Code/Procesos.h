#ifndef PROCESOS_H
#define PROCESOS_H

#include "calculos.h"
#include "estadistica.h"

class Procesos
{
    public:
        //Constructor
            Procesos(int tipo, int identificador, Estadistica datos);

        //Atributos
            //Datos
            int identificador;
            //Estadisticas
            float timeProcesado;    //Tiempo procesado
            float timeProcesador;   //Tiempo en el procesador
            float timeIO;           //Tiempo en el IO
            //Tipos
            int tipo;          //false = Tipo1 ; true = Tipo2

        //Métodos

};

#endif // PROCESOS_H
