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

void move(char direcao){

    if(direcao !='a' && 
        direcao !='d' && 
        direcao !='w' && 
        direcao !='s')return;

    int proximox = heroi.x;
    int proximoy = heroi.y;

    switch(direcao){
        case 'a': 
            proximoy--;break;
        case 'd':
            proximoy++;break;
        case 'w':
            proximox--;break;
        case 's':
            proximox++;break;
    }

    if(proximox >= m.linhas){
        return;
    }
    if(proximoy >= m.colunas){
        return;
    }
    if(m.matriz[proximox][proximoy] != '.'){
        return;
    }

    m.matriz[heroi.x][heroi.y]= '.';
    m.matriz[proximox][proximoy] = '@';
    heroi.x = proximox;
    heroi.y = proximoy;
}

int main(){

    lermapa(&m);
    encontramapa(&m, &heroi, '@');

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