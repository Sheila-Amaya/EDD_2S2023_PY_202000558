from nodoB import NodoB

class RamaB:
    def __init__(self):
        self.primero:NodoB = None #para moverse a traves de todo el arreglo
        self.hoja = True #para saber si es una hoja o una raiz 
        self.contador = 0
        
    def insertar(self,nuevo):
        if self.primero is None:
            self.primero = nuevo
            self.contador += 1
        else: #inserta ordenado
            if nuevo.valor < self.primero.valor: 
                nuevo.siguiente = self.primero
                if self.primero is not None:
                    self.primero.anterior = nuevo
                    self.primero.izquierda = nuevo.derecha
                self.primero = nuevo
            else:
                temp = self.primero
                while temp.siguiente is not None and temp.siguiente.valor < nuevo.valor:
                    temp = temp.siguiente
            nuevo.siguiente = temp.siguiente
            if temp.siguiente is not None:
                temp.siguiente.anterior = nuevo
            temp.siguiente = nuevo
            nuevo.anterior = temp
        self.contador += 1
            