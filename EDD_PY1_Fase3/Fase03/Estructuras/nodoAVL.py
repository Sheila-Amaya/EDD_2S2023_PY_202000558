class Nodo_AVL():
    def __init__(self, valor):
        self.valor = valor
        self.izquierdo = None
        self.derecho = None
        self.altura = 1
        self.factor_equilibrio = 0