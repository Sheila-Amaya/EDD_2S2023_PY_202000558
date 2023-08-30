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

using namespace std;

class ListaCD //Lista circular doblemente enlazada
{
    public:
        NodoCD *Primero;
        int Tamanio;

        void Insertar(std::string nombre, ::string password);//funcion para agregar a la lista
        void mostrar();
        void procesarArchivo(std::string nombre_archivo);
        void graficar();


        ListaCD();
        virtual ~ListaCD();

    protected:
        std::string g_circular(NodoCD *&raiz, int tamanio);

    private:
};

#endif // LISTACD_H
