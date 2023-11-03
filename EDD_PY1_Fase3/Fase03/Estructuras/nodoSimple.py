class Nodo():
    def _init_(self, data):
        self.data = data 
        self.siguiente = None

    def getIdTarea(self):
        return self.data.getIdTarea() if self.data else None

    def getIdProyecto(self):
        return self.data.getIdProyecto() if self.data else None

    def getNombreTarea(self):
        return self.data.getNombreTarea() if self.data else None

    def getCodigoEncargado(self):
        return self.data.getCodigoEncargado() if self.data else None

    def getNombreProyecto(self):
        return self.data.getNombreProyecto() if self.data else None