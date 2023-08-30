#ifndef NODOLISTADOBLE_H
#define NODOLISTADOBLE_H


#include <string>

using namespace std;

class NodoListaDoble
{
    public:

        NodoListaDoble *Siguiente;
        NodoListaDoble *Anterior;

        std::string Codigo;
        std::string Nombre_Tarea;
        std::string Codigo_Encargado;

        NodoListaDoble(std::string codigo, std::string nombre_tarea, std::string codigo_encargado);
        virtual ~NodoListaDoble();

    protected:

    private:
        std::string g_circular(NodoListaDoble *&raiz, int tamanio);
};


#endif // NODOLISTADOBLE_H
