#ifndef PROCESOS_H
#define PROCESOS_H


class Procesos
{
    public:
        //Constructor
            Procesos();

        //Atributos
            //Estadisticas
            int tiempoInicio;       //Inicio del proceso
            int tiempoTermino;      //Final del proceso
            int tiempoProcesador;   //Tiempo en el procesador
            int tiempoIO;           //Tiempo en el IO
            //Tipos
            bool tipo;          //false = Tipo1 ; true = Tipo2

        //Métodos
            int m_Counter;
};

#endif // PROCESOS_H
