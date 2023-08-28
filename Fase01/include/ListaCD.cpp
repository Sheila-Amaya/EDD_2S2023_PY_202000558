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

void ListaCD::procesarArchivo(std::string nombreArchivo)
{
    try
    {
        ifstream lectura;
        lectura.open(nombreArchivo, ios::in);
        bool encabezado = false;

        if (!lectura.is_open()) {
            throw ifstream::failure("No se pudo abrir el archivo");
        }

        for (std::string fila; std::getline(lectura, fila);)
        {
            std::stringstream lineas(fila);
            std::string nombre;
            std::string password;

            if (encabezado)
            {
                getline(lineas, nombre, ',');
                getline(lineas, password, ',');
                this->Insertar(nombre, password);
            }
            else
            {
                encabezado = true;
            }
        }
    }
    catch (exception)
    {
        cout << "\n\tError , no se pudo leer el archivo.." << endl;
    }
}

void ListaCD::Insertar(std::string nombre,std::string codigo)
{
    NodoCD *nuevo = new NodoCD(nombre,codigo);
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
       cout << "Nombre:" << aux->Nombre << endl;
       cout << "contrasenia:" <<aux->Codigo << endl;
       aux = aux->Siguiente;
       contador++;
   }

}
