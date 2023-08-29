#include "Cola.h"

Cola::Cola()
{
    //ctor
    this->Primero = 0;
    this->Tamanio = 0;
}

Cola::~Cola()
{
    //dtor
}

void Cola::Encolar(std::string Nombre, std::string TipoPrioridad)
{
    int numero_proyecto = 100 + this->Tamanio;
    Proyecto *nuevoProyecto = new Proyecto("PY-"+std::to_string(numero_proyecto),Nombre); //genera un proyecto
    NodoCola *nuevoNodo = new NodoCola(nuevoProyecto,TipoPrioridad);
    if(this->Primero == 0) //si esta vacia
    {
        this->Primero = nuevoNodo;
        this->Tamanio++;
    }else{ //si tiene por lo menos un elemento
        NodoCola *aux = this->Primero;
        while(aux->Siguiente)
        {
            aux = aux->Siguiente;
        }
        aux->Siguiente = nuevoNodo;
        this->Tamanio++;
    }

    /**
    1. Crear una funcion que tenga una cola temporal, una copia de la cola actual
    2. Cola temporal, le aplican un ordenamiento.
    3. this->Primero = colaTemp.Primero

    funcion Orderna
        *colatemp = this->primero
        ordenamientoBurbuja(colatemp)

    PY-100 | B - PY-101 | B - PY-102 | A
    PY-102 - PY-100 - PY-101
    */
}

void Cola::VerProyectos()
{
    NodoCola *aux = this->Primero;
    int contador = 0;
    while(aux)
    {
        cout << aux->Proyecto_C->Nombre << endl;
        aux = aux->Siguiente;
        contador++;
    }
}


void Cola::Descolar()
{
    if(this->Primero)
    {
        this->Primero = this->Primero->Siguiente;
    }
}



void Cola::Ordenar()
{
    if(this->Primero)
    {
        NodoCola *piv = this->Primero;
        NodoCola *actual;
        int contador = 0;
        while(contador != this->Tamanio)
        {
            actual = piv->Siguiente;
            while(actual)
            {
                if(piv->Prioridad.compare(actual->Prioridad) == 1)
                {
                    Proyecto *tempProyecto = piv->Proyecto_C;
                    std::string tempPrioridad = piv->Prioridad;
                    piv->Proyecto_C = actual->Proyecto_C;
                    piv->Prioridad = actual->Prioridad;
                    actual->Proyecto_C = tempProyecto;
                    actual->Prioridad = tempPrioridad;
                }
                actual = actual->Siguiente;
            }
            piv = piv->Siguiente;
            contador++;
        }
    }
}



NodoCola* Cola::getUltimoProyecto()
{
    if (!this->Primero) {
        return 0; // Return 0 si la cola esta vacia
    }

    NodoCola* ultimoProyecto = this->Primero;// se crea un puntero para rastrear el ultimo
    while (ultimoProyecto->Siguiente) //recorre desde el primer nodo de la cola
    {
        ultimoProyecto = ultimoProyecto->Siguiente;
    }
    return ultimoProyecto; //luego de terminar el recorrido apunta al ultimo nodo
}


