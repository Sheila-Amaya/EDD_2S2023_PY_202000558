#include <iostream>

#include "ListaCD.h" //importa la clase
#include "Cola.h"
#include "Matriz.h"

#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

//
ListaCD listaC; // lista circular doblemente enlazada
Cola cola; // cola prioridad
Matriz matriz;
ListaDoble lista_doble;// lista doblemente enlazada

bool iniciarSesion();
void mostrarMenu();
void mostrarSubMenu(); //menu empleados
void CrearP(); //menu proyecto
void CrearT(); //menu tarea
void cargaMasiva();
void cargaManual();

int main()
{


    if (iniciarSesion()) {
        cout << "\n\thas iniciado sesion correctamente... bienvenido\n" << endl;
        mostrarMenu();
    }

    return 0;
}


//funcion para iniciar sesion
bool iniciarSesion()
{
    string username;
    string password;

    do {
        cout << "\n\t=============      EDD PROJECT-UP     =============" << endl;
        cout << "\tUSUARIO: " ;
        cin >> username;

        cout << "\tPASSWORD: " ;
        cin >> password;



        if (username == "PM-202000558" && password == "pmPassword123") {
            return true;
        } else {
            cout << "\n\tpassword o username incorrectos, intentelo de nuevo..." << endl;
        }

    } while (username != "PM-202000558" || password != "pmPassword123");

    return false;
}


void cargaManual()
{
    string nombre,password;

    cout << "\n\tIngrese los siguientes datos:" << endl;
    cout << "\tNombre:" ;
    cin >> nombre;
    cout << "\tPassword:" ;
    cin >> password;

    listaC.Insertar(nombre,password);

}

void cargaMasiva()
{

    string nombreArchivo;
    cout << "\n\tIngrese el nombre del archivo: ";
    cin >> nombreArchivo;

    string rutaRelativa = "../Archivo Entrada/" + nombreArchivo;

    listaC.procesarArchivo(rutaRelativa);
    cout << "\tCarga realizada con exito...\n ";
}


//submenu de carga empleados
void mostrarSubMenu()
{
    int subopcion;

    do {
        cout << "\n\t=============      EDD PROJECT-UP     =============" << endl;
        cout << "\t============= Bienvenido PM-202000558 =============" << endl;
        cout << "\t=============     CARGA EMPLEADOS     =============\n" << endl;
        cout << "\t1. Carga Manual" << endl;
        cout << "\t2. Carga Masiva" << endl;
        cout << "\t3. Regresar al menu principal" << endl;
        cout << "\n\tElija una opcion: ";
        cin >> subopcion;

        switch (subopcion) {
            case 1:
                cargaManual();
                break;

            case 2:
                cargaMasiva();
                break;

            case 3:
                cout << "\tVolviendo al Menu Principal..." << endl;
                mostrarMenu();
                break;

            default:
                cout << "\topcion invalida. Intente de nuevo." << endl;
                break;
        }

    } while (subopcion != 3);
}


//submenu crear proyecto
void CrearP()
{
        cout << "\n\t=============      EDD PROJECT-UP     =============" << endl;
        cout << "\t============= Bienvenido PM-202000558 =============" << endl;
        cout << "\t=============     MENU DE PROYECTO     =============\n" << endl; //crear proyecto y asignar

        string nombreP ,prioridad;

        cout << "\tIngrese el nombre del proyecto: " ;
        cin >> nombreP;
        cout << "\tIngrese tipo de prioridad (A-C): " ;
        cin >> prioridad;

        // Validar que la prioridad ingresada sea A, B o C
        while (prioridad != "A" && prioridad != "B" && prioridad != "C")
        {
            cout << "\tPrioridad no valida. Ingrese tipo de prioridad (A-C): ";
            cin >> prioridad;
        }
        cola.Encolar(nombreP,prioridad);

        NodoCola *ultimoProyecto = cola.getUltimoProyecto();
        if (ultimoProyecto) { //si no es 0
            cout << "\tCreado exitosamente: " << ultimoProyecto->Proyecto_C->Nombre << endl;
        }

        //cout << "PROYECTOS\n";
        //cola.VerProyectos();


}

// Función para generar un número aleatorio en un rango dado
int generarNumeroAleatorio(int min, int max) {
    return min + (rand() % (max - min + 1));
}

// Función para generar el código de tarea en el formato especificado
string generarCodigoTarea(string tipo) {
    int numero = generarNumeroAleatorio(1, 999);
    ostringstream ss;
    ss << tipo << "-" << setfill('0') << setw(3) << numero;
    return ss.str();
}


void asignarProyecto() {
    cout << "\n\t=============      EDD PROJECT-UP     =============" << endl;
    cout << "\t============= Bienvenido PM-202000558 =============" << endl;
    cout << "\t============= ASIGNAR TAREA A PROYECTO =============\n" << endl;

    // Mostrar proyectos disponibles
    NodoCola *aux = cola.Primero; // Obtener el primer proyecto en la cola

    if (!aux) {
        cout << "No hay proyectos disponibles para asignar una tarea." << endl;
        return;
    }

    cout << "\tProyectos disponibles para asignar tarea:\n";
    while (aux) {
        cout << "\tCodigo: " << aux->Proyecto_C->Codigo << ", Nombre: " << aux->Proyecto_C->Nombre <<  endl;
        aux = aux->Siguiente;
    }

    // Elegir un proyecto por su código
    string codigoProyecto;
    cout << "\n\tIngrese el codigo del proyecto al que desea asignar una tarea: ";
    cin >> codigoProyecto;

    aux = cola.Primero; // Reiniciar aux al primer proyecto
    bool proyectoEncontrado = false;

    while (aux) {
        if (aux->Proyecto_C->Codigo == codigoProyecto) {
            cout << "\tHa seleccionado el proyecto: " << aux->Proyecto_C->Nombre << endl;
            proyectoEncontrado = true;
            break;
        }
        aux = aux->Siguiente;
    }

    if (!proyectoEncontrado) {
        cout << "\tNo se encontro un proyecto con ese código." << endl;
        return;
    }

    string nombreTarea;
    cout << "\tIngrese el tipo de tarea: ";
    cin >>nombreTarea;

    // Generar código de tarea aleatorio
    string codE;
    cout << "\tIngrese el codigo Empleado: ";
    cin >>codE;


    string codigoTarea = generarCodigoTarea(codE);

    // Insertar la tarea en la ListaDoble
    lista_doble.Insertar(codigoTarea, nombreTarea, codE);

    cout << "\tTarea asignada al proyecto exitosamente." << endl;
}


//submenu crear tareas
void CrearT()
{
        cout << "\n\t=============      EDD PROJECT-UP     =============" << endl;
        cout << "\t============= Bienvenido PM-202000558 =============" << endl;
        cout << "\t=============     MENU DE TAREAS     =============\n" << endl;



}


void asignarTarea()
{

}


void reportes()
{

        cout << "\n\t=============      EDD PROJECT-UP     =============" << endl;
        cout << "\t============= Bienvenido PM-202000558 =============" << endl;
        cout << "\t=============     AREA DE REPORTES     =============\n" << endl;

        int opcion;

        do {
            cout << "\t1. Reporte de la matriz dispersa" << endl;
            cout << "\t2. Reporte de la cola" << endl;
            cout << "\t3. Reporte de la circular doblemente " << endl;
            cout << "\t4. Reporte de la doblemente enlazada" << endl;
            cout << "\t5. Reporte JSON" << endl;
            cout << "\t6. Regresar" << endl;
            cout << "";
            cout << "\n\tElija una opcion: ";
            cin >> opcion;

            switch (opcion) {
            case 1:
                cout << "nada aun";
                break;

            case 2:
                cola.Ordenar();
                cola.graficar();
                reportes();
                break;

            case 3:
                listaC.graficar();
                reportes();
                break;

            case 4:
                lista_doble.graficar();
                reportes();
                break;

            case 5:
                cout << "nada aun";
                break;

            case 6:
                mostrarMenu();
                break;

        }

    } while (opcion != 6);
}

void mostrarMenu()
{
    int opcion;

    do {
        cout << "\n\t=============      EDD PROJECT-UP     =============" << endl;
        cout << "\t============= Bienvenido PM-202000558 =============\n" << endl;
        cout << "\t1. Cargar Empleados" << endl;
        cout << "\t2. Crear Proyecto" << endl;
        cout << "\t3. Asignar Proyecto" << endl;
        cout << "\t4. Crear Tareas" << endl;
        cout << "\t5. Asignar Tareas" << endl;
        cout << "\t6. Reportes" << endl;
        cout << "\t7. Salir" << endl;
        cout << "\n\tElija una opcion: ";
        cout << "";
        cin >> opcion;

        switch (opcion) {
            case 1:
                mostrarSubMenu();
                break;

            case 2:
                CrearP();
                break;

            case 3:
                asignarProyecto();
                break;

            case 4:
                CrearT();
                break;

            case 5:
                asignarTarea();
                break;

            case 6:
                reportes();
                break;

            case 7:
                exit(0);
                break;


            default:
                cout << "\n\topcion invalida. Intente de nuevo." << endl;
                break;
        }

    } while (opcion != 7);
}



