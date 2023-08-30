#ifndef COLA_H
#define COLA_H

#include <NodoCola.h>
#include <Proyecto.h>

#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;


using namespace std;

class Cola
{
    public:

        NodoCola *Primero;
        int Tamanio;
        void Encolar(std::string Nombre, std::string TipoPrioridad);
        void Descolar();
        void VerProyectos();
        void Ordenar();

        NodoCola* getUltimoProyecto();
        void graficar();

        Cola();
        virtual ~Cola();

    protected:
        std::string g_cola(NodoCola *&raiz, int tamanio);

    private:
};

#endif // COLA_H
