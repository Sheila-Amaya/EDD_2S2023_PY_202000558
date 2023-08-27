#include "NodoCD.h"

NodoCD::NodoCD(std::string codigo, std::string nombre)
{
    //ctor
    this->Codigo = codigo;
    this->Nombre = nombre;
    this->Siguiente = 0;
    this->Anterior = 0;
}

NodoCD::~NodoCD()
{
    //dtor
}
