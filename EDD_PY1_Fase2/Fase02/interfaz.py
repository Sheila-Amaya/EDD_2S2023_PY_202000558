import customtkinter as ctk
import tkinter.messagebox as tkmb
import tkinter as tk
from tkinter import ttk, messagebox, filedialog
import csv
from Estructuras.tablaHash import TablaHash

tablaGlobal = TablaHash()

class App():
    def __init__(self):
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
        self.create_ui()

    def create_ui(self):
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
        print(username,password)

        if self.user_entry.get() == "admi" and self.user_pass.get() == "admi":
            tkmb.showinfo(title="Login Successful", message="Has iniciado sesión correctamente")
            self.app.iconify() # minimiza la ventana actual
            self.ventana2() # Abrir una nueva ventana
        elif tablaGlobal.buscar(username, password):
            tkmb.showinfo(title="Login Successful", message="Has iniciado sesión correctamente")
            self.app.iconify() # minimiza la ventana actual
            self.ventana2() # Abrir una nueva ventana
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
        alto_ventana = 600
        # Calcular la posición x e y para centrar la ventana
        x = (ancho / 2) - (ancho_ventana / 2)
        y = (alto / 2) - (alto_ventana / 2)
        # Establecer la geometría de la ventana
        new_window.geometry("%dx%d+%d+%d" % (ancho_ventana, alto_ventana, x, y))

        # Create a menu bar
        menubar = tk.Menu(new_window)
        new_window.config(menu=menubar)

        # Create a "File" menu
        file_menu = tk.Menu(menubar, tearoff=0)
        menubar.add_cascade(label="File", menu=file_menu)

        # Add "Open CSV" menu item
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
        
        file_menu.add_command(label="Open CSV", command=open_csv)

        # Add "Exit" menu item
        def exit_app():
            new_window.destroy()
        file_menu.add_command(label="Exit", command=exit_app)

        tabla_frame = ctk.CTkFrame(new_window)
        tabla_frame.pack(pady=20)

        columns = ("Columna1", "Columna2", "Columna3", "Columna4")
        tabla = ttk.Treeview(tabla_frame, columns=columns, show="headings")
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

        # Start the main loop for the new window
        new_window.mainloop()


    def ventanaJSON(self): 
        # Crear una nueva ventana
        new_= ctk.CTk()
        new_.geometry("300x200")
        new_.title("Nueva Ventana")

        # Agregar contenido a la nueva ventana
        label = ctk.CTkLabel(new_w, text="Bienvenido a la nueva ventana")
        label.pack(pady=20)

        # Iniciar el bucle de la nueva ventana
        new_.mainloop()


    def ventanaEmpleado(self): 
        # Crear una nueva ventana
        new_w = ctk.CTk()
        new_w.geometry("300x200")
        new_w.title("Nueva Ventana")

        # Agregar contenido a la nueva ventana
        label = ctk.CTkLabel(new_w, text="Bienvenido a la nueva ventana")
        label.pack(pady=20)

        # Iniciar el bucle de la nueva ventana
        new_w.mainloop()

    def run(self):
        # Iniciar el bucle principal de la aplicación
        self.app.mainloop()


