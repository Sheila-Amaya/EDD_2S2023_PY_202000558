#include <iostream>

#include "ListaCD.h" //importa la clase
#include "Matriz.h"

using namespace std;

//


bool iniciarSesion();
void mostrarMenu();
void mostrarSubMenu(); //menu empleados
void mostrarSubMenu1(); //menu proyecto
void mostrarSubMenu2(); //menu tarea
void cargaMasiva();

int main()
{
    /*Matriz *matriz = new Matriz();
    matriz->insertarElemento(0,0);
    matriz->insertarElemento(1,1);
    matriz->insertarElemento(2,2);
    matriz->insertarElemento(3,3);

    matriz->insertarElemento(4,0);
    matriz->insertarElemento(5,1);
    matriz->insertarElemento(5,0);
    matriz->insertarElemento(5,3);
    matriz->Graficar();*/

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


void cargaMasiva()
{

    string nombreArchivo;
    cout << "\n\tIngrese el nombre del archivo: ";
    cin >> nombreArchivo;

    string rutaRelativa = "../Archivo Entrada/" + nombreArchivo;

    ListaCD *lista = new ListaCD();
    lista->procesarArchivo(rutaRelativa);
    //lista->mostrar();
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
                cout << "\tRealizar subopcion 2" << endl;
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

}

//submenu crear tareas
void mostrarSubMenu2()
{

        cout << "\n\t=============      EDD PROJECT-UP     =============" << endl;
        cout << "\t============= Bienvenido PM-202000558 =============" << endl;
        cout << "\t=============     MENU DE TAREAS     =============\n" << endl; //crear tarea y asignar

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
        cout << "\t5. Salir" << endl;
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
                cout << "\tRealizar opcion 4" << endl;
                break;

            case 5:
                exit(0);
                break;


            default:
                cout << "\n\topcion invalida. Intente de nuevo." << endl;
                break;
        }

    } while (opcion != 5);
}



