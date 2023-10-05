from Estructuras.nodoAVL import Nodo_AVL
import os

class Arbol_AVL():
    def __init__(self):
        self.raiz = None
    
    def Insertar(self, dato):
        self.raiz = self.InsertarNodo(dato, self.raiz)

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

    def InsertarNodo(self, dato, raiz):
        if raiz is None:
            return Nodo_AVL(dato)
        else:
            if raiz.dato == dato:
                raiz.dato = dato
            elif raiz.dato > dato:
                raiz.izquierdo = self.InsertarNodo(dato, raiz.izquierdo)
            elif raiz.dato < dato:
                raiz.derecho = self.InsertarNodo(dato, raiz.derecho)
        #Luego de insercion, procedemos a realizar rotaciones
        raiz.altura = 1 + max(self.Altura(raiz.izquierdo),self.Altura(raiz.derecho))
        balanceo = self.Equilibrio(raiz)
        raiz.factor_equilibrio = balanceo

        if balanceo > 1 and dato > raiz.derecho.dato:#Rotacion Simple a la Izquierda
            return self.RotacionI(raiz)
        if balanceo < -1 and dato < raiz.izquierdo.dato:#Rotacion Simple a la Derecha
            return self.RotacionD(raiz)
        if balanceo > 1 and dato < raiz.derecho.dato:#Rotacion Doble a la Izquierda
            raiz.derecho = self.RotacionD(raiz.derecho)
            return self.RotacionI(raiz)
        if balanceo < -1 and dato > raiz.izquierdo.dato:#Rotacion Doble a la Derecha
            raiz.izquierdo = self.RotacionI(raiz.izquierdo)
            return self.RotacionD(raiz)
        return raiz
    
    def recorridoInorden(self):
        self.Inorden(self.raiz)

    def Inorden(self, raiz):
        if raiz is not None:
            self.Inorden(raiz.izquierdo)
            print(raiz.dato, end=' ')
            self.Inorden(raiz.derecho)

    def recorridoPreOrden(self):
        self.PreOrden(self.raiz)
    
    def PreOrden(self, raiz):
        if raiz is not None:
            print(raiz.dato, end=' ')
            self.PreOrden(raiz.izquierdo)
            self.PreOrden(raiz.derecho)

    def recorridoPostOrden(self):
        self.PostOrden(self.raiz)

    def PostOrden(self, raiz):
        if raiz is not None:
            self.PostOrden(raiz.izquierdo)
            self.PostOrden(raiz.derecho)
            print(raiz.dato, end=' ')

    def graficar(self):
        cadena = ''
        archivo = "arbolAVL.jpg"
        a = open("arbolAVL.dot","w")
        if self.raiz is not None:
            cadena += "digraph arbol {"
            cadena += self.retornarValoresArbol(self.raiz, 0)
            cadena += "}"
        a.write(cadena)
        a.close()
        os.system("dot -Tjpg arbolAVL.dot -o " + archivo)
        #os.system(archivo)

    def retornarValoresArbol(self, raiz, id):
        cadena = ''
        numero = id + 1
        if raiz is not None:
            cadena += "\""
            cadena += str(raiz.dato)
            cadena += "\" ;\n"
            if(raiz.izquierdo is not None and raiz.derecho is not None):
                cadena += "x{} [label=\"\",width=.1,style=invis];\n".format(numero)
                cadena += "\"{}\" -> {} \"{}\" -> {}".format(raiz.dato, self.retornarValoresArbol(raiz.izquierdo, numero), raiz.dato, self.retornarValoresArbol(raiz.derecho, numero))
                cadena += "{" + "rank=same" + "\"{}\" -> \"{}\" [style=invis]; ".format(raiz.izquierdo.dato, raiz.derecho.dato) + "} \n"
            elif(raiz.izquierdo is not None and raiz.derecho is None):
                cadena += "x{} [label=\"\",width=.1,style=invis];\n".format(numero)
                cadena += "\"{}\" -> {} \"{}\" -> x{}[style=invis];\n".format(raiz.dato, self.retornarValoresArbol(raiz.izquierdo, numero), raiz.dato, numero)
                cadena += "{" + "rank=same " + "\"{}\" -> x{} [style=invis]; ".format(raiz.izquierdo.dato, numero) + "} \n"
            elif(raiz.izquierdo is None and raiz.derecho is not None):
                cadena += "x{} [label=\"\",width=.1,style=invis];\n".format(numero)
                cadena += "\"{}\" -> x{}[style=invis]; \n \"{}\" -> {}".format(raiz.dato, numero, raiz.dato, self.retornarValoresArbol(raiz.derecho, numero))
                cadena += "{" + "rank=same " + "x{} -> \"{}\" [style=invis]; ".format(numero, raiz.derecho.dato) + "} \n"
        return cadena