#ifndef NODOCD_H
#define NODOCD_H

#include <string>
using namespace std;

class NodoCD //Nodo lista circular doblemente enlazada
{
    public:
        std::string Nombre;
        std::string Codigo;

        //apuntadores lista
        NodoCD *Siguiente;
        NodoCD *Anterior;



        NodoCD(std::string codigo, std::string nombre); //constructor
        virtual ~NodoCD();

    protected:

    private:
};

#endif // NODOCD_H
