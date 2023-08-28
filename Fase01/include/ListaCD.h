#ifndef LISTACD_H
#define LISTACD_H

#include "NodoCD.h" //llamado al nodo de la lista
#include <string>
#include <iostream>

//carga masiva
#include <fstream>
#include <string.h>
#include <cstring>
#include <sstream>
#include <stdlib.h>

using namespace std;

class ListaCD //Lista circular doblemente enlazada
{
    public:
        NodoCD *Primero;
        int Tamanio;

        void Insertar(std::string nombre, ::string codigo);//funcion para agregar a la lista
        void mostrar();
        void procesarArchivo(std::string nombre_archivo);


        ListaCD();
        virtual ~ListaCD();

    protected:

    private:
};

#endif // LISTACD_H
