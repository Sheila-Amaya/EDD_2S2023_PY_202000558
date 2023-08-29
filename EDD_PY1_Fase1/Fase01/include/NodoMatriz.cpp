#include "NodoMatriz.h"

NodoMatriz::NodoMatriz(std::string coordenada, int x, int y)
{
    //ctor
    this->Siguiente = 0;
    this->Anterior = 0;
    this->Abajo = 0;
    this->Arriba = 0;

    this->PosX = x;
    this->PosY = y;

    this->Coordenada = coordenada;

}

NodoMatriz::~NodoMatriz()
{
    //dtor
}
