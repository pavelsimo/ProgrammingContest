#!/usr/bin/python

import sys
import os.path

# Este es un script hecho en python para resolver el problema de la
# cadena de Snappers del Code Jam del 2010

# una funcion que resuelve una caso del problema snapper
def casoSnapper(n, k):    
    siguiente = False
    # armar una lista de n snappers, un nodo por cada snapper, para
    # cada snapper el primer valor indica si tiene poder, el segundo
    # indica el estado.
    lsSnapper = [[False, False] for val in range(n)]
    # el primer snnapper tiene poder
    lsSnapper[0][0] = True
    conta = 0
    while (conta < k):
        contb = 0
        while (contb < len(lsSnapper)):
            if (lsSnapper[contb][0]):
                lsSnapper[contb][1] = not lsSnapper[contb][1]
            contb += 1
        contb = 0
        siguiente = True
        while (contb < len(lsSnapper)):
            lsSnapper[contb][0] = siguiente
            if (lsSnapper[contb][0] & lsSnapper[contb][1]):
                siguiente = True
            else:
                siguiente = False
            contb += 1
        
        conta += 1
    
    if (lsSnapper[len(lsSnapper) - 1][0] 
        & lsSnapper[len(lsSnapper) - 1][1]):
        return "ON"
    else:
        return "OFF"

# variable a usar
archsalida = "*.out"
linea = ""
filan = []
contenido = []
contenidon = []
resultado = []

# que tome el nombre del archivo de la linea de comandos
if (len(sys.argv) != 2):
    print " la forma de uso es: $ ./script.py entrada.in"
    sys.exit(0)

# si el archivo no existe que se queje y salga
if (not os.path.exists(sys.argv[1])):
    print " no existe el archivo " + sys.argv[1]
    sys.exit(0)

# si existe que lo abra para lectura
entrada = open(sys.argv[1], "r");

# eligiendo el nombre del archivo de salida
if ("." in sys.argv[1]):
    archsalida = sys.argv[1].split(".")[0]
else:
    archsalida = sys.argv[1]

archsalida += ".out"

# abriendo el archivo para escribir
salida = open(archsalida, "w");

# que lea un archivo y haga una lista con los valores
linea = entrada.readline()
while (linea != ""):
    contenido += [linea.replace("\n","").split(" ")]
    linea = entrada.readline()

entrada.close()

# se trata de numeros hay que convertirlos?
for fila in contenido:
    filan = []
    for valor in fila:
        if (valor.isdigit()):
            filan += [int(valor)]
    if (len(filan) > 0):
        contenidon += [filan[:]]

# procesamiento del problema

c = 0
T = contenidon[0][0]
while (c < T):
    resultado += [casoSnapper(contenidon[c + 1][0]
                              , contenidon[c + 1][1])]
    c += 1

# se escribe la salida
for i in range(0, len(resultado)):
    salida.write ("Case #%i: %s\n" % ((i + 1), resultado[i]))

# se cierra el archivo de salida
salida.close()
