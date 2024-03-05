#include <stdio.h>
#include <stdlib.h>
#include <locale.h>



void linha(){
    int i;

    for(i=0;i<20;i++){
        printf("*");
    }
}

int main(){

    setlocale(LC_ALL, "Portuguese");


    linha();
    printf("\nBem Vindo ao jogo da adivinhação\n");
    linha();

    int chute;

    printf("Qual é o seu chute ? ");
    scanf("%d", &chute);
    


    return 0;
}