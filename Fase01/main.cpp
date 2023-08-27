#include <iostream>

//#include "ListaCD.h" //importa la clase

using namespace std;

//


bool iniciarSesion();
void mostrarMenu();

int main()
{
    if (iniciarSesion()) {
        cout << "\n\tsuccessfully logged in.. welcome\n" << endl;
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
                cout << "\tRealizar opcion 1" << endl;
                break;

            case 2:
                cout << "\tRealizar opcion 2" << endl;
                break;

            case 3:
                cout << "\tRealizar opcion 3" << endl;
                break;

            case 4:
                cout << "\tRealizar opcion 4" << endl;
                break;

            default:
                cout << "\n\topcion invalida. Intente de nuevo." << endl;
                break;
        }

    } while (opcion != 5);
}



