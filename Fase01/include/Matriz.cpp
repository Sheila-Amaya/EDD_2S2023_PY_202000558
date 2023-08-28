#include "Matriz.h"

Matriz::Matriz()
{
    //ctor
    this->Raiz = new NodoMatriz("Raiz",-1,-1);

}

Matriz::~Matriz()
{
    //dtor
}

//funciones
NodoMatriz* Matriz::buscarFila(int y)
{
    NodoMatriz *aux = this->Raiz;
    while(aux != 0)
    {
        if (aux->PosY == y)
        {
            return aux;
        }
        aux = aux->Abajo;
    }
    return 0;
}


NodoMatriz* Matriz::buscarColumna(int x)
{
    NodoMatriz *aux = this->Raiz;
    while(aux != 0)
    {
        if (aux->PosX == x)
        {
            return aux;
        }
        aux = aux->Siguiente;
    }
    return 0;

}


NodoMatriz* Matriz::insertarFila(NodoMatriz *nuevo, NodoMatriz *cabeza_fila)
{
    NodoMatriz *temp = cabeza_fila;
    bool piv = false;
    while(temp->Abajo)
    {
        if(temp->PosY == nuevo->PosY)
        {
            temp->PosX = nuevo->PosX;
            temp->Coordenada = nuevo->Coordenada;
            return temp;
        }else if(temp->PosY > nuevo->PosY){
            piv = true;
            break;

        }
        temp = temp->Abajo;
    }
    if(piv)//ordenar
    {
        nuevo->Abajo = temp;
        temp->Arriba->Abajo = nuevo;
        nuevo->Arriba = temp->Arriba;
        temp->Arriba = nuevo;
    }else{
        temp->Abajo = nuevo;
        nuevo->Anterior =temp;
    }
}


NodoMatriz* Matriz::insertarColumna(NodoMatriz *nuevo, NodoMatriz *cabeza_columna)
{
    NodoMatriz *temp = cabeza_columna;
    bool piv = false;
    while(temp->Siguiente)
    {
        if(temp->PosX == nuevo->PosX)
        {
            temp->PosY = nuevo->PosY;
            temp->Coordenada = nuevo->Coordenada;
            return temp;
        }else if(temp->PosX > nuevo->PosX){
            piv = true;
            break;

        }
        temp = temp->Siguiente;
    }
    if(piv)//ordenar
    {
        nuevo->Siguiente = temp;
        temp->Anterior->Siguiente = nuevo;
        nuevo->Anterior = temp->Anterior;
        temp->Anterior = nuevo;
    }else{
        temp->Siguiente = nuevo;
        nuevo->Anterior =temp;
    }
}

NodoMatriz* Matriz::nueva_fila(int y)
{
    std::string fil = "F";
    fil += std::to_string(y);
    NodoMatriz *fila = this->insertarFila(new NodoMatriz(fil,-1,y),this->Raiz);
    return fila;
}

NodoMatriz* Matriz::nueva_Columna(int x)
{
    std::string col = "C";
    col += std::to_string(x);
    NodoMatriz *columna = this->insertarColumna(new NodoMatriz(col,x,-1),this->Raiz);
    return columna;
}


void Matriz::insertarElemento(int x, int y)
{
    std::string coordenada = std::to_string(x);
    coordenada += ",";
    coordenada += std::to_string(y);
    NodoMatriz *nuevo = new NodoMatriz(coordenada,x,y);
    NodoMatriz *nodo_columna = this->buscarColumna(x);
    NodoMatriz *nodo_fila =this->buscarFila(y);


    if(nodo_columna == 0 && nodo_fila == 0) //no exite fila ni columna
    {
        nodo_columna = this->nueva_Columna(x);
        nodo_fila = this->nueva_fila(y);
        nuevo = this->insertarFila(nuevo,nodo_columna);
        nuevo = this->insertarColumna(nuevo,nodo_fila);

    }else if(nodo_columna == 0 && nodo_fila != 0) //columna no existe pero fila si
    {
        nodo_columna = this->nueva_Columna(x);
        nuevo = this->insertarFila(nuevo,nodo_columna);
        nuevo = this->insertarColumna(nuevo,nodo_fila);

    }else if(nodo_columna != 0 && nodo_fila == 0) //columna si existe pero fila no
    {
        nodo_fila = this->nueva_fila(y);
        nuevo = this->insertarFila(nuevo,nodo_columna);
        nuevo = this->insertarColumna(nuevo,nodo_fila);

    }else if(nodo_columna != 0 && nodo_fila != 0) //si existe columna y fila
    {
        nuevo = this->insertarFila(nuevo,nodo_columna);
        nuevo = this->insertarColumna(nuevo,nodo_fila);
    }

}


