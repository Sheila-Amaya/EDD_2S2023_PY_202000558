from Estructuras.nodoSimple import *

class EnlazadaSimple:
    
    def __init__(self):
        self.primero = None
        self.ultimo = None
    
    def estaVacia(self): #Si la lista esta vacia
        return self.primero == None #si no he agregado nada
    
    def Insertar(self,dato):
        if self.estaVacia():
            self.primero = self.ultimo = Nodo(dato)
        else:
            temp = self.ultimo #guarda el dato en una variable temporal
            self.ultimo = temp.siguiente = Nodo(dato)

    def recorrer(self):
        temp = self.primero
        while temp != None:
            print(temp.dato.idProyecto)
            print(temp.dato.nombreProyecto)
            print(temp.dato.tareas.idTarea)
            print(temp.dato.tareas.nombreTarea)
            print(temp.dato.tareas.codigoEmpleado)
            print(temp.dato.tareas.nombreProyecto)
            print()
            temp = temp.siguiente

    def buscar(self, nombre):
        #
        temp = self.primero
        while temp:
            if  temp.dato.tareas.codigoEmpleado.lower() == nombre.lower():
                return temp.dato  # Devuelve el nodo si se encuentra 
            temp = temp.siguiente
        return None  # Devuelve None si no se encuentra 
    
    def buscarProyecto(self, nombre):
        temp = self.primero
        while temp:
            if temp.dato.nombreProyecto == nombre :
                return temp.dato  # Devuelve el nodo si se encuentra proyecto
            temp = temp.siguiente
        return None  # Devuelve None si no se encuentra el correo
    
    def __iter__(self):
        current = self.primero  # Establece el nodo actual como el primero de la lista
        while current is not None:  # Itera mientras el nodo actual no sea None (hay elementos en la lista)
            yield current.dato  # Devuelve el dato del nodo actual
            current = current.siguiente  # Mueve al siguiente nodo de la lista