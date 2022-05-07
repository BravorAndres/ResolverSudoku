#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

int valor(int x){
	if(x>0)
		return x;
	else
		return -x;
}

bool pista(int x){
	if(x>0)
		return false;
	else
		return true;
}



void imprimirSudoku(int mat[][9]){
	for(int i=0;i<9;i++){
		if(i==3 || i== 6){
			printf("----------------------\n");
		}
		for(int j=0;j<9;j++){
			if(j==3 || j==6){
				printf(" |");
			}
			printf(" %d",valor(mat[i][j]));
		}
		printf("\n");
	}
}

void mat0x0(int mat[][9]){
	for(int j=0;j<9;j++){
		for(int i=0;i<9;i++){
			mat[j][i]=0;
		}
	}
}

int limite(int x){
    if(x<3)
        return 0;
    else if(x<6)
        return 3;
    else
        return 6;
	
}

bool acaja(int mat[][9],int fila,int columna,int x){
	for(int i=limite(fila);i<limite(fila)+3;i++){
		for(int j=limite(columna);j<limite(columna)+3;j++){
			if(x==valor(mat[i][j])){
				return false;
			}
		}
	}
	return true;
}


bool afila(int mat[],int x){
	for(int i=0;i<9;i++){
		if(x==valor(mat[i])){
			return false;
		}
	}
	return true;
}

bool acolumna(int mat[][9],int columna,int x){
	for(int i=0;i<9;i++){
		if(x==valor(mat[i][columna])){
			return false;
		}
	}
	return true;
}


bool encajaNumero(int mat[][9],int fila,int columna,int x){
	return((acaja(mat,fila,columna,x)) && (afila(mat[fila],x)) && (acolumna(mat,columna,x)));
}

void avanza(int &fila,int &columna,int mat[][9]){
	do{
		if(columna==8){
			columna=0;
			fila++;
			if(fila==9)
			    return;
		}else{
			columna++;
			
		}
	}while(!pista(mat[fila][columna]));
}
	
void retrocede(int &fila,int &columna,int mat[][9]){
	do{
		if(columna==0){
			columna=8;
			fila--;
			if(fila==-1)
			    return;
		}else{
			columna--;
		}
	}while(!pista(mat[fila][columna]));
}


bool esSudoku(int mat[][9]){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			if(mat[i][j] !=0){
				if(encajaNumero(mat,i,j,mat[i][j])){
					return false;
				}
			}
		}
	}
	return true;
}


void llenarSudoku(int mat[][9]){
	int fila=0,columna=0;
	int x=9;
	if(pista(mat[0][0])){
		avanza(fila,columna,mat);
	}
	while(fila<9){
	   // printf("%d\n",y++);
		if(x==0){
		
			mat[fila][columna]=0;
			retrocede(fila,columna,mat);
			if(fila==-1){
			    printf("no tiene solucion \n\n\n");
				getchar();
				return;		
			}
			x=valor(mat[fila][columna]);
			x--;
		}else if(encajaNumero(mat,fila,columna,x)){
		
			mat[fila][columna]=x;
			
			x=9;
			if(fila==9){
				return;
			}
		}else{
		
			x--;
		}
		imprimirSudoku(mat);
		printf("\n\n\n\n");
		getche();
		system("cls");
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

void transformar(int mat[][9],char matAux[][9]){
	int x;
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			x=aNumero(matAux[i][j]);
			if(x==0){
				mat[i][j]=x;
			}else{
				mat[i][j]=(-x);
			}
		}
	}
}

void Sudoku(int mat[][9]){
	char matAux[9][9];
//	leerMatriz(matAux);
	mat0x0(mat);
//	transformar(mat,matAux);
//	imprimirSudoku(mat);
	llenarSudoku(mat);
	printf("\n\nsudoku resulto\n\n");
	imprimirSudoku(mat);
}



void inicio(int mat[][9]){
	bool band=true;
	int t;
	while(band){
	    printf("      SUDOKU   \n ");
	    printf("1:resolber Sudoku");
	    printf("2:Salir");
	    
	    
	}
	
}

int main(void){
   int mat[9][9]={{  -1, 0, 0,  -1, 0, 0,  0, 0, 0  },{
	                 0, 0, 0,  0, 0, 0,  0, 0, 0  },{
				     0, 0, 0,  0, 0, 0,  0, 0, 0  },{
						
					 0, 0, 0,  0, 0, 0,  0, 0, 0  },{
					 0, 0, 0,  0, 0, 0,  0, 0, 0  },{
					 0, 0, 0,  0, 0, 0,  0, 0, 0  },{
					
					 0, 0, 0,  0, 0, 0,  0, 0, 0  },{
					 0, 0, 0,  0, 0, 0,  0, 0, 0  },{
					 0, 0, 0,  0, 0, 0,  0, 0, 0  }};  
   
   mat0x0(mat);
   Sudoku(mat);
}
  
   
   
  
  

