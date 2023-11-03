from Estructuras.nodoSimple import *

class EnlazadaSimple:

    def _init_(self):
        self.primero = None
        self.ultimo = None

    def vacia(self):
        return self.primero == None

    def insertar_inicio(self, data):
        nuevo_nodo = Nodo(data)  # Crea un nuevo nodo

        if self.vacia():  # Si la lista está vacía, establece el nuevo nodo como primero y último
            self.primero = self.ultimo = nuevo_nodo
        else:  # Si la lista no está vacía, enlaza el nuevo nodo al antiguo primero y actualiza el primero
            nuevo_nodo.siguiente = self.primero
            self.primero = nuevo_nodo
            
    def recorrerLista(self):
        aux = self.primero

        while aux is not None:
            print(aux.data)
            aux = aux.siguiente
    
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