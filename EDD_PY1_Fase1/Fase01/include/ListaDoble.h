#ifndef LISTADOBLE_H
#define LISTADOBLE_H

#include "NodoListaDoble.h"

#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;


class ListaDoble
{
    public:
        NodoListaDoble *Primero;
        int Tamanio;
        void Insertar(std::string codigo, std::string nombre_tarea, std::string codigo_encargado);
        void Asignar(std::string codigo, std::string nombre_tarea, std::string encargado);
        void graficar();

        ListaDoble();
        virtual ~ListaDoble();

    protected:

    private:
        std::string g_circular(NodoListaDoble *&raiz, int tamanio);
};

#endif // LISTADOBLE_H
