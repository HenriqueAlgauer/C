#include <stdio.h>
#include <stdlib.h>
#include "fogefoge.h"
#include "mapa.h"

MAPA m;

int acabou(){
    return 0;
}

void move(char direcao){
    int x;
    int y;

    for(int i =0;i<m.linhas; i++){
        for(int j=0;j<m.colunas;j++){
            if(m.matriz[i][j] == '@'){
                x =i;
                y =j;
                break;
            }
        }
    }

    switch(direcao){
        case 'a': 
            m.matriz[x][y-1] = '@';break;
        case 'd':
            m.matriz[x][y+1] = '@';break;
        case 'w':
            m.matriz[x-1][y] = '@';break;
        case 's':
            m.matriz[x+1][y] = '@';break;
    }
    m.matriz[x][y] = '.';
}

int main(){

    lermapa(&m);

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