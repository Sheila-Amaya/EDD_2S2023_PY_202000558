import json
from Estructuras.grafo import Grafo


class NodoLista:
    def __init__(self, id_tarea, empleado):
        self.id_tarea = id_tarea
        self.empleado = empleado
        self.siguiente = None


class Lista:
    def __init__(self):
        self.primero = None

    def insertar(self, valor, empleado):
        nuevo = NodoLista(valor, empleado)
        if self.primero is None:
            self.primero = nuevo
        else:
            aux = self.primero
            while aux.siguiente is not None:
                aux = aux.siguiente
            aux.siguiente = nuevo

    def mostrar(self):
        aux = self.primero
        while aux is not None:
            print(aux.id_tarea)
            aux = aux.siguiente

    def listaEmpleados(self, empleado):
        listaAux = Lista()
        aux = self.primero
        while aux is not None:
            if aux.empleado == empleado:
                listaAux.insertar(aux.id_tarea, aux.empleado)
            aux = aux.siguiente
        return listaAux

