#ifndef COLA_H
#define COLA_H

#include <NodoCola.h>
#include <Proyecto.h>

#include <string>
#include <iostream>

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

        Cola();
        virtual ~Cola();

    protected:

    private:
};

#endif // COLA_H
