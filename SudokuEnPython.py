
'''
Programa que resuleve un sudoku de tamaño 9x9 con un algoritmo iterativo

para solucionar el sudoku este debe estar con casillas en calor 0 donde pueda iterar el algoritmo

'''


def rangoSublista(x):
    if(x<3):
        return 0
    elif (x<6):
        return 1
    elif (x<9):
        return 2
    else:
        print("\n-----------  fallo rango: ",x)
        return -1


def rango0a3(x):
    rangoSublist = rangoSublista(x)     
    indice = x-(rangoSublist*3)
    return rangoSublist,indice


def conformarColumna(TableroPrincipal, columna):
    NumerosColumna = []
    sublist,indice = rango0a3(columna)
    for i in TableroPrincipal:
        NumerosColumna.append(i[sublist][indice])
    return NumerosColumna

def conformarCaja(Tablero,fila,columna):
    caja = []
    limFSup = rangoSublista(fila)*3
    indiceCol = rangoSublista(columna)
    caja.append(Tablero[limFSup][indiceCol])
    caja.append(Tablero[limFSup+1][indiceCol])
    caja.append(Tablero[limFSup+2][indiceCol])
    return caja


def evaluar(list1,list2,list3,x):
    return (x not in list1 and x not in list2 and x not in list3)



def Valido(TableroPrincipal,fila,columna,num):
    validoFilas = evaluar(TableroPrincipal[fila][0],TableroPrincipal[fila][1],TableroPrincipal[fila][2],num)
    columnas = conformarColumna(TableroPrincipal,columna)
    validoColumnas = evaluar(columnas[0:3],columnas[3:6],columnas[6:],num)
    caja = conformarCaja(TableroPrincipal,fila,columna)
    validoCaja = evaluar(caja[0],caja[1],caja[2],num)
    return validoCaja and validoColumnas and validoFilas


def matrizAsociada(TableroPrincipal):
    matriz = []
    for i in TableroPrincipal:
        sublist = []
        for j in i:
            sublist.append(j[0]==0)
            sublist.append(j[1]==0)
            sublist.append(j[2]==0)
        matriz.append(sublist)
    return matriz

def retrocesoValido(fila,columna,matriz):
    if (matriz[fila][columna]):
        return fila,columna,True
    else:
        return retroceder(fila,columna,matriz)

def retroceder(fila,columna,matriz):
    if(columna == 0):
        fila = fila-1
        columna = 8
        if(fila < 0):
            return fila,columna,False
        else:
            return retrocesoValido(fila,columna,matriz)
    else:
        columna = columna-1
        return retrocesoValido(fila,columna,matriz)


def avanceValido(fila,columna,matriz):
    if (matriz[fila][columna]):
        return fila,columna,True
    else:
        return avanzar(fila,columna,matriz)

def avanzar(fila,columna,matriz):
    if(columna == 8):
        fila = fila+1
        columna = 0
        if(fila > 8):
            return fila,columna,False
        else:
            return avanceValido(fila,columna,matriz)
    else:
        columna = columna+1
        return avanceValido(fila,columna,matriz)


def imprimirSudoku(Tablero):
    a=1
    for i in Tablero:
        for j in i:
            print(j[0],end=" ")
            print(j[1],end=" ")
            print(j[2],end=" ")
            print(end="  ")
        if(a==3 or a==6):
            print("\n")
        else:
            print("")
        a=a+1

def algoritmoSolucion(TableroPrincipal):
    num = 0 # numero a colocar en determinada posicion
    fila =  0 # fila sobre la cual se opera
    columna = 0
    subList = 0
    indice = 0
    matrizA = matrizAsociada(TableroPrincipal)
    continuar = True

    aux = 0

    if(not matrizA[0][0]):
        fila,columna,continuar = avanzar(fila,columna,matrizA)
    while(continuar):
        aux = aux+1
        if ( aux%1000 == 0):
            print("cuadro:",aux)
            imprimirSudoku(TableroPrincipal)
            print("\n")
            input()
        if(num > 9):
            subList,indice = rango0a3(columna)
            TableroPrincipal[fila][subList][indice] = 0
            fila,columna,continuar = retroceder(fila,columna,matrizA)
            if(continuar):
                subList,indice = rango0a3(columna)
                num = TableroPrincipal[fila][subList][indice]+1
                TableroPrincipal[fila][subList][indice] = 0  
        elif (Valido(TableroPrincipal,fila,columna,num)):
            subList,indice = rango0a3(columna)
            TableroPrincipal[fila][subList][indice] = num
            num = 0
            fila,columna,continuar = avanzar(fila,columna,matrizA)
        else:
            num = num+1





Tablero = [[[1,0,0],[0,0,0],[0,0,0]],
           [[0,2,0],[0,0,0],[0,0,0]],
           [[0,0,3],[0,0,0],[0,0,0]],

           [[0,0,0],[4,0,0],[0,0,0]],
           [[0,0,0],[0,5,0],[0,0,0]],
           [[0,0,0],[0,0,6],[0,0,0]],

           [[0,0,0],[0,0,0],[7,0,0]],
           [[0,0,0],[0,0,0],[0,8,0]],
           [[0,0,0],[0,0,0],[0,0,9]]]

algoritmoSolucion(Tablero)
print("\nSOLUCIONADO")
imprimirSudoku(Tablero)

#matriz = matrizAsociada(Tablero)
#print(retroceder(3,8,matriz))




#----------------------- FINALIZADO .------------------------------    
print("\n\n\n\n Ejecucion completa")
input()