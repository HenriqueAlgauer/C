#include <stdio.h>
#include <stdlib.h>
#include "fogefoge.h"

struct mapa m;

void liberamapa(){
    for(int i =0; i<m.linhas; i++){
        free(m.matriz[i]);
    }
}

void alocamapa(){
    m.matriz = malloc(sizeof(char*)*m.linhas);
    for(int i=0; i<m.linhas; i++){
        m.matriz[i] = malloc(sizeof(char)* (m.colunas+1));
    }
}

void imprimemapa() {
    for(int i = 0; i < m.linhas; i++) {
        printf("%s\n", m.matriz[i]);
    }
}

void lermapa(){
    FILE* f;
    f = fopen("D:/VisualStudioCODE/C/jogo-pac-man/mapa.txt","r");
    if(f==0){
        printf("Erro na abertura do mapa");
        exit(1);
    }

    fscanf(f, "%d %d", &(m.linhas), &(m.colunas));
    alocamapa();

    for(int i =0;i<5;i++){
        fscanf(f,"%s", m.matriz[i]);
    }

    fclose(f);
}

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

    lermapa();

    do{
        imprimemapa();
        char comando;

        scanf(" %c", &comando);
        move(comando);
    }while(!acabou());
    
    for(int i =0;i<5;i++){
        printf("%s\n", m.matriz[i]);
    }

    liberamapa();
}