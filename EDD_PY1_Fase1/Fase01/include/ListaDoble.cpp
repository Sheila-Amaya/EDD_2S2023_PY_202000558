#include "ListaDoble.h"

ListaDoble::ListaDoble()
{
    //ctor
    this->Primero = 0;
    this->Tamanio = 0;
}

ListaDoble::~ListaDoble()
{
    //dtor
}

void ListaDoble::Insertar(std::string codigo, std::string nombre_tarea, std::string codigo_encargado)
{
    NodoListaDoble *nuevo = new NodoListaDoble(codigo, nombre_tarea, codigo_encargado);
    if(this->Primero == 0)
    {
        this->Primero = nuevo;
        this->Tamanio++;
    }else
    {
        NodoListaDoble *aux = this->Primero;
        while(aux->Siguiente)
        {
            aux = aux->Siguiente;
        }
        nuevo->Anterior = aux;
        aux->Siguiente = nuevo;
        this->Tamanio++;
    }
}

void ListaDoble::Asignar(std::string codigo, std::string nombre_tarea, std::string encargado)
{
    if(this->Primero)
    {
        NodoListaDoble *aux = this->Primero;
        while(aux)
        {
            if(aux->Codigo.compare(codigo) == 0 && aux->Nombre_Tarea.compare(nombre_tarea) == 0)
            {
                aux->Codigo_Encargado = encargado;
                break;
            }
            aux = aux->Siguiente;
        }
    }
}
