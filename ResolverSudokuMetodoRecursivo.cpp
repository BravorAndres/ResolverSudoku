#include <stdio.h>


typedef int Matriz[9][9];
int numSol=0;

int limite(int x){
	int a;
	for(a=3;a<=x;a+=3);
	return a-3;
}

bool numeroExistente(Matriz tablero,int px,int py,int x){
	int limX=limite(px);
	int limY=limite(py);
	for(int i=limX;i<limX+3;i++)
	    for(int j=limY;j<limY+3;j++)
	        if(tablero[i][j]==x)
	            return false;
	for(int i=0;i<9;i++)
	    if(tablero[px][i]==x || tablero[i][py]==x)
	        return false;
	return true;
}

void imprimirSudoku(Matriz tablero){
	for(int i=0;i<9;i++){
		if(i==3 || i==6)
		    printf("------------------------\n");
		for(int j=0;j<9;j++){
			if(j==3 || j==6)
			    printf(" |");
			printf(" %d",tablero[i][j]);
		}
		printf("\n");
	}
}

void llenarSudoku(Matriz tablero,int px,int py){
	if(px<9){
	    if(py<9){
	    	if(tablero[px][py]==0){
	    		for(int i=1;i<10;i++)
	    			if(encaja(tablero,px,py,i)){
	    				tablero[px][py]=i;
	    			    llenarSudoku(tablero,px,py+1);
						tablero[px][py]=0;	
					}
		    }else
		        llenarSudoku(tablero,px,py+1);    
		}else
		    llenarSudoku(tablero,px+1,0);
	}else{
		numSol++;
	    printf("solucion NO:%d\n",numSol);
    	imprimirSudoku(tablero);
    	getchar();
    }
}

void mat0x0(Matriz tablero){
	for(int i=0;i<9;i++)
	    for(int j=0;j<9;j++)
	        tablero[i][j]=0;
}



int main(void){
	Matriz sudoku={{1,0,4, 0,5,0, 0,0,0},
	               {0,0,0, 0,0,0, 0,0,5},
				   {6,0,8, 0,0,0, 0,0,0},
				   
				   {0,0,0, 0,0,0, 0,0,0},
				   {0,0,0, 0,0,0, 0,0,0},
				   {0,0,0, 0,0,0, 0,0,0},
				   
				   {0,5,0, 0,0,0, 0,0,0},
				   {0,0,0, 0,0,0, 0,0,0},
				   {0,0,0, 0,0,0, 0,0,0}};
	llenarSudoku(sudoku,0,0);
	printf("sin mas solucion");
	return 0;
}
