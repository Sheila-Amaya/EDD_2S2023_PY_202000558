class NodoB:
    def __init__(self,valor,id):
        self.valor = valor
        self.id = id
        self.siguiente = None #apuntadores para moverse dentro del arreglo
        self.anterior = None
        self.izquierda = None #para moverse en el arbol 
        self.derecha = None
