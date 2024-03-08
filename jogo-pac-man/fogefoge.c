#include <stdio.h>
#include <stdlib.h>
#include "fogefoge.h"
#include "mapa.h"

MAPA m;
POSICAO heroi;

int x;
int y;

int acabou(){
    return 0;
}

int verificadirecao(char direcao){
    return direcao =='a' || 
        direcao =='d' || 
        direcao =='w' || 
        direcao =='s';
}

void move(char direcao){

    if(!verificadirecao(direcao))return;

    int proximox = heroi.x;
    int proximoy = heroi.y;

    switch(direcao){
        case ESQUERDA: 
            proximoy--;break;
        case DIREITA:
            proximoy++;break;
        case CIMA:
            proximox--;break;
        case BAIXO:
            proximox++;break;
    }

    if(!ehvalida(&m, proximox, proximoy))return;  

    if(!ehvazia(&m, proximox, proximoy))return;

    andanomapa(&m, heroi.x, heroi.y, proximox, proximoy);
    heroi.x = proximox;
    heroi.y = proximoy;
}

int main(){

    lermapa(&m);
    encontramapa(&m, &heroi, HEROI);

    do{
        imprimemapa(&m);
        char comando;

        scanf(" %c", &comando);
        move(comando);
    }while(!acabou());
    
    for(int i =0;i<5;i++){
        printf("%s\n", m.matriz[i]);
    }

    liberamapa(&m);
}