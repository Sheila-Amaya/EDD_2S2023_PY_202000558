#include "ListaDoble.h"

ListaDoble::ListaDoble()
{
    //ctor
    this->Primero = 0;
    this->Tamanio = 0;
}

ListaDoble::~ListaDoble()
{
    //dtor
}

void ListaDoble::Insertar(std::string codigo, std::string nombre_tarea, std::string codigo_encargado)
{
    NodoListaDoble *nuevo = new NodoListaDoble(codigo, nombre_tarea, codigo_encargado);
    if(this->Primero == 0)
    {
        this->Primero = nuevo;
        this->Tamanio++;
    }else
    {
        NodoListaDoble *aux = this->Primero;
        while(aux->Siguiente)
        {
            aux = aux->Siguiente;
        }
        nuevo->Anterior = aux;
        aux->Siguiente = nuevo;
        this->Tamanio++;
    }
}

void ListaDoble::Asignar(std::string codigo, std::string nombre_tarea, std::string encargado)
{
    if(this->Primero)
    {
        NodoListaDoble *aux = this->Primero;
        while(aux)
        {
            if(aux->Codigo.compare(codigo) == 0 && aux->Nombre_Tarea.compare(nombre_tarea) == 0)
            {
                aux->Codigo_Encargado = encargado;
                break;
            }
            aux = aux->Siguiente;
        }
    }
}

std::string ListaDoble::g_circular(NodoListaDoble *&raiz, int tamanio){
    std::string cuerpo="";
    NodoListaDoble *aux=raiz;
    for (int i = 0; i < tamanio; i++) {
        cuerpo += "nodo";
        cuerpo += std::to_string(i);
        cuerpo += "[label=\"";
        cuerpo += "Código: " + aux->Codigo + "\\n";
        cuerpo += "Tarea: " + aux->Nombre_Tarea + "\\n";
        cuerpo += "\"]; \n";
        aux = aux->Siguiente;
    }

    cuerpo+="nodonull1 -> nodo0 [dir=back];\n";
    for(int i=0; i<tamanio-1;i++){
        cuerpo+="nodo";
        cuerpo+=std::to_string(i);
        cuerpo+= " -> ";
        cuerpo+= "nodo";
        cuerpo+=std::to_string(i+1);
        cuerpo+="\nnodo";
        cuerpo+=std::to_string(i+1);
        cuerpo+= " -> ";
        cuerpo+= "nodo";
        cuerpo+=std::to_string(i);
        cuerpo+="\n";
    }
    cuerpo+="\nnodo";
    cuerpo+=std::to_string(tamanio-1);
    cuerpo+=" -> nodonull2";
    return cuerpo;
}


void ListaDoble::graficar(){
    ofstream archivo;
    archivo.open("Lista_doble.dot",ios::out);
    if (archivo.fail()){
        cout << "se produjo un error al generar el recorrido inorden" << endl;
    }else{
        archivo<<"digraph lista{\n rankdir=LR;\n node[shape = record]; \n nodonull1[label=\"null\"];\n nodonull2[label=\"null\"];\n"<<g_circular(this->Primero,this->Tamanio)<<" \n}";
        archivo.close();
    }
    try{
        system("dot -Tjpg Lista_doble.dot -o Lista_doble.jpg");
    }catch(exception e){
        cout << "Se produjo un error al correr el .dot" << endl;
    }
}
