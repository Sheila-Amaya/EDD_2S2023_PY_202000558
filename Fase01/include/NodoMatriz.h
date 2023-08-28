#ifndef NODOMATRIZ_H
#define NODOMATRIZ_H

#include <string>
using namespace std;

class NodoMatriz
{
    public:
        NodoMatriz *Siguiente;
        NodoMatriz *Anterior;
        NodoMatriz *Abajo;
        NodoMatriz *Arriba;

        int PosX;
        int PosY;

        std::string Coordenada;

        NodoMatriz(std::string coordenada, int x, int y);
        virtual ~NodoMatriz();

    protected:

    private:
};

#endif // NODOMATRIZ_H
