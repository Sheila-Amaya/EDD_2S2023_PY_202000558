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
    cout <<"hola>>
```

3. Matriz dispersa
    Se utilizó para se utilizo para almacenar proyectos y empleados.

```c++
    cout <<"hola>>
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