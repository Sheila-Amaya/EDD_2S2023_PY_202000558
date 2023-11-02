##  **Manual Técnico**

### 1. **Estructuras**

1. Clase ArbolAVL
    *La clase incluye métodos para insertar nodos en el árbol, calcular la altura y el factor de equilibrio de un nodo, así como para realizar rotaciones izquierda y derecha.*
```py
    def Insertar(self, valor):
        self.raiz = self.InsertarNodo(valor, self.raiz)

    def Altura(self, raiz):
        condicion = raiz == None
        return 0 if condicion else raiz.altura
    
    def Equilibrio(self, raiz):
        condicion = raiz == None
        return 0 if condicion else (self.Altura(raiz.derecho) - self.Altura(raiz.izquierdo))

    def RotacionI(self, raiz):
        raiz_derecho = raiz.derecho
        hijo_izquierdo = raiz_derecho.izquierdo
        raiz_derecho.izquierdo = raiz
        raiz.derecho = hijo_izquierdo
        raiz.altura = 1 + max(self.Altura(raiz.izquierdo),self.Altura(raiz.derecho))
        raiz.factor_equilibrio = self.Equilibrio(raiz)
        raiz_derecho.altura = 1 + max(self.Altura(raiz_derecho.izquierdo),self.Altura(raiz_derecho.derecho))
        raiz_derecho.factor_equilibrio = self.Equilibrio(raiz_derecho)
        return raiz_derecho
    
    def RotacionD(self, raiz):
        raiz_izquierdo = raiz.izquierdo
        hijo_derecho = raiz_izquierdo.derecho
        raiz_izquierdo.derecho = raiz
        raiz.izquierdo = hijo_derecho
        raiz.altura = 1 + max(self.Altura(raiz.izquierdo), self.Altura(raiz.derecho))
        raiz.factor_equilibrio = self.Equilibrio(raiz)
        raiz_izquierdo.altura = 1 + max(self.Altura(raiz_izquierdo.izquierdo), self.Altura(raiz_izquierdo.derecho))
        raiz_izquierdo.factor_equilibrio = self.Equilibrio(raiz_izquierdo)
        return raiz_izquierdo
```

2. Clase ArbolB
*el encarga de dividir las ramas cuando sea necesario para mantener la estructura balanceada del árbol. El árbol B se utiliza comúnmente en bases de datos y sistemas de archivos para organizar y buscar datos de manera eficiente.*
```py
    def insertar(self, valor):
        numero = self.suma_ascii(valor.idTarea)
        nuevo = NodoB(numero, valor)
        if self.raiz is None:
            self.raiz = RamaB()
            self.raiz.insertar(nuevo)
        else:
            obj:NodoB = self.insertar_rama(nuevo, self.raiz)
            if obj is not None:
                self.raiz = RamaB()
                self.raiz.insertar(obj)
                self.raiz.hoja = False
        
    def insertar_rama(self, nodo:NodoB, rama:RamaB):
        if rama.hoja:
            rama.insertar(nodo)
            if rama.contador == self.orden:
                return self.dividir(rama)
            else:
                return None
        else:
            temp:NodoB = rama.primero
            while temp is not None:
                if nodo.valor == temp.valor: #comparar codigo de tareas
                    return None
                elif nodo.valor < temp.valor: #comparar codigo de tareas
                    obj:NodoB = self.insertar_rama(nodo, temp.izquierda)
                    if obj is not None:
                        rama.insertar(obj)
                        if rama.contador == self.orden:
                            return self.dividir(rama)
                    return None
                elif temp.siguiente is None:
                    obj:NodoB = self.insertar_rama(nodo, temp.derecha)
                    if obj is not None:
                        rama.insertar(obj)
                        if rama.contador == self.orden:
                            return self.dividir(rama)
                    return None
                temp = temp.siguiente
        return

```

3. Clase listaSimple
* Insertar nuevos nodos al final de la lista, recorrer la lista para imprimir los datos almacenados y buscar un nodo en función de un criterio de búsqueda. .*
```py
from Estructuras.nodoSimple import *

class EnlazadaSimple:
    
    def __init__(self):
        self.primero = None
        self.ultimo = None
    
    def estaVacia(self): #Si la lista esta vacia
        return self.primero == None #si no he agregado nada
    
    def Insertar(self,dato):
        if self.estaVacia():
            self.primero = self.ultimo = Nodo(dato)
        else:
            temp = self.ultimo #guarda el dato en una variable temporal
            self.ultimo = temp.siguiente = Nodo(dato)

    def recorrer(self):
        temp = self.primero
        while temp != None:
            print(temp.dato.idProyecto)
            print(temp.dato.nombreProyecto)
            print(temp.dato.tareas.idTarea)
            print(temp.dato.tareas.codigoEmpleado)
            print()
            temp = temp.siguiente

    def buscar(self, nombre):
        #
        temp = self.primero
        while temp:
            if  temp.dato.tareas.codigoEmpleado.lower() == nombre.lower():
                return temp.dato  # Devuelve el nodo si se encuentra 
            temp = temp.siguiente
        return None  # Devuelve None si no se encuentra 
    

```

4. Clase tablaHash
*La tabla hash con capacidades de inserción y redimensionamiento dinámico. La tabla hash se utiliza comúnmente para buscar y almacenar datos de manera eficiente utilizando una función hash que asigna claves a ubicaciones en la tabla.*
```py
    def Insertar(self, codigo, nombre, password, puesto):
        indice = self.calculoIndice(codigo)
        nuevo = NodoHash(codigo, nombre, password, puesto)
        if indice < self.capacidad:
            try:
                if not (indice in self.tabla):
                    self.tabla[indice] = nuevo
                    self.utilizacion += 1
                    self.capacidadTabla()
                else:
                    contador = 1
                    indice = self.reCalculoIndice(codigo, contador)
                    while (indice in self.tabla):
                        contador += 1
                        indice = self.reCalculoIndice(codigo, contador)
                    self.tabla[indice] = nuevo
                    self.utilizacion += 1
                    self.capacidadTabla()
            except:
                print("Error...")

    def calculoIndice(self, codigo): #codigo empleado 
        total = 0
        for caracter in codigo:
            valor_ascii = ord(caracter) #funcion nativa py devuelve int 
            total += valor_ascii
        indice = total % self.capacidad #metodo por div 
        return indice
    
```

5. Clase empleado
*Permite crear objetos que representan a los empleados con la información asociada a ellos. *
```py
    def __init__(self,idEmpleado,nombre,password,puesto):
        self.idEmpleado = idEmpleado
        self.nombre = nombre
        self.password = password
        self.puesto = puesto

```

5. Clase proyecto
*Permite crear objetos que representan a los proyectos con la información asociada a ellos.*
```py
    def __init__(self,idProyecto,nombreProyecto,tareas,prioridad):
        self.idProyecto = idProyecto
        self.nombreProyecto = nombreProyecto
        self.tareas = tareas #nombre tarea, empleado , lista simple
        self.prioridad = prioridad 
        

```

7. Clase tarea
*Almacena información sobre las tareas asociadas al proyecto.*
```py
    def __init__(self,idTarea,nombreTarea,codigoEmpleado,nombreProyecto):
        self.idTarea = idTarea
        self.nombreTarea = nombreTarea
        self.codigoEmpleado = codigoEmpleado #fdev-001d
        self.nombreProyecto = nombreProyecto

```

8. Claseinterfaz
*Aplicación  diseñada para proporcionar una interfaz de inicio de sesión donde un usuario puede iniciar sesion y realizar diferntes tareas.*
```py
    def __init__(self):
        self.username = None
        # Configurar la apariencia y el color de la interfaz
        ctk.set_appearance_mode("System")
        ctk.set_default_color_theme("green")

        # Crear la ventana principal
        self.app = ctk.CTk()
        ancho = self.app.winfo_screenwidth()
        alto = self.app.winfo_screenheight()

        ancho_ventana = 400
        alto_ventana = 400
        # Calcular la posición x e y para centrar la ventana
        x = (ancho / 2) - (ancho_ventana / 2)
        y = (alto / 2) - (alto_ventana / 2)
        # Establecer la geometría de la ventana
        self.app.geometry("%dx%d+%d+%d" % (ancho_ventana, alto_ventana, x, y))
        self.app.title("PROJECT UP")

        # Crear elementos de la interfaz
        self.ventana_inicio()

    def ventana_inicio(self):
        # Etiqueta principal
        label = ctk.CTkLabel(self.app, text=" BIENVENIDO ")
        label.pack(pady=10)

        # Marco para el formulario
        frame = ctk.CTkFrame(master=self.app)
        frame.pack(pady=20, padx=40, fill='both', expand=True)

        # Etiqueta del formulario
        label = ctk.CTkLabel(master=frame, text=' ')
        label.pack(pady=12, padx=10)

        # Campos de entrada de usuario y contraseña
        self.user_entry = ctk.CTkEntry(master=frame, placeholder_text="Username")
        self.user_entry.pack(pady=12, padx=10)

        self.user_pass = ctk.CTkEntry(master=frame, placeholder_text="Password", show="*")
        self.user_pass.pack(pady=12, padx=10)

        # Botón de inicio de sesión
        button = ctk.CTkButton(master=frame, text='Login', command=self.login)
        button.pack(pady=12, padx=10)

```
---