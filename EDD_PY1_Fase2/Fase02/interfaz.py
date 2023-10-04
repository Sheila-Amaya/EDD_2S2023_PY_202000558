import customtkinter as ctk
import tkinter.messagebox as tkmb

import csv
from Estructuras.tablaHash import TablaHash

tablaGlobal = TablaHash()

class App():
    def __init__(self):
        tablaGlobal.Insertar("PM-001","PM-202000558","123","Project Manager")
        # Configurar la apariencia y el color de la interfaz
        ctk.set_appearance_mode("System")
        ctk.set_default_color_theme("green")

        # Crear la ventana principal
        self.app = ctk.CTk()
        self.app.geometry("400x400")
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
        username = ""
        password = ""

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

    def ventana2(self): #ventana project manager
        # Crear una nueva ventana
        new_window = ctk.CTk()
        new_window.geometry("300x200")
        new_window.title("Nueva Ventana")

        # Agregar contenido a la nueva ventana
        label = ctk.CTkLabel(new_window, text="Bienvenido a la nueva ventana")
        label.pack(pady=20)

        # Iniciar el bucle de la nueva ventana
        new_window.mainloop()

    def run(self):
        # Iniciar el bucle principal de la aplicación
        self.app.mainloop()


