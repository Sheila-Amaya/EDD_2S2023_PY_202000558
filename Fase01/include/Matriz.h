#ifndef MATRIZ_H
#define MATRIZ_H

#include "NodoMatriz.h"

class Matriz //matriz dispersa
{
    public:
        NodoMatriz *Raiz;

        void insertarElemento(int x, int y); //nombre proyecto, nombre empleado

        Matriz();
        virtual ~Matriz();

    protected:

    private:
        NodoMatriz *buscarFila(int y);
        NodoMatriz *buscarColumna(int x);
        NodoMatriz *nueva_Columna(int x);
        NodoMatriz *nueva_fila(int y);
        NodoMatriz *insertarFila(NodoMatriz *nuevo, NodoMatriz *cabeza_fila);
        NodoMatriz *insertarColumna(NodoMatriz *nuevo, NodoMatriz *cabeza_columna);

};

#endif // MATRIZ_H
