#!/usr/bin/python

import sys
import os.path

# Esto es una plantilla para los programitas de code jam para
# poner un par de cositas que son comunes a todos los programitas


def calcWP(linea):
    # print "WP: ", linea
    g = linea.count("1")
    p = linea.count("0")
    # print float(g)/float(g + p)
    return float(g)/float(g + p)

def calcOWP(i, tabla):
    # print "OWP: ", chr(ord("A") + i), tabla
    owp = 0.0
    c = 0
    co = 0
    while (c < len(tabla[i])):
        if (tabla[i][c] == "1") or (tabla[i][c] == "0"):
            owp += calcWP(tabla[c][:i] + tabla[c][i+1:])
            co += 1
        c += 1
    owp = owp / float(co)
    # print owp
    return owp

def calcOOWP(i, tabla):
    # print "OOWP: ", chr(ord("A") + i), tabla
    oowp = 0.0
    c = 0
    co = 0
    while (c < len(tabla[i])):
        if (tabla[i][c] == "1") or (tabla[i][c] == "0"):
            oowp += calcOWP(c, tabla)
            co += 1
        c += 1
    oowp = oowp / float(co)
    # print oowp
    return oowp

def calcRPI(wp, owp, oowp):
    # print "RPI: ", wp, owp, oowp
    return 0.25 * wp + 0.5 * owp + 0.25 * oowp

def rpis(n, tabla):
    resultado = ""
    for i in range(len(tabla)):
        # print "** calculando ", chr(ord("A") + i)
        resultado += "\n" + str(calcRPI(calcWP(tabla[i])\
                                        , calcOWP(i, tabla)\
                                        , calcOOWP(i, tabla)))
    return resultado

archsalida = "*.out"
linea = ""

# que tome el nombre del archivo de la linea de comandos
if (len(sys.argv) != 2):
    # print " solo se necesita el archivo de entrada como prametro"
    sys.exit(0)

# si el archivo no existe que se queje y salga
if (not os.path.exists(sys.argv[1])):
    # print " no existe el archivo " + sys.argv[1]
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

# normalmente la primera linea dice la cantidad de casos
n = int(entrada.readline().replace("\n", ""))
# se lee la siguiente linea 
linea = entrada.readline()
cont = 0
while ((linea != "") & (cont < n)):

    # cantidad de equipos
    cant = int(linea.replace("\n", ""))

    it = 0
    tabla = []
    while it < cant:
        tabla += [entrada.readline().replace("\n", "")]
        it += 1
    
    # se procesa el caso
    # print "** caso ", cont
    resultado = rpis(cant, tabla)

    # se pone la salida del caso
    salida.write ("Case #%i: %s\n" % ((cont + 1), resultado) )
    cont += 1
    linea = entrada.readline()


# se cierran los archivos
entrada.close()
salida.close()
