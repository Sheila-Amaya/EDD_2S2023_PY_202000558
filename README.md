# EDD_2S2023_PY_202000558
Sheila Elizabeth Amaya Rodríguez - 202000558

##  **Objetivos**

### **General**
Aplicar los conocimientos del curso de Estructuras de Datos en el desarrollo de las diferentes estructuras de datos y los diferentes algoritmos de manipulación de la información en ellas.


### **Específicos**
* Utilizar el lenguaje C++ para implementar estructuras de datos no lineales.
* Utilizar la herramienta Graphviz para graficar las estructuras de datos.
* Definir e implementar algoritmos de búsqueda e inserción para las listas
enlazadas, matrices dispersas y colas

##  **Manual Técnico**

### 1. **Estructuras**

1. Lista Circular Doblemente Enlazada
    Se utilizó para almacenar el equipo de trabajo.

```c++
ListaCD::ListaCD()
{

    this->Primero = 0;
    this->Tamanio = 0;
}

ListaCD::~ListaCD()
{

}

void ListaCD::Insertar(std::string nombre,std::string password)
{
    NodoCD *nuevo = new NodoCD(nombre,password);
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
```


2. Lista Doblemente Enlazada
    Se utilizó para almacenamiento y manejo de tareas.

```c++
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
```

3. Matriz dispersa
    Se utilizó para se utilizo para almacenar proyectos y empleados.

```c++
    Matriz::~Matriz()
    {
        //dtor
    }

Matriz::Matriz()
    {
        //ctor
        this->Raiz = new NodoMatriz(new Proyecto("RAIZ",""),new Empleado("",""),-1,-1);
        this->CoordenadaX = 0;
        this->CoordenadaY = 0;
    }

    NodoMatriz* Matriz::buscarFila(int y)
{
    NodoMatriz *aux = this->Raiz;
    while(aux != 0)
    {
        if(aux->PosY == y)
        {
            return aux;
        }
        aux = aux->Abajo;
    }
    return 0;
}

NodoMatriz* Matriz::buscarColumna(int x)
{
    NodoMatriz *aux = this->Raiz;
    while(aux != 0)
    {
        if(aux->PosX == x)
        {
            return aux;
        }
        aux = aux->Siguiente;
    }
    return 0;
}

NodoMatriz* Matriz::insertarColumna(NodoMatriz *nuevo, NodoMatriz *cabeza_columna)
{
    NodoMatriz *temp = cabeza_columna;
    bool piv = false;
    while(true)
    {
        if(temp->PosX==nuevo->PosX){
            temp->PosY = nuevo->PosY;
            temp->Encargado_c = nuevo->Encargado_c;
            temp->Proyecto_c = nuevo->Proyecto_c;
            return temp;
        }else if(temp->PosX > nuevo->PosX){
            piv=true;
            break;
        }
        if(temp->Siguiente){
            temp = temp->Siguiente;
        }else{
            break;
        }
    }
    if(piv)
    {
        nuevo->Siguiente = temp;
        temp->Anterior->Siguiente = nuevo;
        nuevo->Anterior=temp->Anterior;
        temp->Anterior=nuevo;
    }
    else
    {
        temp->Siguiente=nuevo;
        nuevo->Anterior=temp;
    }
    return nuevo;
}


```

4. Cola de Prioridad
    Se utilizó para se utilizo para el almacenamiento de los proyectos.

```c++
Cola::Cola()
{
    this->Primero = 0;
    this->Tamanio = 0;
}

Cola::~Cola()
{

}

void Cola::Encolar(std::string Nombre, std::string TipoPrioridad)
{
    int numero_proyecto = 100 + this->Tamanio;
    Proyecto *nuevoProyecto = new Proyecto("PY-"+std::to_string(numero_proyecto),Nombre); //genera un proyecto
    NodoCola *nuevoNodo = new NodoCola(nuevoProyecto,TipoPrioridad);
    if(this->Primero == 0) //si esta vacia
    {
        this->Primero = nuevoNodo;
        this->Tamanio++;
    }else{ //si tiene por lo menos un elemento
        NodoCola *aux = this->Primero;
        while(aux->Siguiente)
        {
            aux = aux->Siguiente;
        }
        aux->Siguiente = nuevoNodo;
        this->Tamanio++;
    }

}
```