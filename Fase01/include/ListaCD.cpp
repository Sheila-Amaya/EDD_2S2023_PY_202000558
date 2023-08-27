#include "ListaCD.h"

ListaCD::ListaCD()
{
    //ctor

    //inicializar las variables
    this->Primero = 0;
    this->Tamanio = 0;
}

ListaCD::~ListaCD()
{
    //dtor
}

void ListaCD::Insertar(std::string codigo, std::string nombre)
{
    NodoCD *nuevo = new NodoCD(codigo, nombre);
    if (this->Primero == 0)
    {
        nuevo->Anterior = nuevo;
        nuevo->Siguiente = nuevo;
        this->Primero = nuevo;
        this->Tamanio++;
    }
    else
    {
        NodoCD *aux = this->Primero->Anterior; //
        nuevo->Anterior = aux;
        nuevo->Siguiente = this->Primero;
        aux->Siguiente = nuevo; //
        this->Primero->Anterior = nuevo;
        this->Tamanio++;
    }
}




void ListaCD::mostrar()
{
   NodoCD *aux = this->Primero;
   int contador = 0;
   while(this->Tamanio > contador)
   {
       cout << aux->Codigo << endl;
       aux = aux->Siguiente;
       contador++;
   }

}
