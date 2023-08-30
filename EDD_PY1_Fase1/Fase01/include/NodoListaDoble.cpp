#include "NodoListaDoble.h"


NodoListaDoble::NodoListaDoble(std::string codigo, std::string nombre_tarea, std::string codigo_encargado)
{
    //ctor
    this->Anterior = 0;
    this->Siguiente = 0;

    this->Codigo = codigo;
    this->Nombre_Tarea = nombre_tarea;
    this->Codigo_Encargado = codigo_encargado;

}

NodoListaDoble::~NodoListaDoble()
{
    //dtor
}
