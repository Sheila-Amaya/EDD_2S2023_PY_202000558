class NodoGrafo():
    def __init__(self, valor):
        self.valor = valor
        self.estado = 1  # Nuevo
        self.siguiente = None
        self.abajo = None