from Estructuras.nodoGrafo import NodoGrafo
import os

class Grafo():
    def __init__(self):
        self.principal = None

    def inicio(self, proyecto):
        self.principal = NodoGrafo(proyecto)

    # Ya estaba
    def insertarFila(self, u):
        nuevo = NodoGrafo(u)
        if self.principal == None:
            self.principal = nuevo
        else:
            aux = self.principal
            while aux is not None:
                if aux.valor == nuevo.valor:
                    return
                if aux.abajo is None:
                    break
                aux = aux.abajo
            aux.abajo = nuevo

    def insertarColumna(self, u, v):
        nuevo = NodoGrafo(v)
        if self.principal is not None and self.principal.valor == u:
            aux = self.principal
            while aux.siguiente is not None:
                aux = aux.siguiente
            aux.siguiente = nuevo
        else:
            aux = self.principal
            while aux is not None:
                if aux.valor == u:
                    break
                aux = aux.abajo
            if aux is not None:
                while aux.siguiente is not None:
                    aux = aux.siguiente
                aux.siguiente = nuevo

    def verMatriz(self):
        aux = self.principal
        while aux is not None:
            temp = aux.siguiente
            if temp is None:
                print("\nNodo {} No tiene conexion".format(aux.valor), end='')
            else:
                print("\nNodo {} tiene conexion con ".format(aux.valor), end='')
                while temp is not None:
                    print(" {} ".format(temp.valor), end='')
                    temp = temp.siguiente
            aux = aux.abajo

    def agregarNodo(self, u, v):
        self.insertarColumna(u, v)
        return

    def Grafico(self):
        cadena = "digraph finite_state_machine { \n rankdir=LR;\n node [shape = circle];\n"
        aux = self.principal
        while aux is not None:
            temp = aux.siguiente
            while temp is not None:
                cadena += "\"{}\" -> \"{}\";\n".format(aux.valor, temp.valor)
                temp = temp.siguiente
            aux = aux.abajo
        cadena += "}"
        archivo = "grafo.jpg"
        a = open("grafo.dot", "w")
        a.write(cadena)
        a.close()
        os.system("dot -Tjpg grafo.dot -o " + archivo)
        return

    # Nuevo Codigo
    # tarea = Codigo de la tarea actual, estado 1, 2 o 3
    def CambiarEstadoTarea(self, tarea, estado):
        aux = self.principal
        while aux is not None:
            if aux.valor == tarea:
                if (aux.siguiente is None):
                    aux.estado = estado
                    self.CambiarEstado(tarea, estado)
                    print("Estado Cambiado")
                else:
                    terminado = self.VerificarEstado(tarea)
                    if terminado == True:
                        aux.estado = estado
                        self.CambiarEstado(tarea, estado)
                        print("Estado Cambiado")
                    else:
                        print("Una tarea no se ha comenzado o esta en proceso")
            aux = aux.abajo

    def CambiarEstado(self, tarea, estado):
        aux = self.principal
        while aux is not None:
            temp = aux.siguiente
            if temp is not None:
                while temp is not None:
                    if temp.valor == tarea:
                        temp.estado = estado
                    temp = temp.siguiente
            aux = aux.abajo

    def VerificarEstado(self, tarea):
        aux = self.principal
        arregloBool = []
        while aux is not None:
            if aux.valor == tarea:
                temp = aux.siguiente
                while temp is not None:
                    if temp.estado == 3:
                        arregloBool.append(True)
                    else:
                        arregloBool.append(False)
                    temp = temp.siguiente
            aux = aux.abajo
        if False in arregloBool:
            return False
        else:
            return True