#include "NodoCD.h"

NodoCD::NodoCD(std::string nombre,std::string password)
{
    //ctor
    /*this->Nombre = nombre;
    this->Password = password;*/
    this->Siguiente = 0;
    this->Anterior = 0;
    this->EmpleadoSistema = new Empleado(nombre,password);
}

NodoCD::~NodoCD()
{
    //dtor
}
