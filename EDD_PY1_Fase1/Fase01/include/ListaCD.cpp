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


void ListaCD::Insertar(std::string nombre, std::string password)
{
    NodoCD *nuevo = new NodoCD(nombre, password);
    int numero_empleado = 1 + this->Tamanio;
    std::string codigo = (numero_empleado < 100 ? (numero_empleado < 10 ? "SC-00"+std::to_string(numero_empleado) : "SC-0"+std::to_string(numero_empleado)): "SC-"+std::to_string(numero_empleado));
    nuevo->EmpleadoSistema->Codigo = codigo;
    if(this->Primero == 0)
    {
        /*------------------*/
        nuevo->Anterior = nuevo;
        nuevo->Siguiente = nuevo;

        this->Primero = nuevo;
        this->Tamanio++;
    }else
    {
        NodoCD *aux = this->Primero;
        int contador = 1;
        while(this->Tamanio > contador)
        {
            aux = aux->Siguiente;
            contador++;
        }
        nuevo->Anterior = aux;
        nuevo->Siguiente = this->Primero;//No existe en doble enlazada
        aux->Siguiente = nuevo;
        this->Primero->Anterior = nuevo; //No exites ne doble enlazada
        this->Tamanio++;
    }
}


void ListaCD::mostrar()
{
   NodoCD *aux = this->Primero;
   int contador = 0;
   while(this->Tamanio > contador)
   {
       cout << "\n\tNombre :" << aux->EmpleadoSistema->Nombre << endl;
       cout << "\tContrasenia :" << aux->EmpleadoSistema->Password << endl;
       /*cout << "Nombre:" << aux->Nombre << endl;
       cout << "contrasenia:" <<aux->Password << endl;*/
       aux = aux->Siguiente;
       contador++;
   }


}

std::string ListaCD::g_circular(NodoCD *&raiz, int tamanio) {
    std::string cuerpo = "";
    NodoCD *aux = raiz;

    for (int i = 0; i < tamanio; i++) {
        cuerpo += "nodo";
        cuerpo += std::to_string(i);
        cuerpo += "[label=\"";
        cuerpo += "Nombre: " + aux->EmpleadoSistema->Nombre + "\\n";
        cuerpo += "Código: " + aux->EmpleadoSistema->Codigo;
        cuerpo += "\"]; \n";
        aux = aux->Siguiente;
    }

    for (int i = 0; i < tamanio; i++) {
        cuerpo += "nodo";
        cuerpo += std::to_string(i);
        cuerpo += " -> ";
        cuerpo += "nodo";
        cuerpo += std::to_string((i + 1) % tamanio);
        cuerpo += "\n";
        cuerpo += "nodo";
        cuerpo += std::to_string((i + 1) % tamanio);
        cuerpo += " -> ";
        cuerpo += "nodo";
        cuerpo += std::to_string(i);
        cuerpo += "\n";
    }

    return cuerpo;
}

void ListaCD::graficar() {
    ofstream archivo;
    string ruta_reportes = "../Reportes/";
    string nombre_archivo_dot = "Lista_circular_doble.dot"; // Change the filename
    string nombre_imagen = "Lista_circular_doble.jpg"; // Change the filename

    archivo.open(ruta_reportes + nombre_archivo_dot, ios::out);
    if (archivo.fail()) {
        cout << "Se produjo un error al generar el archivo DOT" << endl;
    } else {
        archivo << "digraph lista{\n rankdir=LR;\n node[shape = record]; \n" << g_circular(this->Primero, this->Tamanio) << " \n}";
        archivo.close();
    }
    try {
        system(("dot -Tjpg -Gcharset=latin1 " + ruta_reportes + nombre_archivo_dot + " -o " + ruta_reportes + nombre_imagen).c_str());
        cout << "\n\tSe genero el reporte con exito\n" << endl;
    } catch (exception e) {
        cout << "Se produjo un error al generar la imagen '" << nombre_imagen << "'." << endl;
    }
}
