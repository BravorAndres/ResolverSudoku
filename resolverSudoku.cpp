#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>


typedef struct {
	int valor;
	bool esPista;
}Dato;


int limCaja(int x){
	if(x<3)
		return 0;
	else if(x<6)
		return 3;
	else
		return 6;
}

bool validar(Dato tablero[9][9],int px,int py,int x){
	//fila y colummna
	for (char i = 0;i<9;i++)
		if(tablero[px][i].valor == x || tablero[i][py].valor == x)
			return false;
	
	int ly,lx;
	lx = limCaja(px);
	ly = limCaja(py);
	for (char i = lx;i<lx+3;i++)
		for (char j = ly;j<ly+3;j++)
			if(tablero[i][j].valor == x)
				return false;
	return true;
}

void avanzar(Dato tablero[9][9],int &px,int &py){
	do{
		if(py == 8){
			py = 0;
			px++;
			if(px==9)
				return;
		}else
			py++;
	}while(tablero[px][py].esPista);
}

void retroceder(Dato tablero[9][9],int &px,int &py){
	do{
		if(py == 0){
			py = 8;
			px--;
			if(px==-1)
				return;
		}else
			py--;
	}while(tablero[px][py].esPista);
}


bool resolver(Dato tablero[9][9]){
	int px = 0, py = 0, x = 1;
	avanzar(tablero,px,py);
	if(px==9)
		return true;
	while(true){
		//printf("px:%d   py:%d \n",px,py);
		if(x==10){
			tablero[px][py].valor = 0;
			retroceder(tablero,px,py);
			if(px == -1)
				return false;
			x = tablero[px][py].valor;
			x++;
			tablero[px][py].valor = 0;
		}else if(validar(tablero,px,py,x)){
			tablero[px][py].valor = x;
			avanzar(tablero,px,py);
			if(px == 9)
				return true;
			x = 1;
		}else
			x++;
	}
}



int aNumero(char x){
	return x-48;
}


void mat0x0(char mat[][9]){
	for(int j=0;j<9;j++){
		for(int i=0;i<9;i++){
			mat[j][i]=0;
		}
	}
}


bool isNumber(char x){
	return (x>47 && x<58);
}



char leerNumero(){
	char x;
    for(;;){
    	x=getche();
    	if(!isNumber(x)){
    		printf("\b \b");
		}else{
			return x;
		}	
	}
}

void leerMatriz(char matlet[][9]){
	printf("   1 2 3   4 5 6   7 8 9\n\n");
	for(int i=0;i<9;i++){
		if(i==3 || i==6){
			printf("   ---------------------\n");
		}
		printf("%d  ",i+1);
		for(int j=0;j<9;j++){
			if(j==3 || j==6){
				printf("| ");
			}
			matlet[i][j]=leerNumero();printf(" ");
		}
		printf("\n");
	}
	
}

void transformar(Dato mat[][9],char matAux[][9]){
	int x;
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			x=aNumero(matAux[i][j]);
			if(x==0){
				mat[i][j].valor=x;
				mat[i][j].esPista=false;
			}else{
				mat[i][j].valor=(x);
				mat[i][j].esPista=true;
			}
		}
	}
}

void imprimirSudoku(Dato tablero[][9]){
	for(int i=0;i<9;i++){
		if(i==3 || i==6)
		    printf("------------------------\n");
		for(int j=0;j<9;j++){
			if(j==3 || j==6)
			    printf(" |");
			printf(" %d",tablero[i][j].valor);
		}
		printf("\n");
	}
}

void inicio(int mat[][9]){
	bool band=true;
	int t;
	while(band){
	    printf("      SUDOKU   \n ");
	    printf("1:resolver Sudoku");
	    printf("2:Salir");
	    
	    
	}
	
}

int main(void){
    
   
   char matriz[9][9];
   leerMatriz(matriz);
   Dato tablero[9][9];
   transformar(tablero,matriz);
   printf("\n\n");
   imprimirSudoku(tablero);
   printf("\n\n");
   if(resolver(tablero))
   		printf("\ntrue\n");
   	else
   		printf("false");
   printf("\n\n");
   imprimirSudoku(tablero);
}
  
   
   
  
  

