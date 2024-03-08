#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fogefoge.h"
#include "mapa.h"

MAPA m;
POSICAO heroi;
int tempilula = 0;

int praondefantasmavai(int xatual, int yatual, 
    int* xdestino, int* ydestino) {

    int opcoes[4][2] = { 
        { xatual   , yatual+1 }, 
        { xatual+1 , yatual   },  
        { xatual   , yatual-1 }, 
        { xatual-1 , yatual   }
    };

    srand(time(0));
    for(int i = 0; i < 10; i++) {
        int posicao = rand() % 4;

        if(podeandar(&m, FANTASMA, opcoes[posicao][0], opcoes[posicao][1])) {
            *xdestino = opcoes[posicao][0];
            *ydestino = opcoes[posicao][1];
            return 1;
        }
    }

    return 0;
}

void fantasmas(){
    MAPA copia;
    
    copiamapa(&copia, &m);

    for(int i =0; i <m.linhas; i++){
        for(int j=0; j <m.colunas;j++){

             if(copia.matriz[i][j] == FANTASMA){

                int xdestino;
                int ydestino;

                int encontrou = praondefantasmavai(i, j, &xdestino, &ydestino);
                
                if(encontrou){
                    andanomapa(&m, i, j,xdestino, ydestino);
                }
             }
        }
    }
    liberamapa(&copia);
}

int acabou(){
    POSICAO pos;
    int perdeu = !encontramapa(&m, &pos, HEROI);
    int ganhou = !encontramapa(&m, &pos, FANTASMA);
    return ganhou || perdeu;
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

    if(!podeandar(&m, HEROI, proximox, proximoy))return;  

    if(ehpersonagem(&m, HEROI, proximox, proximoy)){
        tempilula = 1;
    }

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
        fantasmas();
    }while(!acabou());
    
    for(int i =0;i<5;i++){
        printf("%s\n", m.matriz[i]);
    }

    liberamapa(&m);
}