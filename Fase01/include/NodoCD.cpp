#include "NodoCD.h"

NodoCD::NodoCD(std::string nombre,std::string codigo)
{
    //ctor
    this->Nombre = nombre;
    this->Codigo = codigo;
    this->Siguiente = 0;
    this->Anterior = 0;
}

NodoCD::~NodoCD()
{
    //dtor
}
