#ifndef LISTADOBLE_H
#define LISTADOBLE_H

#include "NodoListaDoble.h"
#include <string>

using namespace std;

class ListaDoble
{
    public:
        NodoListaDoble *Primero;
        int Tamanio;
        void Insertar(std::string codigo, std::string nombre_tarea, std::string codigo_encargado);
        void Asignar(std::string codigo, std::string nombre_tarea, std::string encargado);
        ListaDoble();
        virtual ~ListaDoble();

    protected:

    private:
};

#endif // LISTADOBLE_H
