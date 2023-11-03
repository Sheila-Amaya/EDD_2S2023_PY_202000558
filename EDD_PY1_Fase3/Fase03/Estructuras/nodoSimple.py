class Nodo():
    def __init__(self, dato):
        self.dato = dato 
        self.siguiente = None

    def getIdTarea(self):
        return self.dato.getIdTarea() if self.dato else None

    def getIdProyecto(self):
        return self.dato.getIdProyecto() if self.dato else None

    def getNombreTarea(self):
        return self.dato.getNombreTarea() if self.dato else None

    def getCodigoEncargado(self):
        return self.dato.getCodigoEncargado() if self.dato else None

    def getNombreProyecto(self):
        return self.dato.getNombreProyecto() if self.dato else None
    
    
    def getEstado(self):
        return self.dato.getEstado() if self.dato else None