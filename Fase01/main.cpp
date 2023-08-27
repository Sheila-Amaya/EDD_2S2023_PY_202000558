#include <iostream>

#include "ListaCD.h" //importa la clase

using namespace std;

int main()
{
    //instancia de la lista

    ListaCD *Lista = new ListaCD();
    Lista->Insertar("BDEV-001","HOLA");
    Lista->Insertar("BDEV-002","HOLA");
    Lista->Insertar("BDEV-003","HOLA");
    Lista->mostrar();

    return 0;
}
