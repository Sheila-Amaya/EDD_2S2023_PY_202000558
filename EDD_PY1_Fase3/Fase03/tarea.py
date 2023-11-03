class Tarea:
    def __init__(self,idTarea,nombreTarea,codigoEmpleado,nombreProyecto,estado):
        self.idTarea = idTarea
        self.nombreTarea = nombreTarea
        self.codigoEmpleado = codigoEmpleado #fdev-001d
        self.nombreProyecto = nombreProyecto
        self.estado:int = estado

    #def __str__(self):
    #    return f"Tarea ID: {self.idTarea}\nNombre: {self.nombreTarea}\nEmpleado: {self.codigoEmpleado}"
    def getIdTarea(self):
            return self.idTarea
        
    # def getIdProyecto(self):
    #     return self.id_proyecto
    
    def getNombreTarea(self):
        return self.nombreTarea
    
    def getCodigoEncargado(self):
        return self.codigoEmpleado
    
    def getNombreProyecto(self):
        return self.nombreProyecto
    
    def getEstado(self):
        return self.estado