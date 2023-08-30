#include "NodoCola.h"

NodoCola::NodoCola(std::string nombreP, Proyecto *nuevoProyecto, std::string prioridad)
{
    //ctor
    this->Siguiente = 0;
    this->NombreP = nombreP;
    this->Proyecto_C = nuevoProyecto;
    this->Prioridad = prioridad;

}

NodoCola::~NodoCola()
{
    //dtor
}
