#include <stdio.h>
#include <stdlib.h>
#include "fogefoge.h"

char** mapa;

int linhas;
int colunas;

void liberamapa(){
    for(int i =0; i<linhas; i++){
        free(mapa[i]);
    }
}

void alocamapa(){
    mapa = malloc(sizeof(char*)*linhas);
    for(int i=0; i<linhas; i++){
        mapa[i] = malloc(sizeof(char)* (colunas+1));
    }
}

void lermapa(){
    FILE* f;
    f = fopen("D:/VisualStudioCODE/C/jogo-pac-man/mapa.txt","r");
    if(f==0){
        printf("Erro na abertura do mapa");
        exit(1);
    }

    fscanf(f, "%d %d", &linhas, &colunas);
    alocamapa();

    for(int i =0;i<5;i++){
        fscanf(f,"%s", mapa[i]);
    }

    fclose(f);
}

int main(){

    lermapa();
    
    for(int i =0;i<5;i++){
        printf("%s\n", mapa[i]);
    }

    liberamapa();
}