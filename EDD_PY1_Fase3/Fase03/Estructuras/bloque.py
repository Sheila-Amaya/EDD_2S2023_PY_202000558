from ArbolMerkle import *
from nodos import *
import hashlib
import os 

#No es necesario
import time

class BlockChain():
    def __init__(self) -> None:
        self.inicio = None
        self.bloque_creados = 0
    
    def InsertarBloque(self, fecha, data):
        if self.inicio is None:
            encrypt = self._encriptacionSHA256(str(self.bloque_creados)+ fecha + data)
            nuevoNodo = NodoBloque(str(self.bloque_creados), fecha, data, '0000', encrypt)
            self.inicio = nuevoNodo
            self.bloque_creados += 1
        else:
            encrypt = self._encriptacionSHA256(str(self.bloque_creados)+ fecha + data)
            aux = self.inicio
            while aux.siguiente is not None:
                aux = aux.siguiente
            nuevoNodo = NodoBloque(str(self.bloque_creados), fecha, data, aux.valor['hash'], encrypt)
            nuevoNodo.anterior = aux
            aux.siguiente = nuevoNodo
            self.bloque_creados += 1
        
    def Graficar(self):
        cadena = ''
        archivo = "blockchain.jpg"
        a = open("blockchain.dot","w")
        if self.inicio is not None:
            cadena += "digraph arbol { node [shape=box]; "
            aux = self.inicio
            cont = 0
            while aux.siguiente is not None:
                cadena += "nodo{}[label=".format(cont) 
                cadena += "<"
                cadena += "<B>Index:</B> {} <br /> <B>Timestamp:</B> {} <br /> <B>Data:</B> {} <br /> <B>PreviousHash:</B> {} <br /> <B>Hash:</B> {}".format(aux.valor['index'], aux.valor['timestamp'], aux.valor['data'][:20], aux.valor['previoushash'][:20], aux.valor['hash'][:20])
                cadena += ">]\n"
                aux = aux.siguiente
                cont += 1
            cadena += "nodo{}[label=".format(cont) 
            cadena += "<"
            cadena += "<B>Index:</B> {} <br /> <B>Timestamp:</B> {} <br /> <B>Data:</B> {} <br /> <B>PreviousHash:</B> {} <br /> <B>Hash:</B> {}".format(aux.valor['index'], aux.valor['timestamp'], aux.valor['data'][:20], aux.valor['previoushash'][:20], aux.valor['hash'][:20])
            cadena += ">]\n"
            for i in range(cont):
                cadena += "nodo{} -> ".format(i)
            cadena += "nodo{}".format(cont)
            cadena += "}"
        a.write(cadena)
        a.close()
        os.system("dot -Tjpg blockchain.dot -o " + archivo)

    def _encriptacionSHA256(self, cadena):
        obj = hashlib.sha256()
        obj.update(cadena.encode('utf-8'))
        resultado = obj.hexdigest()
        return resultado #a15387bc
    
