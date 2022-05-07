#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>



typedef struct  {
	int valPrincipal;
	bool pista;	
}Dato;

typedef struct{
	int Px;
	int Py;
}Posiciones;



Dato **matriz(int x,int y){
	Dato **mat;
	mat=(Dato **)malloc(sizeof(Dato*)*x);
	for(int i=0;i<x;i++)
	    mat[i]=(Dato*)malloc(sizeof(Dato)*y);
	return mat;
}


void matrizPorDefecto1(Dato **tablero){
	int mat[16][16]={{1,5,10,2,  3,4,9,11,  12,16,6,14,  15,13,7,8},
	                 {14,16,8,13,  5,15,7,12,  4,3,1,2,  9,10,6,11},
					 {9,12,4,7,  10,16,6,1,  8,13,15,11,  3,5,14,2},
					 {3,6,11,15,  2,13,8,14,  7,5,10,9,  4,16,12,1},
					 
					 {0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0},
					 {0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0},
					 {0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0},
					 {0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0},
					 
					 {0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0},
					 {0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0},
					 {0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0},
					 {0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0},
					 
					 {0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0},
					 {0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0},
					 {0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0},
					 {0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0}};
					 
	for(int i=0;i<16;i++)
	    for(int j=0;j<16;j++){
	    	tablero[i][j].valPrincipal=mat[i][j];
	    	tablero[i][j].pista=(mat[i][j]>0);
		}	
}

void matPorDefecto2(Dato **tab){
	int mat[4][4]={{0,1, 0,0,},
	               {0,0, 2,0,},
	               
				   {0,4, 0,0,},
				   {3,0, 0,0,}};
	for(int i=0;i<4;i++)
	    for(int j=0;j<4;j++){
	        tab[i][j].valPrincipal=mat[i][j];
	        tab[i][j].pista=(mat[i][j]>0);
	    }
}

void matPorDefecto3(Dato **tab){
   int mat[9][9]={{  0, 0, 0,  0, 0, 0,  0, 0, 0  },{
	                 0, 0, 0,  0, 0, 0,  0, 0, 0  },{
				     0, 9, 0,  7, 3, 8,  0, 0, 0  },{
						
					 0, 0, 0,  0, 0, 0,  0, 0, 0  },{
					 0, 0, 0,  0, 0, 0,  0, 0, 0  },{
					 6, 0, 0,  0, 0, 0,  0, 5, 0  },{
					
					 0, 0, 0,  0, 0, 0,  0, 0, 0  },{
					 0, 0, 0,  0, 0, 2,  0, 9, 0  },{
					 0, 0, 0,  1, 0, 0,  0, 0, 0  }};
	for(int i=0;i<9;i++)
	    for(int j=0;j<9;j++){
	        tab[i][j].valPrincipal=mat[i][j];
	        tab[i][j].pista=(mat[i][j]>0);
	    }
}

void tablero0x0(Dato **tab,int tamanio){
	
	for(int i=0;i<tamanio;i++){
	    for(int j=0;j<tamanio;j++){
	    	tab[i][j].valPrincipal=0;
	    	tab[i][j].pista=false;
		}
	}
}

int CantDig(int x){
	if (x==0)
	    return 1;
	int i=0;
	for(;x>0;x=x/10,i++);
	return i;
}

void escribirNumero(int x){
	int CD=CantDig(x);
	switch(CD){
		case 1:
			printf("%d",x);
			break;
		case 2:
			printf("%d",x);
			break;
		case 3:
			printf("%d",x);
		break;
		default:
			printf("%d",x);
			break;
	}
}

void imprimirSudoku(Dato **tablero,int tamanio){
	int Cf,Cc;
	Cf=sqrt(tamanio);
	
	for(int i=0;i<tamanio;i++){
		if(i==Cf){
			printf("\n");
			Cf=Cf+sqrt(tamanio);
		}
	    Cc=sqrt(tamanio);
		for(int j=0;j<tamanio;j++){
		    if(j==Cc){
		    	printf("|");
		    	Cc=Cc+sqrt(tamanio);
			}
			escribirNumero(tablero[i][j].valPrincipal);
		}
	
		printf("\n");
	}
//	printf("**************************   \n");
}


bool aFila(Dato **tab,Posiciones *p,int tamanio,int x){
	for(int i=0;i<tamanio-1;i++)
	    if(tab[p->Px][i].valPrincipal==x)
	        return false;
	return true;
}

bool aColumna(Dato **tab,Posiciones *p,int tamanio,int x){
    for(int i=0;i<tamanio-1;i++)
        if(tab[i][p->Py].valPrincipal==x)
            return false;
    return true;
}

Posiciones *limCuadrante(Posiciones **p,int tamanio){//**************************************************************************
	Posiciones *q,*w;                                //*************        el error esta en esta funcion    ********************
	q=(Posiciones *)malloc(sizeof(Posiciones));      //**************************************************************************
    w=(Posiciones *)malloc(sizeof(Posiciones));      //
                                                     //  formar cuadrantes y preguntar si esta en ellos
    q=*p;                                            //
    int limX,limY;
    
    for(limX=sqrt(tamanio); limX<= q->Px ;  limX=limX+sqrt(tamanio));
    w->Px=limX-sqrt(tamanio);
    
    for(limY=sqrt(tamanio); limY<=q->Py;  limY=limY+sqrt(tamanio));
    w->Py=limY-sqrt(tamanio);
    
    return w;	
}

bool aCaja(Dato **tablero,Posiciones *p,int tamanio,int x){
	Posiciones *q;
	q=limCuadrante(&p,tamanio);
//	printf("\n\nlimites de caja:px=%d  py=%d",q->Px,q->Py);getche();
	for(int i=q->Px;i<q->Px+sqrt(tamanio);i++)
		for(int j=q->Py;j<q->Py+sqrt(tamanio);j++)
		    if(tablero[i][j].valPrincipal==x)
		        return false;
		        
	return true;
}

bool encaja(Dato **tablero,Posiciones *p,int tamanio,int x){
	return((aCaja(tablero,p,tamanio,x)) && (aFila(tablero,p,tamanio,x)) && (aColumna(tablero,p,tamanio,x)));
}

void avanzar(Dato **tablero,Posiciones *p,int tamanio){
    do{
    	if(p->Py==tamanio-1){
    		p->Py=0;
    		p->Px++;
    		if(p->Px==tamanio)
    		    return;
		}else
		    p->Py++;	
	}while(tablero[p->Px][p->Py].pista);
}

void retroceder(Dato **tablero,Posiciones *p,int tamanio){
	do{
		if(p->Py==0){
			p->Py=tamanio-1;
			p->Px--;
			if(p->Px==-1)
			    return;
		}else
		    p->Py--;
	}while(tablero[p->Px][p->Py].pista);
}

void algoritmoLlenar(Dato **tablero,int tamanio){
	Posiciones *p;
	
	p=(Posiciones *)malloc(sizeof(Posiciones));
	p->Px=p->Py=0;
	
	if(tablero[p->Px][p->Py].pista)
     	avanzar(tablero,p,tamanio);
	int x,t=0;
	
	x=0;
	
	while(p->Px<tamanio){
		
	/*	imprimirSudoku(tablero,tamanio);printf("\n\n");//getche();
		printf("x=%d\tpx=%d  py=%d",x,p->Px,p->Py);getche();  */
		
		if(x==tamanio){
		    
		    //printf("aqui\n");
				
			tablero[p->Px][p->Py].valPrincipal=0;
			retroceder(tablero,p,tamanio);
			if(p->Px==-1){
				printf("\n\nno tiene solucion\n");
				return;
			}
			x=tablero[p->Px][p->Py].valPrincipal;
			x--;
			
		}else if(encaja(tablero,p,tamanio,x)){
	       
		   // imprimirSudoku(tablero,tamanio);printf("\n\n");//getche();
	    //	printf("x=%d°-°\tpx=%d  py=%d\n",x,p->Px,p->Py);getche(); 
			
			tablero[p->Px][p->Py].valPrincipal=x;
			avanzar(tablero,p,tamanio);
			x=tamanio;
			if(p->Px==tamanio)
			    return;
		}else{
		//	imprimirSudoku(tablero,tamanio);//getche();
	    //	printf("\n\nx=%d\tpx=%d  py=%d",x,p->Px,p->Py);
		    x++;
	    }
	}   
	
}



int main(){
	
	
	Dato **tab;
	int tamanio=10;
	
    tab=matriz(tamanio,tamanio);
	Posiciones *p;
	p=(Posiciones*)malloc(sizeof(Posiciones));
	p->Px=0;
	p->Py=0;
	
	//matrizPorDefecto1(tab);
    tablero0x0(tab,tamanio);
  //  matPorDefecto2(tab);
    matPorDefecto3(tab);
  
	algoritmoLlenar(tab,tamanio);
    imprimirSudoku(tab,tamanio);
   
    
	
   
	return 0;
}
