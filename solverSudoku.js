
function inicarMatriz(){
    let tablero = [[0,0,0, 0,0,0, 0,0,0],
                   [0,0,0, 0,0,0, 0,0,0],
                   [0,0,0, 0,0,0, 0,0,0],
                   [0,0,0, 0,0,0, 0,0,0],
                   [0,0,0, 0,0,0, 0,0,0],
                   [0,0,0, 0,0,0, 0,0,0],
                   [0,0,0, 0,0,0, 0,0,0],
                   [0,0,0, 0,0,0, 0,0,0],
                   [0,0,0, 0,0,0, 0,0,0],];
    
    return tablero;
}

function rangaCaja(x){
    if(x<3)
        return 0;
    else if (x>=3 && x < 6)
        return 3;
    else 
        return 6;

}

function evaluar(tablero, x,y,n){
    if(!tablero[x].include(n))
        return false;
    else{
        console.log("logrado");
    }
}

function sumar(x,y){
    return x+y;
}

let matriz = inicarMatriz();

console.log(evaluar(matriz,1,2,9))