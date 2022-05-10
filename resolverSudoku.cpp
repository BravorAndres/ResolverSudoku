#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>


typedef struct {
	int valor;
	bool esPista;
}Dato;

typedef struct posiciones{
	int px;
	int py;
}Posicion;



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

int limite(int p){
	int a;
	for(a=3;a<=p;a+=3);
	return a-3;
}

void avanzar(Dato tablero[][9],Posicion *p){
    do{
    	if(p->py==8){
    		p->py=0;
    		p->px++;
    		if(p->px==9)
    		    return;
		}else
		    p->py++;	
	}while(tablero[p->px][p->py].esPista);
}

void retroceder(Dato tablero[][9],Posicion *p){
	do{
		if(p->py==0){
			p->py=8;
			p->px--;
			if(p->px==-1)
			    return;
		}else
		    p->py--;
	}while(tablero[p->px][p->py].esPista);
}

bool validar(Posicion P,Dato tablero[][9],int x){
	for (int i=0;i<9;i++)
		if(tablero[P.px][i].valor==x || tablero[i][P.py].valor==x)
			return true;
	int limX=limite(P.px);
	int limY=limite(P.py);
	for(int i=limX;i<limX+3;i++)
	    for(int j=limY;j<limY+3;j++)
	        if(tablero[i][j].valor==x)
	            return false;
	return true;
}

void llenarSudoku(Dato tablero[][9]){
	Posicion P;
	P.px=P.py=0;
	int x=1;
	while(P.px<9){
		if(x>9){
			tablero[P.px][P.py].valor=0;
			retroceder(tablero,&P);
			if(P.px==9)
				return;
			x=tablero[P.px][P.py].valor;
			x++;
			tablero[P.px][P.py].valor=0;
		}else if(validar(P,tablero,x)){
			tablero[P.px][P.py].valor=x;
			avanzar(tablero,&P);
			if(P.px=9);
			x=0;
		}else
			x++;
	}
}

void mat0x0(int mat[][9]){
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

int aNumero(char x){
	return x-48;
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
				mat[i][j].valor=(-x);
				mat[i][j].esPista=true;
			}
		}
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
   llenarSudoku(tablero);
   printf("\n\n");
   imprimirSudoku(tablero);
}
  
   
   
  
  

