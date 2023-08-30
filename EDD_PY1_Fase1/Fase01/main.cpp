#include <iostream>

#include "ListaCD.h" //importa la clase
#include "Cola.h"
#include "Matriz.h"

#include <string>

using namespace std;

//
ListaCD listaC; // lista circular doblemente enlazada
Cola cola;

bool iniciarSesion();
void mostrarMenu();
void mostrarSubMenu(); //menu empleados
void mostrarSubMenu1(); //menu proyecto
void mostrarSubMenu2(); //menu tarea
void cargaMasiva();

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
    //cout << "Puestos Disponibles" ;
    //mostrar de la LD pusetos disponibles

    listaC.Insertar(nombre,password);

}

void cargaMasiva()
{

    string nombreArchivo;
    cout << "\n\tIngrese el nombre del archivo: ";
    cin >> nombreArchivo;

    string rutaRelativa = "../Archivo Entrada/" + nombreArchivo;

    listaC.procesarArchivo(rutaRelativa);
    listaC.mostrar();
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
void mostrarSubMenu1()
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
        } else {
            cout << "\tNingun proyecto en cola" << endl;
        }


        //cout << "PROYECTOS\n";
        //cola.VerProyectos();


}

//submenu crear tareas
void mostrarSubMenu2()
{

        cout << "\n\t=============      EDD PROJECT-UP     =============" << endl;
        cout << "\t============= Bienvenido PM-202000558 =============" << endl;
        cout << "\t=============     MENU DE TAREAS     =============\n" << endl; //crear tarea y asignar

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
            cout << "\t3. Regresar" << endl;
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
                break;

            case 3:
                mostrarSubMenu();
                break;

        }

    } while (opcion != 3);
}

void mostrarMenu()
{
    int opcion;

    do {
        cout << "\n\t=============      EDD PROJECT-UP     =============" << endl;
        cout << "\t============= Bienvenido PM-202000558 =============\n" << endl;
        cout << "\t1. Cargar Empleados" << endl;
        cout << "\t2. Crear Proyecto" << endl;
        cout << "\t3. Crear Tareas" << endl;
        cout << "\t4. Asignar Tareas" << endl;
        cout << "\t5. Reportes" << endl;
        cout << "\t6. Salir" << endl;
        cout << "\n\tElija una opcion: ";
        cout << "";
        cin >> opcion;

        switch (opcion) {
            case 1:
                mostrarSubMenu();
                break;

            case 2:
                mostrarSubMenu1();
                break;

            case 3:
                mostrarSubMenu2();
                break;

            case 4:
                cout << "op4";
                break;

            case 5:
                reportes();
                break;

            case 6:
                exit(0);
                break;


            default:
                cout << "\n\topcion invalida. Intente de nuevo." << endl;
                break;
        }

    } while (opcion != 5);
}



