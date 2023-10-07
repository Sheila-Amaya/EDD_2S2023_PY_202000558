import customtkinter as ctk
import tkinter.messagebox as tkmb
import tkinter as tk
from tkinter import ttk, messagebox, filedialog
from tkinter import Text
import csv
import json
from Estructuras.tablaHash import TablaHash
from Estructuras.arbolAVL import *
from Estructuras.arbolB import *
from Estructuras.listaSimple import *
from proyecto import Proyecto
from tarea import Tarea

tablaGlobal = TablaHash()
proyectosReporte = Arbol_AVL()
tareasReporte = ArbolB()
listaProyectos = EnlazadaSimple()
listaTareas = EnlazadaSimple()

class App():
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

    def login(self):
        # Obtener las entradas del usuario y la contraseña desde los campos de entrada
        username = self.user_entry.get()
        password = self.user_pass.get()
        self.username = username
        print(username,password)

        if tablaGlobal.buscarM(username, password):
            tkmb.showinfo(title="Login Successful", message="Has iniciado sesión correctamente")
            self.app.withdraw() # cerrar la ventana actual
            self.ventana2() # Abrir una nueva ventana
        elif tablaGlobal.buscar(username, password):
            tkmb.showinfo(title="Login Successful", message="Has iniciado sesión correctamente.")
            self.app.withdraw() # cerrar la ventana actual
            self.ventanaEmpleado() # Abrir una nueva ventana
        elif self.user_entry.get() == username and self.user_pass.get() != password:
            tkmb.showwarning(title='Wrong password', message='Por favor revisa tu contraseña')
        elif self.user_entry.get() != username and self.user_pass.get() == password:
            tkmb.showwarning(title='Wrong username', message='Por favor revisa tu usuario')
        else:
            tkmb.showerror(title="Login Failed", message="Contraseña o usuario incorrectos")

    def ventana2(self):
        # Create a new window
        new_window = ctk.CTk()
        new_window.title("administrador")

        ancho = new_window.winfo_screenwidth()
        alto = new_window.winfo_screenheight()

        ancho_ventana = 850
        alto_ventana = 570
        # Calcular la posición x e y para centrar la ventana
        x = (ancho / 2) - (ancho_ventana / 2)
        y = (alto / 2) - (alto_ventana / 2)
        # Establecer la geometría de la ventana
        new_window.geometry("%dx%d+%d+%d" % (ancho_ventana, alto_ventana, x, y))

        # Crea a menu bar
        menubar = tk.Menu(new_window)
        new_window.config(menu=menubar)

        # Crea "File" en el menubar
        file_menu = tk.Menu(menubar, tearoff=0)
        menubar.add_cascade(label="File", menu=file_menu)

        # "Open CSV" 
        def open_csv():
            ruta_archivo = filedialog.askopenfilename(filetypes=[("Archivos CSV", "*.csv")])
            if ruta_archivo:
                tabla.delete(*tabla.get_children())
                with open(ruta_archivo, newline="\n") as archivo_csv:
                    lector_csv = csv.reader(archivo_csv)
                    next(lector_csv)
                    for fila in lector_csv:
                        id, nombre, password, puesto = fila
                        tablaGlobal.Insertar(id, nombre, password, puesto)
                AgregarTabla()

        # CERRAR SESION
        def cerrarSesion():
            new_window.destroy()
            nueva_app = App()  # Crea una nueva instancia de la aplicación
            nueva_app.run()  # Inicia la nueva aplicación

        #botones menubar
        file_menu.add_command(label="Cargar CSV", command=open_csv)
        file_menu.add_separator()
        file_menu.add_command(label="Json", command= self.ventanaJSON)
        file_menu.add_separator()
        file_menu.add_command(label="Cerrar sesion", command=cerrarSesion)

        #arma la tabla para mostrar tablaHash
        tabla_frame = ctk.CTkFrame(new_window)
        tabla_frame.pack(pady=20)

        columns = ("Columna1", "Columna2", "Columna3", "Columna4")
        
        # Crea un LabelFrame para contener la tabla
        tabla_container = tk.LabelFrame(tabla_frame)
        tabla_container.pack()

        # Crea el Treeview dentro de un LabelFrame
        table_height = 25
        tabla = ttk.Treeview(tabla_container, columns=columns, show="headings", height=table_height)
        tabla.heading("#1", text="No.")
        tabla.heading("#2", text="Codigo Empleado")
        tabla.heading("#3", text="Nombre")
        tabla.heading("#4", text="Puesto")

        def AgregarTabla():
            tabla.delete(*tabla.get_children())
            for clave, valor in tablaGlobal.tabla.items():
                tabla.insert("", "end", values=(clave, valor.codigo, valor.nombre, valor.puesto))

        if tablaGlobal.utilizacion > 0:
            AgregarTabla()

        tabla.pack(pady=20)

        # Inicia el bucle principal para la nueva ventana.
        new_window.mainloop()

    def ventanaJSON(self): 
        # Crear una nueva ventana
        new_ = ctk.CTk()
        new_.geometry("300x200")
        new_.title("ProjectUp")

        ancho = new_.winfo_screenwidth()
        alto = new_.winfo_screenheight()

        ancho_ventana = 850
        alto_ventana = 600
        # Calcular la posición x e y para centrar la ventana
        x = (ancho / 2) - (ancho_ventana / 2)
        y = (alto / 2) - (alto_ventana / 2)
        # Establecer la geometría de la ventana
        new_.geometry("%dx%d+%d+%d" % (ancho_ventana, alto_ventana, x, y))

        # Crea a menu bar
        menubar = tk.Menu(new_)
        new_.config(menu=menubar)

        # Crea "File" en el menubar
        file_menu = tk.Menu(menubar, tearoff=0)
        menubar.add_cascade(label="File", menu=file_menu)

        # Botones menubar
        file_menu.add_command(label="Cargar JSON", command=self.cargar_json)
        file_menu.add_separator()
        file_menu.add_command(label="Reporte Tareas", command=self.ReporteTareas)
        file_menu.add_separator()
        file_menu.add_command(label="Reporte Proyectos" , command=self.ReporteProyecto)

        # Crear el cuadro de texto
        self.cuadro_texto = Text(new_, height=30, width=95)
        self.cuadro_texto.pack()
        self.cuadro_texto.place(x=55, y=45)  # Ubicar el cuadro de texto en el centro

        # Iniciar el bucle principal para la nueva ventana
        new_.mainloop()

    def cargar_json(self):
        ruta_archivo = filedialog.askopenfilename(filetypes=[("Archivos JSON", "*.json")])
        if ruta_archivo:
            with open(ruta_archivo, 'r', encoding='utf-8') as archivo_json:
                datos = json.load(archivo_json)
                proyectos = datos.get("Proyectos", [])
                contenido_json = ""

                for i, proyecto in enumerate(proyectos):
                    id_proyecto = proyecto.get("id", "")
                    contenido_json += "├── {} - {} - {}\n".format(proyecto.get("id", ""), proyecto.get("nombre", ""), proyecto.get("prioridad", ""))
                    cod_proyecto = proyecto.get("id", "")
                    nombre_proyecto = proyecto.get("nombre", "")
                    prioridad = proyecto.get("prioridad", "")
                    
                    # Para procesar las tareas en cada proyecto
                    tareas = proyecto.get("tareas", [])
                    contador = 0

                    for j, tarea in enumerate(tareas):
                        if j == len(tareas) - 1:
                            contenido_json += "│   └── {}\t- {}\n".format(tarea.get("nombre", ""), tarea.get("empleado", ""))
                        else:
                            contenido_json += "│   ├── {}\t- {}\n".format(tarea.get("nombre", ""), tarea.get("empleado", ""))

                        contador += 1  # Incrementa el contador

                        # Almacenar los nombres y empleados de las tareas en variables
                        nombre_tarea = tarea.get("nombre", "")
                        empleado_tarea = tarea.get("empleado", "")
                        id_tarea = "T" + str(contador) + "-" + id_proyecto

                        tarea_ = Tarea(id_tarea, nombre_tarea, empleado_tarea,nombre_proyecto)
                        listaTareas.Insertar(tarea_) #lista simple dentro del objeto Proyecto 
                        tareasReporte.insertar(tarea_)  # Agregar tarea al árbol B

                        # print(tarea_)
                    proyectosReporte.Insertar(cod_proyecto)  # Agregar proyecto al árbol AVL
                    datos = Proyecto(cod_proyecto, nombre_proyecto, tarea_, prioridad)  # PARA EL FILTRADO 
                    listaProyectos.Insertar(datos)

                    if i != len(proyectos) - 1:
                        contenido_json += "│\n"
                    else:
                        contenido_json += "└──\n"  # Imprime una línea en blanco después del último proyecto

                # Limpia el cuadro de texto antes de mostrar el contenido
                self.cuadro_texto.delete(1.0, tk.END)
                # Inserta el contenido del JSON procesado en el cuadro de texto
                self.cuadro_texto.insert(tk.END, contenido_json)

    def ReporteTareas(self):
        tareasReporte.graficar()

    def ReporteProyecto(self):
        proyectosReporte.graficar()


    def ventanaEmpleado(self): 
        # Crear una nueva ventana
        new_w = ctk.CTk()
        new_w.geometry("300x200")
        new_w.title("ProjectUp")

        # Agregar contenido a la nueva ventana
        label = ctk.CTkLabel(new_w, text="Bienvenido, {}".format(self.username))
        label.place(x=650, y=50)

        ancho = new_w.winfo_screenwidth()
        alto = new_w.winfo_screenheight()

        ancho_ventana = 850
        alto_ventana = 600
        # Calcular la posición x e y para centrar la ventana
        x = (ancho / 2) - (ancho_ventana / 2)
        y = (alto / 2) - (alto_ventana / 2)
        # Establecer la geometría de la ventana
        new_w.geometry("%dx%d+%d+%d" % (ancho_ventana, alto_ventana, x, y))

        # Crear un ttk.Combobox para el nombre del proyecto obtenido de la función buscar
        combobox = ttk.Combobox(new_w)
        
        # Obtener el nodo del usuario usando la función buscar
        nodo_usuario = listaProyectos.buscar(self.username)
        print(nodo_usuario)
        listaProyectos.recorrer()
        if nodo_usuario is not None:
            nombre_proyecto = nodo_usuario.idProyecto
            combobox.set(nombre_proyecto)
        
        combobox.place(x=80, y=150)  # Ajusta las coordenadas 

        # Crear un LabelFrame para contener la tabla
        tabla_container = tk.LabelFrame(new_w)
        tabla_container.place(x=80, y=200, width=900)  # Ajusta las coordenadas 

        columns = ("Columna1", "Columna2", "Columna3")
        # Crea el Treeview dentro de un LabelFrame
        table_height = 20
        tabla = ttk.Treeview(tabla_container, columns=columns, show="headings", height=table_height)
        tabla.heading("#1", text="Codigo Tarea")
        tabla.heading("#2", text="Nombre Proyecto")
        tabla.heading("#3", text="Nombre Tarea")

        # Recorrer la lista de tareas y agregar las filas a la tabla
        for tarea in listaTareas:
            if tarea.codigoEmpleado == self.username:  
                tabla.insert("", "end", values=(tarea.idTarea, tarea.nombreProyecto, tarea.nombreTarea))


        # Colocar la tabla en el LabelFrame
        tabla.pack(fill=tk.BOTH, expand=True, pady=20)

        # Iniciar el bucle de la nueva ventana
        new_w.mainloop()

    def run(self):
        # Iniciar el bucle principal de la aplicación
        tablaGlobal.Insertar("PM-202000558","DEFAULT","1","Project Manager") #AGREGA PM POR DEFECTO AL INICIAR EL PROGRAMA
        self.app.mainloop()


