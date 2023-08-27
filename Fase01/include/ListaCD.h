#ifndef LISTACD_H
#define LISTACD_H

#include "NodoCD.h" //llamado al nodo de la lista
#include <string>
#include <iostream>
using namespace std;

class ListaCD //Lista circular doblemente enlazada
{
    public:
        NodoCD *Primero;
        int Tamanio;

        void Insertar(std::string codigo, std::string nombre);//funcion para agregar a la lista
        void mostrar();


        ListaCD();
        virtual ~ListaCD();

    protected:

    private:
};

#endif // LISTACD_H
